#pragma once
#include "object.h"
#include "Bullet.h"

class Camera2D;

class Player : public Object{

public:
	Player();
	~Player();

	void Init()override;
	void Update()override;
	void Draw()override;

private:
	std::vector<Bullet*> bullets_;
	int reloadCount_;
	Camera2D* p_camera_;
	Vec2 bulletDirection_;
	int shakeTime_;

private:
	void Move();
	void MakeScreenVertex();
	void CreateBullet();
	void EraseBullet();

protected:

	Vec2 localVertex_[4];
	Vec2 screenVertex_[4];
	Matrix3x3 worldMatrix_;
	Matrix3x3 screenMatrix_;

public:
	Camera2D* GetCameraPtr()const { return p_camera_; }
	std::vector<Bullet*>GetBullet()const { return bullets_; }
	Vec2 GetPos()const { return pos_; }
	Vec2 GetSize()const { return size_; }
	void SetBulletDirection(Vec2 direction) { bulletDirection_ = direction; }
	Vec2 GetBulletDirection()const { return bulletDirection_; }
};