#include "Scene_Transition.h"
#include "MyTextureManager.h"

Scene_Transition::Scene_Transition() {
	Init();
}

Scene_Transition::~Scene_Transition() {
	Fin();
}

void Scene_Transition::Init() {
	inFrame_ = 30;
	outFrame_ = 30;
	isReturn_ = false;
}

void Scene_Transition::Update() {
	if (inFrame_ > 0) {
		inFrame_--;
		alpha_ = int(float(0xff) * ((30 - inFrame_) / 30.0f));
		isReturn_ = false;

	} else {
		isReturn_ = true;
		if (outFrame_ > 0) {
			outFrame_--;
			alpha_ = int(float(0xff) * (outFrame_ / 30.0f));
		}
	}
}

void Scene_Transition::Draw() {
	Novice::DrawQuad(
		int(0), int(0),
		int(kWindowSizeX), int(0),
		int(0), int(kWindowSizeY),
		int(kWindowSizeX), int(kWindowSizeY),
		0, 0, kWindowSizeX, kWindowSizeY,
		MyTextureManager::texture_[0],
		0x00000000 + alpha_
	);
}

void Scene_Transition::Fin() {
}
