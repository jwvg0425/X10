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
		
		info = TargetInfo("Enemy", Point(200, 400), 0, 0.03f/2);
		m_targetInfoList.push_back(info);

		info = TargetInfo("Cloud", Point(200, 200), 0, 4.0f/2);
		m_targetInfoList.push_back(info); 
		
		info = TargetInfo("Mirror", Point(30, 200), 0, 3.0f/2);
		m_targetInfoList.push_back(info);	

		info = TargetInfo("Bubble", Point(200, 300), 0, 2.5f/2);
		m_targetInfoList.push_back(info);

		info = TargetInfo("Star", Point(100, 250), 0, 0.5f/2);
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
		/**/
	}

	if (stage == 3)
	{
		m_currentTargetIndex = 0;
		m_currentBulletIndex = 0;
		
		Size screen = Director::getInstance()->getVisibleSize();

		TargetInfo info;

		info = TargetInfo("Mirror", Point(0, 200), 0, 1.5);
		m_targetInfoList.push_back(info);
		info = TargetInfo("Mirror", Point(320, 200), 0, 1.5f);
		m_targetInfoList.push_back(info);
		
		info = TargetInfo("Mirror", Point(160, 300), 0, 3.0f / 2);
		m_targetInfoList.push_back(info);

		info = TargetInfo("Mirror_y", Point(160, 100), 0, 2.5f / 2);
		m_targetInfoList.push_back(info);
		info = TargetInfo("Mirror_y", Point(70, 250), 0, 2.5f / 2);
		m_targetInfoList.push_back(info);


		info = TargetInfo("Enemy", Point(300, 360), 0, 0.02f);
		m_targetInfoList.push_back(info);
		info = TargetInfo("Mirror", Point(0, 360), 0, 1.5);
		m_targetInfoList.push_back(info);
		info = TargetInfo("Mirror", Point(320, 360), 0, 1.5f);
		m_targetInfoList.push_back(info);

		for (int xpos = 0; xpos < screen.width + 40; xpos += 34)
		{
			info = TargetInfo("Mirror_y", Point(xpos, 480), 0, 2.5f / 2);
			m_targetInfoList.push_back(info);
		}

		info = TargetInfo("Star", Point(100, 250), 0, 0.25f);
		m_targetInfoList.push_back(info);

		info = TargetInfo("Star", Point(250, 250), 0, 0.25f );
		m_targetInfoList.push_back(info);
		info = TargetInfo("Star", Point(260, 250), 0, 0.25f);
		m_targetInfoList.push_back(info);

		info = TargetInfo("Star", Point(230, 210), 0, 0.25f);
		m_targetInfoList.push_back(info);
		
		info = TargetInfo("Star", Point(220, 190), 0, 0.25f);
		m_targetInfoList.push_back(info);
		info = TargetInfo("Star", Point(230, 190), 0, 0.25f);
		m_targetInfoList.push_back(info);

		string bulletType = "Bullet";
		m_bulletInfoList.push_back(bulletType);
		m_bulletInfoList.push_back(bulletType);
		m_bulletInfoList.push_back(bulletType);
		m_bulletInfoList.push_back(bulletType);
		m_bulletInfoList.push_back(bulletType);
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
	return m_currentTarget.m_typeName;
}

Point StageInformation::GetTargetPosition()
{
	return m_currentTarget.m_position;
}

float StageInformation::GetTargetRotation()
{
	return m_currentTarget.m_rotation;
}

float StageInformation::GetTargetScale()
{
	return m_currentTarget.m_scale;
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