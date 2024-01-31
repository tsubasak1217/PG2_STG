#pragma once
#include "MyFunc.h"

class Camera {

public:
	Camera( Vec2 range);
	~Camera();

protected:
	static Vec2 range_;
	static Vec2 kRange_;
	static Vec2 LT_;
	static Vec2 RB_;

public:
	static Vec2 GetRange() { return range_; }
	static Vec2 GetLT() { return LT_; }
	static Vec2 GetRB() { return RB_; }
};

class Camera2D : public Camera {

public:
	Camera2D(Vec2 pos, Vec2 range);
	~Camera2D();
	static void Init();
	static void Update();
	static void Fin();

private:
	static Vec2 pos_;
	static Vec2 scale_;
	static Vec2 goalScale_;
	static float theta_;
	static Vec2 shake_;
	static Matrix3x3 cameraWorldMatrix_;
	static Matrix3x3 cameraInverse_;
	static Matrix3x3 orthoMatrix_;

private:
	static void MakeMatrix();

public:
	static Vec2 GetPos() { return pos_; }
	static void SetPos(const Vec2& pos){ pos_ = pos; }

	static Vec2 GetScale() { return scale_; }
	static void SetScale(const Vec2& scale) { scale_ = scale; }

	static float GetTheta() { return theta_; }
	static void SetTheta(float theta) { theta_ = theta; }

	static Vec2 GetShake() { return shake_; }
	static void SetShake(const Vec2& shake) { shake_ = shake; }

	static Matrix3x3 GetWorldMatrix() { return cameraWorldMatrix_; }
	static Matrix3x3 GetViewMatrix() { return cameraInverse_; }
	static Matrix3x3 GetOrthoMatrix() { return orthoMatrix_; }
};

class Camera3D : public Camera {
public:
	Camera3D(Vec3 pos, Vec2 range);
	~Camera3D();
	static void Init();
	static void Update();
	static void Fin();

private:
	static Vec3 pos_;
	static Vec3 scale_;
	static Vec3 theta_;
	static Vector3<int> shake_;

public:
	static Vec3 GetPos() { return pos_; }
	static void SetPos(const Vec3& pos) { pos_ = pos; }

	static Vec3 GetScale() { return scale_; }
	static void SetScale(const Vec3& scale) { scale_ = scale; }

	static Vec3 GetTheta() { return theta_; }
	static void SetTheta(const Vec3& theta) { theta_ = theta; }

	static Vector3<int> GetShake() { return shake_; }
	static void SetShake(const Vector3<int>& shake) { shake_ = shake; }
};
