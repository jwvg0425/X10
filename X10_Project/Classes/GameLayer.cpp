#include "stdafx.h"
#include "GameLayer.h"

/* 
///#�ʿ䵵 �����鼭!
GameLayer* GameLayer::createGameLayer()
{
	GameLayer* gLayer = GameLayer::create();
	
	return gLayer;
}
*/
bool GameLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	setName("GameLayer");

	return true;
}