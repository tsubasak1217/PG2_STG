#include "Stage.h"
#include "GameManager.h"
#include "MyTextureManager.h"
#include "Object.h"

Stage::Stage() {
	Init();
}

Stage::~Stage() {
}

void Stage::Init() {

	scale_ = { 1.0f,1.0f };
	theta_ = 0.0f;

	localVertex_[LT] = stageLT;
	localVertex_[RT] = { stageRB.x,stageLT.y };
	localVertex_[LB] = { stageLT.x,stageRB.y };
	localVertex_[RB] = stageRB;

	worldMatrix_ = AffineMatrix(scale_, theta_, { 0.0f,0.0f });
	screenMatrix_ = WvpVpMatrix(worldMatrix_, GameManager::camera_, { float(kWindowSizeX),float(kWindowSizeY) });

	for (int i = 0; i < 4; i++) {
		screenVertex_[i] = Multiply(localVertex_[i], screenMatrix_);
		scrV[i] = screenVertex_[i];
	}
}

void Stage::Update() {
	worldMatrix_ = AffineMatrix(scale_, theta_, { 0.0f,0.0f });
	screenMatrix_ = WvpVpMatrix(worldMatrix_, GameManager::camera_, { float(kWindowSizeX),float(kWindowSizeY) });

	for (int i = 0; i < 4; i++) {
		screenVertex_[i] = Multiply(localVertex_[i], screenMatrix_);
	}
}

void Stage::Draw() {

	Novice::DrawBox(
		0, 0,
		kWindowSizeX, kWindowSizeY,
		0.0f,
		0x000000ff,
		kFillModeSolid
	);

	Novice::DrawQuad(
		int(screenVertex_[0].x), int(screenVertex_[0].y),
		int(screenVertex_[1].x), int(screenVertex_[1].y),
		int(screenVertex_[2].x), int(screenVertex_[2].y),
		int(screenVertex_[3].x), int(screenVertex_[3].y),
		0, 0,
		4096, 2304,
		MyTextureManager::texture_[1],
		0x7f7f7f7f
	);
}

void Stage::Fin() {
}
