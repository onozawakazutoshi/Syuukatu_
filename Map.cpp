#include "Map.h"

void Map::Initialize() {
	for (int i = 0; i < width_; i++) {
		for (int j = 0; j < height_; j++) {
			map_[i][j].position = {i * mapSize.x, j * mapSize.y};
			map_[i][j].type = 0;
		}
	}
	
	uint32_t tex = TextureManager::Load("white1x1.png");
	mapSprite=Sprite::Create(tex,{0, 0}, {1, 1, 1, 1}, {0.5, 0.5},true);
	mapSprite->SetTextureHandle(tex);
}

void Map::Update() {
	for (int i = 0; i < width_; i++) {
		for (int j = 0; j < height_; j++) {
			mapSprite->SetPosition(map_[i][j].position);
		}
	}

}

void Map::Draw(ID3D12GraphicsCommandList* commandList) { 
	Sprite::PreDraw(commandList);
	for (int i = 0; i < width_; i++) {
		for (int j = 0; j < height_; j++) {
			if (map_[i][j].type == 0) {
				mapSprite->Draw();
			}
		}
	}
	Sprite::PostDraw();

}