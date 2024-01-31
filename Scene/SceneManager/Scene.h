#pragma once
#include <Novice.h>
#include "Environment.h"
#include "InputKey.h"

class Scene {

public:

	Scene();
	virtual ~Scene();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Fin();

protected:
	int sceneNum_;
	bool isChangeScene_;
	bool isGameOver_;

public:
	int GetSceneNum()const { return sceneNum_; }
	bool GetIsChangeScene()const { return isChangeScene_; }
	void SetIsChangeScene(bool flag) { isChangeScene_ = flag; }
	bool GetIsGameOver()const { return isGameOver_; }
	void SetIsGameOver(bool flag) { isGameOver_ = flag; }
};

enum SCENE {
	TITLE,
	GAME,
	CLEAR
};