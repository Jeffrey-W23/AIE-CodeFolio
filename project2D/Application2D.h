#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "StateMachine.h"

enum EWhatEntity
{
	EWHATENTITY_PATHFIND,
	EWHATENTITY_PLAYER,
	EWHATENTITY_ENEMYSTATE,
	EWHATENTITY_ENEMYDECTREE,
	EWHATENTITY_ENEMYBEHTREE,
	EWHATENTITY_FLOCKING
};

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

	EWhatEntity m_eEntityType;
	StateMachine* m_StateMachine;
};