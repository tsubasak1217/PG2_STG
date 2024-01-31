#pragma once
#include "Scene.h"

class Scene_Transition final : public Scene {

public:

	Scene_Transition();
	~Scene_Transition();

	void Init() override;
	void Update()override;
	void Draw()override;
	void Fin()override;

private:
	int inFrame_;
	int outFrame_;
	int alpha_;
	bool isReturn_;

public:
	int GetInFrame()const { return inFrame_; }
	int GetOutFrame()const { return outFrame_; }
	bool GetIsReturn()const { return isReturn_; }
};

