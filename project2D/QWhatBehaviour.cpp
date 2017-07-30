#include "QWhatBehaviour.h"
#include "Input.h"
using namespace aie;

QWhatBehaviour::QWhatBehaviour()
{ 
	m_bBehaviour = EWHATBHAVIOUR_STOP;
}

QWhatBehaviour::~QWhatBehaviour()
{
}

void QWhatBehaviour::MakeDecision(Entity* pEntity, float deltaTime)
{
	if (Input::getInstance()->wasKeyPressed(INPUT_KEY_S))
	{
		m_bBehaviour = EWHATBHAVIOUR_SEEK;
	}
	else if (Input::getInstance()->wasKeyPressed(INPUT_KEY_F))
	{
		m_bBehaviour = EWHATBHAVIOUR_FLEE;
	}
	else if (Input::getInstance()->wasKeyPressed(INPUT_KEY_SPACE))
	{
		m_bBehaviour = EWHATBHAVIOUR_STOP;
	}

	if (m_bBehaviour == EWHATBHAVIOUR_SEEK)
	{
		m_pTrueDecision->MakeDecision(pEntity, deltaTime);
	}
	
	if (m_bBehaviour == EWHATBHAVIOUR_FLEE)
	{
		m_pFalseDecision->MakeDecision(pEntity, deltaTime);
	}
}
