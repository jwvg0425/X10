#pragma once

class Collider;
class Bullet;
class Explosion;

class Target : public Node
{
public:
	virtual bool init();

	void ApplyCollisionEffect(Collider* collider); //������ ���� �ȿ� �θ��� To~~~�鸸 �����ϸ� �ǵ��� 
	const Rect& GetBoundingArea();
	void SetSprScaleRatio(float ratio) { m_sprScaleRatio = ratio; }
	void SetSprScale() { m_spr->setScale(m_sprScaleRatio); }
protected:
	virtual void ToBullet(Bullet* collider) = 0;
	virtual void ToExplosion(Explosion* explosion) = 0;
	virtual void ToSelf(const Bullet* bullet) = 0;
	virtual void ToSelf(const Explosion* explosion) = 0;	
	
	Sprite* m_spr;
	float m_sprScaleRatio = 1; ///# ����Ʈ�� �ʱ�ȭ�� ��Ƽ�.. �����ڿ��� �ϰų� ��� ����� �ϰų�.. ���ϵǰ�..
	///# �ڵ� ������ m_��or��? 
	bool m_ApplyEffectToMe;
	bool m_ApplyEffectToBullet;

};