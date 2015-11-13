#pragma once

class Collider;
class Bullet;
class Explosion;

class Target : public Node
{
public:
	CREATE_FUNC(Target);
	virtual bool init();
	virtual void ApplyCollisionEffect(Collider* collider);
	const Rect& GetBoundingBox() { return spr->getBoundingBox(); }


protected:
	Sprite* spr; //�ӽ÷� �ۺ����� �ű�

	virtual void ToBullet(Bullet* collider);
	virtual void ToExplosion(Explosion* explosion);
	virtual void ToSelf(Bullet* bullet);
	virtual void ToSelf(Explosion* explosion);


};