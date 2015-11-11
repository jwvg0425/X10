#include "stdafx.h"
#include "GameScene.h"
#include "GameManager.h"
#include "Sling.h"

GameScene::GameScene() : gameLayer(nullptr), uiLayer(nullptr)
{

}

Scene* GameScene::createScene()
{
	auto scene = Scene::create();

	auto layer = GameScene::create();
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
	auto background = loadBackGround();
	this->addChild(background);

	gameLayer = GameLayer::create();
	uiLayer = UILayer::create();
	this->addChild(gameLayer);
	this->addChild(uiLayer);
	
	this->scheduleUpdate();

	/*stage Information �ҷ����� �κ�. stageInfomation �ϼ��Ǹ� �Ʒ��� �ּ� ���� */
	//SetStageInformation(const char* fileName, int StageNumber) 
	GameManager::GetInstance()->InitTargets(gameLayer);
	auto sling = Sling::GetInstance();
	this->addChild(sling);

	return true;
}

Sprite* GameScene::loadBackGround()
{
	auto background = Sprite::create(BOTTOM_BGIMG_FILE);
	float scale = (Director::getInstance()->getVisibleSize().width) / (background->getContentSize().width);
	background->setAnchorPoint(Point::ZERO);
	background->setScale(scale);
	background->setOpacity(140);
	return background;
}

void GameScene::update(float dt)
{
	GameManager::GetInstance()->Play(gameLayer, uiLayer);
}