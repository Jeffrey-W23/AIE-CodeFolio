//#include, using etc
#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "CollisionManager.h"
#include "Grid.h"
#include "OAMap.h"
#include "PathState.h"
#include "PlayerState.h"
#include "SeekFleeState.h"
#include "DecisionState.h"
#include "BehaviourState.h"
#include "FlockingState.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Application2D::Application2D() 
{
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Application2D::~Application2D() 
{
}

//--------------------------------------------------------------------------------------
// startup: Initialize the game.
//
// Returns:
//		bool: Returns a true or false for if the startup is sucessful.
//--------------------------------------------------------------------------------------
bool Application2D::startup() 
{
	// Create a new instance of the Renderer2D.
	m_2dRenderer = new aie::Renderer2D();

	// Create a new instance of the Font.
	m_font = new aie::Font("./font/consolas.ttf", 20);

	// Create a Singleton of Grid, OAMap, CollisionMnager.
	Grid::create();
	OAMap::create();
	CollisionManager::Create();

	// Create each of the game states. 
	m_StateMachine = new StateMachine();
	m_StateMachine->AddState(0, new PathState());
	m_StateMachine->AddState(1, new PlayerState());
	m_StateMachine->AddState(2, new SeekFleeState());
	m_StateMachine->AddState(3, new DecisionState());
	m_StateMachine->AddState(4, new BehaviourState());
	m_StateMachine->AddState(5, new FlockingState());
	m_StateMachine->PushState(0);

	// Set the m_eEntityType Enum to start the application with PathFind.
	m_eEntityType = EWHATENTITY_PATHFIND;

	return true;
}

//--------------------------------------------------------------------------------------
// shutdown: Called on application shutdown and does all the cleaning up (eg. Deleteing pointers.)
//--------------------------------------------------------------------------------------
void Application2D::shutdown() 
{
	delete m_font;
	delete m_2dRenderer;
	Grid::destroy();
	OAMap::destroy();
	CollisionManager::Destory();
	delete m_StateMachine;
}

//--------------------------------------------------------------------------------------
// Update: A virtual function to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void Application2D::update(float deltaTime) 
{
	// Update states from the state machine
	m_StateMachine->Update(deltaTime);

	// Get instance of Input for keyboard controls
	aie::Input* input = aie::Input::getInstance();

	// -------------------------------------------------
	// Input a number to move between AI example states.
	// -------------------------------------------------
	//Path Finding
	if (input->wasKeyPressed(aie::INPUT_KEY_1))
		m_eEntityType = EWHATENTITY_PATHFIND;

	// Player
	if (input->wasKeyPressed(aie::INPUT_KEY_2))
		m_eEntityType = EWHATENTITY_PLAYER;

	// Seek Flee
	if (input->wasKeyPressed(aie::INPUT_KEY_3))
		m_eEntityType = EWHATENTITY_SEEKFLEESTATE;

	// Decision Tree
	if (input->wasKeyPressed(aie::INPUT_KEY_4))
		m_eEntityType = EWHATENTITY_ENEMYDECTREE;

	// Behaviour Tree
	if (input->wasKeyPressed(aie::INPUT_KEY_5))
		m_eEntityType = EWHATENTITY_ENEMYBEHTREE;

	// Flocking
	if (input->wasKeyPressed(aie::INPUT_KEY_6))
		m_eEntityType = EWHATENTITY_FLOCKING;

	// -------------------------------------------------
	// Push to the next statemachine state.
	// -------------------------------------------------
	// Path Finding
	if (m_eEntityType == EWHATENTITY_PATHFIND)
		m_StateMachine->PushState(0);

	// Player
	else if (m_eEntityType == EWHATENTITY_PLAYER)
		m_StateMachine->PushState(1);

	// Seek Flee
	else if (m_eEntityType == EWHATENTITY_SEEKFLEESTATE)
		m_StateMachine->PushState(2);

	// Decision Tree
	else if (m_eEntityType == EWHATENTITY_ENEMYDECTREE)
		m_StateMachine->PushState(3);

	// Behaviour Tree
	else if (m_eEntityType == EWHATENTITY_ENEMYBEHTREE)
		m_StateMachine->PushState(4);

	// Flocking
	else if (m_eEntityType == EWHATENTITY_FLOCKING)
		m_StateMachine->PushState(5);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

//--------------------------------------------------------------------------------------
// Draw: A virtual function to render (or "draw") objects to the screen.
//--------------------------------------------------------------------------------------
void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// Draw states from the state machine
	m_StateMachine->Draw(m_2dRenderer);

	// Draw Background of nav bar.
	m_2dRenderer->setRenderColour(0.350, 0.350, 0.350, 1);
	m_2dRenderer->drawBox(640, 720, 1280, 80);
	
	// Draw nav buttons.
	m_2dRenderer->setRenderColour(0.150, 0.150, 0.150, 1);
	m_2dRenderer->drawBox(127, 720, 200, 80);
	m_2dRenderer->drawBox(332, 720, 200, 80);
	m_2dRenderer->drawBox(537, 720, 200, 80);
	m_2dRenderer->drawBox(742, 720, 200, 80);
	m_2dRenderer->drawBox(947, 720, 200, 80);
	m_2dRenderer->drawBox(1152, 720, 200, 80);

	// Draw nav button titles.
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawText(m_font, "1. PATHFINDING", 40, 693);
	m_2dRenderer->drawText(m_font, "2. PLAYER", 245, 693);
	m_2dRenderer->drawText(m_font, "3. SEEKFLEE", 450, 693);
	m_2dRenderer->drawText(m_font, "4. DECISIONTREE", 655, 693);
	m_2dRenderer->drawText(m_font, "5. BEHAVIORTREE", 860, 693);
	m_2dRenderer->drawText(m_font, "6. FLOCKING", 1065, 693);

	// -------------------------------------------------
	// Change the color of buttons when they are selected.
	// -------------------------------------------------
	// Path Finding
	if (m_eEntityType == EWHATENTITY_PATHFIND)
	{
		m_2dRenderer->setRenderColour(0.080, 0.080, 0.080, 1);
		m_2dRenderer->drawBox(127, 720, 200, 80);

		m_2dRenderer->setRenderColour(1, 0, 1, 1);
		m_2dRenderer->drawText(m_font, "1. PATHFINDING", 40, 693);
	}

	// Player
	else if (m_eEntityType == EWHATENTITY_PLAYER)
	{
		m_2dRenderer->setRenderColour(0.080, 0.080, 0.080, 1);
		m_2dRenderer->drawBox(332, 720, 200, 80);

		m_2dRenderer->setRenderColour(1, 0, 1, 1);
		m_2dRenderer->drawText(m_font, "2. PLAYER", 245, 693);
	}

	// Seek Flee
	else if (m_eEntityType == EWHATENTITY_SEEKFLEESTATE)
	{
		m_2dRenderer->setRenderColour(0.080, 0.080, 0.080, 1);
		m_2dRenderer->drawBox(537, 720, 200, 80);

		m_2dRenderer->setRenderColour(1, 0, 1, 1);
		m_2dRenderer->drawText(m_font, "3. SEEKFLEE", 450, 693);
	}

	// Decision Tree
	else if (m_eEntityType == EWHATENTITY_ENEMYDECTREE)
	{
		m_2dRenderer->setRenderColour(0.080, 0.080, 0.080, 1);
		m_2dRenderer->drawBox(742, 720, 200, 80);

		m_2dRenderer->setRenderColour(1, 0, 1, 1);
		m_2dRenderer->drawText(m_font, "4. DECISIONTREE", 655, 693);
	}

	// Behaviour Tree
	else if (m_eEntityType == EWHATENTITY_ENEMYBEHTREE)
	{
		m_2dRenderer->setRenderColour(0.080, 0.080, 0.080, 1);
		m_2dRenderer->drawBox(947, 720, 200, 80);

		m_2dRenderer->setRenderColour(1, 0, 1, 1);
		m_2dRenderer->drawText(m_font, "5. BEHAVIORTREE", 860, 693);
	}

	// Flocking
	else if (m_eEntityType == EWHATENTITY_FLOCKING)
	{
		m_2dRenderer->setRenderColour(0.080, 0.080, 0.080, 1);
		m_2dRenderer->drawBox(1152, 720, 200, 80);

		m_2dRenderer->setRenderColour(1, 0, 1, 1);
		m_2dRenderer->drawText(m_font, "6. FLOCKING", 1065, 693);
	}

	// FPS COUNTER
	//char fps[32];
	//sprintf_s(fps, 32, "FPS: %i", getFPS());
	//m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	//m_2dRenderer->drawText(m_font, "Press Space for sound!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}