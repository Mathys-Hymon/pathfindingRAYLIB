#include "MapManager.h"

MapManager::MapManager()
{
}

MapManager::~MapManager()
{
}

void MapManager::Load()
{
	Image mapImage = LoadImage("resources/maps/Map1.png");
	Color* colors = LoadImageColors(mapImage);

	float tileSize = GetScreenWidth() / MAP_SIZE;

	for (int y = 0; y < MAP_SIZE; y++) {
		for (int x = 0; x < MAP_SIZE; x++) {

			if (colors[y * mapImage.width + x].g == 255) {
				mTiles[y][x] = new Node({ x * tileSize ,y * tileSize }, { tileSize, tileSize }, NodeType::NORMAL);
			}
			if (colors[y * mapImage.width + x].b == 255) {
				mTiles[y][x] = new Node({ x * tileSize ,y * tileSize }, { tileSize, tileSize }, NodeType::CHALLENGING);
			}
			if (colors[y * mapImage.width + x].r == 255) {
				mTiles[y][x] = new Node({ x * tileSize ,y * tileSize }, { tileSize, tileSize }, NodeType::DIFFICULT);
			}
			if (colors[y * mapImage.width + x].r == 0 && colors[y * mapImage.width + x].g == 0 && colors[y * mapImage.width + x].b == 0) {

				mTiles[y][x] = new Node({ x * tileSize ,y * tileSize }, { tileSize, tileSize }, NodeType::OBSTACLE);
			}
		}
	}
	UnloadImage(mapImage);
}

void MapManager::Draw()
{
	for (int y = 0; y < MAP_SIZE; y++) {
		for (int x = 0; x < MAP_SIZE; x++) {
			if (mTiles[y][x] != nullptr)
			{
				mTiles[y][x]->Draw();
			}
		}
	}
}

void MapManager::SetStart(Vector2 _position)
{
	mTiles[(int)_position.x][(int)_position.y]->GetType() = NodeType::START;
}

void MapManager::SetEnd(Vector2 _position)
{
	mTiles[(int)_position.x][(int)_position.y]->GetType() = NodeType::END;
}
