#pragma once
#include "BaseObstacle.h"

class Sqr : public BaseObstacle
{
public:
	Sqr(Vector2 v2Pos, float fSize);
	~Sqr();

	void Draw(Renderer2D* m_2dRenderer);
	void Update(float deltaTime);

private:

};

