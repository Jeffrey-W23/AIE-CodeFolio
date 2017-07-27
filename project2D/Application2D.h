#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"

class AIBehaviourTree;
class Enemy;
class Enemy1;
class Enemy2;
class Player;

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	aie::Audio*			m_audio;

	//float m_cameraX, m_cameraY;
	float m_timer;

	Player* m_Player;
	Enemy* m_Enemy;
	Enemy1* m_Enemy1;
	Enemy2* m_Enemy2;
	AIBehaviourTree* m_BehaviourTree;
};