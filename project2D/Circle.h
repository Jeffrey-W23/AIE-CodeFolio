#pragma once
#include "BaseObstacle.h"

class Circle : public BaseObstacle
{
public:
	Circle(Vector2 v2Pos, float fSize);
	~Circle();

	void Draw(Renderer2D* m_2dRenderer);
	void Update(float deltaTime);

private:

};

