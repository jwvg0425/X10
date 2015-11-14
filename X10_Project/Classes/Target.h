#pragma once

class Collider;
class Bullet;
class Explosion;

class Target : public Node
{
public:
	virtual bool init();
	void ApplyCollisionEffect(Collider* collider);// ��� Ÿ���� �� �Լ� ���� ó���� �����Ƿ� �״�� ���°�? ������ ���� ����.
	virtual const Rect& GetBoundingArea() = 0;

protected:
	Sprite* spr; //�ӽ÷� �ۺ����� �ű�

	virtual void ToBullet(Bullet* collider) = 0;
	virtual void ToExplosion(Explosion* explosion) = 0;
	virtual void ToSelf(Bullet* bullet) = 0;
	virtual void ToSelf(Explosion* explosion) = 0;

	const float TARGET_WIDTH = 5;
	const float TARGET_HEIGHT = 5;


};