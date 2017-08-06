// #includes, using, etc
#pragma once
#include "AStarNode.h"
#include "GridNode.h"
#include "Defines.h"

//--------------------------------------------------------------------------------------
// Heuristic. The Heuristic used for the astar path finding.
//
// Returns:
//		Int: Returns an int
// Param:
//		pNode: an AStarNode pointer.
//		pEnd: an AStarNode pointer.
//--------------------------------------------------------------------------------------
static int Heuristic(AStarNode* pNode, AStarNode* pEnd)
{
	//---------------------------------------------------------
	// Manhattan Distance (Melbourne Method)
	//---------------------------------------------------------
	/*int difX = ((GridNode*)pNode)->m_nIndexX - ((GridNode*)pEnd)->m_nIndexX;
	int difY = ((GridNode*)pNode)->m_nIndexY - ((GridNode*)pEnd)->m_nIndexY;
	return (abs(difX) + abs(difY)) * 10;*/

	//---------------------------------------------------------
	// Digonal Shortcut Method
	//---------------------------------------------------------
	int difX = ((GridNode*)pNode)->m_nIndexX - ((GridNode*)pEnd)->m_nIndexX;
	int difY = ((GridNode*)pNode)->m_nIndexY - ((GridNode*)pEnd)->m_nIndexY;

	difX = abs(difX);
	difY = abs(difY);

	if (difX > difY)
	{
		return (DIAGNAL_COST * difY) + ADJACENT_COST * (difX - difY);
	}
	else
	{
		return (DIAGNAL_COST * difX) + ADJACENT_COST * (difY - difX);
	}
}