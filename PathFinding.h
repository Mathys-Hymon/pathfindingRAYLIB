#pragma once
#include "raylib.h"
#include "Vector2D.h"
#include "vector"
#include "HeuristicsType.h"
#include "Node.h"

#define MAP_SIZE 1073

class PathFinding
{
public:
	PathFinding();
	~PathFinding();

	void AStar(Node* _map[MAP_SIZE][MAP_SIZE], Vector2D _start, Vector2D _end, HeuristicsType _type);
	void Dijsktra(Vector2D _start, Vector2D _end, HeuristicsType _type);

private:
	std::vector<Node*> mOpenList;
	std::vector<Node*> mClosedList;
};