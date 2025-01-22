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
	return g + mWeight;
}

int Node::GetHCost()
{
	return h;
}

int Node::GetFCost()
{
	return (g + h);
}

Node* Node::GetParent()
{
	return mParent;
}

void Node::SetType(NodeType _type)
{
	//std::cout << "CHANGE TYPE" << std::endl;
	switch (_type)
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
		mColor = BLACK;
		mWeight = 99;
		break;
	case NodeType::START:
		mColor = RED;
		break;
	case NodeType::END:
		mColor = WHITE;
		break;
	case NodeType::PATH:
		mColor = WHITE;
		break;
	case NodeType::SEARCHED:

		switch (mType)
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
