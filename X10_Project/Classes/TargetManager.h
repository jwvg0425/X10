#pragma once
class Target;
class GameManager;
class StageInformation;

class TargetManager
{
public:
	TargetManager() {}
	~TargetManager() {}
	Vector<Target*> GetTargets() { return m_targets; }  ///# ���� ��° ������ ���� ��ȿ����.
	void InitTargets(StageInformation* si);
	void ResetTargets();
	void EraseTarget(Target* target);

private:
	Vector<Target*> m_targets;
	int m_defaultTargetNumber; //���� reserve �� �� ���

	friend class GameManager;
};