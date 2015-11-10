#pragma once

#include "Collider.h"
#include "Explosion.h"

class Bullet : public Collider
{
public:
	///# ���߿� ���� init�� �θ����� �⺻ �����ڿ��� ��� �ʱ�ȭ�� �ݵ�� �ϵ���. 
	///# ���߿� �ʱ�ȭ�� �Ǳ� ���� �׾����� �װ� Ȯ���� ���� ���� ����.

	CREATE_FUNC(Bullet);

	virtual bool init() override;
	virtual void Act() override;
	virtual void Move();
	virtual Explosion* GetExplosion();

	//Setters and Getters
	void SetDirection(Vec2 dir) { direction = dir; }
	void SetSpeed(float spd) { speed = spd * speedSetRatio; }
	void SetSpeedDecreaseRatio(float ratio) { speedDecreaseRatio = ratio; }
	void SetFlying(bool flag) { isFlying = flag; }
	void SetExplosing(bool flag) { isExplosing = flag; }
	bool IsBullet() { return true; }
	bool IsFlying() { return isFlying; }
	bool IsExplosing() { return isExplosing; }

protected:
	void DecreaseLife(); // call in Move()
	Sprite* MakeBody();

	Vec2 direction;
	float speed;
	
	float lifeTime;
	float timeDecrease;
	float speedSetRatio;
	float speedDecreaseRatio;

	bool isExplosing;

	enum
	{
		BULLET_FRAMES = 5,
		BULLET_WIDTH = 20,
		BULLET_HEIGHT = 20,
		BULLET_RATIO = 2,

		BULLET_LIFETIME = 30,
		BULLET_EXPLODETIME = 0,
		BULLET_REDUCTIONSPEEDTIME = 15,
	};
};