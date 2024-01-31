#pragma once
#include "MyFunc.h"

class Player;
class EnemyManager;

class CollisionManager {

public:
	CollisionManager(Player* playerPtr,EnemyManager* emPtr);
	~CollisionManager();

	void Init();
	void Update();
	void Draw();
	void Fin();

private:
	Player* player_;
	EnemyManager* em_;
	int nearEnemy_;

	bool CheckCollision(Vec2 pos1, Vec2 pos2, Vec2 size1, Vec2 size2);
	int GetNearEnemy() { return nearEnemy_; }

};