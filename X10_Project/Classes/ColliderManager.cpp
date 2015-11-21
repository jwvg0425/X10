#include "stdafx.h"
#include "ColliderManager.h"
#include "Sling.h"
//colliders
#include "Collider.h"
#include "Bullet.h"
#include "CrossBullet.h"

//Stage Information
#include "StageInformation.h"
#include <hash_map>
using namespace stdext;

void ColliderManager::InitBullets(StageInformation* si)
{
	ResetBullets();

	m_BulletNum = si->GetBulletCount();
	m_colliders.reserve(m_BulletNum);
	m_curBulletIndex = -1;

	hash_map<string, void*> bulletTypeInfo;
	bulletTypeInfo.insert(hash_map<string, void*>::value_type("CrossBullet", CrossBullet::create));
	bulletTypeInfo.insert(hash_map<string, void*>::value_type("CrossBullet", CrossBullet::create));
	bulletTypeInfo.insert(hash_map<string, void*>::value_type("CrossBullet", CrossBullet::create));
	bulletTypeInfo.insert(hash_map<string, void*>::value_type("Bullet", Bullet::create));
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
		m_colliders.pushBack(bullet);
	}
	
}


void ColliderManager::AddExplosion(Collider* explosion)
{
	m_colliders.pushBack(explosion);
}

void ColliderManager::ResetBullets()
{
	for (Collider* collider : m_colliders)
	{
		delete collider;
	}
	m_colliders.clear();
}
void ColliderManager::EraseDeadColliders()
{
	Collider* collider = nullptr;
	for (int i = 0; i < m_colliders.size(); i++){
		collider = m_colliders.at(i);
		if (collider->ToBeErased()){
			m_colliders.erase(m_colliders.begin() + i);
			if (collider->IsBullet())
				m_BulletNum--;
		}
	}
}


//�ݵ�� �� �ҷ��� �ִ��� üũ�ϰ� �ҷ��� ���������Ѵ�.
bool ColliderManager::HasBulletToShot()
{
	Collider* collider = nullptr;
	for (int i = 0; i < m_BulletNum; i++){
		collider = m_colliders.at(i);
		if (collider->IsBullet())
		{
			if (dynamic_cast<Bullet*>(collider)->NotShooted()){
				m_curBulletIndex = i;
				return true;
			}
		}
	}
	m_curBulletIndex = -1;
	return false;
}


Bullet* ColliderManager::GetBulletToShot(Sling* sling)
{
	if (m_curBulletIndex != -1)
	{
		Bullet* bullet = (Bullet*)m_colliders.at(m_curBulletIndex);

		bullet->setPosition(sling->getPosition());
		bullet->setRotation(sling->GetRotationAngle());
		bullet->SetDirection(sling->GetDirection());
		bullet->SetSpeed(sling->GetSpeed());
		bullet->SetFlying(true);

		return bullet;
	}

	return nullptr;
}