#pragma once
#include "Renderer2D.h"
#include "Vector2.h" 
using namespace aie;

enum eType
{
	ETYPE_CIRCLE,
	ETYPE_SQR,
};

class BaseObstacle
{
public:
	BaseObstacle();
	~BaseObstacle();

	virtual void Draw(Renderer2D* m_2dRenderer);
	virtual void Update(float deltaTime);

//protected:
	float m_fSize;;
	Vector2 m_v2Pos;
	eType m_eType;
};

