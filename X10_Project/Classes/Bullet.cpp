#include "stdafx.h"
#include "Bullet.h"

//Base Class of All Bullets

bool Bullet::init()
{
	if (!Node::init())
	{
		return false;
	}
	
	//setting initial value
	speed = 0;
	direction = Vec2::ZERO;
	timeDecrease = 1;

	isBullet = true;
	isFlying = false;
	isExplosing = false;

	//depending on the type of bullet
	lifeTime = Director::getInstance()->getFrameRate()*1.0;
	speedSetRatio = 0.3f;
	speedDecreaseRatio = 0.99f;

	MakeBody();

	addChild(body);
	return true;
}

Sprite* Bullet::MakeBody()
{
	body = Sprite::create();

	//�ִϸ��̼� ������ �߰�
	float scale = Director::getInstance()->getContentScaleFactor();
	const Size fireSize(BULLET_WIDTH / scale / BULLET_RATIO, BULLET_HEIGHT / scale / BULLET_RATIO); 
	int frameCut = BULLET_FRAMES;
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(frameCut);
	
	for (int i = 0; i < frameCut; i++)
	{
		///# res/firework.png���� ���ڿ��� ���� ���� �ѱ��� ��Ƴ�����
		SpriteFrame* frame = SpriteFrame::create("res/firework.png", Rect(Point(fireSize.width*i, 0), fireSize)); 
		animFrames.pushBack(frame);
	}
	
	// create the animation out of the frame
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animate = Animate::create(animation);
	RepeatForever *aniAction = RepeatForever::create(animate); //�׼��� ����
	body->runAction(aniAction); //��������Ʈ�� ����
	body->setScale(BULLET_RATIO);
	return body;
}

void Bullet::Act()
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
		isExplosing = true;
	}
}

//move bullet 'node', not its sprite
void Bullet::Move()
{
	Vec2 delta = speed * direction;
	Vec2 curPos = getPosition();
	setPosition(curPos + delta);
}

//add : as lifeTime gets near to zero, 1. speed decreases 2. color turns red
void Bullet::DecreaseLife()
{
	lifeTime -= timeDecrease;
}

Explosion* Bullet::GetExplosion()
{
	Explosion* explosion = Explosion::create();
	return explosion;
}
