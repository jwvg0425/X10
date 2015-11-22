#include "stdafx.h"
#include "StageInformation.h"

StageInformation::StageInformation(int stage)
{
	Size winSize = Director::getInstance()->getWinSize();

	if (stage == 0)
	{
		m_currentTargetIndex =0;
		m_currentBulletIndex =0;
		
		TargetInfo info;
		
		info = TargetInfo("Enemy", Point(200, 400), 0, 0.03f);
		m_targetInfoList.push_back(info);

		info = TargetInfo("Cloud", Point(200, 200), 0, 4.0f);
		m_targetInfoList.push_back(info); 
		
		info = TargetInfo("Mirror", Point(30, 200), 0, 3.0f);
		m_targetInfoList.push_back(info);	

		info = TargetInfo("Bubble", Point(200, 300), 0, 2.5f);
		m_targetInfoList.push_back(info);

		info = TargetInfo("Star", Point(100, 250), 0, 0.5f);
		m_targetInfoList.push_back(info);

		//SeeBirds for tests
		Point seeBirdPos = Point(winSize.width, RandomHelper::random_real(200.0f, winSize.height));
		info = TargetInfo("SeeBird", seeBirdPos, 0, 1.0f);
		m_targetInfoList.push_back(info);

		seeBirdPos = Point(winSize.width, RandomHelper::random_real(200.0f, winSize.height));
		info = TargetInfo("SeeBird", seeBirdPos, 0, 1.0f);
		m_targetInfoList.push_back(info);

		seeBirdPos = Point(winSize.width, RandomHelper::random_real(200.0f, winSize.height));
		info = TargetInfo("SeeBird", seeBirdPos, 0, 1.0f);
		m_targetInfoList.push_back(info);

		seeBirdPos = Point(winSize.width, RandomHelper::random_real(200.0f, winSize.height));
		info = TargetInfo("SeeBird", seeBirdPos, 0, 1.0f);
		m_targetInfoList.push_back(info);

		//CrossBullet 3�� Bullet 2��
		string bulletType = "CrossBullet";
		m_bulletInfoList.push_back(bulletType);
		m_bulletInfoList.push_back(bulletType);
		m_bulletInfoList.push_back(bulletType);

		bulletType = "Bullet";
		m_bulletInfoList.push_back(bulletType);
		m_bulletInfoList.push_back(bulletType);
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
	return m_targetInfoList.size();
}

int StageInformation::GetBulletCount()
{//�� �ҷ� ���� ��ȯ
	return m_bulletInfoList.size();
}

bool StageInformation::HasNextTarget()
{//���� Ÿ���� �ִ��� �˻�
	if (m_currentTargetIndex < GetTargetCount())
	{
		m_currentTarget = m_targetInfoList.at(m_currentTargetIndex);
		m_currentTargetIndex++;
		return true;
	}
	else 
	{
		return false;
	}
}

string StageInformation::GetTargetType()
{//Ÿ�� Ÿ���� �޾ƿ�.
	return m_currentTarget.typeName;
}

Point StageInformation::GetTargetPosition()
{
	return m_currentTarget.position;
}

float StageInformation::GetTargetRotation()
{
	return m_currentTarget.rotation;
}

float StageInformation::GetTargetScale()
{
	return m_currentTarget.scale;
}

bool StageInformation::HasNextBullet() //�� �ѱ� �ҷ��� �ִ��� �˻�
{
	if (m_currentBulletIndex < GetBulletCount())
	{
		m_currentBullet = m_bulletInfoList.at(m_currentBulletIndex);
		m_currentBulletIndex++;
		return true;
	}
	else
	{
		return false;
	}
}

string StageInformation::GetCurrentBulletInfo() //���� �ҷ��� Ÿ���� ��ȯ
{
	return m_currentBullet;
}