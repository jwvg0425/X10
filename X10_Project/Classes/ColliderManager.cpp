#include "stdafx.h"
#include "ColliderManager.h"
#include "Sling.h"
//colliders
#include "Collider.h"
#include "Bullet.h"
//Stage Information
#include "StageInformation.h"
#include <hash_map>
using namespace stdext;

void ColliderManager::InitBullets(StageInformation* si)
{
	ResetBullets();

	defaultBulletNum = si->GetBulletCount();
	colliders.reserve(defaultBulletNum);
	curBulletIndex = 0;

	hash_map<string, void*> bulletTypeInfo;
	bulletTypeInfo.insert(hash_map<string, void*>::value_type("Bullet", Bullet::create));
	while (si->HasNextBullet())
	{
		//Ÿ�� �̸��� �ҷ��ͼ�
		string type = si->GetCurrentBulletInfo();
		void* createFunction = bulletTypeInfo.at(type);
		
		//�ű⿡ �´� ���丮 �Լ� ȣ��
		Bullet* (*create)() = static_cast<Bullet* (*)()>(createFunction);
		Bullet* bullet = (*create)();

		//����Ʈ�� ����.
		colliders.pushBack(bullet);
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

void ColliderManager::ResetBullets()
{
	for (Collider* collider : colliders)
	{
		delete collider;
	}
	colliders.clear();
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

