// #include, using, etc
#include "QWhatBehaviour.h"
#include "Input.h"
using namespace aie;

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
QWhatBehaviour::QWhatBehaviour()
{ 
	// Stop behaviors.
	m_bBehaviour = EWHATBHAVIOUR_STOP;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
QWhatBehaviour::~QWhatBehaviour()
{
}

//--------------------------------------------------------------------------------------
// MakeDecision: A function to update objects over time.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//		pEntity: a pointer to the entity.
//--------------------------------------------------------------------------------------
void QWhatBehaviour::MakeDecision(Entity* pEntity, float deltaTime)
{
	// Keyboard controlls to start and stop behaviours.
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
