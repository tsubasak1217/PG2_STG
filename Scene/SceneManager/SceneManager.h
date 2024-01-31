#pragma once
#include "Scene.h"
#include "Scene_Transition.h"

class SceneManager {

public:
	SceneManager(Scene* scene_);
	~SceneManager();

	void Init(Scene* scene);
	void Update();
	void Draw();
	void Fin();

private:
	static bool isTransition_;
	static Scene_Transition* transition_;
	static Scene* scene_;

public:
	static void SetScene(Scene* scene);

};

