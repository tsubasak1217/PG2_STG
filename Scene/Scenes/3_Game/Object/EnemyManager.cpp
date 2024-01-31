#include "EnemyManager.h"

EnemyManager::EnemyManager(Scene_Game* sceneGame_ptr) {
	Init(sceneGame_ptr);
}

EnemyManager::~EnemyManager() {
	Fin();
}

void EnemyManager::Init(Scene_Game* sceneGame_ptr) {
	chapter_ = 1;
	loadOrder_ = true;
	sceneGame_ptr_ = sceneGame_ptr;
	enemy_.clear();
}

void EnemyManager::Update() {

	LoadEnemy();

	for (int i = 0; i < enemy_.size(); i++) {
		enemy_[i]->Update();
	}

	switch (chapter_) {

	case 1:
		if (enemy_.size() <= 0) {
			chapter_ = 2;
			loadOrder_ = true;
		}

		break;

	case 2:
		if (enemy_.size() <= 0) {
			chapter_ = 3;
			loadOrder_ = true;
		}
		break;

	case 3:
		if (enemy_.size() <= 0) {
			sceneGame_ptr_->SetIsChangeScene(true);
		}
		break;

	default:
		break;
	}

	EraseEnemy();

}

void EnemyManager::Draw() {

	for (int i = 0; i < enemy_.size(); i++) {
		enemy_[i]->Draw();
	}
}

void EnemyManager::Fin() {
}


void EnemyManager::LoadEnemy() {

	if (!loadOrder_) { return; }
	enemy_.clear();

	switch (chapter_) {
	case 1:
		for (int i = 0; i < 4; i++) { enemy_.push_back(new Enemy());}
		break;

	case 2:
		for (int i = 0; i < 8; i++) { enemy_.push_back(new Enemy()); }
		break;

	case 3:
		for (int i = 0; i < 16; i++) { enemy_.push_back(new Enemy()); }
		break;

	default:
		break;
	}

	for (int i = 0; i < enemy_.size(); i++) {
		enemy_[i]->SetPos(
			{
			float(rand() % int(stageSizeX)) - stageSizeX * 0.5f,
			float(rand() % int(stageSizeY)) - stageSizeY * 0.5f
			});
	}

	loadOrder_ = false;
}

void EnemyManager::EraseEnemy() {
	for (int i = 0; i < enemy_.size(); i++) {
		if (!enemy_[i]->GetIsAlive()) {
			enemy_.erase(enemy_.begin() + i);
		}
	}
}
