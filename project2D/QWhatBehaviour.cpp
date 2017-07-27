#include "QWhatBehaviour.h"
#include "Input.h"
using namespace aie;

QWhatBehaviour::QWhatBehaviour()
{ 
	m_bBehaviour = true;
}

QWhatBehaviour::~QWhatBehaviour()
{
}

void QWhatBehaviour::MakeDecision(Entity* pEntity, float deltaTime)
{
	if (Input::getInstance()->wasKeyPressed(INPUT_KEY_1))
	{
		m_bBehaviour = true;
	}
	else if (Input::getInstance()->wasKeyPressed(INPUT_KEY_2))
	{
		m_bBehaviour = false;
	}

	if (m_bBehaviour)
	{
		m_pTrueDecision->MakeDecision(pEntity, deltaTime);
	}
	else
	{
		m_pFalseDecision->MakeDecision(pEntity, deltaTime);
	}
}
