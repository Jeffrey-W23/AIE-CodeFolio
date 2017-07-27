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
	int nMouseX;
	int nMouseY;

	Input::getInstance()->getMouseXY(&nMouseX, &nMouseY);
	Vector2 v2MousePos(nMouseX, nMouseY);

	Vector2 v2Dir = pEntity->GetPosition() - v2MousePos;
	v2Dir.normalise();

	return v2Dir * 100.0f * deltaTime;
}