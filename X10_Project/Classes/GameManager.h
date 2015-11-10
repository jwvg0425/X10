#pragma once
#include "stdafx.h"
class GameLayer;
class UILayer;
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

private:
	void CheckCollide(Collider* bullet, Vector<Target*> targets);
	//# ����� ���͸� ��°�� �ѱ��� ����.. const &�� �ѱ� ��..
	static GameManager* instance;
	Sling* sling;
	ColliderManager* colliderManager;
	TargetManager* targetManager;
	GameManager();
	~GameManager();
};
