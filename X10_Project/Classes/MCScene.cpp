#include "stdafx.h"
#include "MainScene.h"
#include "MCScene.h"
#include "Explosion.h"
#include "Enemy.h"
#include "Sling.h"
#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <json/json.h>

Scene* MCScene::createScene()
{
	auto scene = Scene::create();

	auto layer = MCScene::create();
	
	scene->addChild(layer);

	return scene;
}

bool MCScene::init()
{
	if (!CCLayerColor::initWithColor(Color4B(0, 0, 0, 255)))
	{
		return false;
	}

	//background color change
	this->schedule(schedule_selector(MCScene::ChangeBackGroundColor), BG_CHANGE_INTERVAL);
	
	//Sexy girl picture of background
	//Two wall papers are scrolling infinetely
	auto dir = Director::getInstance();
	auto screen = dir->getVisibleSize();

	//fist girl
	auto backgroundGirl0 = Sprite::create("res/mc.jpg");
	backgroundGirl0->setAnchorPoint(Point::ZERO);
	backgroundGirl0->setPosition(Point::ZERO);
	int width = backgroundGirl0->getContentSize().width;
	int height = backgroundGirl0->getContentSize().height;
	float scrollVelocity = 100;
	float scaleRatio = screen.height / height;
	int opacityFactor = 128;
	
	//second girl
	auto backgroundGirl1 = Sprite::create("res/mc.jpg");
	backgroundGirl1->setAnchorPoint(Point::ZERO);
	backgroundGirl1->setPosition(Point(width, 0));

	auto moveRight = MoveTo::create(screen.width / scrollVelocity , Point(-width * scaleRatio, 0));
	auto moveBack = MoveTo::create(0, Point::ZERO);
	auto scrollBG = RepeatForever::create(Sequence::create(moveRight, moveBack, NULL));
	backgroundGirl0->runAction(scrollBG);

	//show both color and girl by being transeparenting of girls. 
	backgroundGirl0->addChild(backgroundGirl1);
	backgroundGirl0->setOpacity(opacityFactor);
	backgroundGirl1->setOpacity(opacityFactor);
	backgroundGirl0->setScale(scaleRatio);
	this->addChild(backgroundGirl0);
	
	// go back to main scene
	auto GotoMainScene = MenuItemFont::create("Go to MainScene", CC_CALLBACK_1(MCScene::ChangeToMainScene, this));
	auto GotoMainSceneMenu = Menu::create(GotoMainScene, NULL);
	GotoMainSceneMenu->setPosition(200, 300);
	this->addChild(GotoMainSceneMenu);

	//text : JUMP!!!
	auto taewooMission1 = Label::createWithTTF("JUMP!!!", "fonts/arial.ttf", 50);
	taewooMission1->setPosition(Point(200, 150));
	taewooMission1->setName("twMissionLabel");
	taewooMission1->setVisible(false);
	this->addChild(taewooMission1);

	//running boy.
	auto jinwookMission = Sprite::create("boy 31x40.png");
	auto boysize = jinwookMission->getContentSize();
	jinwookMission->setPosition(0 + boysize.width / 2, 0 + boysize.height / 2);
	jinwookMission->setName("boy");
	this->addChild(jinwookMission);

	auto moveToRL = MoveBy::create(1, Point(screen.width - boysize.width, 0));
	auto moveToRU = MoveBy::create(1, Point(0 , screen.height - boysize.height));
	auto moveToLU = MoveBy::create(1, Point( -screen.width + boysize.width, 0));
	auto moveToLL = MoveBy::create(1, Point(0, -screen.height + boysize.height));

	auto moveArround = Sequence::create(moveToRL, moveToRU, moveToLU, moveToLL, NULL);
	auto repeat_action = RepeatForever::create(moveArround);
	jinwookMission->runAction(repeat_action);

	//mouse event . running man jump!
	auto _mouseListener = EventListenerMouse::create();
	_mouseListener->onMouseUp = CC_CALLBACK_1(MCScene::onMouseUp, this);
	_mouseListener->onMouseDown = CC_CALLBACK_1(MCScene::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
	

	//animation man
	auto aniSprite = Sprite::create();
	aniSprite->setPosition(100, 100);
	//애니매이션 프레임 추가
	Vector<SpriteFrame*> animFrames;
	const int frameCut = 3;//사용된 프레임 개수
	const int AniCharheight = boysize.height;
	const int AniCharWidth = boysize.width;

	animFrames.reserve(frameCut);
	for (int i = 0; i < frameCut; i++)
		animFrames.pushBack(SpriteFrame::create("res/animSprite2.png", Rect(AniCharWidth * i*3, AniCharheight, AniCharWidth, AniCharheight)));

	// create the animation out of the frame
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animate = Animate::create(animation);
	RepeatForever* aniAction = RepeatForever::create(animate); //액션을 만들어서

	// run it and repeat it forever
	auto jump = JumpBy::create(0.5, Point(0, 0), 20, 1);
	RepeatForever *jumpForever = RepeatForever::create(jump);
	aniSprite->runAction(aniAction); //스프라이트(spr)에 실행
	aniSprite->runAction(jumpForever);


	auto sling = Sling::create();
	this->addChild(sling);


	Sprite* fireWorks = Sprite::create();
	fireWorks->setPosition(100, 200);
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("res/mcatlas.plist");
	const int frameNum = 5;
	Vector<SpriteFrame*> aniFrames(frameNum);
	char str[100] = { 0 };
	for (int i = 1; i <= frameNum; i++)
	{
		sprintf(str, "firework%d.png", i);
		SpriteFrame* frame = cache->getSpriteFrameByName(str);

		aniFrames.pushBack(frame);
	}
	Animation* ani = Animation::createWithSpriteFrames(aniFrames, Director::getInstance()->getSecondsPerFrame());
	Animate* animateFromTmpAtlas = Animate::create(ani);
	RepeatForever *aniRepeat = RepeatForever::create(animateFromTmpAtlas); //액션을 만들어서
	fireWorks->runAction(aniRepeat);
	//fireWorks->addChild(Label::create("HH   ", "arial", 10));
	this->addChild(fireWorks);


	/*JSON Test*/
	string jsonTest = makeJsonTestString();
	
	return true;
}

string MCScene::makeJsonTestString()
{
	/*
	{
		"type" : 0 ,
		"position": {
						"x" : 200 ,
						"y" : 300
					} ,
		"rotation" : 0 ,
		"scale" :	{
						"x" : 2.0 ,
						"y" : 2.0
					}
	}
	*/
	
	Json::Value target;
	Json::Value targets;

	for (int j = 0; j <= 17; j++)
	{
		target["type"] = 4;
		Json::Value position;
		position["x"] = 160 + j * 10;
		position["y"] = 100 + j * 15;
		target["position"] = position;
		target["rotation"] = 0;
		Json::Value scale;
		scale["x"] = 2.0f;
		scale["y"] = 2.0f;
		target["scale"] = scale;

		targets.append(target);
	}

	for (int j = 0; j <= 17; j++)
	{
		target["type"] = 4;
		Json::Value position;
		position["x"] = 160 - j * 10;
		position["y"] = 100 + j * 15;
		target["position"] = position;
		target["rotation"] = 0;
		Json::Value scale;
		scale["x"] = 2.0f;
		scale["y"] = 2.0f;
		target["scale"] = scale;

		targets.append(target);
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i * 2 - 1; j++)
		{
			target["type"] = 5;
			Json::Value position;
			position["x"] = 180 + (j * 15) - (i * 20);
			position["y"] = 175 + (i * 20);
			target["position"] = position;
			target["rotation"] = i * 30 + j * 2;
			Json::Value scale;
			scale["x"] = 2.0f;
			scale["y"] = 2.0f;
			target["scale"] = scale;

			targets.append(target);
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i * 2 - 1; j++)
		{
			target["type"] = 5;
			Json::Value position;
			position["x"] = 180 + (j * 15) - (i * 20);
			position["y"] = 385 - (i * 20);
			target["position"] = position;
			target["rotation"] = i * 30 + j * 2;
			Json::Value scale;
			scale["x"] = 2.0f;
			scale["y"] = 2.0f;
			target["scale"] = scale;

			targets.append(target);
		}
	}

	Json::StyledWriter writer;
	string result = writer.write(targets);

	ofstream out("test.json");
	out << result;
	out.close();

	return result;
}

void MCScene::ChangeToMainScene(Ref* pSender)
{
	Director::getInstance()->replaceScene(MainScene::createScene());
}

void MCScene::onMouseUp(Event *event)
{
	auto label = this->getChildByName("twMissionLabel");
	label->setVisible(false);
}

void MCScene::onMouseDown(Event *event)
{
	if (event == nullptr)
		return;
	auto e = (EventMouse*)event;
	auto mousePos = e->getLocation();
	float xPos = e->getCursorX();
	float yPos = e->getCursorY();

	//A running man jump
	auto blinkLabel = this->getChildByName("twMissionLabel");
	blinkLabel->setVisible(true);
	auto runningBoy = this->getChildByName("boy");
	auto moveToMouse = JumpBy::create(0.3f, Point(0, 0), 50, 1);
	runningBoy->runAction(moveToMouse);

//	Explosion::boom((Scene*)this, Point(xPos, yPos));
}

void MCScene::ChangeBackGroundColor(const float intervalTime)
{
	this->setColor(Color3B((random() % 255), (random() % 255), (random() % 255)));
}
