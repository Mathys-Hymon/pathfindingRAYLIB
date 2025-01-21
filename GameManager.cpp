#include "GameManager.h"

GameManager::GameManager() : mapManager(nullptr)
{
}

GameManager::~GameManager()
{
}

void GameManager::Load()
{
	mapManager = new MapManager();
	mapManager->Load();
}

void GameManager::Update()
{
	Vector2 mousePosition = GetMousePosition();

	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
	}
}

void GameManager::Draw()
{
	mapManager->Draw();
}
