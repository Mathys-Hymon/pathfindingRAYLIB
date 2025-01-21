#pragma once
#include "Vector2D.h"
#include "raylib.h"
#include "NodeType.h"

class Node
{
public:

	Node(Vector2D _position, Vector2D _scale, NodeType _type);
	~Node();

	void Draw();
	int GetDistance(Node* from);
	NodeType& GetType();
	void SetType(NodeType _type);
	void SetParent(Node* _parent);

private:
	Node* mParent;
	Vector2D mPosition, mScale;
	int g, h, f;
	NodeType mType;
	Color mColor;
};