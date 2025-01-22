#include "MapManager.h"

MapManager::MapManager() : mPathFinding(nullptr), mStart({ -1, -1 }), mEnd({ -1, -1 })
{
}

MapManager::~MapManager()
{
}

void MapManager::Load()
{
	Image mapImage = LoadImage("resources/maps/Map2.png");
	Color* colors = LoadImageColors(mapImage);

	int tileSize = GetScreenWidth() / MAP_SIZE;

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
	std::string temps;

	switch (mTiles[_position.x][_position.y]->GetType())
	{
	case NodeType::NORMAL:
		temps = "NORMAL";
		break;
	case NodeType::CHALLENGING:
		temps = "CHALLENGING";
		break;
	case NodeType::DIFFICULT:
		temps = "DIFFICULT";
		break;
	case NodeType::OBSTACLE:
		temps = "OBSTACLE";
		break;
	default:
		break;
	};
	std::cout << temps << std::endl;

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

	if (mStart != mEnd && mStart != Vector2D{ -1, -1 } && mEnd != Vector2D{ -1, -1 })
	{
		mPathFinding->AStar(mTiles, mStart, mEnd, HeuristicsType::EUCLIDEAN);
		mStart = { -1, -1 };
		mEnd = { -1, -1 };
	}
}

//void MapManager::SetNodeType(Vector2D _position, NodeType _type)
//{
//	mTiles[(int)_position.x][(int)_position.y]->SetType(_type);
//}

//Node* MapManager::GetNode(Vector2D _position)
//{
//	return mTiles[(int)_position.x][(int)_position.y];
//}
