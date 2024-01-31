#pragma once
#include "Scene.h"

class Player;
class EnemyManager;
class Stage;
class CollisionManager;

class Scene_Game final : public Scene {

public:

	Scene_Game();
	~Scene_Game();

	void Init() override;
	void Update()override;
	void Draw()override;
	void Fin()override;

private:
	Stage* stage;
	Player* player_;
	EnemyManager* em_;
	CollisionManager* cm_;

	int chapter_;
	int frameCount_;

public:
	int GetChapter()const { return chapter_; }
	int GetFrameCount()const { return frameCount_; }

};