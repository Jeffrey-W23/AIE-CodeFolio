#pragma once
#include "AStarNode.h"
#include "DynamicArray.h"

class AStar
{
public:
	AStar();
	~AStar();

	bool CalculatePath(AStarNode* pStart, AStarNode* pEnd, DynamicArray<AStarNode*>* finishedPath);

private:
	void SortOpenList(); // Delete when I add a heap, Dont need it for the heap

	DynamicArray<AStarNode*> m_OpenList; // Change to a heap
	DynamicArray<bool> m_ClosedList;
};