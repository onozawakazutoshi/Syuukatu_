#include "GameScene.h"


void GameScene::Initialize() {
	map_->Initialize();
}

void GameScene::Update() { 
	map_->Update();
}

void GameScene::Draw(ID3D12GraphicsCommandList* commandList) { 
	Sprite::PreDraw(commandList);
	map_->Draw();
	Sprite::PostDraw();
	
}
