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

	float tileSize = GetScreenWidth() / (float)mapImage.height;

	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 20; x++) {

			if (colors[y * mapImage.width + x].g == 255) {
				mTiles[y][x] = new Node({ x * tileSize ,y * tileSize }, { tileSize, tileSize }, NodeType::NORMAL);
			}
			else if (colors[y * mapImage.width + x].b == 255) {
				mTiles[y][x] = new Node({ x * tileSize ,y * tileSize }, { tileSize, tileSize }, NodeType::CHALLENGING);
			}
			else if (colors[y * mapImage.width + x].r == 255) {
				mTiles[y][x] = new Node({ x * tileSize ,y * tileSize }, { tileSize, tileSize }, NodeType::DIFFICULT);
			}
			else if (colors[y * mapImage.width + x].r == 0 && colors[y * mapImage.width + x].g == 0 && colors[y * mapImage.width + x].b == 0) {

				mTiles[y][x] = new Node({ x * tileSize ,y * tileSize }, { tileSize, tileSize }, NodeType::OBSTACLE);
				//spawnPos = { (float)Map[y][x]->GetPosition().x + (Map[y][x]->GetSize() / 2), (float)Map[y][x]->GetPosition().y + (Map[y][x]->GetSize() / 2) };
			}

		}
	}
}

void MapManager::Draw()
{
}
