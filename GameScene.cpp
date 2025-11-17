#include "GameScene.h"


void GameScene::Initialize() {
	map_->Initialize();
	enemy_->Initialize(map_);
}

void GameScene::Update() { 
	map_->Update();
	enemy_->Updete();
}

void GameScene::Draw(ID3D12GraphicsCommandList* commandList) { 
	Sprite::PreDraw(commandList);
	map_->Draw();
	
	enemy_->Drow();
	Sprite::PostDraw();
	
}
