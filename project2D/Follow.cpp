#include "Follow.h"
#include "Entity.h"
#include "AStarNode.h"
#include "GridNode.h"
#include "Defines.h"
#include "DynamicArray.h"
#include "AStar.h"
#include <math.h>
#include "Heuristics.h"

struct GridNode;
using namespace aie;

Follow::Follow(float fWeighting) : IBehaviour(fWeighting)
{
	Grid* pGrid = Grid::Instance();

	m_pGrid = pGrid;

	// Setup AStar
	m_pAStar = new AStar(GRID_SIZE * GRID_SIZE);

	m_pAStar->SetFunction(&Heuristic);

	m_NextNode = 0;
}

Follow::~Follow()
{
	delete m_pAStar;
}

Vector2 Follow::Update(Entity* pEntity, float deltaTime)
{
	m_path.Clear();
	m_pAStar->CalculatePath(m_pGrid->GetGrid(1), m_pGrid->GetGrid(88), &m_path);

	if (m_NextNode >= m_path.Size())
	{
		pEntity->SetPosition(((GridNode*)m_path[m_path.Size() -1])->m_v2Pos);
		return Vector2(0, 0);;
	}

	Vector2 dest = ((GridNode*)m_path[m_NextNode])->m_v2Pos;
	Vector2 dir = dest - pEntity->GetPosition();
	dir.normalise();
	pEntity->SetPosition(pEntity->GetPosition() + dir * 80.0 * deltaTime);

	//Check distance and update destination when we get close to node
	Vector2 dist = dest - pEntity->GetPosition();
	float fDist = dist.magnitude();

	if (fDist < 2)
	{
		++m_NextNode;
	}

	return Vector2(0, 0);
}

//http://natureofcode.com/book/chapter-6-autonomous-agents/