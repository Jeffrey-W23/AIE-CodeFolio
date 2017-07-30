#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "CollisionManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Enemy4.h"
#include "Grid.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	m_shipTexture = new aie::Texture("./textures/ship.png");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_audio = new aie::Audio("./audio/powerup.wav");

	Grid::create();

	// Create instance for the collision manger
	CollisionManager::Create();

	m_Player = new Player();
	m_Enemy = new Enemy();
	m_Enemy1 = new Enemy1();
	m_Enemy2 = new Enemy2();
	m_Enemy3 = new Enemy3();
	m_Enemy4 = new Enemy4();

	//m_cameraX = -300;
	//m_cameraY = -150;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() {
	delete m_audio;
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
	Grid::destroy();

	// Call the collision destroy fucntion to delete all bounding boxes.
	CollisionManager::Destory();

	delete m_Player;
	delete m_Enemy;
	delete m_Enemy1;
	delete m_Enemy2;
	delete m_Enemy3;
	delete m_Enemy4;
}

void Application2D::update(float deltaTime) 
{
	m_Enemy->Update(deltaTime);
	m_Enemy4->Update(deltaTime);
	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	if (input->wasKeyPressed(aie::INPUT_KEY_1))
		m_eEntityType = EWHATENTITY_PLAYER;

	if (input->wasKeyPressed(aie::INPUT_KEY_2))
		m_eEntityType = EWHATENTITY_ENEMYSTATE;

	if (input->wasKeyPressed(aie::INPUT_KEY_3))
		m_eEntityType = EWHATENTITY_ENEMYDECTREE;

	if (input->wasKeyPressed(aie::INPUT_KEY_4))
		m_eEntityType = EWHATENTITY_ENEMYBEHTREE;

	// Which Entity
	if (m_eEntityType == EWHATENTITY_PLAYER)
		m_Player->Update(deltaTime);

	else if (m_eEntityType == EWHATENTITY_ENEMYSTATE)
		m_Enemy1->Update(deltaTime);

	else if (m_eEntityType == EWHATENTITY_ENEMYDECTREE)
		m_Enemy2->Update(deltaTime);

	else if (m_eEntityType == EWHATENTITY_ENEMYBEHTREE)
		m_Enemy3->Update(deltaTime);

	// use arrow keys to move camera
	/*if (input->isKeyDown(aie::INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;*/

	// example of audio
	/*if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
		m_audio->play();*/

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	//m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	Grid::Instance()->DrawGrid(m_2dRenderer);

	m_Player->Draw(m_2dRenderer);
	m_Enemy->Draw(m_2dRenderer);
	m_Enemy1->Draw(m_2dRenderer);
	m_Enemy2->Draw(m_2dRenderer);
	m_Enemy3->Draw(m_2dRenderer);
	m_Enemy4->Draw(m_2dRenderer);

	//// demonstrate animation
	//m_2dRenderer->setUVRect(int(m_timer) % 8 / 8.0f, 0, 1.f / 8, 1.f / 8);
	//m_2dRenderer->drawSprite(m_texture, 200, 200, 100, 100);

	//// demonstrate spinning sprite
	//m_2dRenderer->setUVRect(0,0,1,1);
	//m_2dRenderer->drawSprite(m_shipTexture, 600, 400, 0, 0, m_timer, 1);

	//// draw a thin line
	//m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);

	// draw a moving purple circle
	m_2dRenderer->setRenderColour(1, 0, 1, 1);
	m_2dRenderer->drawCircle(950, 150, 30, 30);

	//// draw a rotating red box
	//m_2dRenderer->setRenderColour(1, 0, 0, 1);
	//m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);

	//// draw a slightly rotated sprite with no texture, coloured yellow
	//m_2dRenderer->setRenderColour(1, 1, 0, 1);
	//m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);
	//
	//// output some text, uses the last used colour
	//char fps[32];
	//sprintf_s(fps, 32, "FPS: %i", getFPS());
	//m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	//m_2dRenderer->drawText(m_font, "Press Space for sound!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}