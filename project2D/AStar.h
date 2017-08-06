// #includes, using, etc
#pragma once
#include "AStarNode.h"
#include "Heap.h"

// In the order written its typedef, the Return type, Function pointer name, the input parameter.
typedef int(*CalcHeuristic)(AStarNode*, AStarNode*);

//--------------------------------------------------------------------------------------
// AStarNode object.
//--------------------------------------------------------------------------------------
class AStar
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor. Taking in an int nMaxNodes.
	//--------------------------------------------------------------------------------------
	AStar(int nMaxNodes);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~AStar();

	//--------------------------------------------------------------------------------------
	// CalculatePath: Calculate the Astar path.
	//
	// Returns:
	//		bool: Returns true or false if a path is found or not.
	// Param:
	//		pStart: AStarNode pointer for the start of the path.
	//		pEnd: AStarNode pointer for the end of the path.
	//		finishedPath: A DynamicArray pointer of AstarNode pointers.
	//--------------------------------------------------------------------------------------
	bool CalculatePath(AStarNode* pStart, AStarNode* pEnd, DynamicArray<AStarNode*>* finishedPath);
	
	// Call the function pointer.
	int Callfunction(AStarNode* pStart, AStarNode* pEnd);
	
	// Set the function pointer.
	void SetFunction(CalcHeuristic func);

private:

	//--------------------------------------------------------------------------------------
	// A Heap for the OpenList.
	//--------------------------------------------------------------------------------------
	Heap m_OpenList;

	//--------------------------------------------------------------------------------------
	// A bool pointer for the m_ClosedList
	//--------------------------------------------------------------------------------------
	bool* m_ClosedList;

	//--------------------------------------------------------------------------------------
	// An int for the maxNode
	//--------------------------------------------------------------------------------------
	int m_MaxNode;

	//--------------------------------------------------------------------------------------
	// Assign CalcHeuristic to the var fn_CalcHeuristic and set to null.
	//--------------------------------------------------------------------------------------
	CalcHeuristic fn_CalcHeuristic = nullptr;
};