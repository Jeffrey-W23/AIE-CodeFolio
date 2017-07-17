#pragma once
#include "AStarNode.h"
#include "Vector2.h"

struct GridNode : public AStarNode
{
	GridNode(Vector2 pos, int nIndeX, int nIndexY) : AStarNode()
	{
		m_v2Pos = pos;
		m_nIndexX = nIndeX;
		m_nIndexY = nIndexY;
	}

	int m_nIndexX;
	int m_nIndexY;

	Vector2 m_v2Pos;
};