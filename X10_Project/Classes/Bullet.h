#pragma once

#include "Collider.h"
#include "Explosion.h"

class Bullet : public Collider
{
public:
	///# 나중에 따로 init을 부르더라도 기본 생성자에서 멤버 초기화는 반드시 하도록. 
	///# 나중에 초기화가 되기 전에 죽었을때 그걸 확인할 길이 없기 때문.

	CREATE_FUNC(Bullet);

	virtual bool init() override;
	virtual void Act() override;
	virtual void Move();
	virtual Explosion* GetExplosion();

	//Setters and Getters
	void SetDirection(Vec2 dir) { direction = dir; }
	void SetSpeed(float spd) { speed = spd * speedSetRatio; }
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
		BULLET_RATIO = 2
	};
};