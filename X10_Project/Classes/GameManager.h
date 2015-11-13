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

	void Play(GameLayer* gameLayer, UILayer* uiLayer);
	
	void SetTargets(GameLayer* gameLayer);
	void SetStage(int StageNumber);


private:
	GameManager();
	~GameManager();
	void CheckCollide(Collider* bullet, Vector<Target*> targets);
	//# ����� ���͸� ��°�� �ѱ��� ����.. const &�� �ѱ� ��..

private:
	static GameManager* instance;
	StageInformation* stage;
	ColliderManager* colliderManager;
	TargetManager* targetManager;
	Sling* sling;
};
