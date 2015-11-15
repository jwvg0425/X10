#pragma once

class Collider;
class Bullet;
class Explosion;

class Target : public Node
{
public:
	virtual bool init();
	void ApplyCollisionEffect(Collider* collider); //������ ���� �ȿ� �θ��� To~~~�鸸 �����ϸ� �ǵ��� 
	const Rect& GetBoundingArea() { return Rect(getPosition(), spr->getContentSize()); }

protected:
	Sprite* spr;

	virtual void ToBullet(Bullet* collider) = 0;
	virtual void ToExplosion(Explosion* explosion) = 0;
	virtual void ToSelf(const Bullet* bullet) = 0;
	virtual void ToSelf(const Explosion* explosion) = 0;

	const float TARGET_WIDTH = 5;
	const float TARGET_HEIGHT = 5;
};