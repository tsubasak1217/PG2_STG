#pragma once
#include <Novice.h>
#include "SceneManager.h"
#include "Camera.h"

class GameManager {

public:
	GameManager(SceneManager* sceneManager);
	~GameManager();

	static void Init(SceneManager* sceneManager);
	static void Update();
	static void Draw();
	static void Run();
	static void Finalize();

public:
	static Camera2D* camera_;

private:
	static SceneManager* sceneManager_;
};

