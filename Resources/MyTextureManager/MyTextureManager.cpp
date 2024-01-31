#include "MyTextureManager.h"
#include <Novice.h>

int MyTextureManager::texture_[kMaxTexture_] = {0};

MyTextureManager::MyTextureManager() {
	texture_[0] = Novice::LoadTexture("white1x1.png");
	texture_[1] = Novice::LoadTexture("./Resources/Images/hexagon.png");
	texture_[2] = Novice::LoadTexture("./Resources/Images/ellipse.png");
	texture_[3] = Novice::LoadTexture("./Resources/Images/title.png");
	texture_[4] = Novice::LoadTexture("./Resources/Images/CLEAR.png");
}
