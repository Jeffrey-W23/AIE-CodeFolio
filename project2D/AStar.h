#pragma once
#include "AStarNode.h"
#include "Heap.h"

class AStar
{
public:
	AStar(int nMaxNodes);
	~AStar();
	bool CalculatePath(AStarNode* pStart, AStarNode* pEnd, DynamicArray<AStarNode*>* finishedPath);
	int CalcHeuristic(AStarNode* pNode, AStarNode* pEnd);

private:
	Heap m_OpenList;
	bool* m_ClosedList;
	int m_MaxNode;
};