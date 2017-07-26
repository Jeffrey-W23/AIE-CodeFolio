// #include, using, etc
#pragma once
#include "Renderer2D.h"
#include "rect.h"
#include "Vector2.h"
#include "Collider.h"
#include "DynamicArray.h"
#include "AIStateMachine.h"
using namespace aie;

// Enums for each type a entity can be
enum Types
{
	BULLET,
	WALL,
	PLAYER,
	ENEMY
};

//--------------------------------------------------------------------------------------
// Dirt object.
//--------------------------------------------------------------------------------------
class Entity
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Entity();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	virtual ~Entity();

	//--------------------------------------------------------------------------------------
	// SetActive: A function to set the object to active for the object pool
	//
	// Param:
	//		m_bActive: a bool for if you want the object to be active or not.
	//--------------------------------------------------------------------------------------
	void SetActive(bool m_bActive);

	//--------------------------------------------------------------------------------------
	// GetActive: A function to check if an object is active or not for the object pool.
	//--------------------------------------------------------------------------------------
	bool GetActive();

	//--------------------------------------------------------------------------------------
	// setParent: Set the parent of the entity.
	//
	// Param:
	//		sParent: An entity for the parent object.
	//--------------------------------------------------------------------------------------
	void setParent(Entity* sParent);

	//--------------------------------------------------------------------------------------
	// setChild: Set the child of the entity.
	//
	// Param:
	//		sChild: An entity for the child object.
	//--------------------------------------------------------------------------------------
	void setChild(Entity* sChild);

	//--------------------------------------------------------------------------------------
	// updateGlobalTransform: Update the Global Transform.
	//--------------------------------------------------------------------------------------
	void updateGlobalTransform();

	//--------------------------------------------------------------------------------------
	// GetCollider
	//
	// Return:
	//		Collider: Return Collider
	//--------------------------------------------------------------------------------------
	Collider& GetCollider();

	//--------------------------------------------------------------------------------------
	// GetPosition: Get the position of the entity.
	//--------------------------------------------------------------------------------------
	Vector2 GetPosition();

	//--------------------------------------------------------------------------------------
	// SetPosition: Set the position of the entity.
	//
	// Param:
	//		x: a float for the x of entity.
	//		y: a float for the y of enity.
	//--------------------------------------------------------------------------------------
	void SetPosition(Vector2 nPos);

	//--------------------------------------------------------------------------------------
	// SetType: Set what type the entity is.
	//
	// Param:
	//		types: a Type enum value.
	//--------------------------------------------------------------------------------------
	void SetType(Types types);

	//--------------------------------------------------------------------------------------
	// Update: Get the Entity type.
	//
	// Return:
	//		Types: Returns the type for the entity.
	//--------------------------------------------------------------------------------------
	Types GetType();

	//--------------------------------------------------------------------------------------
	// LocalToGlobal: Change a localtransform to a globaltransform.
	//--------------------------------------------------------------------------------------
	void LocalToGlobal();






	// Getters
	Vector2 GetForce();
	Vector2 GetVelocity();
	Vector2 GetAcceleration();

	// Setters
	void SetForce(Vector2 nForce);
	void SetVelocity(Vector2 nVel);
	void SetAcceleration(Vector2 nAccel);









	//--------------------------------------------------------------------------------------
	// Update: A function to update objects.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//--------------------------------------------------------------------------------------
	void Update(float deltaTime);

	//--------------------------------------------------------------------------------------
	// Draw: A function to render (or "draw") objects to the screen.
	//
	// Param:
	//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);

	//--------------------------------------------------------------------------------------
	// A rect used as the bounding box for all entites
	//--------------------------------------------------------------------------------------
	rect boundingBox;







protected:
	Vector2 m_force;
	Vector2 m_acceleration;
	Vector2 m_velocity;
	Vector2 m_position;
	AIStateMachine* m_AIStateMachine;

	//--------------------------------------------------------------------------------------
	// A Matrix3 for the local and global transforms.
	//--------------------------------------------------------------------------------------
	Matrix3 localTransform;
	Matrix3 GlobalTrasform;







private:

	//--------------------------------------------------------------------------------------
	// A Entity pointer for parent
	//--------------------------------------------------------------------------------------
	Entity* Parent;

	//--------------------------------------------------------------------------------------
	// A Dynamic array of Entity pointers
	//--------------------------------------------------------------------------------------
	DynamicArray<Entity*> children;

	//--------------------------------------------------------------------------------------
	// A bool m_bActive for setting object active or unactive.
	//--------------------------------------------------------------------------------------
	bool m_bActive;
	
	//--------------------------------------------------------------------------------------
	// A float m_x for the x position of the object 
	//--------------------------------------------------------------------------------------
	//float m_x;

	//--------------------------------------------------------------------------------------
	// A float m_y for the y position of the object 
	//--------------------------------------------------------------------------------------
	//float m_y;

	//--------------------------------------------------------------------------------------
	// A float m_rot for the rotation of the dir object.
	//--------------------------------------------------------------------------------------
	float m_rot;

	//--------------------------------------------------------------------------------------
	// An instance of the Collider
	//--------------------------------------------------------------------------------------
	Collider m_Collider;

	//--------------------------------------------------------------------------------------
	// An instance of Type. What type is the object
	//--------------------------------------------------------------------------------------
	Types types;
};