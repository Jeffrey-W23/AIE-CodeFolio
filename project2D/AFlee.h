// #include, using, etc
#pragma once
#include "BaseAnwser.h"
#include "DynamicArray.h"

// forward declarations
class IBehaviour;

//--------------------------------------------------------------------------------------
// AFlee object. Inheritance from BaseAnwser.
//--------------------------------------------------------------------------------------
class AFlee : public BaseAnwser
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	AFlee();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~AFlee();

	//--------------------------------------------------------------------------------------
	// MakeDecision: A virtual function to update objects over time.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//		pEntity: a pointer to the entity.
	//--------------------------------------------------------------------------------------
	void MakeDecision(Entity* pEntity, float deltaTime);

private:

	//--------------------------------------------------------------------------------------
	// A DynamicArray of IBehaviour pointers.
	//--------------------------------------------------------------------------------------
	DynamicArray<IBehaviour*> m_behaviours;
};

