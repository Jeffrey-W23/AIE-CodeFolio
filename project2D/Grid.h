#pragma once
#include "AStarNode.h"
#include "Renderer2D.h"
using namespace aie;

struct GridNode;
class AStar;

class Grid
{
public:
	Grid();
	~Grid();

	void DrawGrid(Renderer2D* m_2dRenderer);

protected:
	GridNode** m_ppGrid;
	AStar* m_pAStar;
};