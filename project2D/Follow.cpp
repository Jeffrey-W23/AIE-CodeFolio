#include "Follow.h"
#include "BaseAgent.h"
#include "AStarNode.h"
#include "GridNode.h"
#include "Defines.h"
#include "DynamicArray.h"
#include "AStar.h"
#include <math.h>
#include "Heuristics.h"

struct GridNode;
using namespace aie;

Follow::Follow() // Make grid a singleton
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

void Follow::Update(BaseAgent* agent, float deltaTime)
{
	m_path.Clear();
	m_pAStar->CalculatePath(m_pGrid->GetGrid(1), m_pGrid->GetGrid(88), &m_path);

	if (m_NextNode >= m_path.Size())
	{
		agent->SetPosition(((GridNode*)m_path[m_path.Size() -1])->m_v2Pos);
		return;
	}

	Vector2 dest = ((GridNode*)m_path[m_NextNode])->m_v2Pos;
	Vector2 dir = dest - agent->GetPosition();
	dir.normalise();
	agent->SetPosition(agent->GetPosition() + dir * 80.0 * deltaTime);

	//Check distance and update destination when we get close to node
	Vector2 dist = dest - agent->GetPosition();
	float fDist = dist.magnitude();

	if (fDist < 2)
	{
		++m_NextNode;
	}
}

//http://natureofcode.com/book/chapter-6-autonomous-agents/