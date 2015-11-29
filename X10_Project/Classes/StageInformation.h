#pragma once

class StageInformation
{
public:

	StageInformation(int stage);
	~StageInformation();
	int GetTargetCount();//�� Ÿ�� ���� ��ȯ
	int GetBulletCount();//�� �ҷ� ���� ��ȯ
	
	bool HasNextTarget(); // �� �ѱ� Ÿ���� �ִ��� �˻�
	string GetTargetType(); //Ÿ���� Ÿ���� ��ȯ
	Point GetTargetPosition(); //Ÿ�� ��ġ ��ȯ
	float GetTargetRotation(); //Ÿ�� ���ư� ���� ��ȯ
	float GetTargetScale(); //Ÿ�� ������ ��ȯ
	
	bool HasNextBullet(); //�� �ѱ� �ҷ��� �ִ��� �˻�
	string GetCurrentBulletInfo(); //���� �ҷ��� Ÿ���� ��ȯ

private:

	struct TargetInfo //���� ������ �̳� Ŭ����...struct�� �Ҳ�.
	{
	public:
		string m_typeName;
		Point m_position;
		float m_rotation;
		float m_scale;

		TargetInfo() : TargetInfo("", Point::ZERO, 0, 0) {}
		TargetInfo(string str, Point p, float r = 0.0, float scale = 1.0) 
			: m_typeName(str), m_position(p), m_rotation(r), m_scale(scale)
		{}
		~TargetInfo(){}
	};


	const char* FILENAME = "temp.txt";
	int m_currentTargetIndex;
	int m_currentBulletIndex;
	TargetInfo m_currentTarget;
	string m_currentBullet;
	vector<TargetInfo> m_targetInfoList;
	vector<string> m_bulletInfoList;
};

