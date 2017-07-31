#pragma once
#include "DynamicArray.h"
#include "Renderer2D.h"
using namespace aie;

class BaseObstacle;
class Circle;
class Sqr;

class OAMap
{
private:
	OAMap();
	~OAMap();
	static OAMap* m_instance;

public:
	void Draw(Renderer2D* m_2dRenderer);
	void Update(float deltaTime);
	DynamicArray<BaseObstacle*>& GetArray();

	static void create() { m_instance = new OAMap(); }
	static void destroy() { delete m_instance; }
	static OAMap* Instance();

private:
	DynamicArray<BaseObstacle*> m_aObstacle;
};