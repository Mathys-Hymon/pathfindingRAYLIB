#pragma once
#include "Vector2.h"
#include "raylib.h"
#include "NodeType.h"

class Node
{
public:

	Node(Vector2 _position, Vector2 _scale, NodeType _type);
	~Node();

	void Draw();
	int GetDistance(Node* from);
	NodeType& GetType();

private:
	Node* mParent;
	Vector2 mPosition, mScale;
	int g, h, f;
	NodeType mType;
	Color mColor;
};