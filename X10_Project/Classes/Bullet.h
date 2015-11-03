#ifndef __BULLET_H__
#define __BULLET_H__
class Target;

class Bullet : public Layer
{
public:

	virtual bool init();

	void Move(Vec2 initialDirection);
	//Sprite* GetInstance();

	int GetSpeed(){ return speed; }
	void SetSpeed(float _speed){ speed = _speed; }
	void SetDirection(Vec2 _direction){ direction = _direction; }
	Vec2 GetDirection() { return direction; }
	CREATE_FUNC(Bullet);
	void SetAlive(bool _alive) { alive = _alive; }
	bool IsAlive(){ return alive; }
	void HitProgress(Target& target );
	void Start(Vec2 direction, float power);
	void setPosition(const Vec2 &position) override { bullet->setPosition(position); }

	const Vec2& getPosition() const override {	return bullet->getPosition(); }

	void setAnchorPoint(const Vec2& anchorPoint) override {	bullet->setAnchorPoint(anchorPoint);}

	Rect getBoundingBox() const override { return bullet->getBoundingBox(); }

	void boom(Scene* scene, Point p);
private:

	Sprite* bullet; ///# �ڵ� ������: ��� ������ �տ� m_������ ���̵���..
	Vec2 direction;
	int speed;
	const double duration = 1 / Director::getInstance()->getFrameRate();; ///# ���� �Լ�ȣ���ϴ� �̷��Ŵ� ������ �Ǵ� init���� ��������� ���ֱ� �ٶ�.
	bool alive;
};

#endif