#include "GameManager.h"

GameManager::GameManager() : mMapManager(nullptr)
{
}

GameManager::~GameManager()
{
}

void GameManager::Load()
{
	mMapManager = new MapManager();
	mMapManager->Load();
}

void GameManager::Update()
{
	Vector2D mousePosition = { (int)GetMousePosition().x, (int)GetMousePosition().y};

	if (!mCanClick)
	{
		ResetCanClick();
	}
	else 
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			//std::cout << "START AT : " << mousePosition.x / ((int)GetScreenWidth() / MAP_SIZE) << " X | " << mousePosition.y / ((int)GetScreenHeight() / MAP_SIZE) << " Y" << std::endl;
			mMapManager->SetStart({ mousePosition.x / ((int)GetScreenWidth() / MAP_SIZE), mousePosition.y / ((int)GetScreenHeight() / MAP_SIZE) });
		}
		else if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
		{
		//	std::cout << "END AT : " << mousePosition.x / ((int)GetScreenWidth() / MAP_SIZE) << " X | " << mousePosition.y / ((int)GetScreenHeight() / MAP_SIZE) << " Y" << std::endl;
			mMapManager->SetEnd({ mousePosition.x / ((int)GetScreenWidth() / MAP_SIZE), mousePosition.y / ((int)GetScreenHeight() / MAP_SIZE) });
		}
	}

}

void GameManager::Draw()
{
	mMapManager->Draw();
}

void GameManager::ResetCanClick()
{
	if(mDelay <= 1.0)
	{
		mDelay += GetFrameTime();
	}
	else
	{
		mCanClick = true;
		mDelay = 0;
	}
}
