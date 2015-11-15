#include "stdafx.h"
#include "Target.h"
#include "Collider.h"
#include "Explosion.h"
#include "Bullet.h"

#include "Mirror.h"

bool Mirror::init()
{
	spr = Sprite::create(FILE_MIRROR);
	addChild(spr);

	//테스트용 코드
	spr->setScale(3.0f);
	setPosition(30, 200);
	return true;
}

void Mirror::ToBullet(Bullet* bullet)
{
	Vec2 curDir = bullet->GetDirection();
	Vec2 reflect = Vec2(curDir.x * -1, curDir.y);
	bullet->SetDirection(reflect);
}

void Mirror::ToExplosion(Explosion* explosion)
{

}

void Mirror::ToSelf(const Bullet* bullet)
{
	spr->removeFromParent();
	spr = Sprite::create(FILE_MIRROR_ANGRY);
	addChild(spr);
	spr->setScale(spr->getScale()+0.5);
}

void Mirror::ToSelf(const Explosion* explosion)
{

}
