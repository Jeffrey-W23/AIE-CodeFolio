#pragma once
#include "AStarNode.h"
#include "Renderer2D.h"
using namespace aie;

struct GridNode;
class AStar;

class Grid
{
private:
	Grid();
	~Grid();
	static Grid* m_instance;
	
public:
	void DrawGrid(Renderer2D* m_2dRenderer);
	GridNode* GetGrid(int nIndex);
	static void create() { m_instance = new Grid(); }
	static void destroy() { delete m_instance; }
	static Grid* Instance();

protected:
	GridNode** m_ppGrid;
	AStar* m_pAStar;
};