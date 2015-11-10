#include "stdafx.h"
#include "Bullet.h"
#include "MoonBullet.h"
#include "MoonExplosion.h"

bool MoonBullet::init()
{
	if (!Node::init())
	{
		return false;
	}

	//temporary initialization for test
	speed = 0;
	direction = Vec2::ZERO;
	timeDecrease = 1;
	//status
	isFlying = false;

	//depending on the type of MoonBullet
	lifeTime = Director::getInstance()->getFrameRate()*1.0;
	speedSetRatio = 0.3f;
	speedDecreaseRatio = 0.99f;

	return true;
}

void MoonBullet::Act()
{
	if (lifeTime > 0)
	{
		Move();
		DecreaseLife();

		if (lifeTime < 15)
		{
			SetSpeed(speed * speedDecreaseRatio);
			speedDecreaseRatio -= 0.06f;
		}
	}
	else
	{
		removeFromParent();
		isFlying = false;
	}
}

void MoonBullet::Move()
{
	Vec2 delta = speed * direction;
	Vec2 curPos = this->getPosition();
	setPosition(curPos + delta);
}

///# �Լ� �ȿ��� �ڿ��� ������ ������ �� �����͸� ������ �Ѱ��ִ� �������� ������... �ڿ������ϱ� ���� �����..
Explosion* MoonBullet::GetExplosion() 
{
	return MoonExplosion::create();
}
