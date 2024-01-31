#pragma once
#include "MyFunc.h"
#include "Camera.h"
#include "Environment.h"

#include "MyTextureManager.h"

class Object {
public:
	Object();
	~Object();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Fin();

private:

protected:
	Vec2 pos_;
	Vec2 size_;
	Vec2 scale_;
	float theta_;

public:
	Vec2 GetPos() const { return pos_; }
	Vec2 GetSize() const { return size_; }
	float GetTheta() const { return theta_; }

	void SetPos(const Vec2& pos) { pos_ = pos; }
	void SetSize(const Vec2& size) { size_ = size; }
	void SetTheta(float theta) { theta_ = theta; }
};

enum VETEXES {
	LT,
	RT,
	LB,
	RB
};