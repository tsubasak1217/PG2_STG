#pragma once
#include "Environment.h"
#include "VectorN.h"
#include "MatrixNxN.h"

class Stage {
public:
	Stage();
	~Stage();

	void Init();
	void Update();
	void Draw();
	void Fin();

private:
	
	Vec2 scale_;
	float theta_;

	Vec2 localVertex_[4];
	Vec2 screenVertex_[4];

	Matrix3x3 worldMatrix_;
	Matrix3x3 screenMatrix_;
};