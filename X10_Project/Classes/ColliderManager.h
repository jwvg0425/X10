#pragma once
class StageInformation;
class Collider;
class Bullet;

class ColliderManager
{
public:
	static ColliderManager* GetInstance();
	void Init();
	Bullet* GetBulletToShot();
	Vector<Collider*>& GetColliders(){ return colliders; } ///# ���� �÷����� ��°�� ������ �����شٴ� �Ҹ��� colliders�� private�� ������ ���� ������? ��-��ü�������ε�..
	/// ���� �浹 ó���� ColliderMananger���� �ϴ���...

	void AddExplosion(Collider* explosion);
	bool HasBullet();
	void Reset();
	void EraseCollider(Collider* collider); 
	void InitColliders(StageInformation* stage);

private:
	void InitColliders(); // called in Init()
	static ColliderManager* instance;
	Vector<Collider*> colliders;
	int curBulletIndex;
	int defaultBulletNum;
	ColliderManager();
	~ColliderManager();
};