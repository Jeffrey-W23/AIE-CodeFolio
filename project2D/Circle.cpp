#include "Circle.h"

Circle::Circle(Vector2 v2Pos, float fSize)
{
	m_eType = ETYPE_CIRCLE;
	m_v2Pos = v2Pos;
	m_fSize = fSize;
}

Circle::~Circle()
{
}

void Circle::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(1, 0, 1, 1);
	m_2dRenderer->drawCircle(m_v2Pos.x, m_v2Pos.y, m_fSize * 0.5f);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}

void Circle::Update(float deltaTime)
{

}