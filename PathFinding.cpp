#include "PathFinding.h"

PathFinding::PathFinding()
{
}

PathFinding::~PathFinding()
{
}

void PathFinding::AStar(Node* _map[MAP_SIZE][MAP_SIZE], Vector2D _start, Vector2D _end, HeuristicsType _type)
{
	Node* startNode = _map[_start.x][_start.y];
	Node* endNode = _map[_end.x][_end.y];

	startNode->SetType(NodeType::START);
	endNode->SetType(NodeType::END);

	mOpenList.clear();
	mClosedList.clear();

	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			if (i != _start.x && j != _start.y && i != _end.x && j != _end.y) 
			{
				Node* tempNode = _map[i][j];

				mOpenList.push_back(tempNode);
				if (tempNode->GetType() != NodeType::OBSTACLE)
				{
					tempNode->SetGCost(inf);
					tempNode->SetHCost(inf);
					tempNode->SetParent(nullptr);
				}
			}
		}
	}
	Node* currentNode = startNode;

	while (currentNode != endNode)
	{
		int lowestCost = inf;
		int nearestNode = -1;

		for (int i = 0; i < mOpenList.size(); i++)
		{
			if (mOpenList[i]->GetFCost() <= lowestCost)
			{
				if (mOpenList[i]->GetFCost() == lowestCost)
				{
					if (mOpenList[i]->GetHCost() < mOpenList[nearestNode]->GetHCost())
					{
						nearestNode = i;
						lowestCost = mOpenList[i]->GetFCost();
					}
				}
				else
				{
					nearestNode = i;
					lowestCost = mOpenList[i]->GetFCost();
				}
			}
		}
		Node* u = mOpenList[nearestNode];
		mOpenList.erase(mOpenList.begin() + nearestNode);



	}



}