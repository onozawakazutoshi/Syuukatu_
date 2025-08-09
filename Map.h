#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

struct Mapdate {
	Vector2 position;
	int type;
};

class Map {
public:
	void Initialize();
	void Update();
	void Draw(ID3D12GraphicsCommandList* commandList);

private:
	static const int width_ = 100;
	static const int height_ = 100;
	Mapdate map_[width_][height_] = {0};

	Sprite* mapSprite = nullptr;

	Vector2 mapSize = {10.0f,10.0f};
};
