#pragma once
class MyTextureManager {

public:
	MyTextureManager();

public:
	static const int kMaxTexture_ = 32;
	static int texture_[kMaxTexture_];
};

