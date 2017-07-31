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
bool LineIntersectsCircle(Vector2 ahead, Vector2 ahead2, Vector2 vCirclePos, float fRadius)
{
	Vector2 result;
	return result.Distance(vCirclePos, ahead) <= fRadius || result.Distance(vCirclePos, ahead2) <= fRadius;
}

// Find The Most threating Obstacle.
BaseObstacle* findMostThreateningObstacle(Entity* pEntity, Vector2 ahead, Vector2 ahead2)
{
	OAMap* pOAMap = OAMap::Instance();

	BaseObstacle* mostThreatening = nullptr;

	for (int i = 0; i < pOAMap->GetArray().Size(); ++i) 
	{
		BaseObstacle* obs = pOAMap->GetArray()[i];
		bool collision = LineIntersectsCircle(ahead, ahead2, obs->m_v2Pos, obs->m_fSize);
	
		if (collision && (mostThreatening == nullptr || Vector2::Distance(pEntity->GetPosition(), obs->m_v2Pos) < Vector2::Distance(pEntity->GetPosition(), mostThreatening->m_v2Pos)))
			mostThreatening = obs;
	}

	return mostThreatening;
}

// Update
Vector2 ObstacleAvoidance::Update(Entity* pEntity, float deltaTime)
{
	Vector2 v2Target;
	float fMaxSee = 50.0f;

	Vector2 vel = pEntity->GetVelocity();
	vel.normalise();

	Vector2 ahead = pEntity->GetPosition() + vel * fMaxSee;
	Vector2 ahead2 = pEntity->GetPosition() + vel * fMaxSee * 0.5;

	BaseObstacle* mostThreatening = findMostThreateningObstacle(pEntity, ahead, ahead2);
	Vector2 avoidance;

	if (mostThreatening != nullptr) 
	{
		avoidance.x = ahead.x - mostThreatening->m_fSize / 2;
		avoidance.y = ahead.y - mostThreatening->m_fSize / 2;

		avoidance.normalise();

		avoidance.x = avoidance.x * fMaxSee;
		avoidance.y = avoidance.y * fMaxSee;
	}
	else 
	{
		avoidance.x = 0;
		avoidance.y = 0;
	}

	return avoidance;
}