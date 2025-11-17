#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

struct MapDate {
	Vector2 position;
	int type;
};

class Map {
public:
	void Initialize();
	void Update();
	void Draw();

	Vector2 Getmappos(int x, int y) { return map_[x][y].position; };
	int GetMachineType(int x, int y) { return map_[x][y].type; }
	int GetMapheight() { return height_; }
	int GetMapwidth() { return width_; }

	Vector2 GetMapSize() { return mapSize; }

private:
	static const int width_ = 10;
	static const int height_ = 10;
	MapDate map_[width_][height_] = {0};

	Sprite* mapSprite[width_][height_];

	Vector2 mapSize = {50.0f, 50.0f};

	int maptype[width_][height_] = {
	    {0, 0, 0, 0, 2, 0, 0, 0, 0, 0},
	    {0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 5, 0, 0, 0, 0, 0},
	    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};

};