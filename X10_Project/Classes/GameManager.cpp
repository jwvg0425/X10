#include "stdafx.h"
#include "GameLayer.h"
#include "UILayer.h"
#include "GameManager.h"
#include "StageInformation.h"
#include "ColliderManager.h"
#include "TargetManager.h"
#include "Collider.h"
#include "Bullet.h"
#include "Target.h"
#include "Sling.h"
#include "Mirror.h"

GameManager* GameManager::instance = nullptr;

GameManager* GameManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new GameManager();
	}
	return instance;
}

GameManager::GameManager()
{
	sling = nullptr;
	colliderManager = new ColliderManager();
	targetManager = new TargetManager();
	stage = nullptr;
}

GameManager::~GameManager()
{

}

void GameManager::Reset()
{
	delete instance;
	instance = nullptr;
}

void GameManager::SetStage(GameLayer* gameLayer, int StageNumber)
{	
	if (stage != nullptr)
	{
		delete stage;
	}

	stage = new StageInformation(StageNumber);
	
	//�ش� ���������� Ÿ�� ������ ���Ϳ� ����
	targetManager->InitTargets(stage);
	//���̾ �ٿ��ش�
	AppendTargetsToLayer(gameLayer);
	
	//�ҷ� ����
	colliderManager->InitBullets(stage);

	//���� ����
	sling = SetSling(gameLayer);
}

Sling* GameManager::SetSling(GameLayer* gameLayer)
{

	Sling* sling = Sling::create();
	gameLayer->addChild(sling);

	//�Ѿ��� ������
	if (colliderManager->HasBullet())
	{
		//�������� �Ѿ��� �����϶�� �˸���.
		sling->LoadBullet();
	}

	return sling;
}

void GameManager::AppendTargetsToLayer(GameLayer* gameLayer)
{
	Vector<Target*> targets = targetManager->GetTargets();

	for (Target* target : targets)
	{
		gameLayer->addChild(target);
	}

}

void GameManager::ShotBullet(Sling* sling)
{
	//������ ���°� 'IsShotted'�̸�
	if (sling->IsShotted())
	{
		//��ġ, ����, �ӵ��� ���õ� bullet�� �����ϰ� ���̾ ���δ�
		Bullet* bullet = static_cast<Bullet*>(colliderManager->GetBulletToShot(sling));
		Scene* currentScene = Director::getInstance()->getRunningScene();
		Scene* gameScene = static_cast<Scene*>(currentScene->getChildByName("GameScene"));
		Layer* gameLayer = static_cast<Layer*>(gameScene->getChildByName("GameLayer"));
		gameLayer->addChild(bullet);
		//�������� �߻簡 �Ϸ�Ǿ��ٰ� �˸���.
		sling->ShotComplete();
		
		//�Ѿ��� ������
		if (colliderManager->HasBullet())
		{
			//�������� �Ѿ��� �����϶�� �˸���.
			sling->LoadBullet();
		}
	}
}

void GameManager::Play(GameLayer* gameLayer, UILayer* uiLayer)
{
	//���͸� ��°�� �����ؼ� �ӽ� ������ ���� ����. ���� ������ ����
	Vector<Collider*> colliders = colliderManager->GetColliders();
	Vector<Target*> targets = targetManager->GetTargets(); 


	for (Collider* collider : colliders)
	{
		//1. ���� �ִ� 'collider'�� 
		if (collider->IsFlying())
		{
			//'Act()'�� ��Ű��
			collider->Act(colliderManager);
			//�� 'collider'�� Ÿ���� �浹�ϴ��� üũ�Ѵ�. 
			CheckCollide(collider, targets);
		}

		//2. 'collider'�� bullet�̰�
		if (collider->IsBullet())
		{
			//�����ؾ��ϸ�
			if (((Bullet*)collider)->ShouldExplode())
			{
				//������ �����Ͽ� ���Ϳ� �ְ� ���̾ �ٿ��ش�
				Explosion* explosion = (static_cast<Bullet*>(collider))->GetExplosion();
				colliderManager->AddExplosion(explosion);
				gameLayer->addChild(explosion);
			}
		}
	}
}

void GameManager::CheckCollide(Collider* collider, Vector<Target*> targets)
{
	static Target* lastTarget = nullptr;
	for (Target*& target : targets)
	{
		if (target == lastTarget)
			continue;

		if (collider->IsBullet())
		{
			const Rect colliderBoundingBox = (static_cast<Bullet*>(collider))->GetBoundingArea();
			const Rect targetBoundingBox = target->GetBoundingArea();

			if (colliderBoundingBox.intersectsRect(targetBoundingBox))
			{
				lastTarget = target;
				target->ApplyCollisionEffect(collider);
			}
		}
		else
		{
			const float explosionRadius = (static_cast<Explosion*>(collider))->GetBoundingRadius();
			const Vec2 explosionPosition = (static_cast<Explosion*>(collider))->getPosition();
			const Rect targetBoundingBox = target->GetBoundingArea();

			if (targetBoundingBox.intersectsCircle(explosionPosition, explosionRadius))
			{
				lastTarget = target;
				target->ApplyCollisionEffect(collider);
			}
		}
	}
}