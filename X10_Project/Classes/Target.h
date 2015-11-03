#pragma once
class Bullet;

//if you want to make targets like enemy or some obstacles,  you should extend Target
class Target : public Layer
{
public:
	virtual void SetEffect(Bullet& bullet) = 0;

	virtual bool init() = 0;

	void setPosition(const Vec2 &position) override { mySprite->setPosition(position); } ///# �ζ��� �Լ��� �ƴ� ȣ���� �ִٸ� ������ cpp�� �ű�� �ٶ�

	const Vec2& getPosition() const override { return mySprite->getPosition(); }

	void setAnchorPoint(const Vec2& anchorPoint) override { mySprite->setAnchorPoint(anchorPoint); }

	Rect getBoundingBox() const override { return mySprite->getBoundingBox(); } ///# ���������� �����η�..

protected:
	Sprite* mySprite;
};

