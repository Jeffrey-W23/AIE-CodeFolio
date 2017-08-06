// #include, using, etc
#pragma once
#include "Entity.h"

// forward declarations
class BTBaseNode;

// Enums to stop and start the entity.
enum EBehaviourType
{
	EBEHAVIOURTYPE_STOP,
	EBEHAVIOURTYPE_OA,
};

//--------------------------------------------------------------------------------------
// BehaviourEntity object. Inheritance from Entity.
//--------------------------------------------------------------------------------------
class BehaviourEntity : public Entity
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	BehaviourEntity();
	
	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~BehaviourEntity();

	//--------------------------------------------------------------------------------------
	// Update: A function to update objects.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//--------------------------------------------------------------------------------------
	void Update(float deltaTime);
	
	//--------------------------------------------------------------------------------------
	// Draw: A function to render (or "draw") objects to the screen.
	//
	// Param:
	//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);

	//--------------------------------------------------------------------------------------
	// A varaible of enum EBehaviourType.
	//--------------------------------------------------------------------------------------
	EBehaviourType m_eBehType;

private:
	
	//--------------------------------------------------------------------------------------
	// A BTBaseNode pointer.
	//--------------------------------------------------------------------------------------
	BTBaseNode* m_pRoot;
	
	//--------------------------------------------------------------------------------------
	// A bool for stopping and starting the entity.
	//--------------------------------------------------------------------------------------
	bool m_bStop;
};