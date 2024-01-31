#include "Bullet.h"
#include "Player.h"

Bullet::Bullet(Player* player) {

	p_camera_ = player->GetCameraPtr();
	pos_ = player->GetPos();
	direction_ = player->GetBulletDirection();
	speed_ = 64.0f;
	size_ = { 16.0f,16.0f };
	isAlive_ = true;
}

Bullet::~Bullet() {
}

void Bullet::Init() {
}

void Bullet::Update() {

	if (isAlive_) {
		pos_ += (direction_ * speed_);

		Vec2 halfRange = Camera2D::GetRange() * 0.5f;

		// 画面外で消える処理
		if (pos_.y > stageLT.y + size_.y * 0.5f) {
			isAlive_ = false;
		} else if (pos_.y < stageRB.y - size_.y * 0.5f) {
			isAlive_ = false;
		}

		if (pos_.x < stageLT.x - size_.x * 0.5f) {
			isAlive_ = false;
		} else if (pos_.x > stageRB.x + size_.x * 0.5f) {
			isAlive_ = false;
		}

		MakeMatrix();

	}
}

void Bullet::Draw() {

	if (isAlive_) {
		Novice::DrawEllipse(
			int(screenPos_.x),
			int(screenPos_.y),
			int(size_.x * 0.5f),
			int(size_.y * 0.5f),
			theta_,
			0xffffffff,
			kFillModeSolid
		);
	}
}

void Bullet::Fin() {
}

void Bullet::MakeMatrix() {
	worldMatrix_ = AffineMatrix(scale_, theta_, pos_);
	screenMatrix_ = WvpVpMatrix(worldMatrix_, p_camera_, { float(kWindowSizeX),float(kWindowSizeY) });
	screenPos_ = Multiply({ 1.0f,1.0f }, screenMatrix_);
}
