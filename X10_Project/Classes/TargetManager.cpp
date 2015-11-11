#include "stdafx.h"
#include "TargetManager.h"
#include "StageInformation.h"

TargetManager* TargetManager::instance = nullptr;

TargetManager* TargetManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new TargetManager();
	}
	return instance;
}

TargetManager::TargetManager()
{
	targets.reserve(5);
}

void TargetManager::InitTargets(StageInformation* stage)
{
	//���⿡ ���� Ÿ�� ������ �����ϼ���~
}

TargetManager::~TargetManager() {}

