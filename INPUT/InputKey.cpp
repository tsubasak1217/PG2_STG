#include "InputKey.h"
#include <Novice.h>
#include "GameManager.h"

char InputKey::keys[kMaxKey_] = { 0 };
char InputKey::preKeys[kMaxKey_] = { 0 };
bool InputKey::trigger[kMaxKey_] = { false };
bool InputKey::release[kMaxKey_] = { false };
int InputKey::mouseX = 0;
int InputKey::mouseY = 0;
bool InputKey::pressMouse[2] = {false};
bool InputKey::prePressMouse[2] = {false};
bool InputKey::triggerMouse[2] = { false };
bool InputKey::releaseMouse[2] = { false };
Matrix3x3 InputKey::mouseTransMatrix_;
Vec2 InputKey::mousePos_ = { 0.0f };
Vec2 InputKey::worldMousePos_ = { 0.0f };
int InputKey::mouseWheel = 0;

void InputKey::Update() {
	// マウスの入力
	Novice::GetMousePosition(&mouseX, &mouseY);
	mousePos_ = { float(mouseX),float(mouseY) };
	MakeMatrix();
	worldMousePos_ = Multiply({ float(mouseX),float(mouseY) }, mouseTransMatrix_);

	for (int i = 0; i < 2; i++) {
		prePressMouse[i] = pressMouse[i];
		pressMouse[i] = Novice::IsPressMouse(i);
		triggerMouse[i] = !prePressMouse[i] && pressMouse[i];
		releaseMouse[i] = prePressMouse[i] && !pressMouse[i];
	}

	mouseWheel = Novice::GetWheel();

	// キーボードの入力
	for (int i = 0; i < kMaxKey_; i++) {
		trigger[i] = !preKeys[i] && keys[i];
		release[i] = preKeys[i] && !keys[i];
	}
}

void InputKey::MakeMatrix() {

	mouseTransMatrix_ = Multiply(
		InverseMatrix(ViewportMatrix({ float(kWindowSizeX),float(kWindowSizeY) },{ 0.0f, 0.0f })),
		InverseMatrix(GameManager::camera_->GetOrthoMatrix())
	);

	mouseTransMatrix_ = Multiply(mouseTransMatrix_, GameManager::camera_->GetWorldMatrix());
}
