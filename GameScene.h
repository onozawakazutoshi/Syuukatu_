#pragma once
#include "KamataEngine.h"
#include "Map.h"

using namespace KamataEngine;

class GameScene {
public:
	
	void Initialize();
	void Update();
	void Draw(ID3D12GraphicsCommandList* commandList);

private:
	Map* map_ = new Map();
	
};
