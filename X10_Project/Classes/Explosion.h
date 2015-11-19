#pragma once

#include "Collider.h"
class ColliderManager;

class Explosion : public Collider
{
public:
	CREATE_FUNC(Explosion);
	virtual bool init();
	virtual void Act(ColliderManager* cm);
	virtual const float& GetBoundingRadius();

	void SetFlying(bool flag);
	bool IsBullet() { return false; }
	void SetPosition(Point pos);

protected:
	ParticleExplosion* m_explosion; ///# �ڵ� ������
	float m_lifeTime;
	float m_radius;
	float m_maxRadius;
};