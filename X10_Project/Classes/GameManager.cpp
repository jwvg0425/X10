#include "stdafx.h"
#include "GameLayer.h"
#include "UILayer.h"
#include "GameManager.h"
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
	colliderManager = ColliderManager::GetInstance();
	targetManager = TargetManager::GetInstance();
}

GameManager::~GameManager(){}

void GameManager::Reset()
{
	delete instance;
	instance = nullptr;
	ColliderManager::GetInstance()->Reset();
//	TargetManager::GetInstance()->Reset();
}

void GameManager::InitTargets(GameLayer* gameLayer)
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
		//��ġ, ����, �ӵ��� ���õ� bullet�� �����Ͽ� ���̾ ���δ�
		Bullet* bullet = (Bullet*)colliderManager->GetBulletToShot();
		gameLayer->addChild(bullet);
		//�������� �߻簡 �Ϸ�Ǿ��ٰ� �˸���.
		sling->ShotComplete();
	}

	for (Collider* collider : colliders)
	{
		//���� �ִ� 'collider'�� 
		if (collider->IsFlying())
		{
			//'Act()'�� �϶�� ��Ű��
			collider->Act();
			//�� 'collider'�� Ÿ���� �浹�ϴ��� üũ�Ѵ�. 
			CheckCollide(collider, targets);
		}

		//�� 'collider'�� bullet�̸�
		if (collider->IsBullet())
		{
			//�׸��� �����ϴ� ���̸�
			if (((Bullet*)collider)->IsExplosing()) ///# C++ ĳ������ ���.
			{
				//���߽����ְ�
				Explosion* explosion = ((Bullet*)collider)->GetExplosion();
				gameLayer->addChild(explosion);
				//�� 'collider'(bullet)���� ���¸� �ٲٶ�� �˸���
				((Bullet*)collider)->StopExplosing();
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
			target->ApplyEffectToBullet((Bullet*)collider);
		}
	}
}