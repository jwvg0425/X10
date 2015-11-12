#pragma once

#include "Collider.h"
#include "Explosion.h"

class ColliderManager;

class Bullet : public Collider
{
public:
	///# ���߿� ���� init�� �θ����� �⺻ �����ڿ��� ��� �ʱ�ȭ�� �ݵ�� �ϵ���. 
	///# ���߿� �ʱ�ȭ�� �Ǳ� ���� �׾����� �װ� Ȯ���� ���� ���� ����.

	CREATE_FUNC(Bullet);

	virtual bool init() override;
	virtual void Act(ColliderManager* cm) override;
	virtual void Move();
	virtual Explosion* GetExplosion();

	//Setters and Getters
	void SetDirection(Vec2 dir) { direction = dir; }
	void SetSpeed(float spd) { speed = spd * speedSetRatio; }
	void SetSpeedDecreaseRatio(float ratio) { speedDecreaseRatio = ratio; }
	void SetFlying(bool flag) { isFlying = flag; }
	bool IsBullet() { return true; }
	bool IsFlying() { return isFlying; }
	bool ShouldExplode() { return shouldExplode; }

	//Status 
	void Crashed();
	void Exploded();
	void TimeUp();

	void ReduceSpeed();

protected:
	void DecreaseLife(); // call in Move()
	Sprite* MakeBody();
	
protected:
	Sprite* body;

	Vec2 direction;
	float speed;
	
	float lifeTime;
	float timeDecrease;
	float speedSetRatio;
	float speedDecreaseRatio;

	bool shouldExplode;

	const char* FILE_NAME= "res/firework.png";
	enum
	{
		BULLET_FRAMES = 5,
		BULLET_WIDTH = 10,
		BULLET_HEIGHT = 10,
		BULLET_RATIO = 2,

		BULLET_LIFETIME = 30,
		BULLET_EXPLODETIME = 0,
		BULLET_REDUCTIONSPEEDTIME = 15,
	};
};