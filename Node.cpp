#include "Node.h"

Node::Node(Vector2 _position, Vector2 _scale, NodeType _type) : mPosition(_position), mScale(_scale), mType(_type), mParent(nullptr), g(-1), h(-1), f(-1), mColor(WHITE)
{
	switch (mType)
	{
	case NodeType::NORMAL:
		mColor = GREEN;
		break;
	case NodeType::CHALLENGING:
		mColor = ORANGE;
		break;
	case NodeType::DIFFICULT:
		mColor = RED;
		break;
	case NodeType::OBSTACLE:
		mColor = BLACK;
		break;
	default:
		mColor = BLACK;
		break;
	}
}

Node::~Node()
{
}

void Node::Draw()
{
	DrawRectanglePro({ 0,0,mScale.x,mScale.y }, mPosition, 0, WHITE);
}

int Node::GetDistance(Node* from)
{
	return 0;
}

NodeType& Node::GetType()
{
	return mType;
}
