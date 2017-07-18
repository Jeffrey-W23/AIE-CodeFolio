#include "AStar.h"
#include "GridNode.h"
#include <math.h>

AStar::AStar(int nMaxNodes)
{
	m_ClosedList = new bool[nMaxNodes];
	m_MaxNode = nMaxNodes;
}

AStar::~AStar()
{
	delete[] m_ClosedList;
}


bool AStar::CalculatePath(AStarNode* pStart, AStarNode* pEnd, DynamicArray<AStarNode*>* finishedPath)
{
	//http://www.policyalmanac.org/games/aStarTutorial.htm

	// Clear open list
	m_OpenList.Clear();

	// Set all elements in closed list to false
	memset(m_ClosedList, 0, sizeof(bool) * m_MaxNode);

	// Set start nodes G score to zero
	pStart->m_nGScore = 0;

	// Calculate start nodes H score (for now set to zero).
	pStart->m_nHScore = CalcHeuristic(pStart, pEnd);
	
	// Calculate start nodes F score.
	pStart->m_nFScore = pStart->m_nGScore + pStart->m_nHScore;

	// Set start nodes prev to null.
	pStart->m_nPrev = nullptr;
	
	// Add start node to open list.
	m_OpenList.Push(pStart);

	// While there are still nodes in the open list
	while (m_OpenList.GetSize() > 0)
	{
		// Get the node from the open list with the lowest F Score, we'll call that currentNode. (Pop off the top)
		AStarNode* pCurrentNode = m_OpenList.Pop();

		// Add currentNode to the closed list. (by setting the indexed bool to true)
		m_ClosedList[pCurrentNode->m_nIndex] = true;

		// if currentNode is the end node, we are finished
		if (pCurrentNode == pEnd)
		{
			// Build path (remember it is backwards so we need to fix that)
			AStarNode* pNode = pEnd;

			do
			{
				finishedPath->PushFront(pNode);
				pNode = pNode->m_nPrev;
			}

			while (pNode);

			// Return true to indicate that we found a valid path.
			return true;
		}

		// Loop through all of currentNode's neighbours
		for (int i = 0; i < pCurrentNode->m_AdjacentList.Size(); ++i)
		{
			AStarNode* pNeighbour = pCurrentNode->m_AdjacentList[i]->m_nEndNode;
			int nCost = pCurrentNode->m_AdjacentList[i]->m_nCost;

			// Skip neighbours that are already in the closed list.
			if (m_ClosedList[pNeighbour->m_nIndex])
			{
				continue;
			}

			// if neighbour is already in open list...
			if (m_OpenList.Contains(pNeighbour))
			{
				// Check if this current path is better than old path (loser F Score)
				if (pCurrentNode->m_nFScore + nCost < pNeighbour->m_nFScore)
				{
					// Update G Score.
					pNeighbour->m_nGScore = pCurrentNode->m_nGScore + nCost;

					// Update F Score.
					pNeighbour->m_nFScore = pNeighbour->m_nGScore + pNeighbour->m_nHScore;

					// Update Prev Node.
					pNeighbour->m_nPrev = pCurrentNode;
				}
			}

			// else (neighbour not in open list)
			else
			{
				// Calculate G Score.
				pNeighbour->m_nGScore = pCurrentNode->m_nGScore + nCost;

				// Calculate H Score.
				pNeighbour->m_nHScore = CalcHeuristic(pNeighbour, pEnd);;

				// Calculate F Score.
				pNeighbour->m_nFScore = pNeighbour->m_nGScore + pNeighbour->m_nHScore;

				// Set Prev node pointer.
				pNeighbour->m_nPrev = pCurrentNode;

				// Add neigbour to open list.
				m_OpenList.Push(pNeighbour);
			}
		}
	}

	// No path found if we got to here, so return false.
	return false;
}

int AStar::CalcHeuristic(AStarNode* pNode, AStarNode* pEnd)
{
	// Make custom Heuristic for higher then credit mark

	// Manhattan  Distance (Melb)
	int difX = ((GridNode*)pNode)->m_nIndexX - ((GridNode*)pEnd)->m_nIndexX;
	int difY = ((GridNode*)pNode)->m_nIndexY - ((GridNode*)pEnd)->m_nIndexY;

	return (abs(difX) + abs(difY)) * 10;
}
