#include "GameScene.h"


void GameScene::Initialize() {
	map_ = new Map();
	map_->Initialize();
}

void GameScene::Update() { 
	map_->Update();
}

void GameScene::Draw(ID3D12GraphicsCommandList* commandList) { 
	map_->Draw(commandList);
}
