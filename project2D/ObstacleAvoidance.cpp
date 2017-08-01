#include "ObstacleAvoidance.h"
#include "Input.h"
#include "Entity.h"
#include "OAMap.h"
#include "BaseObstacle.h"
#include <math.h>
using namespace aie;
#include <iostream>


ObstacleAvoidance::ObstacleAvoidance(float fWeighting) : IBehaviour(fWeighting)
{
}

ObstacleAvoidance::~ObstacleAvoidance()
{
}











bool LineIntersectsRectangle(Vector2 ahead, Vector2 pos, BaseObstacle* pObstacle)
{
	// ahead
	Vector2 v2Point1a = pos;
	Vector2 v2Point1b = ahead;
	
	// ahead
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

	if (minX > maxX) // If their projections do not intersect return false
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

	if (minY > maxY) // If Y-projections do not intersect return false
	{
		return false;
	}

	std::cout << "Box" << std::endl;
	return true;
}













// Does Line Intersects Circle
bool LineIntersectsCircle(Vector2 ahead, Vector2 ahead2, BaseObstacle* pObstacle)
{
	Vector2 result;
	return result.Distance(pObstacle->m_v2Pos, ahead) <= pObstacle->m_fSize || result.Distance(pObstacle->m_v2Pos, ahead2) <= pObstacle->m_fSize;
}

// Find The Most threating Obstacle.
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

// Update
Vector2 ObstacleAvoidance::Update(Entity* pEntity, float deltaTime)
{
	float fMaxSee = 100.0f;

	Vector2 vel = pEntity->GetVelocity();
	vel.normalise();

	float dynamicLength = pEntity->GetVelocity().magnitude() / 80.0f;

	Vector2 ahead = pEntity->GetPosition() + vel * dynamicLength;
	Vector2 ahead2 = pEntity->GetPosition() + vel * dynamicLength * 0.5;

	BaseObstacle* mostThreatening = findMostThreateningObstacle(pEntity, ahead, ahead2);
	Vector2 avoidance = Vector2(0,0);

	if (mostThreatening != nullptr) 
	{
		avoidance.x = ahead.x - mostThreatening->m_v2Pos.x;
		avoidance.y = ahead.y - mostThreatening->m_v2Pos.y;

		avoidance.normalise();

		avoidance.x = avoidance.x * fMaxSee;
		avoidance.y = avoidance.y * fMaxSee;
		//m_fWeighting = 2; //scale up based on distance to obstacle
	}
	else 
	{
		avoidance.x = 0;
		avoidance.y = 0;
		//m_fWeighting = 0;
	}

	return avoidance;
}