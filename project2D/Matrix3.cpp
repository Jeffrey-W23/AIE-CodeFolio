// #include, using, etc
#include "Matrix3.h"

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
Matrix3::Matrix3::Matrix3()
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 1;
	m[5] = 0;
	m[6] = 0;
	m[7] = 0;
	m[8] = 1;
}

//--------------------------------------------------------------------------------------
// Constructor for passing in 9 floats.
//--------------------------------------------------------------------------------------
Matrix3::Matrix3(float Xx, float Xy, float Xz, float Yx, float Yy, float Yz, float Zx, float Zy, float Zz)
{
	m[0] = Xx;
	m[1] = Xy;
	m[2] = Xz;
	m[3] = Yx;
	m[4] = Yy;
	m[5] = Yz;
	m[6] = Zx;
	m[7] = Zy;
	m[8] = Zz;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Matrix3::~Matrix3()
{
}

//--------------------------------------------------------------------------------------
// Multiply: Overloads the "*" operator so that you can multiply a Matrix by a Vector
//
// Param:
//		rhs: The right hand side value being passed into the function that you want multiplied.
// Return:
//		Returns a Vector3 of the result.
//--------------------------------------------------------------------------------------
Vector3 Matrix3::operator*(const Vector3& rhs)
{
	Vector3 result;

	result.x = m[0] * rhs.x + m[3] * rhs.y + m[6] * rhs.z;
	result.y = m[1] * rhs.x + m[4] * rhs.y + m[7] * rhs.z;
	result.z = m[2] * rhs.x + m[5] * rhs.y + m[8] * rhs.z;

	return result;
}

//--------------------------------------------------------------------------------------
// Multiply: Overloads the "*" operator so that you can multiply two Matrix toegther.
//
// Param:
//		rhs: The right hand side value being passed into the function that you want multiplied.
// Return:
//		Returns a Matrix3 value of the result.
//--------------------------------------------------------------------------------------
Matrix3 Matrix3::operator*(const Matrix3& rhs)
{
	Matrix3 result;

	result.m[0] = m[0] * rhs.m[0] + m[3] * rhs.m[1] + m[6] * rhs.m[2];
	result.m[1] = m[1] * rhs.m[0] + m[4] * rhs.m[1] + m[7] * rhs.m[2]; 
	result.m[2] = m[2] * rhs.m[0] + m[5] * rhs.m[1] + m[8] * rhs.m[2];

	result.m[3] = m[0] * rhs.m[3] + m[3] * rhs.m[4] + m[6] * rhs.m[5];
	result.m[4] = m[1] * rhs.m[3] + m[4] * rhs.m[4] + m[7] * rhs.m[5];
	result.m[5] = m[2] * rhs.m[3] + m[5] * rhs.m[4] + m[8] * rhs.m[5];

	result.m[6] = m[0] * rhs.m[6] + m[3] * rhs.m[7] + m[6] * rhs.m[8];
	result.m[7] = m[1] * rhs.m[6] + m[4] * rhs.m[7] + m[7] * rhs.m[8];
	result.m[8] = m[2] * rhs.m[6] + m[5] * rhs.m[7] + m[8] * rhs.m[8];

	return result;
}

//--------------------------------------------------------------------------------------
// Sub-script operator returning a reference
//
// Param:
//		rhs: takes in an int.
// Return:
//		Returns a Vector3.
//--------------------------------------------------------------------------------------
Vector3& Matrix3::operator[](const int rhs)
{
	return *(Vector3*)(m + 3 * rhs);
}

//--------------------------------------------------------------------------------------
// Cast operator to float pointer
//--------------------------------------------------------------------------------------
Matrix3::operator float*()
{
	return &m[0];
}

//--------------------------------------------------------------------------------------
// Set Rotation X for the matrix
//
// Param:
//		a: float to rotate by.
//--------------------------------------------------------------------------------------
void Matrix3::setRotateX(const float a)
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = cosf(a);
	m[5] = sinf(a);
	m[6] = 0;
	m[7] = -sinf(a);
	m[8] = cosf(a);
}

