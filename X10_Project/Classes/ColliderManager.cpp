#include "stdafx.h"
#include "StageInformation.h"
#include "ColliderManager.h"
#include "Collider.h"
#include "Bullet.h"
#include "Sling.h"

ColliderManager* ColliderManager::instance = nullptr;

ColliderManager::ColliderManager() :curBulletIndex(0), defaultBulletNum(0)
{
	colliders.reserve(defaultBulletNum);
}

ColliderManager::~ColliderManager() {}

ColliderManager* ColliderManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new ColliderManager();
	}
	return instance;
}

void ColliderManager::InitColliders() //Temporary init colliders
{
	curBulletIndex = 0;
	defaultBulletNum = 5;
	colliders.reserve(defaultBulletNum);

	for (int i = 0; i < defaultBulletNum; i++)
	{
		colliders.pushBack(Bullet::create()); ///# ���ο��� new�� �ؼ� ���Ϳ� �ֱ� ������ �ڿ������� �ݵ�� ���� ����� �Ѵ�.
	}
}

void ColliderManager::InitColliders(StageInformation* stage) //<- pass stage information parameter 
{
	// ex
	// Colliders.pushBack(si->Colliders->pop_back());
	// Colliders.pushBack(si->Colliders->pop_back());
	// Colliders.pushBack(si->Colliders->pop_back());
	// Colliders.pushBack(si->Colliders->pop_back());
	// ...
}

Bullet* ColliderManager::GetBulletToShot()
{
	if (curBulletIndex < defaultBulletNum)
	{
		Sling* sling = Sling::GetInstance();
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

bool ColliderManager::HasBullet()
{
	if (curBulletIndex < defaultBulletNum)
	{
		return true;
	}
	return false;
}

void ColliderManager::Reset()
{
	colliders.clear(); ///# ��? Collider* ���ҵ��� �� �޸� ���� ���ڳ�..
	InitColliders();
}

void ColliderManager::EraseCollider(Collider* collider)
{
	colliders.eraseObject(collider);
}