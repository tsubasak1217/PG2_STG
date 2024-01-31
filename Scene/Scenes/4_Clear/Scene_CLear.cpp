#include "Scene_Clear.h"

#include "Scene_Title.h"
#include "Scene_Select.h"
#include "Scene_Game.h"
#include "Scene_Transition.h"
#include "SceneManager.h"

Scene_Clear::Scene_Clear() {
	sceneNum_ = CLEAR;
}

Scene_Clear::~Scene_Clear() {
}

void Scene_Clear::Init() {
}

void Scene_Clear::Update() {
	if (InputKey::triggerMouse[0]) {
		isChangeScene_ = true;
	}
}

void Scene_Clear::Draw() {

	Novice::DrawQuad(
		int(0), int(0),
		int(kWindowSizeX), int(0),
		int(0), int(kWindowSizeY),
		int(kWindowSizeX), int(kWindowSizeY),
		0, 0, kWindowSizeX, kWindowSizeY,
		MyTextureManager::texture_[4],
		0xffffffff
	);

#ifdef _DEBUG
	Novice::ScreenPrintf(20, 20, "scene: Clear");
#endif //_DEBUG
}

void Scene_Clear::Fin() {
}
