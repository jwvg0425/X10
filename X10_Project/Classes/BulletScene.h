#pragma once
#include "Bullet.h"
class BulletScene : public Layer
{
public:

	static Scene* createScene();
	virtual bool init();


	void update(float dt);
	Target* CheckHit();
	void HitOperator(Target* target);
	CREATE_FUNC(BulletScene);

private:
	Bullet* bullet;
	vector<Target*> targetList;

};
