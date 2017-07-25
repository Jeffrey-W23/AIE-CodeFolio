// #include, using, etc
#pragma once
#include "Vector3.h"
#include "Matrix3.h"

//--------------------------------------------------------------------------------------
// Rect object. Used for SAT collisions.
//--------------------------------------------------------------------------------------
class rect
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	rect();

	//--------------------------------------------------------------------------------------
	// Constructor passing in Vector3 _size.
	//
	// Param: 
	//		_size: a Vector3 for rect size.
	//--------------------------------------------------------------------------------------
	rect(Vector3 _size);

	//--------------------------------------------------------------------------------------
	// Default passing in Vector3 _pos and Vector3 _size.
	//
	// Param: 
	//		_pos: a Vector3 for rect position.
	//		_size: a Vector3 for rect size.
	//--------------------------------------------------------------------------------------
	rect(Vector3 _pos, Vector3 _size);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~rect();

	//--------------------------------------------------------------------------------------
	// MoveBy: Move the rect object by a specified amount.
	//
	// Param:
	//		by: a Vector3 value for specifying how much to move the rect object by.
	//--------------------------------------------------------------------------------------
	void MoveBy(Vector3 by);

	//--------------------------------------------------------------------------------------
	// MoveTo: Move the rect object to a specified position.
	//
	// Param:
	//		To: a Vector3 value for specifying where to reposition rect to.
	//--------------------------------------------------------------------------------------
	void MoveTo(Vector3 To);

	//--------------------------------------------------------------------------------------
	// RotateBy: Rotate the rect object by a specified amount.
	//
	// Param:
	//		by: a Vector3 value for specifying how much to rotate the rect object by.
	//--------------------------------------------------------------------------------------
	void RotateBy(Matrix3 by);

	//--------------------------------------------------------------------------------------
	// SetSize: Set the size of the rect object.
	//
	// Param:
	//		_size: specify the size of the rect with a Vector3 value.
	//--------------------------------------------------------------------------------------
	void SetSize(Vector3 _size);

	//--------------------------------------------------------------------------------------
	// Vector3 for each corner of rect
	//--------------------------------------------------------------------------------------
	Vector3 UpperLeft;
	Vector3 UpperRight;
	Vector3 LowerLeft;
	Vector3 LowerRight;

private:
	//--------------------------------------------------------------------------------------
	// CalcVertices: Calculate the vertcies of each corner.
	//--------------------------------------------------------------------------------------
	void CalcVertices();

	//--------------------------------------------------------------------------------------
	// UpdateVertices: Update the vertices of each corner.
	//--------------------------------------------------------------------------------------
	void UpdateVertices();

	//--------------------------------------------------------------------------------------
	// Keep track of the oringal corners. Vector3 for each corner of rect.
	//--------------------------------------------------------------------------------------
	Vector3 OriginalUpperLeft;
	Vector3 OriginalUpperRight;
	Vector3 OriginalLowerLeft;
	Vector3 OriginalLowerRight;

	//--------------------------------------------------------------------------------------
	// A Matrix3 for rot. Keeps track of rotation value.
	//--------------------------------------------------------------------------------------
	Matrix3 rot;

	//--------------------------------------------------------------------------------------
	// Vector3 for the position of the object.
	//--------------------------------------------------------------------------------------
	Vector3 pos;

	//--------------------------------------------------------------------------------------
	// A Vector3 for the size ofthe object.
	//--------------------------------------------------------------------------------------
	Vector3 size;
};

