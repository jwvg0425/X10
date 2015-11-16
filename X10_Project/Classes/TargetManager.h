#pragma once
class Target;
class GameManager;
class StageInformation;

class TargetManager
{
public:
	TargetManager() {}
	~TargetManager() {}
	Vector<Target*> GetTargets() { return targets; };
	void InitTargets(StageInformation* si);
	void ResetTargets();
	void EraseTarget(Target* target);

private:
	Vector<Target*> targets;
	int defaultTargetNumber; //���� reserve �� �� ���

	friend class GameManager;
};