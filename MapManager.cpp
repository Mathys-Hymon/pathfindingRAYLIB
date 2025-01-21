#include "MapManager.h"

MapManager::MapManager()
{
}

MapManager::~MapManager()
{
}

std::vector<Node*> MapManager::GetNeighbours(Node* _node)
{
	std::vector<Node*> neighbours;

	if (_node->GetPosition().x - 1 >= 0 && mTiles[(int)_node->GetPosition().x - 1][(int)_node->GetPosition().y]->GetType() != NodeType::OBSTACLE)
	{
		neighbours.push_back(mTiles[(int)_node->GetPosition().x - 1][(int)_node->GetPosition().y]);
	}
	if (_node->GetPosition().x + 1 < MAP_SIZE && mTiles[(int)_node->GetPosition().x + 1][(int)_node->GetPosition().y]->GetType() != NodeType::OBSTACLE)
	{
		neighbours.push_back(mTiles[(int)_node->GetPosition().x + 1][(int)_node->GetPosition().y]);
	}
	if (_node->GetPosition().y - 1 >= 0 && mTiles[(int)_node->GetPosition().x][(int)_node->GetPosition().y - 1]->GetType() != NodeType::OBSTACLE)
	{
		neighbours.push_back(mTiles[(int)_node->GetPosition().x][(int)_node->GetPosition().y - 1]);
	}
	if (_node->GetPosition().y + 1 < MAP_SIZE && mTiles[(int)_node->GetPosition().x][(int)_node->GetPosition().y + 1]->GetType() != NodeType::OBSTACLE)
	{
		neighbours.push_back(mTiles[(int)_node->GetPosition().x][(int)_node->GetPosition().y + 1]);
	}

	return neighbours;
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

void MapManager::SetNodeType(Vector2D _position, NodeType _type)
{
	mTiles[(int)_position.x][(int)_position.y]->SetType(_type);
}

Node* MapManager::GetNode(Vector2D _position)
{
	return mTiles[(int)_position.x][(int)_position.y];
}
