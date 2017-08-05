// #includes, using, etc
#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "StateMachine.h"

//--------------------------------------------------------------------------------------
// Enum EWhatEntity. Used for switcing the AI example states.
//--------------------------------------------------------------------------------------
enum EWhatEntity
{
	EWHATENTITY_PATHFIND,
	EWHATENTITY_PLAYER,
	EWHATENTITY_SEEKFLEESTATE,
	EWHATENTITY_ENEMYDECTREE,
	EWHATENTITY_ENEMYBEHTREE,
	EWHATENTITY_FLOCKING
};

//--------------------------------------------------------------------------------------
// Application2D object. Inheritance from Application.
//--------------------------------------------------------------------------------------
class Application2D : public aie::Application {
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Application2D();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	virtual ~Application2D();

	//--------------------------------------------------------------------------------------
	// startup: Initialize the game.
	//
	// Returns:
	//		bool: Returns a true or false for if the startup is sucessful.
	//--------------------------------------------------------------------------------------
	virtual bool startup();

	//--------------------------------------------------------------------------------------
	// shutdown: Called on application shutdown and does all the cleaning up (eg. Deleteing pointers.)
	//--------------------------------------------------------------------------------------
	virtual void shutdown();

	// --------------------------------------------------------------------------------------
	// Update: A virtual function to update objects.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//--------------------------------------------------------------------------------------
	virtual void update(float deltaTime);

	//--------------------------------------------------------------------------------------
	// Draw: A virtual function to render (or "draw") objects to the screen.
	//--------------------------------------------------------------------------------------
	virtual void draw();

protected:

	//--------------------------------------------------------------------------------------
	// A pointer to Renderer2D
	//--------------------------------------------------------------------------------------
	aie::Renderer2D* m_2dRenderer;

	//--------------------------------------------------------------------------------------
	// A pointer to Font
	//--------------------------------------------------------------------------------------
	aie::Font* m_font;

	//--------------------------------------------------------------------------------------
	// m_eEntityType an enum of EWhatEntity.
	//--------------------------------------------------------------------------------------
	EWhatEntity m_eEntityType;

	//--------------------------------------------------------------------------------------
	// A pointer to StateMachine
	//--------------------------------------------------------------------------------------
	StateMachine* m_StateMachine;
};