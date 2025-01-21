#pragma once
#include <vector>
#include <raylib.h>
#include "iostream"
#include "Node.h"

#define MAP_SIZE 1073

class MapManager {

public:
	MapManager();
	~MapManager();

	void Load();
	void Draw();
	void SetStart(Vector2 _position);
	void SetEnd(Vector2 _position);

private:
	Node* mTiles[MAP_SIZE][MAP_SIZE];
};