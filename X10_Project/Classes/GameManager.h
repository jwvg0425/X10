#pragma once
#include "stdafx.h"
class GameLayer;
class UILayer;
class StageInformation;
class ColliderManager;
class TargetManager;
class Collider;
class Target;
class Sling;

class GameManager
{
public:
	static GameManager* GetInstance();
	static void Reset();
	void InitTargets(GameLayer* gameLayer);
	void Play(GameLayer* gameLayer, UILayer* uiLayer);
	void SetStageNumber(int StageNumber);

private:
	GameManager();
	~GameManager();
	void CheckCollide(Collider* bullet, Vector<Target*> targets);
	void SetStageInformation(const char* FILENAME, int StageNumber);
	//# ����� ���͸� ��°�� �ѱ��� ����.. const &�� �ѱ� ��..

private:
	int StageNumber;
	StageInformation* stage;
	static GameManager* instance;
	Sling* sling;
	ColliderManager* colliderManager;
	TargetManager* targetManager;
};
