#include "stdafx.h"
#include "Target.h"
#include "Bubble.h"

//��� ����: ����￡ ���� ���� 
//�����ַ��� ��Ʈ�ȴ���...... ��
bool Bubble::init()
{
	spr = Sprite::create(FILE_BUBBLE);
	addChild(spr);
	applyEffectToMe = true;

	return true;
}

void Bubble::ToBullet(Bullet* collider)
{

}

void Bubble::ToExplosion(Explosion* explosion)
{

}

//ToSelf�� ���� �����Ǿ�� �ϴ����� ���� �ǹ�
//�Ѿ˿� �µ���, ���߹��� �µ��� �ڱ����� ����Ǵ� ȿ���� ����
//���߿� ������ ���� �������� �𸣴ϱ� �ϴ� �����
void Bubble::ToSelf(const Bullet* bullet)
{
	if (applyEffectToMe)
	{
		applyEffectToMe = false;

		spr->setVisible(false); //�ӽ� �ڵ�, 
								//Ÿ�� �Ŵ����� ��� �ִ� targets���� �������ִ� �� �´µ�
								//�׷��� �Ϸ��� Ÿ�� �Ŵ����� �Ű������� �����ؾ���

		Sprite* spr_00 = Sprite::create(FILE_BUBBLE_POP);
		spr_00->setScale(sprScaleRatio);
		addChild(spr_00);
		Sequence* action = Sequence::create(
			DelayTime::create(0.5f),
			RemoveSelf::create(),
			NULL);
		spr_00->runAction(action);
	}
}

void Bubble::ToSelf(const Explosion* explosion)
{
	if (applyEffectToMe)
	{
		applyEffectToMe = false;

		spr->setVisible(false); //�ӽ� �ڵ�, 
								//Ÿ�� �Ŵ����� ��� �ִ� targets���� �������ִ� �� �´µ�
								//�׷��� �Ϸ��� Ÿ�� �Ŵ����� �Ű������� �����ؾ���

		Sprite* spr_00 = Sprite::create(FILE_BUBBLE_POP);
		spr_00->setScale(sprScaleRatio);
		addChild(spr_00);
		Sequence* action = Sequence::create(
			DelayTime::create(0.5f),
			RemoveSelf::create(),
			NULL);
		spr_00->runAction(action);
	}
}

