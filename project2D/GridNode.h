// #includes, using, etc
#pragma once
#include "AStarNode.h"
#include "Vector2.h"

//--------------------------------------------------------------------------------------
// GridNode object. Inheritance from AStarNode.
//--------------------------------------------------------------------------------------
struct GridNode : public AStarNode
{
	//--------------------------------------------------------------------------------------
	// Default Constructor. taking in Vector2 for pos, int for Index and 3 ints for Indexs XY.
	//--------------------------------------------------------------------------------------
	GridNode(Vector2 pos, int nIndex,  int nIndexX, int nIndexY) : AStarNode(nIndex)
	{
		m_v2Pos = pos;
		m_nIndexX = nIndexX;
		m_nIndexY = nIndexY;
	}

	//--------------------------------------------------------------------------------------
	// An int IndexX and IndexY
	//--------------------------------------------------------------------------------------
	int m_nIndexX;
	int m_nIndexY;

	//--------------------------------------------------------------------------------------
	// A Vector2 position.
	//--------------------------------------------------------------------------------------
	Vector2 m_v2Pos;
};