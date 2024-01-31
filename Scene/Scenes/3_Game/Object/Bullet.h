#pragma once
#include "Object.h"

class Player;

class Bullet : public Object {
public:
	Bullet(Player* player);
	~Bullet();

	void Init()override;
	void Update()override;
	void Draw()override;
	void Fin()override;

	static const int kMaxBullet_ = 128;

private:

	bool isAlive_;
	Vec2 direction_;
	Vec2 velocity_;
	float speed_;

	Camera2D* p_camera_;

	Matrix3x3 worldMatrix_;
	Matrix3x3 screenMatrix_;
	Vec2 screenPos_;

private:
	void MakeMatrix();

public:
	void SetDirection(const Vec2& direction) { direction_ = direction; }
	void SetIsAlive(bool flag) { isAlive_ = flag; }
	bool GetIsAlive()const { return isAlive_; }
	Vec2 GetPos()const { return pos_; }
	Vec2 GetSize()const { return size_; }
};