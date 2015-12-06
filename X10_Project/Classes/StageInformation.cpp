#include "stdafx.h"
#include "StageInformation.h"
#include <fstream>
#include <json/json.h>

StageInformation::StageInformation(int stage)
{
	Size winSize = Director::getInstance()->getWinSize();
	m_currentTargetIndex = 0;
	m_currentBulletIndex = 0;

	TargetInfo info;

	if (stage <= 2 && stage >=0)
	{
		char fileName[100];
		sprintf(fileName, "../Resources/files/target%d.txt", stage);
		ifstream ifs(fileName);

		while (!ifs.eof())
		{
			int type;
			float posX, posY, rotation, scaleX, scaleY;
			ifs >> type >> posX >> posY >> rotation >> scaleX >> scaleY;
			info = TargetInfo(static_cast<TargetType>(type), Point(posX, posY), rotation, scaleX, scaleY);
			m_targetInfoList.push_back(info);
		}

		sprintf(fileName, "../Resources/files/bullet%d.txt", stage);
		ifs = ifstream(fileName);

		while (!ifs.eof())
		{
			int crossnum, bulletnum;
			ifs >> crossnum >> bulletnum;

			string bulletType = "CrossBullet";
			for (int i = 0; i < crossnum; i++)
			{
				m_bulletInfoList.push_back(bulletType);
			}

			bulletType = "Bullet";
			for (int i = 0; i < bulletnum; i++)
			{
				m_bulletInfoList.push_back(bulletType);
			}

		}

		return;

	}
	else if (stage == 3)
	{
		/// �׽�Ʈ��.
		info = TargetInfo(TargetInfo::ENEMY, Point(160, 280), 0, 1.03f);
		m_targetInfoList.push_back(info);

		for (int j = 0; j <= 17; j++)
		{
			info = TargetInfo(TargetInfo::BUBBLE, Point(160 + j * 10, 100 + j * 15), 0, 2.5f / 2);
			m_targetInfoList.push_back(info);
		}

		for (int j = 0; j <= 17; j++)
		{
			info = TargetInfo(TargetInfo::BUBBLE, Point(160 - j * 10, 100 + j * 15), 0, 2.5f / 2);
			m_targetInfoList.push_back(info);
		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j <= i * 2 - 1; j++)
			{
				info = TargetInfo(TargetInfo::STAR, Point(180 + (j * 15) - (i * 20), 175 + (i * 20)), i * 30 + j * 2, 2.0,2.0);
				m_targetInfoList.push_back(info);
			}
		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j <= i * 2 - 1; j++)
			{
				info = TargetInfo(TargetInfo::STAR, Point(180 + (j * 15) - (i * 20), 385 - (i * 20)), i * 30 + j * 2, 2.0, 2.0);
				m_targetInfoList.push_back(info);
			}
		}

		//Bullet 5��`
		string bulletType = "Bullet";
		m_bulletInfoList.push_back(bulletType);
		m_bulletInfoList.push_back(bulletType);
		m_bulletInfoList.push_back(bulletType);
		m_bulletInfoList.push_back(bulletType);
		m_bulletInfoList.push_back(bulletType);
	}
	else
	{

	}
}

StageInformation::~StageInformation()
{
	m_targetInfoList.clear();
	m_bulletInfoList.clear();
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

TargetType StageInformation::GetTargetType()
{//Ÿ�� Ÿ���� �޾ƿ�.
	return m_currentTarget.m_name;
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
	return (m_currentTarget.m_scaleX +m_currentTarget.m_scaleY)/2;
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