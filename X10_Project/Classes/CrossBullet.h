#pragma once

#include "Bullet.h"

class CrossBullet : public Bullet
{
public:
	CREATE_FUNC(CrossBullet);
	bool init();
	void Act();
	Explosion* GetExplosion();

private:
	int m_pattern;

	enum PATTERN
	{
		MOVE,
		CENTER, 
		CROSS_LEFT,
		CROSS_RIGHT,
		CROSS_UP,
		CROSS_DOWN,
		DIE,
	};
	
	
	float tmp_BULLET_REDUCTIONSPEEDTIME; //�ӽ÷� 
	const float DELTA_POS = 17.5f;
	const float DELTA_TIME = 0.5f;
};