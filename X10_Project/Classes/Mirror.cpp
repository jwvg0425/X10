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
	return true;
}

//ȿ���� �ѹ��� ����Ǵ°� �ƴ϶� ��� ����� 
//�ѹ��� ������ �ٲ��ִ°� �ƴ϶� �迡�� ������ �ٲ��ְԵ�
//�׷��� �����ϴ� �Ѿ��� �����...
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
	//ȿ���� �ѹ��� ����Ǵ°� �ƴ϶� �迡���� ����� 
	//-> �����ذ� �ʿ� (����� Ŭ���忡���� �ذ�, �ѹ� �浹���� �� ��Ʈ���� �Ǵϱ�)

	spr->removeFromParent();
	spr = Sprite::create(FILE_MIRROR_ANGRY);
	addChild(spr);
	sprScaleRatio *= 1.01f; //1.01�谡 �浹�� �ִ� ���� �迡�������� �����
	spr->setScale(sprScaleRatio);
}

void Mirror::ToSelf(const Explosion* explosion)
{

}
