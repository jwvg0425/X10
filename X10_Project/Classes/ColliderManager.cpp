#include "stdafx.h"
#include "StageInformation.h"
#include "ColliderManager.h"
#include "Collider.h"
#include "Bullet.h"
#include "Sling.h"

ColliderManager::ColliderManager()
{
	curBulletIndex = 0;
	defaultBulletNum = 5;
	colliders.reserve(defaultBulletNum);
}

ColliderManager::~ColliderManager()
{
	colliders.clear();
}

void ColliderManager::InitBullets(StageInformation* si)
{
	//���Ŀ� si�� �ʱ�ȭ
	for (int i = 0; i < defaultBulletNum; i++)
	{
		colliders.pushBack(Bullet::create());
	}
}

Bullet* ColliderManager::GetBulletToShot(Sling* sling)
{
	if (curBulletIndex < defaultBulletNum)
	{
		Bullet* bullet = (Bullet*)colliders.at(curBulletIndex++);
		
		bullet->setPosition(sling->getPosition());
		bullet->setRotation(sling->GetRotationAngle());
		bullet->SetDirection(sling->GetDirection());
		bullet->SetSpeed(sling->GetSpeed());
		bullet->SetFlying(true);

		return bullet;
	}

	return nullptr;
}

void ColliderManager::AddExplosion(Collider* explosion)
{
	colliders.pushBack(explosion);
}

void ColliderManager::EraseCollider(Collider* collider)
{
	colliders.eraseObject(collider);
}

bool ColliderManager::HasBullet()
{
	if (curBulletIndex < defaultBulletNum)
	{
		return true;
	}
	return false;
}

