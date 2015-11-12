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
	sling = Sling::GetInstance();
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

void GameManager::SetStage(int StageNumber)
{	
	if (stage != nullptr)
	{
		delete stage;
	}

	stage = new StageInformation(StageNumber);
	
	targetManager->InitTargets(stage);
	colliderManager->InitBullets(stage);
}

void GameManager::SetTargets(GameLayer* gameLayer)
{
	Vector<Target*> targets = targetManager->GetTargets();

	for (Target* target : targets)
	{
		gameLayer->addChild(target);
	}
}

void GameManager::Play(GameLayer* gameLayer, UILayer* uiLayer)
{
	//���͸� ��°�� �����ؼ� �ӽ� ������ ���� ����. ���� ������ ����
	Vector<Collider*> colliders = colliderManager->GetColliders();
	Vector<Target*> targets = targetManager->GetTargets(); 

	//�Ѿ��� ������
	if (colliderManager->HasBullet())
	{
		//�������� �Ѿ��� �����϶�� �˸���.
		sling->LoadBullet();
	}

	//������ ���°� 'IsShotted'�̸�
	if (sling->IsShotted())
	{
		//��ġ, ����, �ӵ��� ���õ� bullet�� �����ϰ� ���̾ ���δ�
		Bullet* bullet = (Bullet*)colliderManager->GetBulletToShot(sling);
		gameLayer->addChild(bullet);
		//�������� �߻簡 �Ϸ�Ǿ��ٰ� �˸���.
		sling->ShotComplete();
	}

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
				Explosion* explosion = ((Bullet*)collider)->GetExplosion();
				colliderManager->AddExplosion(explosion);
				gameLayer->addChild(explosion);
			}
		}
	}
}

void GameManager::CheckCollide(Collider* collider, Vector<Target*> targets)
{
	for (Target* target : targets)
	{
		if (collider->getBoundingBox().intersectsRect(target->getBoundingBox()))
		{
			target->ApplyCollisionEffect(collider);
		}
	}
}