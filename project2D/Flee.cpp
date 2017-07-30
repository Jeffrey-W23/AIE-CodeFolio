#include "Flee.h"
#include "Input.h"
#include "Entity.h"
using namespace aie;

Flee::Flee(float fWeighting, bool bFleeMouse) : IBehaviour(fWeighting)
{
	m_bFleeMouse = bFleeMouse;
}

Flee::~Flee()
{
}

Vector2 Flee::Update(Entity* pEntity, float deltaTime)
{
	int nMouseX;
	int nMouseY;

	Input::getInstance()->getMouseXY(&nMouseX, &nMouseY);

	Vector2 vPos;

	if (m_bFleeMouse)
		vPos = Vector2(nMouseX, nMouseY);
	else
		vPos = Vector2(950, 150);

	Vector2 v2Dir = pEntity->GetPosition() - vPos;
	v2Dir.normalise();

	return v2Dir * 100.0f * deltaTime;
}