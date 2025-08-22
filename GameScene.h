#pragma once
#include "KamataEngine.h"
#include "Map.cpp"

using namespace KamataEngine;

class GameScene {
public:
	GameScene() {}
	~GameScene() {
	
	}
	void Initialize();
	void Update();
	void Draw(ID3D12GraphicsCommandList* commandList);

private:
	Map* map_ = nullptr;
};
