#pragma once
#include "Target.h"

class Enemy : public Target
{
	///# private / public ���� �ڵ� ������ ���ϰ�, ��� ������ �ִ��� �����ھȿ��� �ʱ�ȭ �ϴ� ������..
private:
	float hp;
public:
	void getHp();
};