#include "stdafx.h"
#include "ColliderManager.h"
#include "Collider.h"
#include "Bullet.h"
#include "Sling.h"
ColliderManager* ColliderManager::instance = nullptr;

ColliderManager::ColliderManager() {
	Init();
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

//call in game manager's init
void ColliderManager::Init() //<- pass stage information parameter (si->ColliderManger)
{										//that holds the number of Colliders to have(not implemented yet)
	//temporary initialization for test
	curBulletIndex = 0;
	defaultBulletNum = 5;
	colliders.reserve(defaultBulletNum);

	InitColliders();
}

void ColliderManager::InitColliders() //<- pass stage information parameter (si->Colliders) 
{								  //that holds what Colliders to use (not implemented yet)

// ex
// Colliders.pushBack(si->Colliders->pop_back());
// Colliders.pushBack(si->Colliders->pop_back());
// Colliders.pushBack(si->Colliders->pop_back());
// Colliders.pushBack(si->Colliders->pop_back());
// ...
	for (int i = 0; i < defaultBulletNum; i++)
	{
		colliders.pushBack(Bullet::create()); ///# ���ο��� new�� �ؼ� ���Ϳ� �ֱ� ������ �ڿ������� �ݵ�� ���� ����� �Ѵ�.
	}
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
	Init();
}

void ColliderManager::EraseCollider(Collider* collider)
{
	colliders.eraseObject(collider);
}