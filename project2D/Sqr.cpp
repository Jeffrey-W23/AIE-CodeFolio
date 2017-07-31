#include "Sqr.h"

Sqr::Sqr(Vector2 v2Pos, float fSize)
{
	m_eType = ETYPE_SQR;

	m_v2Pos = v2Pos;
	m_fSize = fSize;
}

Sqr::~Sqr()
{
}

void Sqr::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(1, 0, 1, 1);
	m_2dRenderer->drawBox(m_v2Pos.x, m_v2Pos.y, m_fSize, m_fSize);
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
}

void Sqr::Update(float deltaTime)
{

}