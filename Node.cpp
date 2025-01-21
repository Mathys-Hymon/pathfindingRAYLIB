#include "Node.h"

Node::Node(Vector2D _position, Vector2D _scale, NodeType _type) : mPosition(_position), mScale(_scale), mType(_type), mParent(nullptr), g(inf), h(inf), mWeight(1), mColor(WHITE)
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

void Node::SetGCost(int _g)
{
	g = _g;
}

void Node::SetHCost(int _h)
{
	h = _h;
}

int Node::GetGCost()
{
	return g * mWeight;
}

int Node::GetHCost()
{
	return h * mWeight;
}

int Node::GetFCost()
{
	return (g + h) * mWeight;
}

Node* Node::GetParent()
{
	return mParent;
}

void Node::SetType(NodeType _type)
{
	mType = _type;

	switch (mType)
	{
	case NodeType::NORMAL:
		mColor = GREEN;
		mWeight = 1;
		break;
	case NodeType::CHALLENGING:
		mColor = DARKGREEN;
		mWeight = 2;
		break;
	case NodeType::DIFFICULT:
		mColor = YELLOW;
		mWeight = 3;
		break;
	case NodeType::OBSTACLE:
		mColor = DARKBLUE;
		mWeight = 99;
		break;
	case NodeType::START:
		mColor = RED;
		break;
	case NodeType::END:
		mColor = WHITE;
		break;
	default:
		mColor = DARKBLUE;
		mWeight = 99;
		break;
	}
}

void Node::SetParent(Node* _parent)
{
	mParent = _parent;
}
