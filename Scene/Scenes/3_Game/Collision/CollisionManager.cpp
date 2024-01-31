#include "CollisionManager.h"
#include "Player.h"
#include "EnemyManager.h"

CollisionManager::CollisionManager(Player* playerPtr, EnemyManager* emPtr) {
	player_ = playerPtr;
	em_ = emPtr;
}

CollisionManager::~CollisionManager() {
}

void CollisionManager::Init() {
}

void CollisionManager::Update() {

	for (int i = 0; i < player_->GetBullet().size(); i++) {
		for (int j = 0; j < em_->GetEnemy().size(); j++) {

			// 敵と弾の当たり判定
			if (CheckCollision(
				player_->GetBullet()[i]->GetPos(),
				em_->GetEnemy()[j]->GetPos(),
				player_->GetBullet()[i]->GetSize(),
				em_->GetEnemy()[j]->GetSize()
			)) {
				em_->GetEnemy()[j]->SetHP(em_->GetEnemy()[j]->GetHP() - 1);
			}
		}
	}

	float distance = 100000;
	nearEnemy_ = -1;
	for (int i = 0; i < em_->GetEnemy().size(); i++) {

		if (distance > CheckLength(player_->GetPos(), em_->GetEnemy()[i]->GetPos())) {
			distance = CheckLength(player_->GetPos(), em_->GetEnemy()[i]->GetPos());
			nearEnemy_ = i;

			// ゲームオーバー
			if (distance < player_->GetSize().x * 0.5f + em_->GetEnemy()[i]->GetSize().x * 0.5f) {

			}
		}
	}

	if (nearEnemy_ >= 0) {
		player_->SetBulletDirection(Normalize(em_->GetEnemy()[nearEnemy_]->GetPos(), player_->GetPos()));
	} else {
		player_->SetBulletDirection({ 0.0f,1.0f });
	}
}

void CollisionManager::Draw() {
}

void CollisionManager::Fin() {
}

bool CollisionManager::CheckCollision(Vec2 pos1, Vec2 pos2, Vec2 size1, Vec2 size2) {

	return CheckLength(pos1, pos2) <= (size1.x * 0.5f + size2.x * 0.5f);
}
