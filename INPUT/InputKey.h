#pragma once
#include "MyFunc.h"

class InputKey {
public:
	static const int kMaxKey_ = 256;
	static char keys[kMaxKey_];
	static char preKeys[kMaxKey_];

	static bool trigger[kMaxKey_];
	static bool release[kMaxKey_];

	static int mouseX;
	static int mouseY;
	static Vec2 mousePos_;
	static Vec2 worldMousePos_;
	static Matrix3x3 mouseTransMatrix_;

	static bool pressMouse[2];
	static bool prePressMouse[2];
	static bool triggerMouse[2];
	static bool releaseMouse[2];
	static int mouseWheel;


	static void Update();
	static void MakeMatrix();
};

