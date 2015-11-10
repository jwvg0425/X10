#pragma once

class Sling : public Node
{
public: //constant
	///# �̷��Ŵ� enum����.. (��)
	enum SLING_CONFIG
	{
		SC_WIDTH = 20,
		SC_HEIGHT = 50,
		/// ...
	};

	const float WIDTH	= 20;
	const float HEIGHT	= 50;
	const float YPOS	= 50;
	const float MAX_POWER	= 30;
	const float FONT_SIZE	= 24;
	const float PREDICT_LINE_TIME = 0.5;
	const float CLICKABLE_RANGE = 10;

public:
	static Sling* GetInstance();
	static bool isExist;

	/*���� ��ȭ�� ���� ȣ���ϴ� �Լ���*/
	void Reset(); // --> �Ž����������� ����. �Ű������� ����.
	void NewColliderLoad();
	void PullStart(Event* e);
	void Pull(Event* e);
	void Shot(Event* e);
	
	bool IsShotted(); // --> ������ üũ
	Vec2 GetDirection();
	float GetAngleInRadian();
	float GetSpeed();
	float GetRotationAngle();
	
private: //function to get singleton instance
	CREATE_FUNC(Sling);
	virtual bool init();
	static Sling* instance;

	//member function
	enum Status 
	{ 
		empty, ///# ���� ENUM�� �빮�ڷ�... ��: STATUS_EMPTY
		loaded,
		pulling,
		shotted 
	} status; ///# emumŸ�� ��� ������ ���� �ٹٲ㼭..

	void ChangeToLoaded();	//empty -> load
	void ChangeToPulling(); //loaded -> pulling
	void ChangeToShotted(); //pullig -> shotted
	void ChangeToEmpty();	//shotted -> empty

	Point GetStartLocation();

private: //member variable
	Vec2 shotAngle;
	float shotPower;
};