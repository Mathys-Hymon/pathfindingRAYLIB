#include "PathFinding.h"

PathFinding::PathFinding()
{
}

PathFinding::~PathFinding()
{
}

void PathFinding::Draw(Node* _map[MAP_SIZE][MAP_SIZE])
{
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
}

void PathFinding::AStar(Node* _map[MAP_SIZE][MAP_SIZE], Vector2D _start, Vector2D _end, HeuristicsType _type)
{
	std::cout << "ASTAR STARTED" << std::endl;
	std::cout << "START AT : " << _start.x << " X | " << _start.y << " Y" << std::endl;
	std::cout << "END AT : " << _end.x << " X | " << _end.y << " Y" << std::endl;

	mOpenList.clear();
	mClosedList.clear();


	Node* startNode = _map[_start.y][_start.x];
	Node* endNode = _map[_end.y][_end.x];


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

		Draw(_map);


		std::vector<Vector2D> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1,1}, {-1,1}, { 1,-1 }, {-1,-1} };
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


			int tentativeGCost = currentNode->GetGCost() + currentNode->GetDistance(neighbor);

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


	std::cout << "ASTAR FINISHED" << std::endl;

}

void PathFinding::Dijsktra(Node* _map[MAP_SIZE][MAP_SIZE], Vector2D _start, Vector2D _end, HeuristicsType _type)
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

int PathFinding::CalculateHeuristic(Vector2D a, Vector2D b, HeuristicsType _type)
{
	if (_type == HeuristicsType::MANHATTAN) {
		return std::abs(a.x - b.x) + std::abs(a.y - b.y);
	}
	else if (_type == HeuristicsType::EUCLIDEAN) {
		return static_cast<int>(std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
	}
	return 0;
}
