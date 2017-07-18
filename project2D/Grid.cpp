#include "Grid.h"
#include <math.h>
#include "Renderer2D.h"
#include "Defines.h"
#include "GridNode.h"
#include "AStar.h"
#include "DynamicArray.h"
#include "AStarNode.h"

struct GridNode;
using namespace aie;

// Did I put it in the right place, am I doing it right? ASK RICHARD
int Heuristic(AStarNode* pNode, AStarNode* pEnd)
{
	// Make custom Heuristic for higher then credit mark

	// Manhattan Distance (Melbourne Method)
	int difX = ((GridNode*)pNode)->m_nIndexX - ((GridNode*)pEnd)->m_nIndexX;
	int difY = ((GridNode*)pNode)->m_nIndexY - ((GridNode*)pEnd)->m_nIndexY;

	return (abs(difX) + abs(difY)) * 10;
}

Grid::Grid()
{
	m_ppGrid = new GridNode*[GRID_SIZE * GRID_SIZE];

	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			// Calculate the index 
			int index = (y * GRID_SIZE) + x;

			Vector2 pos(x * NODE_SIZE, y * NODE_SIZE);
			m_ppGrid[index] = new GridNode(pos, index, x, y);
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

	// Setup AStar
	m_pAStar = new AStar(GRID_SIZE * GRID_SIZE);

	// Set Function pointer
	SetFunction(&Heuristic);
}


Grid::~Grid()
{
	delete m_pAStar;

	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
	{
		delete m_ppGrid[i];
	}

	delete[]m_ppGrid;
}

void Grid::DrawGrid(Renderer2D* m_2dRenderer)
{
	// Draw the Grid
	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
	{
		float x = m_ppGrid[i]->m_v2Pos.x;
		float y = m_ppGrid[i]->m_v2Pos.y;

		m_2dRenderer->drawBox(x, y, NODE_SIZE - GRID_SPACING, NODE_SIZE - GRID_SPACING);

		// Draw Adjacency
		for (int a = 0; a < m_ppGrid[i]->m_AdjacentList.Size(); ++a)
		{
			GridNode* otherNode = ((GridNode*)m_ppGrid[i]->m_AdjacentList[a]->m_nEndNode);

			float otherx = otherNode->m_v2Pos.x;
			float othery = otherNode->m_v2Pos.y;
			m_2dRenderer->setRenderColour(0xFF0000FF);
			m_2dRenderer->drawLine(x, y, otherx, othery, EDGE_THICKNESS);
			m_2dRenderer->setRenderColour(0xFFFFFFFF);
		}
	}

	// Draw Path
	DynamicArray<AStarNode*> path;
	m_pAStar->CalculatePath(m_ppGrid[2], m_ppGrid[98], &path);

	for (int i = 0; i < path.Size(); ++i)
	{
		GridNode* pNode = (GridNode*)path[i];
		m_2dRenderer->setRenderColour(0x00FF00FF);
		m_2dRenderer->drawBox(pNode->m_v2Pos.x, pNode->m_v2Pos.y, NODE_SIZE / 2, NODE_SIZE / 2);
		m_2dRenderer->setRenderColour(0xFFFFFFFF);
	}
}

int Grid::Callfunction(AStarNode* pStart, AStarNode* pEnd)
{
	return fn_CalcHeuristic(pStart, pEnd);
}

void Grid::SetFunction(CalcHeuristic func)
{
	fn_CalcHeuristic = func;
}