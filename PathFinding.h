#pragma once
#include "raylib.h"
#include "Vector2D.h"
#include "vector"
#include "HeuristicsType.h"
#include <iostream>
#include "Node.h"

#define MAP_SIZE 128

class PathFinding
{
public:
	PathFinding();
	~PathFinding();

	void Draw(Node* _map[MAP_SIZE][MAP_SIZE]);

	void AStar(Node* _map[MAP_SIZE][MAP_SIZE], Vector2D _start, Vector2D _end, HeuristicsType _type);
	void Dijsktra(Node* _map[MAP_SIZE][MAP_SIZE], Vector2D _start, Vector2D _end, HeuristicsType _type);

private:
	std::vector<Node*> mOpenList;
	std::vector<Node*> mClosedList;

	Node* mEndNode;

	Vector2D mStart, mEnd;

	float mPathDelay = 0;

	int CalculateHeuristic(Vector2D a, Vector2D b, HeuristicsType _type);
};