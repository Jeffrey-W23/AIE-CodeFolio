// #include, using, etc
#pragma once
#include "BaseQuestion.h"

//--------------------------------------------------------------------------------------
// Enum EWhatBehaviour. Used for switcing the AI Behaviours.
//--------------------------------------------------------------------------------------
enum EWhatBehaviour
{
	EWHATBHAVIOUR_SEEK,
	EWHATBHAVIOUR_FLEE,
	EWHATBHAVIOUR_STOP
};

//--------------------------------------------------------------------------------------
// QWhatBehaviour object. Inheritance from BaseQuestion.
//--------------------------------------------------------------------------------------
class QWhatBehaviour : public BaseQuestion
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	QWhatBehaviour();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~QWhatBehaviour();

	//--------------------------------------------------------------------------------------
	// MakeDecision: A function to update objects over time.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//		pEntity: a pointer to the entity.
	//--------------------------------------------------------------------------------------
	void MakeDecision(Entity* pEntity, float deltaTime);

private:

	//--------------------------------------------------------------------------------------
	// m_bBehaviour an enum of EWhatBehaviour.
	//--------------------------------------------------------------------------------------
	EWhatBehaviour m_bBehaviour;
};