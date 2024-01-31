#pragma once
#include "VectorN.h"
const char kWindowTitle[] = "LC1A_14_クロカワツバサ_PG2_STG";
const int kWindowSizeX = 1280;
const int kWindowSizeY = 720;

const float stageSizeX = 6400.0f;
const float stageSizeY = 3600.0f;
const  Vec2 stageLT = { stageSizeX * -0.5f,stageSizeY * 0.5f };
const  Vec2 stageRB = { stageSizeX * 0.5f,stageSizeY * -0.5f };

static Vec2 scrV[4];