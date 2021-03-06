// #includes, using, etc
#include "Grid.h"
#include <math.h>
#include "Renderer2D.h"
#include "Defines.h"
#include "GridNode.h"
#include "AStar.h"
#include "DynamicArray.h"
#include "AStarNode.h"
#include "Defines.h"
using namespace aie;

// forward declarations
struct GridNode;

//--------------------------------------------------------------------------------------
// The one and only instance of this class
//--------------------------------------------------------------------------------------
Grid* Grid::m_instance = nullptr;

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Grid::Grid()
{
	m_ppGrid = new GridNode*[GRID_SIZE * GRID_SIZE];

	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			// Calculate the index 
			int index = (y * GRID_SIZE) + x;

			Vector2 pos(x * NODE_SIZE + 400, y * NODE_SIZE + 150);
			m_ppGrid[index] = new GridNode(pos, index, x, y);

			if (x % 3 == 0 && y != 5)
			{
				m_ppGrid[index]->m_Blocked = true;
			}
		}
	}

	// connect up adjacent nodes
	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			int index = (y * GRID_SIZE) + x;
			GridNode* currentNode = m_ppGrid[index];

			//Adjacent nodes

			// -------------
			// |   | 3 |   |
			// -------------
			// | 0 | C | 2 |
			// -------------
			// |   | 1 |   |
			// -------------
			for (int a = 0; a < 4; ++a)
			{
				int localx = x;
				int localy = y;

				if (a % 2 == 0)
					localx += a - 1;
				else
					localy += a - 2;

				if (localx < 0 || localx >= GRID_SIZE)
					continue;

				if (localy < 0 || localy >= GRID_SIZE)
					continue;

				int localIndex = (localy * GRID_SIZE) + localx;
				GridNode* adjNode = m_ppGrid[localIndex];

				// Connect adjacency
				AStarEdge* pEdge = new AStarEdge();
				pEdge->m_nEndNode = adjNode;
				pEdge->m_nCost = ADJACENT_COST;

				currentNode->m_AdjacentList.PushBack(pEdge);
			}

			// Diagnal nodes

			// -------------
			// | 1 |   | 2 |
			// -------------
			// |   | C |   |
			// -------------
			// | 0 |   | 3 |
			// -------------
			for (int d = 0; d < 4; ++d)
			{
				int localx = x;
				int localy = y;

				if (d % 2 == 0)
				{
					localx += d - 1;
					localy += d - 1;
				}

				else
				{
					localx += d - 2;
					localy -= d - 2;
				}

				if (localx < 0 || localx >= GRID_SIZE)
					continue;

				if (localy < 0 || localy >= GRID_SIZE)
					continue;

				int localIndex = (localy * GRID_SIZE) + localx;
				GridNode* adjNode = m_ppGrid[localIndex];

				// Connect adjacency
				AStarEdge* pEdge = new AStarEdge();
				pEdge->m_nEndNode = adjNode;
				pEdge->m_nCost = DIAGNAL_COST;

				currentNode->m_AdjacentList.PushBack(pEdge);
			}
		}
	}
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Grid::~Grid()
{
	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
	{
		delete m_ppGrid[i];
	}

	delete[]m_ppGrid;
}

//--------------------------------------------------------------------------------------
// Instance: The function for providing access.
//--------------------------------------------------------------------------------------
Grid* Grid::Instance()
{
	return m_instance;
}

//--------------------------------------------------------------------------------------
// DrawGrid: A function to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void Grid::DrawGrid(Renderer2D* m_2dRenderer)
{
	// Draw the Grid
	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
	{
		float x = m_ppGrid[i]->m_v2Pos.x;
		float y = m_ppGrid[i]->m_v2Pos.y;

		if (m_ppGrid[i]->m_Blocked)
			m_2dRenderer->setRenderColour(0x303030FF);
		else
			m_2dRenderer->setRenderColour(0x808080FF);

		m_2dRenderer->drawBox(x, y, NODE_SIZE - GRID_SPACING, NODE_SIZE - GRID_SPACING);
		m_2dRenderer->setRenderColour(0xFFFFFFFF);

		// Draw Adjacency
		/*for (int a = 0; a < m_ppGrid[i]->m_AdjacentList.Size(); ++a)
		{
			GridNode* otherNode = ((GridNode*)m_ppGrid[i]->m_AdjacentList[a]->m_nEndNode);

			float otherx = otherNode->m_v2Pos.x;
			float othery = otherNode->m_v2Pos.y;
			m_2dRenderer->setRenderColour(0xFF0000FF);
			m_2dRenderer->drawLine(x, y, otherx, othery, EDGE_THICKNESS);
			m_2dRenderer->setRenderColour(0xFFFFFFFF);
		}*/
	}

	// Draw Path
	/*DynamicArray<AStarNode*> path;
	m_pAStar->CalculatePath(m_ppGrid[31], m_ppGrid[868], &path);

	for (int i = 0; i < path.Size(); ++i)
	{
		GridNode* pNode = (GridNode*)path[i];
		m_2dRenderer->setRenderColour(0x00FF00FF);
		m_2dRenderer->drawBox(pNode->m_v2Pos.x, pNode->m_v2Pos.y, NODE_SIZE / 2, NODE_SIZE / 2);
		m_2dRenderer->setRenderColour(0xFFFFFFFF);
	}*/
}

//--------------------------------------------------------------------------------------
// GetGrid: Get the grid.
//
// Returns:
//		GetGrid: Returns a GridNode pointer.
// Param:
//		nIndex: An int Index for the grid index you want.
//--------------------------------------------------------------------------------------
GridNode* Grid::GetGrid(int nIndex)
{
	return m_ppGrid[nIndex];
}