#include "Seek.h"
#include "Input.h"
#include "Entity.h"
using namespace aie;

Seek::Seek(float fWeighting) : IBehaviour(fWeighting)
{
}

Seek::~Seek()
{
}

Vector2 Seek::Update(Entity* pEntity, float deltaTime)
{
	int nMouseX;
	int nMouseY;

	Input::getInstance()->getMouseXY(&nMouseX, &nMouseY);
	Vector2 v2MousePos(nMouseX, nMouseY);

	Vector2 v2Dir = v2MousePos - pEntity->GetPosition();
	v2Dir.normalise();

	return v2Dir * 100.0f * deltaTime;
}