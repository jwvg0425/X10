#include "stdafx.h"
#include "Target.h"
#include "Collider.h"
#include "Explosion.h"
#include "Bullet.h"
#include "Cloud.h"

bool Cloud::init()
{
	spr = Sprite::create(FILE_CLOUD);
	addChild(spr);
	applyEffectToMe = true;

	return true;
}

void Cloud::ToBullet(Bullet* collider)
{

}

void Cloud::ToExplosion(Explosion* explosion)
{

}

//ToSelf�� ���� �����Ǿ�� �ϴ����� ���� �ǹ�
//�Ѿ˿� �µ���, ���߹��� �µ��� �ڱ����� ����Ǵ� ȿ���� ����
//���߿� ������ ���� �������� �𸣴ϱ� �ϴ� �����
void Cloud::ToSelf(const Bullet* bullet)
{
	if (applyEffectToMe)
	{
		applyEffectToMe = false;

		spr->setVisible(false); //�ӽ� �ڵ�, 
								//Ÿ�� �Ŵ����� ��� �ִ� targets���� �������ִ� �� �´µ�
								//�׷��� �Ϸ��� Ÿ�� �Ŵ����� �Ű������� �����ؾ���

		Sprite* spr_00 = Sprite::create(FILE_CLOUD_LEFT);
		Sprite* spr_01 = Sprite::create(FILE_CLOUD_RIGHT);
		addChild(spr_00);
		addChild(spr_01);

		spr_00->setPosition(Vec2(-20, 0));
		spr_01->setPosition(Vec2(20, 0));

		Sequence* action_00 = Sequence::create(
			MoveBy::create(1.0f, Vec2(-30, 0)),
			RemoveSelf::create(),
			NULL);
		Sequence* action_01 = Sequence::create(
			MoveBy::create(1.0f, Vec2(30, 0)),
			RemoveSelf::create(),
			NULL);

		spr_00->runAction(action_00);
		spr_01->runAction(action_01);

		spr_00->setScale(sprScaleRatio);
		spr_01->setScale(sprScaleRatio);
	}
}

void Cloud::ToSelf(const Explosion* explosion)
{
	if (applyEffectToMe)
	{
		applyEffectToMe = false;

		spr->setVisible(false); //�ӽ� �ڵ�, 
								//Ÿ�� �Ŵ����� ��� �ִ� targets���� �������ִ� �� �´µ�
								//�׷��� �Ϸ��� Ÿ�� �Ŵ����� �Ű������� �����ؾ���

		Sprite* spr_00 = Sprite::create(FILE_CLOUD_LEFT);
		Sprite* spr_01 = Sprite::create(FILE_CLOUD_RIGHT);
		addChild(spr_00);
		addChild(spr_01);

		spr_00->setPosition(Vec2(-20, 0));
		spr_01->setPosition(Vec2(20, 0));

		Sequence* action_00 = Sequence::create(
			MoveBy::create(1.0f, Vec2(-30, 0)),
			RemoveSelf::create(),
			NULL);
		Sequence* action_01 = Sequence::create(
			MoveBy::create(1.0f, Vec2(30, 0)),
			RemoveSelf::create(),
			NULL);

		spr_00->runAction(action_00);
		spr_01->runAction(action_01);

		spr_00->setScale(sprScaleRatio);
		spr_01->setScale(sprScaleRatio);
	}
}

