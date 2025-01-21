#include "Node.h"

Node::Node(Vector2D _position, Vector2D _scale, NodeType _type) : mPosition(_position), mScale(_scale), mType(_type), mParent(nullptr), g(-1), h(-1), f(-1), mColor(WHITE)
{
	SetType(_type);
}

Node::~Node()
{
}

void Node::Draw()
{
	DrawRectangle(mPosition.x, mPosition.y, mScale.x, mScale.y, mColor);
}

int Node::GetDistance(Node* from)
{
	return mPosition.Distance(from->mPosition);
}

NodeType& Node::GetType()
{
	return mType;
}

void Node::SetType(NodeType _type)
{
	mType = _type;

	switch (mType)
	{
	case NodeType::NORMAL:
		mColor = GREEN;
		break;
	case NodeType::CHALLENGING:
		mColor = DARKGREEN;
		break;
	case NodeType::DIFFICULT:
		mColor = YELLOW;
		break;
	case NodeType::OBSTACLE:
		mColor = DARKBLUE;
		break;
	case NodeType::START:
		mColor = RED;
		break;
	case NodeType::END:
		mColor = WHITE;
		break;
	default:
		mColor = DARKBLUE;
		break;
	}
}

void Node::SetParent(Node* _parent)
{
	mParent = _parent;
}