//--------------------------------------------------------------------------------------
// Set Rotation Y for the matrix
//
// Param:
//		a: float to rotate by.
//--------------------------------------------------------------------------------------
void Matrix3::setRotateY(const float a)
{
	m[0] = cosf(a);
	m[1] = 0;
	m[2] = -sinf(a);
	m[3] = 0;
	m[4] = 1;
	m[5] = 0;
	m[6] = sinf(a);
	m[7] = 0;
	m[8] = cosf(a);
}

//--------------------------------------------------------------------------------------
// Set Rotation Z for the matrix
//
// Param:
//		a: float to rotate by.
//--------------------------------------------------------------------------------------
void Matrix3::setRotateZ(const float a)
{
	m[0] = cosf(a);
	m[1] = sinf(a);
	m[2] = 0;
	m[3] = -sinf(a);
	m[4] = cosf(a);
	m[5] = 0;
	m[6] = 0;
	m[7] = 0;
	m[8] = 1;
}

//--------------------------------------------------------------------------------------
// Set Scale: set the scale of the matrix
//
// Param:
//		x: float for the x axis
//		y: float for the y axis
//--------------------------------------------------------------------------------------
void Matrix3::setScale(const float x, const float y, const float z)
{
	m[0] = x;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = y;
	m[5] = 0;
	m[6] = 0;
	m[7] = 0;
	m[8] = z;
}

//--------------------------------------------------------------------------------------
// Get Scale
//
// Return:
//		Returns a Vector2 of the scale of the matrix
//--------------------------------------------------------------------------------------
Vector3 Matrix3::getScale()
{
	Vector3 res;

	Vector3 xcol(m[0], m[1], m[2]);
	Vector3 ycol(m[3], m[4], m[5]);
	Vector3 zcol(m[6], m[7], m[8]);

	res.x = xcol.magnitude();
	res.y = ycol.magnitude();
	res.z = zcol.magnitude();

	return res;
}

//--------------------------------------------------------------------------------------
// Set Postion Vector: Set position with a vector.
//
// Param:
//		rhs: Vector for postion value.
//--------------------------------------------------------------------------------------
void Matrix3::setPostionv(const Vector2& rhs)
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 1;
	m[5] = 0;
	m[6] = rhs.x;
	m[7] = rhs.y;
	m[8] = 1;
}

//--------------------------------------------------------------------------------------
// Set Postion float: Set position with a float.
//
// Param:
//		x: float for x axis
//		y: float for y axis
//--------------------------------------------------------------------------------------
void Matrix3::setPostionf(const float x, const float y)
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 1;
	m[5] = 0;
	m[6] = x;
	m[7] = y;
	m[8] = 1;
}

//--------------------------------------------------------------------------------------
// Get Postion
//
// Return:
//		Returns a Vector3.
//--------------------------------------------------------------------------------------
Vector3 Matrix3::getPos()
{
	Vector3 result;
	result.x = m[6];
	result. y = m[7];

	return result;
}

//--------------------------------------------------------------------------------------
// Determinant: The determinant of the matrix.
//
// Return:
//		Returns a float
//--------------------------------------------------------------------------------------
float Matrix3::Determinant()
{
	float res1 = m[0] * ((m[4] * m[8]) - (m[7] * m[5]));
	float res2 = m[3] * ((m[1] * m[8]) - (m[7] * m[2]));
	float res3 = m[6] * ((m[1] * m[5]) - (m[4] * m[2]));

	return res1 - res2 + res3;
}

//--------------------------------------------------------------------------------------
// isIdentity: Check which one the Identity matrix is.
//
// Return:
//		Returns a bool true or false if it is the identity matrix or not.
//--------------------------------------------------------------------------------------
bool Matrix3::isIdentity()
{
	int count = 0;

	for (int i = 0; i < 9; i++)
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

	if (count == 9)
		return true;

	return false;
}

//--------------------------------------------------------------------------------------
// Transpose: get the transpose of this matrix.
//--------------------------------------------------------------------------------------
void Matrix3::Transpose()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[i][j] = a[j][i];
		}
	}
}