#pragma once
#include "Vector2D.h"
#include "raylib.h"
#include "NodeType.h"
#include <iostream>

#define inf std::numeric_limits<int>::max()

class Node
{
public:

	Node(Vector2D _position, Vector2D _scale, NodeType _type);
	~Node();

	void Draw();

	void SetGCost(int _g);
	void SetHCost(int _h);
	void SetType(NodeType _type);
	void SetParent(Node* _parent);


	int GetDistance(Node* from);
	int GetGCost();
	int GetHCost();
	int GetFCost();
	Node* GetParent();
	NodeType& GetType();
	Vector2D GetPosition() { return mPosition; }

private:
	Node* mParent;
	Vector2D mPosition, mScale;
	int g, h, mWeight;
	NodeType mType;
	Color mColor;
};