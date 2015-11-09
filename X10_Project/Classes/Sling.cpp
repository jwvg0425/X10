#include "stdafx.h"
#include "Sling.h"

Sling* Sling::instance = nullptr;
bool Sling::isExist = false;

Sling* Sling::GetInstance()
{
	if (instance == nullptr || isExist == false){
		instance = Sling::create();
		isExist = true;
	}
	return instance;
}


bool Sling::init()
{
	if (Node::init() == false)
	{
		return false;
	}
	//set Name
	setName("Sling");

	//set Empey status
	ChangeToEmpty();

	//set some frame work variable
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//set position low center position
	setPosition(Point(visibleSize.width/2, YPOS));
	
	//charater set
	auto body = Sprite::create("HelloWorld.png");
	body->setName("body");
	//scale adjustment
	Size bodySize = body->getContentSize();
	float bodyScale = MIN(WIDTH / bodySize.width, HEIGHT / bodySize.height);
	body->setScale(bodyScale);

	this->addChild(body);
	
	EventListenerMouse* _mouseListener = EventListenerMouse::create();
	_mouseListener->onMouseUp = CC_CALLBACK_1(Sling::Shot, this);
	_mouseListener->onMouseDown = CC_CALLBACK_1(Sling::PullStart, this);
	_mouseListener->onMouseMove = CC_CALLBACK_1(Sling::Pull, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);

	return true;
}


void Sling::Reset() // --> �Ž����������� ����. �Ű������� ����.
{
	ChangeToEmpty();
}
void Sling::NewBulletLoad()
{
	ChangeToLoaded();
}

void Sling::PullStart(Event* e)
{
	if (status != loaded)
	{
		return;
	}

	//
	/*�̰��� Pull mouse ��ġ ���� ���� �� �� ����.*/
	//
	ChangeToPulling();
}


void Sling::Pull(Event* e)
{
	if (status != pulling)
	{
		return;
	}
	EventMouse* evMouse = (EventMouse*)e;
	Point mouseLocation = evMouse->getLocationInView();
	Point startLocation = GetStartLocation();
	
	shotAngle = startLocation - mouseLocation;
	if (shotAngle.getAngle() < Vec2::ZERO.getAngle())
	{
		//������ ������ �Ѱ踦 �Ѿ�� �͵� �����ϴ� �κ�..
		//���� �ȸ���
	}

	shotPower = startLocation.getDistance(mouseLocation);
	if (shotPower > MAX_POWER)
	{	
		shotAngle = shotAngle / (shotPower / MAX_POWER);
		shotPower = MAX_POWER;
	}

	auto label = Label::create(".","arial", FONT_SIZE);
	auto delay = MoveBy::create(PREDICT_LINE_TIME, shotAngle);
	auto action = Sequence::create(delay, RemoveSelf::create(), NULL);
	this->addChild(label);
	label->runAction(action);
	
}

Point Sling::GetStartLocation()
{
	return getPosition();
}

void Sling::Shot(Event* e)
{
	if (status != pulling)
	{
		return;
	}
	//fix shot angle,power from last pointer position.
	Pull(e);

	ChangeToShotted();
}

bool Sling::IsShotted() // --> ������ üũ
{
	if (status == shotted)
	{
		return true;
	}
	else
	{
		return false;
	}	
}

Vec2 Sling::GetDirection()
{
	return shotAngle;
}

float Sling::GetAngleInRadian()
{
	return shotAngle.getAngle();
}

float Sling::GetSpeed()
{
	return shotPower;
}


void Sling::ChangeToLoaded() //empty -> load
{
	if (status != empty)
		return;
	status = loaded;
}
void Sling::ChangeToPulling() //loaded -> pulling
{
	if (status != loaded)
		return;
	status = pulling;
}
void Sling::ChangeToShotted() //pullig -> shotted
{
	if (status != pulling)
		return;
	status = shotted;
}
void Sling::ChangeToEmpty() //shotted -> empty
{
	status = empty;
}
