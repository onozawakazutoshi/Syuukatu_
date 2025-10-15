#include "Map.h"

void Map::Initialize() {
	for (int i = 0; i < width_; i++) {
		for (int j = 0; j < height_; j++) {
			map_[i][j].position = {i * mapSize.x + 640 - width_ * mapSize.x/2, j * mapSize.y + 360 - height_ * mapSize.y/2};
			map_[i][j].type = maptype[i][j];
		}
	}
	
	uint32_t tex = TextureManager::Load("Sprit/white1x1.png");
	for (int i = 0; i < width_; i++) {
		for (int j = 0; j < height_; j++) {
			if (map_[i][j].type == 1) {
				mapSprite[i][j] = Sprite::Create(tex, {0, 0}, {1, 1, 1, 1}, {0.5, 0.5}, true);
				mapSprite[i][j]->SetTextureHandle(tex);
			}
			if (map_[i][j].type == 2) {
				mapSprite[i][j] = Sprite::Create(tex, {0, 0}, {0, 0, 0, 1}, {0.5, 0.5}, true);
				mapSprite[i][j]->SetTextureHandle(tex);
			}
			if (map_[i][j].type == 5) {
				mapSprite[i][j] = Sprite::Create(tex, {0, 0}, {0, 0, 1, 1}, {0.5, 0.5}, true);
				mapSprite[i][j]->SetTextureHandle(tex);
			}
		}
	}
}

void Map::Update() {
	for (int i = 0; i < width_; i++) {
		for (int j = 0; j < height_; j++) {
			mapSprite[i][j]->SetPosition(map_[i][j].position);
			mapSprite[i][j]->SetSize({mapSize.x-1, mapSize.y-1});
		}
	}

}

void Map::Draw() { 
	
	for (int i = 0; i < width_; i++) {
		for (int j = 0; j < height_; j++) {
			mapSprite[i][j]->Draw();
		}
	}

}