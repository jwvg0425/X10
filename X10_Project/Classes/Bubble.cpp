#include "stdafx.h"
#include "Target.h"
#include "Bubble.h"

bool Bubble::init()
{
	spr = Sprite::create("res/targets/Mirror.png"); //example ///# ���� ���ͷ�

	return true;
}

void Bubble::ApplyEffectToBullet(Bullet* bullet)
{

}


