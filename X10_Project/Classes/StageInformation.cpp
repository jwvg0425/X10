#include "stdafx.h"
#include "StageInformation.h"

StageInformation::StageInformation(int stage)
{
	//0ź �ӽ� ������
	if (stage == 0)
	{
		CurrentTargetIndex =0;
		CurrentBulletIndex =0;
		
		TargetInfo info;
		
		info = TargetInfo("Enemy", Point(200, 400), 0, 0.03f);
		TargetInfoList.push_back(info);

		info = TargetInfo("Mirror", Point(30, 200),0, 3.0f);
		TargetInfoList.push_back(info);

		info = TargetInfo("Cloud", Point(200, 200), 0, 4.0f);
		TargetInfoList.push_back(info);

		info = TargetInfo("Bubble", Point(200, 300), 0, 2.5f);
		TargetInfoList.push_back(info);

		//bullet �ټ���
		string bulletType = "Bullet";
		BulletInfoList.push_back(bulletType);
		BulletInfoList.push_back(bulletType);
		BulletInfoList.push_back(bulletType);
		BulletInfoList.push_back(bulletType);
		BulletInfoList.push_back(bulletType);
	}

	if (stage > 0)
	{
		/*���Ͽ��� ������ �ҷ��� stage ������ ä�� �κ�*/
	}
}

StageInformation::~StageInformation()
{

}

int StageInformation::GetTargetCount()
{// �� Ÿ�ټ��� ��ȯ
	return TargetInfoList.size();
}

int StageInformation::GetBulletCount()
{//�� �ҷ� ���� ��ȯ
	return BulletInfoList.size();
}

bool StageInformation::HasNextTarget()
{//���� Ÿ���� �ִ��� �˻�
	if (CurrentTargetIndex < GetTargetCount())
	{
		currentTarget = TargetInfoList.at(CurrentTargetIndex);
		CurrentTargetIndex++;
		return true;
	}
	else 
	{
		return false;
	}
}

string StageInformation::GetTargetType()
{//Ÿ�� Ÿ���� �޾ƿ�.
	return currentTarget.typeName;
}

Point StageInformation::GetTargetPosition()
{
	return currentTarget.position;
}

float StageInformation::GetTargetRotation()
{
	return currentTarget.rotation;
}

float StageInformation::GetTargetScale()
{
	return currentTarget.scale;
}

bool StageInformation::HasNextBullet() //�� �ѱ� �ҷ��� �ִ��� �˻�
{
	if (CurrentBulletIndex < GetBulletCount())
	{
		currentBullet = BulletInfoList.at(CurrentBulletIndex);
		CurrentBulletIndex++;
		return true;
	}
	else
	{
		return false;
	}
}

string StageInformation::GetCurrentBulletInfo() //���� �ҷ��� Ÿ���� ��ȯ
{
	return currentBullet;
}