// #include, using, etc
#include "Entity.h"
#include <crtdbg.h>

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Entity::Entity()
{
	// initialize Parent to null
	Parent = nullptr;

	// start the active status as false 
	m_bActive = false;

	// Bind the boundingbox with Entity. (for AABB collision.)
	m_Collider.m_TL = Vector2(-30, -30);
	m_Collider.m_BR = Vector2(30, 30);

	// Set the size of the boundingbox
	boundingBox.SetSize(Vector3(-60, -60, 0));

	// Set the AI Behaviour state machine
	m_AIStateMachine = new AIStateMachine();
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Entity::~Entity()
{
	delete m_AIStateMachine;
}

//--------------------------------------------------------------------------------------
// setParent: Set the parent of the entity.
//
// Param:
//		sParent: An entity for the parent object.
//--------------------------------------------------------------------------------------
void Entity::setParent(Entity* parent)
{
	Parent = parent;
}

//--------------------------------------------------------------------------------------
// setChild: Set the child of the entity.
//
// Param:
//		sChild: An entity for the child object.
//--------------------------------------------------------------------------------------
void Entity::setChild(Entity* child)
{
	children.PushBack(child);
}

//--------------------------------------------------------------------------------------
// SetActive: A function to set the object to active for the object pool
//
// Param:
//		m_bActive: a bool for if you want the object to be active or not.
//--------------------------------------------------------------------------------------
void Entity::SetActive(bool bActive)
{
	m_bActive = bActive;
}

//--------------------------------------------------------------------------------------
// GetActive: A function to check if an object is active or not for the object pool.
//--------------------------------------------------------------------------------------
bool Entity::GetActive()
{
	return m_bActive;
}

//--------------------------------------------------------------------------------------
// updateGlobalTransform: Update the Global Transform.
//--------------------------------------------------------------------------------------
void Entity::updateGlobalTransform()
{
	if (Parent != nullptr)
	{
		GlobalTrasform = Parent->GlobalTrasform * localTransform;
	}
	else
	{
		GlobalTrasform = localTransform;
	}

	for (int i = 0; i < children.Size(); i++)
	{
		children[i]->updateGlobalTransform();
	}
}

//--------------------------------------------------------------------------------------
// GetCollider
//
// Return:
//		Collider: Return Collider
//--------------------------------------------------------------------------------------
Collider& Entity::GetCollider()
{
	return m_Collider;
}

//--------------------------------------------------------------------------------------
// GetPosition: Get the position of the entity.
//--------------------------------------------------------------------------------------
Vector2 Entity::GetPosition()
{
	Vector2 pos;

	pos.x = GlobalTrasform.m[6];
	pos.y = GlobalTrasform.m[7];

	return pos;
}

//--------------------------------------------------------------------------------------
// SetPosition: Set the position of the entity.
//
// Param:
//		x: a float for the x of entity.
//		y: a float for the y of enity.
//--------------------------------------------------------------------------------------
void Entity::SetPosition(Vector2 nPos)
{
	localTransform.m[6] = nPos.x;
	localTransform.m[7] = nPos.y;

	updateGlobalTransform();
}

//--------------------------------------------------------------------------------------
// SetType: Set what type the entity is.
//
// Param:
//		types: a Type enum value.
//--------------------------------------------------------------------------------------
void Entity::SetType(Types types)
{
	this->types = types;
}

//--------------------------------------------------------------------------------------
// Update: Get the Entity type.
//
// Return:
//		Types: Returns the type for the entity.
//--------------------------------------------------------------------------------------
Types Entity::GetType()
{
	return types;
}

//--------------------------------------------------------------------------------------
// LocalToGlobal: Change a localtransform to a globaltransform.
//--------------------------------------------------------------------------------------
void Entity::LocalToGlobal()
{
	localTransform = GlobalTrasform;
}










Vector2 Entity::GetForce()
{
	return m_force;
}

Vector2 Entity::GetVelocity()
{
	return m_velocity;
}

Vector2 Entity::GetAcceleration()
{
	return m_acceleration;
}

void Entity::SetForce(Vector2 nForce)
{
	m_force = nForce;
}

void Entity::SetVelocity(Vector2 nVel)
{
	m_velocity = nVel;
}

void Entity::SetAcceleration(Vector2 nAccel)
{
	m_acceleration = nAccel;
}

//--------------------------------------------------------------------------------------
// Update: A function to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void Entity::Update(float deltaTime)
{
	m_AIStateMachine->Update(deltaTime, this);
}

//--------------------------------------------------------------------------------------
// Draw: A function to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void Entity::Draw(Renderer2D* m_2dRenderer)
{
	m_AIStateMachine->Draw(m_2dRenderer);
}