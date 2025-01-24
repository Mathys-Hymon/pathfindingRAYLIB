#include "PathFinding.h"

PathFinding::PathFinding()
{
}

PathFinding::~PathFinding()
{
}

void PathFinding::Draw(Node* _map[MAP_SIZE][MAP_SIZE], Node* currentNode)
{
	int totalNode = 0;
	Node* pathNode = currentNode;
	while (pathNode != nullptr) {
		totalNode++;
		pathNode->SetType(NodeType::PATH);
		pathNode = pathNode->GetParent();
	}
	BeginDrawing();
	for (int y = 0; y < MAP_SIZE; y++) {
		for (int x = 0; x < MAP_SIZE; x++) {
			if (_map[y][x] != nullptr)
			{
				_map[y][x]->Draw();
			}
		}
	}
	EndDrawing();
	//std::cout << "Node amount : " << totalNode << " | cost : " << currentNode->GetGCost() << std::endl;
	pathNode = currentNode;
	while (pathNode != nullptr) {
		pathNode->SetType(NodeType::SEARCHED);
		pathNode = pathNode->GetParent();
	}
}

void PathFinding::AStar(Node* _map[MAP_SIZE][MAP_SIZE], Vector2D& _start, Vector2D& _end, HeuristicsType _type)
{
	std::cout << "START AT : " << _start.x << " X | " << _start.y << " Y" << std::endl;
	std::cout << "END AT : " << _end.x << " X | " << _end.y << " Y" << std::endl;

	mOpenList.clear();
	mClosedList.clear();


	Node* startNode = _map[(int)_start.y][(int)_start.x];
	Node* endNode = _map[(int)_end.y][(int)_end.x];


	startNode->SetGCost(0);
	startNode->SetHCost(CalculateHeuristic(_start, _end, _type));
	mOpenList.push_back(startNode);

	while (!mOpenList.empty()) {

		Node* currentNode = *std::min_element(mOpenList.begin(), mOpenList.end(), [](Node* a, Node* b) {
			return a->GetFCost() < b->GetFCost() || (a->GetFCost() == b->GetFCost() && a->GetHCost() < b->GetHCost());
			});

		if (currentNode == endNode) {
		Node* pathNode = currentNode;
		while (pathNode != nullptr) {
			pathNode->SetType(NodeType::PATH);
			pathNode = pathNode->GetParent();
		}
		break;
		}


		mOpenList.erase(std::remove(mOpenList.begin(), mOpenList.end(), currentNode), mOpenList.end());
		mClosedList.push_back(currentNode);

		Draw(_map,currentNode);


		std::vector<Vector2D> directions = { {1, 1}, { 0, 1}, {-1, 1}, 
			                                 {1, 0},          {-1, 0},
			                                 {1,-1}, { 0,-1}, {-1,-1} };
		for (auto& dir : directions) {
			int neighborX = currentNode->GetPosition().x + dir.x;
			int neighborY = currentNode->GetPosition().y + dir.y;


			if (neighborX < 0 || neighborX >= MAP_SIZE || neighborY < 0 || neighborY >= MAP_SIZE)
				continue;

			Node* neighbor = _map[neighborY][neighborX];

			if (neighbor == nullptr)
				continue;
			if (neighbor->GetType() == NodeType::OBSTACLE || std::find(mClosedList.begin(), mClosedList.end(), neighbor) != mClosedList.end())
				continue;


			int tentativeGCost = currentNode->GetGCost() + (currentNode->GetDistance(neighbor) * 10);

			if (tentativeGCost < neighbor->GetGCost() || std::find(mOpenList.begin(), mOpenList.end(), neighbor) == mOpenList.end()) {
				neighbor->SetGCost(tentativeGCost);
				neighbor->SetHCost(CalculateHeuristic(neighbor->GetPosition(), _end, _type));
				neighbor->SetParent(currentNode);


				if (std::find(mOpenList.begin(), mOpenList.end(), neighbor) == mOpenList.end()) {
					mOpenList.push_back(neighbor);
				}

				currentNode->SetType(NodeType::SEARCHED);
			}
		}
	}
}

void PathFinding::Dijsktra(Node* _map[MAP_SIZE][MAP_SIZE], Vector2D _start, Vector2D _end, HeuristicsType _type)
{
	Node* startNode = _map[(int)_start.x][(int)_start.y];
	Node* endNode = _map[(int)_end.x][(int)_end.y];

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

float PathFinding::CalculateHeuristic(Vector2D a, Vector2D b, HeuristicsType _type)
{
	if (_type == HeuristicsType::MANHATTAN) {
		return std::abs(a.x - b.x) + std::abs(a.y - b.y) * 10;
	}
	else if (_type == HeuristicsType::EUCLIDEAN) {
		return a.Distance(b) * 10;
	}
	return 0;
}
