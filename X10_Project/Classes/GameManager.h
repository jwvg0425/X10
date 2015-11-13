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
	//# 복사로 벡터를 통째로 넘기지 마라.. const &로 넘길 것..

private:
	static GameManager* instance;
	StageInformation* stage;
	ColliderManager* colliderManager;
	TargetManager* targetManager;
	Sling* sling;
};
