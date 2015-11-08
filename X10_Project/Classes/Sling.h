#pragma once

class Sling : public Node
{
public: //constant
	const float WIDTH = 20;
	const float HEIGHT = 50;
	const float YPOS = 50;

public:
	static Sling* GetInstance();
	static bool isExist;

	/*���� ��ȭ�� ���� ȣ���ϴ� �Լ���*/
	void Reset(); // --> �Ž����������� ����. �Ű������� ����.
	//sling manager�� �ִٸ� �������� �� �Լ���
	void NewBulletLoad();
	void PullStart(Event* e);
	void Pull(Event* e);
	void Shot(Event* e);
	
	bool IsShotted(); // --> ������ üũ
	Vec2 GetDirection();
	float GetSpeed();
	
private: //function to get singleton instance
	CREATE_FUNC(Sling);
	virtual bool init();
	static Sling* instance;

private: //member function
	enum Status { empty, loaded, pulling, shotted } status;
	void ChangeToLoaded(); //empty -> load
	void ChangeToPulling(); //loaded -> pulling
	void ChangeToShotted(); //pullig -> shotted
	void ChangeToEmpty(); //shotted -> empty

	Point GetStartLocation();

private: //member variable
	Vec2 shotAngle;
	float shotPower;
};