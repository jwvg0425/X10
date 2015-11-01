#include "stdafx.h"
#include "Explosion.h"

Explosion* Explosion::createExplosion(int dmg)
{
	auto Explosion = Explosion::create();
	auto body = Sprite::create("res/explosion.png");
	body->setName("ExplosionBody");
	Explosion->addChild(body);

	return Explosion;
}

bool Explosion::init()
{
	if (Node::init() == false)
		return false;


	return true;
}

void Explosion::boom(const float dTime)
{
	auto body = this->getChildByName("ExplosionBody");
	if (body != nullptr && body->getScale() * body->getContentSize().width < 100)
	{
		makeBigger(body);
	}
	else
	{
		this->removeFromParent();
	}
	return;
}

void Explosion::makeBigger(Node* spr)
{
	spr->setScale(spr->getScale()+0.1);
}