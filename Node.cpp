#include "Node.h"

Node::Node(Vector2D _position, int _scale, NodeType _type) : mPosition(_position), mScale(_scale), mType(_type), mParent(nullptr), g(inf), h(inf), mWeight(1), mColor(WHITE)
{
	SetType(_type);
}

Node::~Node()
{
}

void Node::Draw()
{
	DrawRectangle((mPosition.x * mScale), (mPosition.y * mScale), mScale, mScale, mColor);
}

float Node::GetDistance(Node* from)
{
	return mPosition.Distance(from->mPosition);
}

NodeType& Node::GetType()
{
	return mType;
}

void Node::SetGCost(float _g)
{
	g = _g;
}

void Node::SetHCost(float _h)
{
	h = _h;
	f = (g + h);
}

float Node::GetGCost()
{
	return g * mWeight;
}

float Node::GetHCost()
{
	return h;
}

float Node::GetFCost()
{
	return f;
}

Node* Node::GetParent()
{
	return mParent;
}

void Node::SetType(NodeType _type)
{
	switch (_type)
	{
	case NodeType::NORMAL:
		mColor = GREEN;
		mOldType = mType;
		mWeight = 1;
		break;
	case NodeType::CHALLENGING:
		mColor = DARKGREEN;
		mOldType = mType;
		mWeight = 1.2;
		break;
	case NodeType::DIFFICULT:
		mColor = YELLOW;
		mOldType = mType;
		mWeight = 1.5;
		break;
	case NodeType::OBSTACLE:
		mColor = BLACK;
		mWeight = 99;
		mOldType = mType;
		break;
	case NodeType::START:
		mColor = RED;
		mOldType = mType;
		break;
	case NodeType::END:
		mColor = WHITE;
		mOldType = mType;
		break;
	case NodeType::PATH:
		mColor = WHITE;
		break;
	case NodeType::SEARCHED:

		switch (mOldType)
		{
		case NodeType::NORMAL:
			mColor = GRAY;
			break;

		case NodeType::CHALLENGING :
			mColor = DARKGRAY;
			break;

		case NodeType::DIFFICULT:
			mColor = DARKBROWN;
			break;
		}

		break;

	default:
		mColor = DARKBLUE;
		mWeight = 99;
		break;
	}
	mType = _type;
}

void Node::SetParent(Node* _parent)
{
	mParent = _parent;
}
