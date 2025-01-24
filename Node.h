#pragma once
#include "Vector2D.h"
#include "raylib.h"
#include "NodeType.h"
#include <iostream>

#define inf std::numeric_limits<int>::max()

class Node
{
public:

	Node(Vector2D _position, int _scale, NodeType _type);
	~Node();

	void Draw();

	void SetGCost(float _g);
	void SetHCost(float _h);
	void SetType(NodeType _type);
	void SetParent(Node* _parent);


	float GetDistance(Node* from);
	float GetGCost();
	float GetHCost();
	float GetFCost();
	Node* GetParent();
	NodeType& GetType();
	Vector2D GetPosition() { return mPosition; }

private:
	Node* mParent;
	Vector2D mPosition;
	int mScale;
	float mWeight, g, h, f;
	NodeType mOldType, mType;
	Color mColor;
};