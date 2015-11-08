#pragma once

class Sling : public Node
{
public:
	static Sling* GetInstance();
	void Reset(); // --> �Ž����������� ����. �Ű������� ����.
	bool IsShoted(); // --> ������ üũ
	Vec2 GetDirection();
	float GetSpeed();
private:
	static Sling* instance;
};