#pragma once
#include "raylib.h"
#include "MapManager.h"
#include "PathFinding.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Load();
	void Update();
	void Draw();

private:
	MapManager* mMapManager;
	float mDelay = 0.0f;
	bool mCanClick = true;

	void ResetCanClick();
};
