#pragma once

class GameManager;
class GameLayer;
class UILayer;

class GameScene : public Layer
{
public:
	GameScene();
	static Scene* createScene();
	virtual bool init(); 
	CREATE_FUNC(GameScene);
	virtual void update(float dt);
	GameLayer* GetGameLayer() { return gameLayer; }
	UILayer* GetUILayer() { return uiLayer; }

private:
	GameLayer* gameLayer;
	UILayer* uiLayer;
	GameManager* gameManager;
	Sprite* loadBackground(); //���׸� ����� �κ�.
	const char* BOTTOM_BGIMG_FILE = "res/background2.png"; ///# �����ä
	const char* CHARACTER_FILE = "res/character2.png";
};