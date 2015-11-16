#include "stdafx.h"
#include "TargetManager.h"
//Targets
#include "Enemy.h"
#include "Mirror.h"
#include "Cloud.h"
#include "Bubble.h"
//Stage Information
#include "StageInformation.h"
#include <hash_map>
using namespace stdext;

void TargetManager::InitTargets(StageInformation* si)
{
	ResetTargets();

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
		target->SetSprScaleRatio(si->GetTargetScale());
		target->SetSprScale(); //sprScaleRatio ���� ���� �������� ������

		//����Ʈ�� ����.
		targets.pushBack(target);
	}
}

void TargetManager::ResetTargets()
{
	for (Target* target : targets)
	{
		delete target;
	}
	targets.clear();
}

void TargetManager::EraseTarget(Target* target)
{
	targets.eraseObject(target);
}
