#pragma once

#include "Collider.h"

class Explosion : public Collider
{
public:
	///# �⺻ �����ڿ��� ��� �ʱ�ȭ �� ��

	CREATE_FUNC(Explosion);
	virtual bool init();
	virtual void Act();
	virtual bool IsFlying();
	virtual void SetFlying(bool flag);
	bool IsBullet() override;
	void SetPosition(Vec2 position);

protected:
	ParticleExplosion* particle; ///# �ڵ� ������
	int lifeTime;
};