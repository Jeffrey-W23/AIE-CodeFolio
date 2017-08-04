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

Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{
	m_2dRenderer = new aie::Renderer2D();
	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");
	m_font = new aie::Font("./font/consolas.ttf", 20);
	m_audio = new aie::Audio("./audio/powerup.wav");

	Grid::create();
	OAMap::create();
	CollisionManager::Create();

	m_StateMachine = new StateMachine();
	m_StateMachine->AddState(0, new PathState());
	m_StateMachine->AddState(1, new PlayerState());
	m_StateMachine->AddState(2, new SeekFleeState());
	m_StateMachine->AddState(3, new DecisionState());
	m_StateMachine->AddState(4, new BehaviourState());
	m_StateMachine->AddState(5, new FlockingState());
	m_StateMachine->PushState(0);

	m_eEntityType = EWHATENTITY_PATHFIND;

	return true;
}

void Application2D::shutdown() 
{
	delete m_audio;
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;

	Grid::destroy();
	OAMap::destroy();
	CollisionManager::Destory();

	delete m_StateMachine;
}

void Application2D::update(float deltaTime) 
{
	m_StateMachine->Update(deltaTime);

	// input a number for an AI Example
	aie::Input* input = aie::Input::getInstance();

	if (input->wasKeyPressed(aie::INPUT_KEY_1))
		m_eEntityType = EWHATENTITY_PATHFIND;

	if (input->wasKeyPressed(aie::INPUT_KEY_2))
		m_eEntityType = EWHATENTITY_PLAYER;

	if (input->wasKeyPressed(aie::INPUT_KEY_3))
		m_eEntityType = EWHATENTITY_ENEMYSTATE;

	if (input->wasKeyPressed(aie::INPUT_KEY_4))
		m_eEntityType = EWHATENTITY_ENEMYDECTREE;

	if (input->wasKeyPressed(aie::INPUT_KEY_5))
		m_eEntityType = EWHATENTITY_ENEMYBEHTREE;

	if (input->wasKeyPressed(aie::INPUT_KEY_6))
		m_eEntityType = EWHATENTITY_FLOCKING;

	// Push the AI Example
	if (m_eEntityType == EWHATENTITY_PATHFIND)
		m_StateMachine->PushState(0);

	else if (m_eEntityType == EWHATENTITY_PLAYER)
		m_StateMachine->PushState(1);

	else if (m_eEntityType == EWHATENTITY_ENEMYSTATE)
		m_StateMachine->PushState(2);

	else if (m_eEntityType == EWHATENTITY_ENEMYDECTREE)
		m_StateMachine->PushState(3);

	else if (m_eEntityType == EWHATENTITY_ENEMYBEHTREE)
		m_StateMachine->PushState(4);

	else if (m_eEntityType == EWHATENTITY_FLOCKING)
		m_StateMachine->PushState(5);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	m_StateMachine->Draw(m_2dRenderer);

	m_2dRenderer->setRenderColour(0.350, 0.350, 0.350, 1);
	m_2dRenderer->drawBox(640, 720, 1280, 80);
	

	m_2dRenderer->setRenderColour(0.150, 0.150, 0.150, 1);
	m_2dRenderer->drawBox(127, 720, 200, 80);

	m_2dRenderer->setRenderColour(0.150, 0.150, 0.150, 1);
	m_2dRenderer->drawBox(332, 720, 200, 80);

	m_2dRenderer->setRenderColour(0.150, 0.150, 0.150, 1);
	m_2dRenderer->drawBox(537, 720, 200, 80);

	m_2dRenderer->setRenderColour(0.150, 0.150, 0.150, 1);
	m_2dRenderer->drawBox(742, 720, 200, 80);

	m_2dRenderer->setRenderColour(0.150, 0.150, 0.150, 1);
	m_2dRenderer->drawBox(947, 720, 200, 80);

	m_2dRenderer->setRenderColour(0.150, 0.150, 0.150, 1);
	m_2dRenderer->drawBox(1152, 720, 200, 80);

	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawText(m_font, "1. PATHFINDING", 40, 693);
	m_2dRenderer->drawText(m_font, "2. PLAYER", 245, 693);
	m_2dRenderer->drawText(m_font, "3. SEEKFLEE", 450, 693);
	m_2dRenderer->drawText(m_font, "4. DECISIONTREE", 655, 693);
	m_2dRenderer->drawText(m_font, "5. BEHAVIORTREE", 860, 693);
	m_2dRenderer->drawText(m_font, "6. FLOCKING", 1065, 693);


	
	if (m_eEntityType == EWHATENTITY_PATHFIND)
	{
		m_2dRenderer->setRenderColour(0.080, 0.080, 0.080, 1);
		m_2dRenderer->drawBox(127, 720, 200, 80);

		m_2dRenderer->setRenderColour(1, 0, 1, 1);
		m_2dRenderer->drawText(m_font, "1. PATHFINDING", 40, 693);
	}
	else if (m_eEntityType == EWHATENTITY_PLAYER)
	{
		m_2dRenderer->setRenderColour(0.080, 0.080, 0.080, 1);
		m_2dRenderer->drawBox(332, 720, 200, 80);

		m_2dRenderer->setRenderColour(1, 0, 1, 1);
		m_2dRenderer->drawText(m_font, "2. PLAYER", 245, 693);
	}
	else if (m_eEntityType == EWHATENTITY_ENEMYSTATE)
	{
		m_2dRenderer->setRenderColour(0.080, 0.080, 0.080, 1);
		m_2dRenderer->drawBox(537, 720, 200, 80);

		m_2dRenderer->setRenderColour(1, 0, 1, 1);
		m_2dRenderer->drawText(m_font, "3. SEEKFLEE", 450, 693);
	}
	else if (m_eEntityType == EWHATENTITY_ENEMYDECTREE)
	{
		m_2dRenderer->setRenderColour(0.080, 0.080, 0.080, 1);
		m_2dRenderer->drawBox(742, 720, 200, 80);

		m_2dRenderer->setRenderColour(1, 0, 1, 1);
		m_2dRenderer->drawText(m_font, "4. DECISIONTREE", 655, 693);
	}
	else if (m_eEntityType == EWHATENTITY_ENEMYBEHTREE)
	{
		m_2dRenderer->setRenderColour(0.080, 0.080, 0.080, 1);
		m_2dRenderer->drawBox(947, 720, 200, 80);

		m_2dRenderer->setRenderColour(1, 0, 1, 1);
		m_2dRenderer->drawText(m_font, "5. BEHAVIORTREE", 860, 693);
	}
	else if (m_eEntityType == EWHATENTITY_FLOCKING)
	{
		m_2dRenderer->setRenderColour(0.080, 0.080, 0.080, 1);
		m_2dRenderer->drawBox(1152, 720, 200, 80);

		m_2dRenderer->setRenderColour(1, 0, 1, 1);
		m_2dRenderer->drawText(m_font, "6. FLOCKING", 1065, 693);
	}


	//// output some text, uses the last used colour
	//char fps[32];
	//sprintf_s(fps, 32, "FPS: %i", getFPS());
	//m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	//m_2dRenderer->drawText(m_font, "Press Space for sound!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}