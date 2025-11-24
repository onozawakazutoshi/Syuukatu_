#include "Map.h"

void Map::Initialize() {
	

	

	for (int i = 0; i < height_; i++) {
		for (int j = 0; j < width_; j++) {
			map_[j][i].position = {j * mapSize.x + 640 - width_ * mapSize.x / 2, i * mapSize.y + 360 - height_ * mapSize.y / 2};
			map_[j][i].type = maptype[j][i];
			worldTransform_[i][j].Initialize();
			model_[j][i] = Model::CreateFromOBJ("cube");
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
			worldTransform_[j][i].translation_ = Vector3{map_[j][i].position.x, map_[j][i].position.y, 0};
			worldTransform_[j][i].scale_ = Vector3{2.0f, 2.0f, 2.0f};
			worldTransform_[j][i].UpdateMatrix();
		}
	}
	
}

void Map::Draw(ID3D12GraphicsCommandList* commandList, Camera& camera) { 
	Model::PreDraw(commandList);
	for (int i = 0; i < height_; i++) {
		for (int j = 0; j < width_; j++) {
			model_[j][i]->Draw(worldTransform_[j][i], camera);
		}
	}
	Model::PostDraw();

}