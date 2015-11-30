#pragma once


class StageInformation
{
public:
	struct TargetInfo //���� ������ inner struct
	{
	public:
		enum TargetType
		{
			ENEMY,
			MIRROR,
			MIRROR_Y,
			CLOUD,
			BUBBLE,
			STAR,
			SEEBIRD
		} m_name;
		
		Point m_position;
		float m_rotation;
		float m_scaleX;
		float m_scaleY;

		TargetInfo() : TargetInfo(TargetType::ENEMY, Point::ZERO) {}
		TargetInfo(TargetType name, Point p, float r = 0.0f, float scalex = 1.0f, float scaley = 1.0f)
			: m_name(name), m_position(p), m_rotation(r), m_scaleX(scalex), m_scaleY(scaley)
		{}
		~TargetInfo(){}
	};

	StageInformation(int stage);
	~StageInformation();
	int GetTargetCount();//�� Ÿ�� ���� ��ȯ
	int GetBulletCount();//�� �ҷ� ���� ��ȯ
	
	bool HasNextTarget(); // �� �ѱ� Ÿ���� �ִ��� �˻�
	StageInformation::TargetInfo::TargetType GetTargetType(); //Ÿ���� Ÿ���� ��ȯ
	Point GetTargetPosition(); //Ÿ�� ��ġ ��ȯ
	float GetTargetRotation(); //Ÿ�� ���ư� ���� ��ȯ
	float GetTargetScale(); //Ÿ�� ������ ��ȯ
	
	bool HasNextBullet(); //�� �ѱ� �ҷ��� �ִ��� �˻�
	string GetCurrentBulletInfo(); //���� �ҷ��� Ÿ���� ��ȯ


private:

	

	const char* FILENAME = "temp.txt";
	int m_currentTargetIndex;
	int m_currentBulletIndex;
	TargetInfo m_currentTarget;
	string m_currentBullet;
	vector<TargetInfo> m_targetInfoList;
	vector<string> m_bulletInfoList;
};

typedef StageInformation::TargetInfo::TargetType TargetType;
