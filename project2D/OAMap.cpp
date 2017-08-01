#include "OAMap.h"
#include "Circle.h"
#include "Sqr.h"

OAMap* OAMap::m_instance = nullptr;

OAMap::OAMap()
{
	m_aObstacle.PushBack(new Circle(Vector2(250, 250), 50));
	m_aObstacle.PushBack(new Sqr(Vector2(350, 400), 50));
	m_aObstacle.PushBack(new Circle(Vector2(150, 300), 50));
	m_aObstacle.PushBack(new Sqr(Vector2(600, 430), 50));
	m_aObstacle.PushBack(new Circle(Vector2(700, 250), 50));
	m_aObstacle.PushBack(new Sqr(Vector2(550, 100), 50));
}

OAMap::~OAMap()
{
	for (int i = 0; i < m_aObstacle.Size(); ++i)
	{
		delete m_aObstacle[i];
	}
}

OAMap* OAMap::Instance()
{
	return m_instance;
}

void OAMap::Draw(Renderer2D* m_2dRenderer)
{
	for (int i = 0; i < m_aObstacle.Size(); ++i)
	{
		m_aObstacle[i]->Draw(m_2dRenderer);
	}
}

void OAMap::Update(float deltaTime)
{
	for (int i = 0; i < m_aObstacle.Size(); ++i)
	{
		m_aObstacle[i]->Update(deltaTime);
	}
}

DynamicArray<BaseObstacle*>& OAMap::GetArray()
{
	return m_aObstacle;
}