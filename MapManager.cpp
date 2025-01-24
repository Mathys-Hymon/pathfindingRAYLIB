#include "MapManager.h"

MapManager::MapManager() : mPathFinding(nullptr), mStart({ -1, -1 }), mEnd({ -1, -1 })
{
}

MapManager::~MapManager()
{
}

void MapManager::Load()
{
	Image mapImage = LoadImage("resources/maps/Map3.png");
	Color* colors = LoadImageColors(mapImage);

	int tileSize = GetScreenWidth() / MAP_SIZE;
	std::cout << tileSize;

	for (int y = 0; y < MAP_SIZE; y++) {
		for (int x = 0; x < MAP_SIZE; x++) {

			if (colors[y * mapImage.width + x].g == 255) {
				mTiles[y][x] = new Node({ (float)x ,(float)y }, tileSize, NodeType::NORMAL);
			}
			if (colors[y * mapImage.width + x].b == 255) {
				mTiles[y][x] = new Node({ (float)x ,(float)y }, tileSize, NodeType::CHALLENGING);
			}
			if (colors[y * mapImage.width + x].r == 255) {
				mTiles[y][x] = new Node({ (float)x ,(float)y }, tileSize, NodeType::DIFFICULT);
			}
			if (colors[y * mapImage.width + x].r == 0 && colors[y * mapImage.width + x].g == 0 && colors[y * mapImage.width + x].b == 0) {

				mTiles[y][x] = new Node({ (float)x ,(float)y }, tileSize, NodeType::OBSTACLE);
			}
			else
			{

			}
		}
	}
	UnloadImage(mapImage);

	mPathFinding = new PathFinding();
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

void MapManager::SetStart(Vector2D _position)
{
	mStart = _position;
	mTiles[(int)_position.y][(int)_position.x]->SetType(NodeType::START);

	if (mStart != mEnd && mStart != Vector2D{ -1, -1 } && mEnd != Vector2D{ -1, -1 })
	{
		mPathFinding->AStar(mTiles, mStart, mEnd, HeuristicsType::EUCLIDEAN);
		mStart = { -1, -1 };
		mEnd = { -1, -1 };
	}
}

void MapManager::SetEnd(Vector2D _position)
{
	mEnd = _position;
	mTiles[(int)_position.y][(int)_position.x]->SetType(NodeType::END);

	if (mStart != mEnd && mStart != Vector2D{ -1, -1 } && mEnd != Vector2D{ -1, -1 })
	{
		mPathFinding->AStar(mTiles, mStart, mEnd, HeuristicsType::EUCLIDEAN);
		mStart = { -1, -1 };
		mEnd = { -1, -1 };
	}
}