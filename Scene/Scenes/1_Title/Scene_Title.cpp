#include "Scene_Title.h"

#include "Scene_Select.h"
#include "Scene_Clear.h"
#include "Scene_Game.h"
#include "Scene_Transition.h"
#include "SceneManager.h"


Scene_Title::Scene_Title() {
	sceneNum_ = TITLE;
}

Scene_Title::~Scene_Title() {
}

void Scene_Title::Init() {
}

void Scene_Title::Update() {
	if (InputKey::triggerMouse[0]) {
		isChangeScene_ = true;
	}
}

void Scene_Title::Draw() {

	//My::DrawQuad(
	//	{ float(kWindowSizeX * 0.5f),float(kWindowSizeY * 0.5f) },
	//	{ float(kWindowSizeX),float(kWindowSizeY) },
	//	0, 0, 1280, 720,
	//	1.0f, 1.0f,
	//	MyTextureManager::texture_[3],
	//	0.0f,
	//	0xffffffff
	//);

	Novice::DrawQuad(
		int(0), int(0),
		int(kWindowSizeX), int(0),
		int(0), int(kWindowSizeY),
		int(kWindowSizeX), int(kWindowSizeY),
		0, 0, kWindowSizeX, kWindowSizeY,
		MyTextureManager::texture_[3],
		0xffffffff
	);

#ifdef _DEBUG
	Novice::ScreenPrintf(20, 20, "scene: Title");
#endif //_DEBUG
}

void Scene_Title::Fin() {
}
