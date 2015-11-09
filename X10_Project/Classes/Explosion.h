#pragma once

#include "Collider.h"

class Explosion : public Collider
{
public:
	CREATE_FUNC(Explosion);
	virtual bool init();
	virtual void Act();
	virtual bool IsFlying();
	virtual void SetFlying(bool flag);

protected:
	ParticleExplosion* particle;
	bool isFlying;
};