// #include, using, etc
#include "Matrix2.h"

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
Matrix2::Matrix2()
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 1;
}

//--------------------------------------------------------------------------------------
// Constructor for passing in four floats.
//--------------------------------------------------------------------------------------
Matrix2::Matrix2(float Xx, float Xy, float Yx, float Yy)
{
	m[0] = Xx;
	m[1] = Xy;
	m[2] = Yx;
	m[3] = Yy;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Matrix2::~Matrix2()
{
}

//--------------------------------------------------------------------------------------
// Multiply: Overloads the "*" operator so that you can multiply a Matrix by a Vector
//
// Param:
//		rhs: The right hand side value being passed into the function that you want multiplied.
// Return:
//		Returns a Vector2 of the result.
//--------------------------------------------------------------------------------------
Vector2 Matrix2::operator*(const Vector2& rhs)
{
	Vector2 result;

	result.x = m[0] * rhs.x + m[2] * rhs.y;
	result.y = m[1] * rhs.x + m[3] * rhs.y;

	return result;
}

//--------------------------------------------------------------------------------------
// Multiply: Overloads the "*" operator so that you can multiply two Matrix toegther.
//
// Param:
//		rhs: The right hand side value being passed into the function that you want multiplied.
// Return:
//		Returns a Matrix2 value of the result.
//--------------------------------------------------------------------------------------
Matrix2 Matrix2::operator*(const Matrix2& rhs)
{
	Matrix2 result;

	result.m[0] = m[0] * rhs.m[0] + m[2] * rhs.m[1];
	result.m[1] = m[1] * rhs.m[0] + m[3] * rhs.m[1];

	result.m[2] = m[0] * rhs.m[2] + m[2] * rhs.m[3];
	result.m[3] = m[1] * rhs.m[2] + m[3] * rhs.m[3];

	return result;
}

//--------------------------------------------------------------------------------------
// Sub-script operator returning a reference
//
// Param:
//		rhs: takes in an int.
// Return:
//		Returns a Vector2.
//--------------------------------------------------------------------------------------
Vector2& Matrix2::operator[](const int rhs)
{
	return *(Vector2*)(m + 2 * rhs);
}

//--------------------------------------------------------------------------------------
// Cast operator to float pointer
//--------------------------------------------------------------------------------------
Matrix2::operator float*()
{
	return &m[0];
}

//--------------------------------------------------------------------------------------
// Set Rotation for the matrix
//
// Param:
//		a: float to rotate by.
//--------------------------------------------------------------------------------------
void Matrix2::setRotate(const float a)
{
	m[0] = cosf(a);
	m[1] = sinf(a);
	m[2] = -sinf(a);
	m[3] = cosf(a);
}

//--------------------------------------------------------------------------------------
// Set Scale: set the scale of the matrix
//
// Param:
//		x: float for the x axis
//		y: float for the y axis
//--------------------------------------------------------------------------------------
void Matrix2::setScale(const float x, const float y)
{
	m[0] = x;
	m[1] = 0;
	m[2] = 0;
	m[3] = y;
}

//--------------------------------------------------------------------------------------
// Get Scale
//
// Return:
//		Returns a Vector2 of the scale of the matrix
//--------------------------------------------------------------------------------------
Vector2 Matrix2::getScale()
{
	Vector2 res;

	Vector2 xcol(m[0], m[1]);
	Vector2 ycol(m[2], m[3]);

	res.x = xcol.magnitude();
	res.y = ycol.magnitude();

	return res;
}

//--------------------------------------------------------------------------------------
// Determinant: The determinant of the matrix.
//
// Return:
//		Returns a float
//--------------------------------------------------------------------------------------
float Matrix2::Determinant()
{
	float res1 = (m[0] * m[3]);
	float res2 = (m[2] * m[1]);
	return res1 - res2;
}

//--------------------------------------------------------------------------------------
// isIdentity: Check which one the Identity matrix is.
//
// Return:
//		Returns a bool true or false if it is the identity matrix or not.
//--------------------------------------------------------------------------------------
bool Matrix2::isIdentity()
{
	int count = 0;

	for (int i = 0; i < 4; i++)
	{
		if (m[i] == 1 && i % 5 == 0)
		{
			++count;
		}
		else if (m[i] == 0)
		{
			++count;
		}
	}

	if (count == 4)
		return true;

	return false;
}

//--------------------------------------------------------------------------------------
// Transpose: get the transpose of this matrix.
//--------------------------------------------------------------------------------------
void Matrix2::Transpose()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			a[i][j] = a[j][i];
		}
	}
}