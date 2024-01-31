#pragma once
#include "Enemy.h"
#include "Scene_Game.h"

class EnemyManager {
public:
	EnemyManager(Scene_Game* sceneGame_ptr);
	~EnemyManager();

	void Init(Scene_Game* sceneGame_ptr);
	void Update();
	void Draw();
	void Fin();

private:
	Scene_Game* sceneGame_ptr_;
	std::vector<Enemy*> enemy_;
	bool loadOrder_;

private:
	void Update_Chapter1();
	void Update_Chapter2();
	void Update_Chapter3();

	void LoadEnemy();
	void EraseEnemy();

public:
	std::vector<Enemy*>GetEnemy() { return enemy_; }
};