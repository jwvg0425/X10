#include "stdafx.h"
#include "TargetManager.h"
//Targets
#include "Enemy.h"
#include "Mirror.h"
#include "Mirror_y.h"
#include "Cloud.h"
#include "Bubble.h"
#include "Star.h"
#include "SeeBird.h"

//Stage Information
#include "StageInformation.h"
#include <hash_map>
#include <functional>
using namespace stdext;

void TargetManager::InitTargets(StageInformation* si)
{
	ResetTargets();

	m_defaultTargetNumber = si->GetTargetCount();
	m_targets.reserve(m_defaultTargetNumber);

	//������ Ŭ������ �´� �Լ������� �� void*���·� hash_map�� ����
	typedef hash_map<string,std::function<Target*()>>  TargetInfoMap;
	TargetInfoMap targetTypeInfo;
	targetTypeInfo.insert(TargetInfoMap::value_type("Enemy", Enemy::create));
	targetTypeInfo.insert(TargetInfoMap::value_type("Mirror", Mirror::create));
	targetTypeInfo.insert(TargetInfoMap::value_type("Mirror_y", Mirror_y::create));
	targetTypeInfo.insert(TargetInfoMap::value_type("Cloud", Cloud::create));
	targetTypeInfo.insert(TargetInfoMap::value_type("Bubble", Bubble::create));
	targetTypeInfo.insert(TargetInfoMap::value_type("Star", Star::create));
	targetTypeInfo.insert(TargetInfoMap::value_type("SeeBird", SeeBird::create));

	while (si->HasNextTarget())
	{
		//Ÿ�� �̸��� �ҷ��ͼ�
		string type = si->GetTargetType();
		auto createFunction = targetTypeInfo.at(type);	
		//�ű⿡ �´� ���丮 �Լ� ȣ��
		Target* target = createFunction();

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
