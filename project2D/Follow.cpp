// #include, using, etc
#include "Follow.h"
#include "Entity.h"
#include "AStarNode.h"
#include "GridNode.h"
#include "Defines.h"
#include "DynamicArray.h"
#include "AStar.h"
#include <math.h>
#include "Heuristics.h"
using namespace aie;

// forward declarations
struct GridNode;

//--------------------------------------------------------------------------------------
// Default Constructor. Taking in a int fWeighting, an int for the start node and end.
//--------------------------------------------------------------------------------------
Follow::Follow(float fWeighting, int nStart, int nEnd) : IBehaviour(fWeighting)
{
	// new instance of the grid.
	Grid* pGrid = Grid::Instance();
	m_pGrid = pGrid;

	// Setup AStar
	m_pAStar = new AStar(GRID_SIZE * GRID_SIZE);

	// set function pointer
	m_pAStar->SetFunction(&Heuristic);

	// set vars
	m_NextNode = 0;
	m_nStart = nStart;
	m_nEnd = nEnd;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Follow::~Follow()
{
	delete m_pAStar;
}

//--------------------------------------------------------------------------------------
// Update: A virtual function from IBehaviour to update objects over time.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pEntity: a pointer to an entity.
//--------------------------------------------------------------------------------------
Vector2 Follow::Update(Entity* pEntity, float deltaTime)
{
	// Calculate the Astar path to follow
	m_path.Clear();
	m_pAStar->CalculatePath(m_pGrid->GetGrid(m_nStart), m_pGrid->GetGrid(m_nEnd), &m_path);

	if (m_NextNode >= m_path.Size())
	{
		pEntity->SetPosition(((GridNode*)m_path[m_path.Size() -1])->m_v2Pos);
		return Vector2(0, 0);;
	}

	Vector2 dest = ((GridNode*)m_path[m_NextNode])->m_v2Pos;
	Vector2 dir = dest - pEntity->GetPosition();
	dir.normalise();

	//Check distance and update destination when we get close to node
	Vector2 dist = dest - pEntity->GetPosition();
	float fDist = dist.magnitude();

	if (fDist < 2)
	{
		++m_NextNode;
	}

	// return the follow weight
	return dir * 80.0 * deltaTime;
}