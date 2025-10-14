#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

struct Mapdate {
	Vector2 position;
	int type;
};

class Map {
public:
	void Initialize();
	void Update();
	void Draw();

private:
	static const int width_ = 10;
	static const int height_ = 10;
	Mapdate map_[width_][height_] = {0};

	Sprite* mapSprite[width_][height_];

	Vector2 mapSize = {50.0f, 50.0f};

	int maptype[width_][height_] = {
	    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	    {2, 1, 1, 1, 1, 1, 1, 1, 1, 2},
	    {2, 1, 1, 1, 1, 1, 1, 1, 1, 2},
	    {2, 1, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 1, 1, 1, 5, 1, 1, 1, 1, 2},
        {2, 1, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 1, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 1, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 1, 1, 1, 1, 1, 1, 1, 1, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
	};

};