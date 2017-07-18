#pragma once
#include "AStarNode.h"
#include "Renderer2D.h"
using namespace aie;

// Return/Type/Input
typedef int(*CalcHeuristic)(AStarNode*, AStarNode*);

struct GridNode;
class AStar;

class Grid
{
public:
	Grid();
	~Grid();

	void DrawGrid(Renderer2D* m_2dRenderer);

	// Pointer Function
	int Callfunction(AStarNode* pStart, AStarNode* pEnd);
	void SetFunction(CalcHeuristic func);
	CalcHeuristic fn_CalcHeuristic = nullptr;

protected:
	GridNode** m_ppGrid;
	AStar* m_pAStar;
};