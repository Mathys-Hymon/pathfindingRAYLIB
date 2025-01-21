#pragma once
#include "iostream"
#include "PathFinding.h"


class MapManager {

public:
	MapManager();
	~MapManager();

	std::vector<Node*> GetNeighbours(Node* _node);

	void Load();
	void Draw();
	void SetNodeType(Vector2D _position, NodeType _type);
	Node* GetNode(Vector2D _position);

private:
	Node* mTiles[MAP_SIZE][MAP_SIZE];
};