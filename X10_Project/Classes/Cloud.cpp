#include "stdafx.h"
#include "Target.h"
#include "Collider.h"
#include "Explosion.h"
#include "Bullet.h"
#include "Cloud.h"

bool Cloud::init()
{
	m_spr = Sprite::create(FILE_CLOUD);
	addChild(m_spr);
	m_applyEffectToMe = true;
	return true;
}

void Cloud::ToBullet(Bullet* bullet)
{

}

void Cloud::ToSelf(const Bullet* bullet)
{
	if (m_applyEffectToMe)
	{
		m_applyEffectToMe = false;

		m_spr->setVisible(false); 

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

		Sequence* action_02 = Sequence::create(
			DelayTime::create(1.25f),
		//	RemoveSelf::create(),
			NULL);

		spr_00->setScale(m_sprScaleRatio);
		spr_01->setScale(m_sprScaleRatio);

		spr_00->runAction(action_00);
		spr_01->runAction(action_01);
	//	m_spr->runAction(action_02);
	}
}

void Cloud::ToSelf(const Explosion* explosion)
{
	if (m_applyEffectToMe)
	{
		m_applyEffectToMe = false;

		m_spr->setVisible(false);

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

		Sequence* action_02 = Sequence::create(
			DelayTime::create(1.25f),
		//	RemoveSelf::create(),
			NULL);

		spr_00->setScale(m_sprScaleRatio);
		spr_01->setScale(m_sprScaleRatio);

		spr_00->runAction(action_00);
		spr_01->runAction(action_01);
	//	m_spr->runAction(action_02);
	}
}

