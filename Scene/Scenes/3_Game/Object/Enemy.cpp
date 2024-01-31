#include "Enemy.h"
#include "GameManager.h"

Enemy::Enemy() {
	size_.x = float(rand()%64 + 64);
	size_.y = size_.x;
	scale_ = { 1.0f,1.0f };
	theta_ = 0.0f;
	isAlive_ = true;

	localVertex_[LT] = { -size_.x * 0.5f,  size_.y * 0.5f };
	localVertex_[RT] = { size_.x * 0.5f,  size_.y * 0.5f };
	localVertex_[LB] = { -size_.x * 0.5f, -size_.y * 0.5f };
	localVertex_[RB] = { size_.x * 0.5f, -size_.y * 0.5f };

	direction_ = {
		Normalize(
			{0.0f,0.0f},
			{float(rand() % 1028 - 512),float(rand() % 1028 - 512)}
		)
	};

	speed_ = float(rand() % 6 + 1);

	HP_ = 3;
}

Enemy::~Enemy() {
}

void Enemy::Init() {
	localVertex_[LT] = { -size_.x * 0.5f,  size_.y * 0.5f };
	localVertex_[RT] = { size_.x * 0.5f,  size_.y * 0.5f };
	localVertex_[LB] = { -size_.x * 0.5f, -size_.y * 0.5f };
	localVertex_[RB] = { size_.x * 0.5f, -size_.y * 0.5f };
}

void Enemy::Update() {
	MakeMatrix();

	pos_ += direction_ * speed_;

	if (pos_.x < (GameManager::camera_->GetRange().x * 4.0f) * - 0.5f + size_.x * 0.5f) {
		pos_.x = (GameManager::camera_->GetRange().x * 4.0f) * -0.5f + size_.x * 0.5f;
		direction_.x *= -1.0f;

	} else if (pos_.x > (GameManager::camera_->GetRange().x * 4.0f) * 0.5f - size_.x * 0.5f) {
		pos_.x = (GameManager::camera_->GetRange().x * 4.0f) * 0.5f - size_.x * 0.5f;
		direction_.x *= -1.0f;
	}

	if (pos_.y < (GameManager::camera_->GetRange().y * 4.0f) * -0.5f + size_.y * 0.5f) {
		pos_.y = (GameManager::camera_->GetRange().y * 4.0f) * -0.5f + size_.y * 0.5f;
		direction_.y *= -1.0f;

	} else if (pos_.y > (GameManager::camera_->GetRange().y * 4.0f) * 0.5f - size_.y * 0.5f) {
		pos_.y = (GameManager::camera_->GetRange().y * 4.0f) * 0.5f - size_.y * 0.5f;
		direction_.y *= -1.0f;
	}

	if (HP_ <= 0) {
		isAlive_ = false;
	}
}

void Enemy::Draw() {
	if (isAlive_) {

		Novice::SetBlendMode(kBlendModeSubtract);
		for (int i = 0; i < 10; i++) {

			My::DrawQuad(
				Multiply({ 0.0f,0.0f }, WvpVpMatrix(AffineMatrix(scale_, theta_, pos_), GameManager::camera_, { float(kWindowSizeX),float(kWindowSizeY) })),
				(size_ + (12.0f * i)) * GameManager::camera_->GetScale(),
				0, 0,
				240, 240,
				1.0f, 1.0f,
				MyTextureManager::texture_[2],
				0.0f,
				0xd6274700 + (0x02 * i)
			);
		}
		Novice::SetBlendMode(kBlendModeNormal);

		Novice::DrawQuad(
			int(screenVertex_[0].x), int(screenVertex_[0].y),
			int(screenVertex_[1].x), int(screenVertex_[1].y),
			int(screenVertex_[2].x), int(screenVertex_[2].y),
			int(screenVertex_[3].x), int(screenVertex_[3].y),
			0, 0,
			1, 1,
			MyTextureManager::texture_[0],
			0xff0000ff
		);


	}
}

void Enemy::Fin() {
}

void Enemy::MakeMatrix() {
	worldMatrix_ = AffineMatrix(scale_, theta_, pos_);
	screenMatrix_ =
		WvpVpMatrix(worldMatrix_, GameManager::camera_, { float(kWindowSizeX),float(kWindowSizeY) });
	screenPos_ = Multiply({0.0f,0.0f}, screenMatrix_);

	for (int i = 0; i < 4; i++) {
		screenVertex_[i] = Multiply(localVertex_[i], screenMatrix_);
	}
}
