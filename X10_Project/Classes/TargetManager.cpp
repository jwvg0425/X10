#include "stdafx.h"
#include "TargetManager.h"
//Targets
#include "Enemy.h"
#include "Mirror.h"
#include "Cloud.h"
#include "Bubble.h"
#include "Star.h"
//Stage Information
#include "StageInformation.h"
#include <hash_map>
using namespace stdext;

void TargetManager::InitTargets(StageInformation* si)
{
	ResetTargets();

	m_defaultTargetNumber = si->GetTargetCount();
	m_targets.reserve(m_defaultTargetNumber);

	//������ Ŭ������ �´� �Լ������� �� void*���·� hash_map�� ����

	///# �̷��� typedef�����ŷ� ġȯ�س����� ���ϴ�
	///# �ٵ� void* ��������.. �Լ� ������ ���Ÿ� std::funcktion!!
	typedef hash_map<string, void*> TargetInfoMap;

	TargetInfoMap targetTypeInfo; //string�� Ÿ�� �̸�.
	targetTypeInfo.insert(TargetInfoMap::value_type("Enemy", Enemy::create));
	targetTypeInfo.insert(TargetInfoMap::value_type("Mirror", Mirror::create));
	targetTypeInfo.insert(TargetInfoMap::value_type("Cloud", Cloud::create));
	targetTypeInfo.insert(TargetInfoMap::value_type("Bubble", Bubble::create));
	targetTypeInfo.insert(TargetInfoMap::value_type("Star", Star::create));

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
		m_targets.pushBack(target);
	}
}

void TargetManager::ResetTargets()
{
	for (Target* target : m_targets)
	{
		delete target;
	}
	m_targets.clear();
}

void TargetManager::EraseTarget(Target* target)
{
	m_targets.eraseObject(target);
}
