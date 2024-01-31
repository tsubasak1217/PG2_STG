#pragma once
#include "Object.h"
#include "Bullet.h"

class EnemyManager;

class Enemy : public Object {
public:
	Enemy();
	~Enemy();

	void Init()override;
	void Update()override;
	void Draw()override;
	void Fin()override;

private:
	const int kBulletMax_ = 32;
	std::vector<Bullet*> bullets_;

	int HP_;
	bool isAlive_;

	Vec2 localVertex_[4];
	Vec2 screenVertex_[4];
	Matrix3x3 worldMatrix_;
	Matrix3x3 screenMatrix_;
	Vec2 screenPos_;

	Vec2 direction_;
	float speed_;

private:
	void MakeMatrix();

public:
	Vec2 GetPos()const { return pos_; }
	int GetHP()const { return HP_; }
	void SetHP(int hp) { HP_ = hp; }
	bool GetIsAlive()const { return isAlive_; }
};