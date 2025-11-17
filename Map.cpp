#include "Map.h"

void Map::Initialize() {
	for (int i = 0; i < height_; i++) {
		for (int j = 0; j < width_; j++) {
			map_[j][i].position = {j * mapSize.x + 640 - width_ * mapSize.x / 2, i * mapSize.y + 360 - height_ * mapSize.y / 2};
			map_[j][i].type = maptype[j][i];
		}
	}
	
	uint32_t tex = TextureManager::Load("white1x1.png");
	for (int i = 0; i < height_; i++) {
		for (int j = 0; j < width_; j++) {
			if (map_[j][i].type == 0) {
				mapSprite[j][i] = Sprite::Create(tex, {0, 0}, {1, 1, 1, 1}, {0.5, 0.5}, true);
				mapSprite[j][i]->SetTextureHandle(tex);
			}
			if (map_[j][i].type == 1) {
				mapSprite[j][i] = Sprite::Create(tex, {0, 0}, {1, 0, 1, 1}, {0.5, 0.5}, true);
				mapSprite[j][i]->SetTextureHandle(tex);
			}
			if (map_[j][i].type == 2) {
				mapSprite[j][i] = Sprite::Create(tex, {0, 0}, {0, 0, 0, 1}, {0.5, 0.5}, true);
				mapSprite[j][i]->SetTextureHandle(tex);
			}
			if (map_[j][i].type == 5) {
				mapSprite[j][i] = Sprite::Create(tex, {0, 0}, {0, 0, 1, 1}, {0.5, 0.5}, true);
				mapSprite[j][i]->SetTextureHandle(tex);
			}
		}
	}
}

void Map::Update() {
	for (int i = 0; i < height_; i++) {
		for (int j = 0; j < width_; j++) {
			mapSprite[j][i]->SetPosition(map_[j][i].position);
			mapSprite[j][i]->SetSize({mapSize.x-1, mapSize.y-1});
		}
	}

}

void Map::Draw() { 
	
	for (int i = 0; i < height_; i++) {
		for (int j = 0; j < width_; j++) {
			mapSprite[i][j]->Draw();
		}
	}

}