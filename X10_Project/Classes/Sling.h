#ifndef __SLING_H__
#define __SLING_H__

#include "Bullet.h"

class Sling : public Node
{
public:
	static Sling* createSling();
	CREATE_FUNC(Sling);
	virtual bool init();

	void onMouseDown(cocos2d::Event* event);
	void onMouseUp(cocos2d::Event* event);
	void onMouseMove(cocos2d::Event* event);
	
	bool IsShooted() { return isShooted; }
	bool isShooted; ///# �ۺ����� �����Ÿ� ���� ���� �����ڸ� ���� �ʿ� �ֳ�? private�� �ű�� ��� ���� ǥ�ø� �ϴ� ���� ������.

	bool IsPressed() { return isPressed; }
	bool isPressed;

	Point posStartClick;
	
	Sprite* Stick; ///# �ڵ� ������ �� �⺻�� �ʱ�ȭ ��.
	Sprite* Shooter;

	Point angle;
	float power;

	enum { ShooterUIBoundaryHeight = 200,  ///# �ڵ� ������: �߰�ȣ �����
		ShooterUIBoundaryLeft = 0, 
		ShooterUIBoundaryRight = 400 };
};

#endif