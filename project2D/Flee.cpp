#include "Flee.h"
#include "Input.h"
#include "Entity.h"
using namespace aie;

Flee::Flee(float fWeighting) : IBehaviour(fWeighting)
{
}

Flee::~Flee()
{
}

Vector2 Flee::Update(Entity* pEntity, float deltaTime)
{
	Vector2 vFleePos(200.0f, 200.0f);

	Vector2 v2Dir = pEntity->GetPosition() - vFleePos;
	v2Dir.normalise();

	return v2Dir * 100.0f * deltaTime;
}