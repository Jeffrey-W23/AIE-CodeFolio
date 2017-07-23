#include "Follow.h"
#include "BaseAgent.h"
#include "AStarNode.h"
#include "GridNode.h"
#include "Defines.h"
#include "DynamicArray.h"
#include "AStar.h"
#include <math.h>

struct GridNode;
using namespace aie;

// Digonal Shortcut Method
int HeuristicFollow(AStarNode* pNode, AStarNode* pEnd)
{
	int difX = ((GridNode*)pNode)->m_nIndexX - ((GridNode*)pEnd)->m_nIndexX;
	int difY = ((GridNode*)pNode)->m_nIndexY - ((GridNode*)pEnd)->m_nIndexY;

	difX = abs(difX);
	difY = abs(difY);

	if (difX > difY)
		return (DIAGNAL_COST * difY) + ADJACENT_COST * (difX - difY);
	else
		return (DIAGNAL_COST * difX) + ADJACENT_COST * (difY - difX);
}

Follow::Follow()
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

			if (x % 3 == 0 && y != 15)
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

	// Setup AStar
	m_pAStar = new AStar(GRID_SIZE * GRID_SIZE);

	// Set Function pointer
	m_pAStar->SetFunction(&HeuristicFollow);
}

Follow::~Follow()
{
	delete m_pAStar;

	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
	{
		delete m_ppGrid[i];
	}

	delete[]m_ppGrid;
}

void Follow::Update(BaseAgent* agent, float deltaTime)
{
	DynamicArray<AStarNode*> path;
	m_pAStar->CalculatePath(m_ppGrid[31], m_ppGrid[868], &path);

	for (int i = 0; i < path.Size(); ++i)
	{
		GridNode* pNode = (GridNode*)path[i];
		agent->m_position.x = pNode->m_v2Pos.x + 100 * deltaTime;
		agent->m_position.y = pNode->m_v2Pos.y  + 100 * deltaTime;
	}
}

//http://natureofcode.com/book/chapter-6-autonomous-agents/