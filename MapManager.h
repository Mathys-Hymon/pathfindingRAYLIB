#pragma once
#include <vector>
#include <raylib.h>
#include "Node.h"


class MapManager {

public:
	MapManager();
	~MapManager();

	void Load();
	void Draw();

private:
	Node* mTiles[1073][1073];
};