#pragma once
#include "raylib.h"
#include "MapManager.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Load();
	void Update();
	void Draw();

private:
	MapManager* mapManager;
};
