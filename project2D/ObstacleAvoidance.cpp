// #include, using, etc
#include "ObstacleAvoidance.h"
#include "Input.h"
#include "Entity.h"
#include "OAMap.h"
#include "BaseObstacle.h"
#include <math.h>
#include <iostream>
using namespace aie;

//--------------------------------------------------------------------------------------
// Default Constructor. Taking in a float fWeighting.
//--------------------------------------------------------------------------------------
ObstacleAvoidance::ObstacleAvoidance(float fWeighting) : IBehaviour(fWeighting)
{
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
ObstacleAvoidance::~ObstacleAvoidance()
{
}

//--------------------------------------------------------------------------------------
// LineIntersectsRectangle: Does Line Intersects Rectangle.
//
// Returns:
//		bool: Is the line intersecting.
// Param:
//		ahead: a Vector coming off the entity.
//		pos: A Vector for the entity pos.
//		pObstacle: The Obstacle being checked.
//--------------------------------------------------------------------------------------
bool LineIntersectsRectangle(Vector2 ahead, Vector2 pos, BaseObstacle* pObstacle)
{
	Vector2 v2Point1a = pos;
	Vector2 v2Point1b = ahead;
	double minX = v2Point1a.x;
	double maxX = v2Point1b.x;

	if (v2Point1a > v2Point1b)
	{
		minX = v2Point1b.x;
		maxX = v2Point1a.x;
	}

	// Find the intersection of the segment's and rectangle's x-projections
	if (maxX > (pObstacle->m_v2Pos.x + pObstacle->m_fSize))
	{
		maxX = (pObstacle->m_v2Pos.x + pObstacle->m_fSize);
	}

	if (minX < pObstacle->m_v2Pos.x - pObstacle->m_fSize)
	{
		minX = pObstacle->m_v2Pos.x - pObstacle->m_fSize;
	}

	// If their projections do not intersect return false
	if (minX > maxX) 
	{
		return false;
	}

	// Find corresponding min and max Y for min and max X we found before
	double minY = v2Point1a.y;
	double maxY = v2Point1b.y;

	double dx = v2Point1b.x - v2Point1a.x;

	if (abs(dx) > 0.0000001)
	{
		double a = (v2Point1b.y - v2Point1a.y) / dx;
		double b = v2Point1a.y - a * v2Point1a.x;
		minY = a * minX + b;
		maxY = a * maxX + b;
	}

	if (minY > maxY)
	{
		double tmp = maxY;
		maxY = minY;
		minY = tmp;
	}

	// Find the intersection of the segment's and rectangle's y-projections
	if (maxY > (pObstacle->m_v2Pos.y + pObstacle->m_fSize))
	{
		maxY = (pObstacle->m_v2Pos.y + pObstacle->m_fSize);
	}

	if (minY < pObstacle->m_v2Pos.y - pObstacle->m_fSize)
	{
		minY = pObstacle->m_v2Pos.y - pObstacle->m_fSize;
	}

	// If Y-projections do not intersect return false
	if (minY > maxY)
	{
		return false;
	}

	std::cout << "Box" << std::endl;
	return true;
}

//--------------------------------------------------------------------------------------
// LineIntersectsCircle: Does Line Intersects Circle
//
// Returns:
//		bool: Is the line intersecting.
// Param:
//		ahead: a Vector coming off the entity.
//		ahead2: a Vector coming off the entity.
//		pObstacle: The Obstacle being checked.
//--------------------------------------------------------------------------------------
bool LineIntersectsCircle(Vector2 ahead, Vector2 ahead2, BaseObstacle* pObstacle)
{
	Vector2 result;
	return result.Distance(pObstacle->m_v2Pos, ahead) <= pObstacle->m_fSize || result.Distance(pObstacle->m_v2Pos, ahead2) <= pObstacle->m_fSize;
}

//--------------------------------------------------------------------------------------
// findMostThreateningObstacle: Find The Most threating Obstacle.
//
// Returns:
//		BaseObstacle: the obstacle that is most threating.
// Param:
//		ahead: a Vector coming off the entity.
//		ahead2: a Vector coming off the entity.
//		pEntity: a pointer to an entity.
//--------------------------------------------------------------------------------------
BaseObstacle* findMostThreateningObstacle(Entity* pEntity, Vector2 ahead, Vector2 ahead2)
{
	OAMap* pOAMap = OAMap::Instance();

	BaseObstacle* mostThreatening;
	mostThreatening = nullptr;

	for (int i = 0; i < pOAMap->GetArray().Size(); ++i) 
	{
		BaseObstacle* obs = pOAMap->GetArray()[i];
		bool collision;

		if (obs->m_eType == ETYPE_CIRCLE)
		{
			collision = LineIntersectsCircle(ahead, ahead2, obs);
			if(collision)
				std::cout << "Circle" << std::endl;
		}
		else if (obs->m_eType == ETYPE_SQR)
			collision = LineIntersectsRectangle(ahead, pEntity->GetPosition(), obs) || LineIntersectsRectangle(ahead2, pEntity->GetPosition(), obs);

		if (collision && (mostThreatening == nullptr || Vector2::Distance(pEntity->GetPosition(), obs->m_v2Pos) < Vector2::Distance(pEntity->GetPosition(), mostThreatening->m_v2Pos)))
			mostThreatening = obs;
	}

	return mostThreatening;
}

//--------------------------------------------------------------------------------------
// Update: A virtual function from IBehaviour to update objects over time.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pEntity: a pointer to an entity.
//--------------------------------------------------------------------------------------
Vector2 ObstacleAvoidance::Update(Entity* pEntity, float deltaTime)
{
	// Set variables
	float fMaxSee = 100.0f;
	Vector2 vel = pEntity->GetVelocity();
	vel.normalise();
	float dynamicLength = pEntity->GetVelocity().magnitude() / 80.0f;
	Vector2 ahead = pEntity->GetPosition() + vel * dynamicLength;
	Vector2 ahead2 = pEntity->GetPosition() + vel * dynamicLength * 0.5;
	BaseObstacle* mostThreatening = findMostThreateningObstacle(pEntity, ahead, ahead2);
	Vector2 avoidance = Vector2(0,0);

	// Move the enity if there is a mostThreating.
	if (mostThreatening != nullptr) 
	{
		avoidance.x = ahead.x - mostThreatening->m_v2Pos.x;
		avoidance.y = ahead.y - mostThreatening->m_v2Pos.y;
		avoidance.normalise();
		avoidance.x = avoidance.x * fMaxSee;
		avoidance.y = avoidance.y * fMaxSee;
	}
	else 
	{
		avoidance.x = 0;
		avoidance.y = 0;
	}

	// return the avoidance weight
	return avoidance;
}