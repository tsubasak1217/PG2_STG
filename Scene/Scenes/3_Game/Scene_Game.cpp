#include "Scene_Game.h"

#include "Scene_Title.h"
#include "Scene_Select.h"
#include "Scene_Clear.h"
#include "Scene_Transition.h"
#include "SceneManager.h"

#include "Player.h"
#include "EnemyManager.h" 
#include "Stage.h"

#include "CollisionManager.h"

Scene_Game::Scene_Game() {
	Init();
}

Scene_Game::~Scene_Game() {
}

void Scene_Game::Init() {

	sceneNum_ = GAME;

	chapter_ = 1;
	stage = new Stage();
	player_ = new Player();
	em_ = new EnemyManager(this);
	cm_ = new CollisionManager(player_, em_);
}

void Scene_Game::Update() {

	frameCount_++;

	stage->Update();
	player_->Update();
	em_->Update();

	cm_->Update();

	if (em_->GetEnemy().size() <= 0) {
		isChangeScene_ = true;
		return;
	}
}

void Scene_Game::Draw() {

	stage->Draw();
	em_->Draw();
	player_->Draw();

#ifdef _DEBUG
	Novice::ScreenPrintf(20, 20, "scene: Game");
#endif //_DEBUG
}

void Scene_Game::Fin() {
}
