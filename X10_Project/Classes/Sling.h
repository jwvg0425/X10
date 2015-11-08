#pragma once

class Sling : public Node
{
public: //constant
	

public:
	static Sling* GetInstance();
	
	/*���� ��ȭ�� ���� ȣ���ϴ� �Լ���*/
	void Reset(); // --> �Ž����������� ����. �Ű������� ����.
	//sling manager�� �ִٸ� �������� �� �Լ���
	//void NewBulletLoad(Bullet* b);
	void PullStart(Event* e);
	void Pull(Event* e);
	void Shot(Event* e);
	
	bool IsShoted(); // --> ������ üũ
	Vec2 GetDirection();
	float GetSpeed();
	
private: //function to get singleton instance
	CREATE_FUNC(Sling);
	virtual bool init();
	static Sling* instance;

private: //member function
	enum Status { empty, loaded, pulling, shoted } status;
	void ChangeToLoaded(); //empty -> load
	void ChangeToPulling(); //loaded -> pulling
	void ChangeToShooted(); //pullig -> shooted
	void ChangeToEmpty(); //shooted -> empty

	Point getStartLocation();

private: //member variable
	Vec2 shootAngle;
	float shootPower;
};