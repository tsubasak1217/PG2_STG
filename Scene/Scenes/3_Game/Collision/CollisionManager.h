#pragma once
#include "MyFunc.h"

class Player;
class EnemyManager;
class Scene_Game;

class CollisionManager {

public:
	CollisionManager(Player* playerPtr,EnemyManager* emPtr,Scene_Game* p_scene);
	~CollisionManager();

	void Init();
	void Update();
	void Draw();
	void Fin();

private:
	Player* player_;
	EnemyManager* em_;
	Scene_Game* scene_GamePtr;
	int nearEnemy_;
	bool isGameOver_;

	bool CheckCollision(Vec2 pos1, Vec2 pos2, Vec2 size1, Vec2 size2);
	int GetNearEnemy() { return nearEnemy_; }

public:
	bool isGameOver()const { return isGameOver_; }

};