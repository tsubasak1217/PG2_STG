#include "GameManager.h"
#include "SceneManager.h"
#include "Environment.h"
#include "InputKey.h"

#include "Scene_Title.h"
#include "Scene_Select.h"
#include "Scene_Clear.h"
#include "Scene_Game.h"
#include "Scene_Transition.h"

#include "MyTextureManager.h"

SceneManager* GameManager::sceneManager_ = nullptr;
Camera2D* GameManager::camera_ = nullptr;

//--------------------------------------------------------------------------------
GameManager::GameManager(SceneManager* sceneManager) {
	Init(sceneManager);
}

GameManager::~GameManager() {
}

//--------------------------------------------------------------------------------
void GameManager::Init(SceneManager* sceneManager) {
	sceneManager_ = sceneManager;
}

//--------------------------------------------------------------------------------
void GameManager::Update() {
	sceneManager_->Update();
}

//--------------------------------------------------------------------------------
void GameManager::Draw() {
	sceneManager_->Draw();
}

//--------------------------------------------------------------------------------
void GameManager::Finalize() {

}

//--------------------------------------------------------------------------------
void GameManager::Run() {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowSizeX, kWindowSizeY);

	camera_ = new Camera2D(// カメラのインスタンス作成
		{ 0.0f,0.0f },// pos
		{ float(kWindowSizeX),float(kWindowSizeY) }// cameraRange
	);

	MyTextureManager* tx = new MyTextureManager();
	tx;

	// ゲームマネージャーのインスタンス作成
	GameManager gameManager(new SceneManager(new Scene_Title));

	unsigned int currentTime = unsigned int(time(nullptr));
	srand(currentTime);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		// キー入力を受け取る
		memcpy(InputKey::preKeys, InputKey::keys, 256);
		Novice::GetHitKeyStateAll(InputKey::keys);

		InputKey::Update();// 自分用にトリガーやリリースを取得するクラス
		camera_->Update();

		// ゲームマネージャー自身の処理
		Update();
		Draw();

		// フレームの終了
		Novice::EndFrame();
	}

	// ライブラリの終了
	Finalize();
	Novice::Finalize();
}

