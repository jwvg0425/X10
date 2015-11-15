#include "stdafx.h"
#include "TargetManager.h"
#include "StageInformation.h"

#include "Mirror.h"
#include "Cloud.h"
#include "Bubble.h"
#include "Enemy.h"

TargetManager::TargetManager()
{
	currentTargetIdx = 0;
	defaultTargetNumber = 3;
	targets.reserve(defaultTargetNumber);
}
TargetManager::~TargetManager()
{
	targets.clear();
}

void TargetManager::InitTargets(StageInformation* si)
{
	targets.pushBack(Mirror::create());
	targets.pushBack(Enemy::create());
	targets.pushBack(Cloud::create());
	targets.pushBack(Bubble::create());

	//���߿� ----> si������ ��ġ���� ���⼭
}

void TargetManager::EraseTarget(Target* target)
{
	targets.eraseObject(target);
}
