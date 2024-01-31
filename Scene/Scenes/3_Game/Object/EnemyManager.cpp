#include "EnemyManager.h"

EnemyManager::EnemyManager(Scene_Game* sceneGame_ptr) {
	Init(sceneGame_ptr);
}

EnemyManager::~EnemyManager() {
	Fin();
}

void EnemyManager::Init(Scene_Game* sceneGame_ptr) {
	loadOrder_ = true;
	sceneGame_ptr_ = sceneGame_ptr;
	enemy_.clear();
}

void EnemyManager::Update() {

	LoadEnemy();

	switch (sceneGame_ptr_->GetChapter()) {

	case 1:
		Update_Chapter1();
		break;

	case 2:
		Update_Chapter2();
		break;

	case 3:
		Update_Chapter3();
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

void EnemyManager::Update_Chapter1() {

	for (int i = 0; i < enemy_.size(); i++) {
		enemy_[i]->Update();
	}
}

void EnemyManager::Update_Chapter2() {
}

void EnemyManager::Update_Chapter3() {
}

void EnemyManager::LoadEnemy() {

	if (!loadOrder_) { return; }
	enemy_.clear();

	switch (sceneGame_ptr_->GetChapter()) {
	case 1:
		for (int i = 0; i < 16; i++) { enemy_.push_back(new Enemy());}

		break;

	case 2:
		for (int i = 0; i < 32; i++) { enemy_.push_back(new Enemy()); }
		break;

	case 3:
		for (int i = 0; i < 64; i++) { enemy_.push_back(new Enemy()); }
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
