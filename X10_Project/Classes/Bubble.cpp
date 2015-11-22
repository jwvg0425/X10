#include "stdafx.h"
#include "Target.h"
#include "Bubble.h"

bool Bubble::init()
{
	m_spr = Sprite::create(FILE_BUBBLE);
	addChild(m_spr);
	m_applyEffectToMe = true;

	return true;
}

void Bubble::ToBullet(Bullet* bullet)
{

}

void Bubble::ToSelf(const Bullet* bullet)
{
	if (m_applyEffectToMe)
	{
		m_applyEffectToMe = false;

		m_spr->removeFromParent();
		m_spr = Sprite::create(FILE_BUBBLE_POP);
		m_spr->setScale(m_sprScaleRatio);
		addChild(m_spr);

		Sequence* action = Sequence::create(
			DelayTime::create(0.5f),
		//	RemoveSelf::create(),
			NULL);

		m_spr->runAction(action);
	}
}

void Bubble::ToSelf(const Explosion* explosion)
{
	ToSelf(static_cast<Bullet*>(NULL));
}