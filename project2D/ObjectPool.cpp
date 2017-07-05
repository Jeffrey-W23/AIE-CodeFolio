//#include, using etc
#include "ObjectPool.h"
#include <crtdbg.h>

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
ObjectPool::ObjectPool(int nMaxSize)
{
	m_nMaxSize = nMaxSize;

	m_pPool = new Entity*[nMaxSize];
	_ASSERT(m_pPool);

	for (int i = 0; i < nMaxSize; ++i)
	{
		m_pPool[i] = new Entity();
		_ASSERT(m_pPool[i]);
	}
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
ObjectPool::~ObjectPool()
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		delete m_pPool[i];
	}

	delete[] m_pPool;
}

//--------------------------------------------------------------------------------------
// Allocate: A function to Allocate objects to the object pool.
//
// Return:
//		Dirt: Returns a pointer to dirt.
//--------------------------------------------------------------------------------------
Entity* ObjectPool::Allocate()
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if (!m_pPool[i]->GetActive())
		{
			m_pPool[i]->SetActive(true);
			return m_pPool[i];
		}
	}

	return nullptr;
}

//--------------------------------------------------------------------------------------
// Deallocate: A function to Deallocate objects from the object pool.
//
// Param:
//		Dirt: takes in a Dirt pointer for the object to deallocate.
//--------------------------------------------------------------------------------------
void ObjectPool::Deallocate(Entity* object)
{
	_ASSERT(object);

	object->SetActive(false);
}

//--------------------------------------------------------------------------------------
// Update: A function to update objects over time in the object pool.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void ObjectPool::Update()
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if (m_pPool[i]->GetActive())
		{
			m_pPool[i]->Update();
		}
	}
}

//--------------------------------------------------------------------------------------
// Draw: A function to render (or "draw") objects to the screen in the object pool.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void ObjectPool::Draw()
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if (m_pPool[i]->GetActive())
		{
			m_pPool[i]->Draw();
		}
	}
}