#pragma once
class Target;
class GameManager;
class StageInformation;

class TargetManager
{
public:
	~TargetManager() { m_targets.clear(); }
	Vector<Target*>& GetTargets() { return m_targets; }; ///# �� accessor�� �ʿ� ����. ������ Ŭ�������� �ٷ� ���� �����ϱ� ����.
	void InitTargets(StageInformation* si);
	void ResetTargets();
	void EraseDeadTargets();
	bool HasEnemy();

private:
	Vector<Target*> m_targets;
	int m_defaultTargetNumber; //���� reserve �� �� ���

	friend class GameManager;
};
