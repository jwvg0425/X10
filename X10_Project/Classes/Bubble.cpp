#include "stdafx.h"
#include "Target.h"
#include "Bubble.h"

//��� ����: ����￡ ���� ���� 
//�����ַ��� ��Ʈ�ȴ���...... �� //�� �̳�����
bool Bubble::init()
{
	m_spr = Sprite::create(FILE_BUBBLE);
	addChild(m_spr);
	m_applyEffectToMe = true;

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
	if (m_applyEffectToMe)
	{
		m_applyEffectToMe = false;

		m_spr->setVisible(false); //�ӽ� �ڵ�, 
								//Ÿ�� �Ŵ����� ��� �ִ� targets���� �������ִ� �� �´µ�
								//�׷��� �Ϸ��� Ÿ�� �Ŵ����� �Ű������� �����ؾ���

		Sprite* spr_00 = Sprite::create(FILE_BUBBLE_POP);
		spr_00->setScale(m_sprScaleRatio);
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
	if (m_applyEffectToMe)
	{
		m_applyEffectToMe = false;

		m_spr->setVisible(false); //�ӽ� �ڵ�, 
								//Ÿ�� �Ŵ����� ��� �ִ� targets���� �������ִ� �� �´µ�
								//�׷��� �Ϸ��� Ÿ�� �Ŵ����� �Ű������� �����ؾ���

		Sprite* spr_00 = Sprite::create(FILE_BUBBLE_POP);
		spr_00->setScale(m_sprScaleRatio);
		addChild(spr_00);
		Sequence* action = Sequence::create(
			DelayTime::create(0.5f),
			RemoveSelf::create(),
			NULL);
		spr_00->runAction(action);
	}
}