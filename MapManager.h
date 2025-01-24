#pragma once
#include "iostream"
#include "PathFinding.h"
#include <thread>


class MapManager {

public:
	MapManager();
	~MapManager();

	void Load();
	void Draw();
	void SetStart(Vector2D _position);
	void SetEnd(Vector2D _position);


private:
	Vector2D mStart, mEnd;
	Node* mTiles[MAP_SIZE][MAP_SIZE];
	PathFinding* mPathFinding;
};