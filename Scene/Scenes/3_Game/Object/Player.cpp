#include "Player.h"
#include "GameManager.h"

Player::Player() {
	Init();
}

Player::~Player() {
	Fin();
}

void Player::Init() {
	pos_ = { 0.0f,0.0f };
	size_ = { float(kWindowSizeX) * 0.05f,float(kWindowSizeX) * 0.05f };
	scale_ = { 1.0f,1.0f };
	theta_ = 0.0f;

	localVertex_[LT] = { -size_.x * 0.5f,  size_.y * 0.5f };
	localVertex_[RT] = { size_.x * 0.5f,  size_.y * 0.5f };
	localVertex_[LB] = { -size_.x * 0.5f, -size_.y * 0.5f };
	localVertex_[RB] = { size_.x * 0.5f, -size_.y * 0.5f };

	p_camera_ = GameManager::camera_;
	reloadCount_ = 1;
	shakeTime_ = 0;
	MakeScreenVertex();
}

void Player::Update() {

	if (shakeTime_ > 0) {
		GameManager::camera_->SetShake({
		float((rand() % shakeTime_) - float(shakeTime_) * 0.5f),
		float((rand() % shakeTime_) - float(shakeTime_) * 0.5f)
		});
		shakeTime_--;
	}

	Move();

	CreateBullet();

	for (int i = 0; i < bullets_.size(); i++) {
		bullets_[i]->Update();
	}

	EraseBullet();

	MakeScreenVertex();
}

void Player::Draw() {

	Novice::DrawQuad(
		int(screenVertex_[0].x), int(screenVertex_[0].y),
		int(screenVertex_[1].x), int(screenVertex_[1].y),
		int(screenVertex_[2].x), int(screenVertex_[2].y),
		int(screenVertex_[3].x), int(screenVertex_[3].y),
		0, 0,
		1, 1,
		MyTextureManager::texture_[0],
		0xffffffff
	);

	for (int i = 0; i < bullets_.size(); i++) {
		bullets_[i]->Draw();
	}
}

void Player::Move() {
	pos_ = InputKey::worldMousePos_;
}

void Player::MakeScreenVertex() {
	worldMatrix_ = AffineMatrix(scale_, theta_, pos_);
	screenMatrix_ = WvpVpMatrix(worldMatrix_, p_camera_, { float(kWindowSizeX),float(kWindowSizeY) });

	for (int i = 0; i < 4; i++) {
		screenVertex_[i] = Multiply(localVertex_[i], screenMatrix_);
	}
}

void Player::CreateBullet() {

	if (reloadCount_) {
		reloadCount_--;

	} else {

		if (InputKey::pressMouse[0]) {

			if (bullets_.size() < Bullet::kMaxBullet_) {
				bullets_.push_back(new Bullet(this));
				reloadCount_ = 5;
				shakeTime_ = 16;
			}
		}
	}
}

void Player::EraseBullet() {
	for (int i = 0; i < bullets_.size(); i++) {
		if (!bullets_[i]->GetIsAlive()) {
			bullets_.erase(bullets_.begin() + i);
		}
	}
}
