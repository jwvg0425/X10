#include "stdafx.h"
#include "Enemy.h"
#include "Bullet.h"

bool Enemy::init()
{
	m_spr = Sprite::create(FILE_ENEMY);
	addChild(m_spr);

	return true;
}

void Enemy::ToBullet(Bullet* bullet)
{
	bullet->Crashed(); 
	bullet->removeFromParent();
}

void Enemy::ToExplosion(Explosion* explosion)
{

}

///# �Ʒ� �� ToSelf�� ��ǻ� ������ �ƴѰ�? Bullet�� Explosion��� Collider�� �ڽ��̸� ToSelf(const Collider* bullet) �ϳ��� �־ ����?
void Enemy::ToSelf(const Bullet* bullet)
{
	m_spr->removeFromParent();
	m_spr = Sprite::create(FILE_ENEMY_DEAD);
	addChild(m_spr);
	m_spr->setScale(0.03f);
	this->removeFromParent();
}

void Enemy::ToSelf(const Explosion* explosion)
{
	m_spr->removeFromParent();
	m_spr = Sprite::create(FILE_ENEMY_DEAD);
	addChild(m_spr);
	m_spr->setScale(0.03f);
	this->removeFromParent();
}
