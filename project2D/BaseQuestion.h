// #include, using, etc
#pragma once
#include "BaseDecision.h"

//--------------------------------------------------------------------------------------
// BaseQuestion object. Inheritance from BaseDecision.
//--------------------------------------------------------------------------------------
class BaseQuestion : public BaseDecision
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	BaseQuestion() {};

	//--------------------------------------------------------------------------------------
	// Virtual Default Destructor
	//--------------------------------------------------------------------------------------
	virtual ~BaseQuestion() {};

	//--------------------------------------------------------------------------------------
	// MakeDecision: A virtual function to update objects over time.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//		pEntity: a pointer to the entity.
	//--------------------------------------------------------------------------------------
	virtual void MakeDecision(Entity* pEntity, float deltaTime) = 0;

	//--------------------------------------------------------------------------------------
	// A BaseDecision pointer for true anwser.
	//--------------------------------------------------------------------------------------
	BaseDecision* m_pTrueDecision;
	
	//--------------------------------------------------------------------------------------
	// A BaseDecision pointer for false anwser.
	//--------------------------------------------------------------------------------------
	BaseDecision* m_pFalseDecision;
};