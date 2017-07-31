#include "ObstacleAvoidance.h"
#include "Input.h"
#include "Entity.h"
#include "OAMap.h"
#include "BaseObstacle.h"
using namespace aie;

ObstacleAvoidance::ObstacleAvoidance(float fWeighting) : IBehaviour(fWeighting)
{
}

ObstacleAvoidance::~ObstacleAvoidance()
{
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
			collision = LineIntersectsCircle(ahead, ahead2, obs);
		else if (obs->m_eType == ETYPE_SQR)
			collision = LineIntersectsCircle(ahead, ahead2, obs);

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

	float dynamicLength = pEntity->GetVelocity().magnitude() / 10.0f;

	Vector2 ahead = pEntity->GetPosition() + vel * dynamicLength; // replace fMaxSee with dynamicLength (so called improved way)
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
	}
	else 
	{
		avoidance.x = 0;
		avoidance.y = 0;
	}

	return avoidance * deltaTime;
}