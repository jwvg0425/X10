#include "stdafx.h"
#include "TargetManager.h"
#include "StageInformation.h"

#include "Mirror.h"
#include "Cloud.h"
#include "Bubble.h"
#include "Enemy.h"
#include "Bubble.h"

#include <hash_map>
using namespace stdext;

TargetManager::TargetManager()
{
	currentTargetIdx = -1;
	defaultTargetNumber = -1;
}

TargetManager::~TargetManager()
{
	targets.clear();
}

void TargetManager::InitTargets(StageInformation* si)
{
<<<<<<< HEAD
	targets.pushBack(Mirror::create());
	targets.pushBack(Enemy::create());
	targets.pushBack(Cloud::create());
	targets.pushBack(Bubble::create());

	//���߿� ----> si������ ��ġ���� ���⼭
=======
	defaultTargetNumber = si->GetTargetCount();
	targets.reserve(defaultTargetNumber);

	//������ Ŭ������ �´� �Լ������� �� void*���·� hash_map�� ����
	hash_map<string, void*> targetTypeInfo; //string�� Ÿ�� �̸�.
	targetTypeInfo.insert(hash_map<string, void*>::value_type("Enemy", Enemy::create));
	targetTypeInfo.insert(hash_map<string, void*>::value_type("Mirror", Mirror::create));
	targetTypeInfo.insert(hash_map<string, void*>::value_type("Cloud", Cloud::create));
	targetTypeInfo.insert(hash_map<string, void*>::value_type("Bubble", Bubble::create));

	while (si->HasNextTarget())
	{
		//Ÿ�� �̸��� �ҷ��ͼ�
		string type = si->GetTargetType();
		void* createFunction = targetTypeInfo.at(type);	
		//�ű⿡ �´� ���丮 �Լ� ȣ��
		Target* (*create)() = static_cast<Target* (*)()>(createFunction);
		Target* target = (*create)();

		//��ġ, ���� ���� ����
		target->setPosition(si->GetTargetPosition());
		target->setRotation(si->GetTargetRotation());
		target->setScale(si->GetTargetScale());
		
		//����Ʈ�� ����.
		targets.pushBack(target);
	}
>>>>>>> a4f768468edb0674a486148eebec9441eb654651
}

void TargetManager::EraseTarget(Target* target)
{
	targets.eraseObject(target);
}
