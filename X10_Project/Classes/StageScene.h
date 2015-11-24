#pragma once

class StageScene : public Layer
{
public:
	enum CONSTANT
	{
		STAR_WIDTH = 20,
		STAR_HEIGHT = 20
	};
	const char* BGIMG_FILE = "res/starry_night.jpg"; ///# �̷��� ���߿� ���� �����ä�� �ȴ�. �ѱ��� ���� ��Ƴ�����

	StageScene();
	
	///# �Ҹ��� ������ ������ ���� �� ��. Ư�� �Ʒ� �Ҹ����� ��쿡�� virtual�ӿ��� �װ� ǥ������ �����鼭 ������ �� ������ ���� �򰥸���.
	~StageScene();

	static Scene* CreateScene();
	CREATE_FUNC(StageScene);
	virtual bool init();

	/*�������� �ѹ��� �̿��ؼ� �Ѿ�� �Լ�. �������� ��ư�� �� �Լ��� �Լ� ��ȣ�� �Ѱ��ָ� �˴ϴ�*/
	static void GotoStage(Ref* pSender,int stageNum);
	
	void MenuButtonCallback(Ref* pSender);

private:
	void ChangeToMainScene(Ref* pSender);
	Sprite* LoadBackground(); //���� ��� �ȸ���...
	MenuItemImage* MakeBackButton();
	MenuItemImage* MakeStageButton(int stage, float xPos, float yPos);
};

