#include "SceneManager.h"
#include "Scene_Game.h"
#include "Scene_Title.h"
#include "Scene_Select.h"
#include "Scene_Clear.h"

// static init
Scene* SceneManager::scene_ = nullptr;
Scene_Transition* SceneManager::transition_ = nullptr;
bool SceneManager::isTransition_ = false;

//--------------------------------------------------------------------------------
SceneManager::SceneManager(Scene* scene) {
	Init(scene);
}

SceneManager::~SceneManager() {
}

//--------------------------------------------------------------------------------
void SceneManager::Init(Scene* scene) {
	scene_ = scene;
	transition_ = new Scene_Transition();
}

//--------------------------------------------------------------------------------
void SceneManager::Update() {

	scene_->Update();

	if (isTransition_) {
		transition_->Update();

		if (transition_->GetInFrame() <= 0) {

			if (!transition_->GetIsReturn()) {
				switch (scene_->GetSceneNum()) {

				case TITLE:
					scene_ = new Scene_Game();
					break;

				case GAME:
					scene_ = new Scene_Clear();
					break;

				case CLEAR:
					scene_ = new Scene_Title();
					break;

				default:
					break;
				}
			}
		}

		if (transition_->GetOutFrame() <= 0) {

			isTransition_ = false;
		}

	} else {
		if (scene_->GetIsChangeScene()) {
			isTransition_ = true;
			transition_->Init();
		}
	}
	
}

//--------------------------------------------------------------------------------
void SceneManager::Draw() {

	scene_->Draw();
	
	if (isTransition_) {
		transition_->Draw();
	}
}

//--------------------------------------------------------------------------------
void SceneManager::Fin() {
}


void SceneManager::SetScene(Scene* scene) {
	delete scene_;
	scene_ = scene;
}
