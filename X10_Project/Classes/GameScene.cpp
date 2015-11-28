#include "stdafx.h"
#include "GameScene.h"
#include "GameManager.h"
#include "GameLayer.h"
#include "UILayer.h"
#include "Sling.h"

GameScene::GameScene() : gameLayer(nullptr), uiLayer(nullptr) {}

Scene* GameScene::createScene()
{
	Scene* scene = Scene::create();

	Layer* layer = GameScene::create();
	layer->setName("GameScene");
	scene->addChild(layer);
	
	return scene;
}

bool GameScene::init()
{
	if (Layer::init() == false)
	{
		return false;
	}
	
	//��� �׸� ����.
	auto background = loadBackground();
	this->addChild(background);

	//���̾� ����
	gameLayer = GameLayer::create();
	uiLayer = UILayer::create();
	this->addChild(gameLayer);
	this->addChild(uiLayer);
	
	//���� �Ŵ��� �ʱ�ȭ
	gameManager = GameManager::GetInstance();

	this->scheduleUpdate();

	return true;
}

Sprite* GameScene::loadBackground()
{
	auto background = Sprite::create(BOTTOM_BGIMG_FILE);

	Sprite* character = Sprite::create(CHARACTER_FILE);

	//animation man
	auto aniSprite = Sprite::create();
	aniSprite->setPosition(100, 100);
	//�ִϸ��̼� ������ �߰�
	Vector<SpriteFrame*> animFrames;
	const int frameCut = 3;//���� ������ ����
	const int AniCharheight = 20;
	const int AniCharWidth = 20;

	animFrames.reserve(frameCut);
	animFrames.pushBack(SpriteFrame::create("res/standing_boy.png", Rect(Point(40, 12), Size(AniCharWidth, AniCharheight))));
	animFrames.pushBack(SpriteFrame::create("res/happy_boy.png", Rect(Point(40, 12), Size(AniCharWidth, AniCharheight))));

	// create the animation out of the frame
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animate = Animate::create(animation);
	
	aniSprite->runAction(animate);
	aniSprite->setPosition(10, 20);
	background->addChild(aniSprite);

	character->setPosition(40, 12);
	//character->setScale(10);
	background->addChild(character);

	float scale = (Director::getInstance()->getVisibleSize().width) / (background->getContentSize().width);
	background->setAnchorPoint(Point::ZERO);
	background->setScale(scale);
	background->setOpacity(140);
	return background;
}

void GameScene::update(float dt)
{
	gameManager->Play(gameLayer, uiLayer);
}