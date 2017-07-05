// #include, using, etc
#include "Vector3.h"

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

//--------------------------------------------------------------------------------------
// Constructor for passing in three floats.
//--------------------------------------------------------------------------------------
Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Vector3::~Vector3()
{
}

//--------------------------------------------------------------------------------------
// Addition: Overloads the "+" operator so that Vector3 can be added together.
//
// Param:
//		rhs: The right hand side value being passed into the function that you want added.
// Return:
//		Returns a Vector3 value equel to the values you added together.
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator+(const Vector3& rhs)
{
	Vector3 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;

	return result;
}

//--------------------------------------------------------------------------------------
// Subtraction: Overloads the "-" operator so that Vector3s can be subtracted from each other.
//
// Param:
//		rhs: The right hand side value being passed into the function that you want subtract.
// Return:
//		Returns a Vector3 value equel to the values you subtract together.
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator-(const Vector3& rhs)
{
	Vector3 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;

	return result;
}

//--------------------------------------------------------------------------------------
// Divide: Overloads the "/" operator so that Vector3s can be Divided together.
//
// Param:
//		rhs: The right hand side value being passed into the function that you want Divide.
// Return:
//		Returns a Vector3 value equel to the values you Divide together.
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator/(const float rhs)
{
	Vector3 result;
	result.x = x / rhs;
	result.y = y / rhs;
	result.z = z / rhs;

	return result;
}

//--------------------------------------------------------------------------------------
// Multiply vector by float: Overloads the "*" operator so that Vector3s can be Multiplied by floats.
//
// Param:
//		rhs: The float you would like to be multiplied by the vector
// Return:
//		Returns a Vector3 value equel to the values you Multiplied by.
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator*(const float rhs)
{
	Vector3 result;
	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;

	return result;
}

//--------------------------------------------------------------------------------------
// Multiply float by vector: Overloads the "*" operator so that floats can be Multiplied by Vector3s.
//
// Param:
//		lhs: The float you would like to multiply by the Vector3.
//		rhs: The Vector3 you would like to be multiplied by the float.
// Return:
//		Returns a Vector3 value equel to the values you Multiplied by.
//
// (out side of class so we can order)
//--------------------------------------------------------------------------------------
Vector3 operator*(float lhs, const Vector3& rhs)
{
	Vector3 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;

	return result;
}

//--------------------------------------------------------------------------------------
// Allow negative vectors: overload the "-" operator to also allow negative vectors.
//
// Return:
//		Returns a negative Vector3.
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator-()
{
	Vector3 result;
	result.x = -x;
	result.y = -y;
	result.z = -z;

	return result;
}

//--------------------------------------------------------------------------------------
// Greater then operator: Overloads the ">" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector to be checked against.
// Return:
//		Returns a bool of true or false for if the value is greater then or not.
//--------------------------------------------------------------------------------------
bool Vector3::operator>(const Vector3 rhs)
{
	return (x > rhs.x && y > rhs.y && z > rhs.z);
}

// --------------------------------------------------------------------------------------
// Less then operator: Overloads the "<" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector to be checked against.
// Return:
//		Returns a bool of true or false for if the value is less then or not.
//--------------------------------------------------------------------------------------
bool Vector3::operator<(const Vector3 rhs)
{
	return (x < rhs.x && y < rhs.y && z < rhs.z);

}

//--------------------------------------------------------------------------------------
// Plus equal: Overloads the "+=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector you would like to increase incremently.
// Return:
//		Returns a Vector3.
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator+=(const Vector3& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;

	return *this;
}

//--------------------------------------------------------------------------------------
// Subtract equal: Overloads the "-=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector you would like to decrease incremently.
// Return:
//		Returns a Vector3.
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator-=(const Vector3& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;

	return *this;
}

//--------------------------------------------------------------------------------------
// Multiply equal: Overloads the "*=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector you would like to decrease incremently.
// Return:
//		Returns a Vector3.
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator*=(const float rhs)
{
	Vector3 result;
	result.x = x *= rhs;
	result.y = y *= rhs;
	result.z = z *= rhs;

	return result;
}

//--------------------------------------------------------------------------------------
// Divide equal: Overloads the "/=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector you would like to Divide incremently.
// Return:
//		Returns a Vector3.
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator/=(const float rhs)
{
	Vector3 result;
	result.x = x /= rhs;
	result.y = y /= rhs;
	result.z = z /= rhs;

	return result;
}

//--------------------------------------------------------------------------------------
// Sub-script operator returning a reference
//
// Param:
//		rhs: takes in an int.
// Return:
//		Returns a float.
//--------------------------------------------------------------------------------------
float& Vector3::operator[](const int rhs)
{
	if (rhs == 0)
		return x;
	else if (rhs == 1)
		return y;
	else if (rhs == 2)
		return z;
	else
		return x;
}

//--------------------------------------------------------------------------------------
// Cast operator to float pointer
//--------------------------------------------------------------------------------------
Vector3::operator float*()
{
	return &x;
}

//--------------------------------------------------------------------------------------
// Equal to operator: Overloads the "==" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector to be checked against.
// Return:
//		Returns a bool of true or false for if the value is equal to or not.
//--------------------------------------------------------------------------------------
bool Vector3::operator==(const Vector3 rhs)
{
	return (x == rhs.x && y == rhs.y && z == rhs.z);
}

//--------------------------------------------------------------------------------------
// Not Equal to operator: Overloads the "!=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector to be checked against.
// Return:
//		Returns a bool of true or false for if the value is equal to or not.
//--------------------------------------------------------------------------------------
bool Vector3::operator!=(const Vector3 rhs)
{
	return (x != rhs.x && y != rhs.y && z != rhs.z);
}

//--------------------------------------------------------------------------------------
// Greater then or equal to operator: Overloads the ">=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector to be checked against.
// Return:
//		Returns a bool of true or false for if the value is greater then or equal to or not.
//--------------------------------------------------------------------------------------
bool Vector3::operator>=(const Vector3 rhs)
{
	return (x >= rhs.x && y >= rhs.y && z >= rhs.z);
}

//--------------------------------------------------------------------------------------
// Less then or equal to operator: Overloads the "<=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector to be checked against.
// Return:
//		Returns a bool of true or false for if the value is less then or equal or not.
//--------------------------------------------------------------------------------------
bool Vector3::operator<=(const Vector3 rhs)
{
	return (x <= rhs.x && y <= rhs.y && z <= rhs.z);
}

//--------------------------------------------------------------------------------------
// Dot Product: Dot Product of two vectors.
//
// Param:
//		rhs: Vector3 you want the dot product of.
// Return:
//		Returns a float value of the dot product of the vector.
//--------------------------------------------------------------------------------------
float Vector3::dot(const Vector3& rhs)
{
	float result;
	result = x * rhs.x + y * rhs.y + z * rhs.z;
	return result;
}

//--------------------------------------------------------------------------------------
// Cross: Cross Product of two vectors is another Vector.
//
// Param:
//		rhs: Vector3 to do the corss product on.
// Return:
//		Returns a Vector3 value that is the new Vector.
//--------------------------------------------------------------------------------------
Vector3 Vector3::cross(const Vector3& rhs)
{
	Vector3 result;
	result.x = y * rhs.z - z * rhs.y;
	result.y = z * rhs.x - x * rhs.z;
	result.z = x * rhs.y - y * rhs.x;

	return result;
}

//--------------------------------------------------------------------------------------
// Magnitude: Returns the length of this vector.
//
// Return:
//		Returns a float that is the length of the vector.
//--------------------------------------------------------------------------------------
float Vector3::magnitude()
{
	float result;
	result = sqrtf(x*x + y*y + z*z);
	return result;
}

//--------------------------------------------------------------------------------------
// MagnititudeSquared: Returns the squared length of this vector
//
// Return:
//		Returns a float that is the length of the vector.
//--------------------------------------------------------------------------------------
float Vector3::MagnititudeSquared()
{
	float result;
	result = x*x + y*y + z*z;
	return result;
}

//--------------------------------------------------------------------------------------
// Normalise: Makes this vector have a magnitude of 1. (It keeps the same direction)
// This function will change the current vector.
//--------------------------------------------------------------------------------------
void Vector3::normalise()
{
	float mag = magnitude();

	if (mag != 0)
	{
		x = x / mag;
		y = y / mag;
		z = z / mag;
	}
}

//--------------------------------------------------------------------------------------
// Normalised: Makes this vector have a magnitude of 1. (It keeps the same direction) 
// This function will not change the current vector and a new one will be created.
//
// Param:
//		data: A Vector3 to be normalised.
// Return:
//		Returns a Vector3 of the normalised value.
//--------------------------------------------------------------------------------------
Vector3 Vector3::Normalised(Vector3 data)
{
	float mag = data.magnitude();

	Vector3 result;

	if (mag != 0)
	{
		result.x = data.x / mag;
		result.y = data.y / mag;
		result.z = data.z / mag;

		return result;
	}

	return Vector3();
}

//--------------------------------------------------------------------------------------
// CalcNormal: Calculate the normal of a face.
//
// Param:
//		pos: Vector3 position.
// Return:
//		Returns a Vector3 value that is the normal of a face.
//--------------------------------------------------------------------------------------
Vector3 Vector3::CalcNormal(Vector3 pos1, Vector3 pos2)
{
	Vector3 vec1;
	Vector3 vec2;

	vec1.x = pos1.x - x;
	vec1.y = pos1.y - y;
	vec1.z = pos1.z - z;
	
	vec2.x = pos2.x - x;
	vec2.y = pos2.y - y;
	vec2.z = pos2.z - z;

	Vector3 res = vec1.cross(vec2);
	res.normalise();

	return res;
}

//--------------------------------------------------------------------------------------
// Min: Returns a vector that is made from the smallest components of two vectors.
//
// Param:
//		rhs: The second vector to compare to.
// Return:
//		Returns a Vector3 that is the smallest components of two vectors.
//--------------------------------------------------------------------------------------
Vector3 Vector3::Min(Vector3 rhs)
{
	Vector3 result;

	if (x < rhs.x)
		result.x = x;
	else
		result.x = rhs.x;

	if (y < rhs.y)
		result.y = y;
	else
		result.y = rhs.y;

	if (z < rhs.z)
		result.z = z;
	else
		result.z = rhs.z;

	return result;
}

//--------------------------------------------------------------------------------------
// Max: Returns a vector that is made from the largest components of two vectors.
//
// Param:
//		rhs: The second vector to compare to.
// Return:
//		Returns a Vector3 that is the largest components of two vectors.
//--------------------------------------------------------------------------------------
Vector3 Vector3::Max(Vector3 rhs)
{
	Vector3 result;

	if (x > rhs.x)
		result.x = x;
	else
		result.x = rhs.x;

	if (y > rhs.y)
		result.y = y;
	else
		result.y = rhs.y;

	if (z > rhs.z)
		result.z = z;
	else
		result.z = rhs.z;

	return result;
}

//--------------------------------------------------------------------------------------
// Clamp: Stop a vector at a max length.
//
// Param:
//		min: The minimum of the vector.
//		max: The maximum of the vector.
// Return:
//		Returns a Vector3 clamped at the maxlength.
//--------------------------------------------------------------------------------------
Vector3 Vector3::Clamp(Vector3 min, Vector3 max)
{
	Vector3 result;

	result = this->Max(min);
	result = result.Min(max);

	return result;
}

//--------------------------------------------------------------------------------------
// Lerp: Linearly interpolates between vectors a and b by t.
//
// Param:
//		a: Vector3
//		b: Vector3
//		t: Float 
// Return:
//		Returns a Vector3 
//--------------------------------------------------------------------------------------
Vector3 Vector3::Lerp(Vector3 a, Vector3 b, float t)
{
	return (a + b) * t;
}

//--------------------------------------------------------------------------------------
// Distance: Returns the distance between a and b.
//
// Param:
//		a: Vector3
//		b: Vector3
// Return:
//		Returns a float which is the distance between a and b.
//--------------------------------------------------------------------------------------
float Vector3::Distance(Vector3 pos1, Vector3 pos2)
{
	Vector3 diff = pos1 - pos2;
	return diff.magnitude();
}

//--------------------------------------------------------------------------------------
// Bezier: A function to calculate a bezier curves.
//
// Param:
//		t: A float representing time.
//		a: Vector3 point.
//		b: Vector3 point.
//		c: Vector3 point.
// Return:
//		Returns a Vector3 value of the Bezier curve.
//--------------------------------------------------------------------------------------
Vector3 Vector3::Bezier(float t, Vector3 a, Vector3 b, Vector3 c)
{
	Vector3 result;
	Vector3 ab = Lerp(a, b, t);
	Vector3 bc = Lerp(b, c, t);
	result = Lerp(ab, bc, t);

	return result;
}

//--------------------------------------------------------------------------------------
// hermiteCurve: A function to calculate a hermite Curve.
//
// Param:
//		point0: Vector3 point.
//		tangent0: Vector3 tangent.
//		point1: Vector3 point.
//		tangent1: Vector3 tangent.
//		t: A float representing time.
// Return:
//		Returns a Vector3 value of the hermite curve.
//--------------------------------------------------------------------------------------
Vector3 Vector3::hermiteCurve(Vector3 point0, Vector3 tangent0, Vector3 point1, Vector3 tangent1, float t)
{
	// calculate t-squared and t-cubed
	float tsq = t * t;
	float tcub = tsq * t;

	// calculate the 4 basis functions
	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + t;
	float h11 = tcub - tsq;

	// return the combined result
	return h00 * point0 + h10 * tangent0 + h01 * point1 + h11 * tangent1;
}

//--------------------------------------------------------------------------------------
// Swizzle: Switch around the values of x, y and z to every possible combo.
//
// Return:
//		Returns a Vector3 value with the applied changes.
//--------------------------------------------------------------------------------------
//////////////// SWIZZLE ////////////////
// Swizzle for xxx
Vector3 Vector3::xxx()
{
	Vector3 result;
	result.x = x;
	result.y = x;
	result.z = x;
	return result;
}

// Swizzle for xxy
Vector3 Vector3::xxy()
{
	Vector3 result;
	result.x = x;
	result.y = x;
	result.z = y;
	return result;
}

// Swizzle for xxz
Vector3 Vector3::xxz()
{
	Vector3 result;
	result.x = x;
	result.y = x;
	result.z = z;
	return result;
}

// Swizzle for xyx
Vector3 Vector3::xyx()
{
	Vector3 result;
	result.x = x;
	result.y = y;
	result.z = x;
	return result;
}

// Swizzle for xyy
Vector3 Vector3::xyy()
{
	Vector3 result;
	result.x = x;
	result.y = y;
	result.z = y;
	return result;
}

// Swizzle for xyz
Vector3 Vector3::xyz()
{
	Vector3 result;
	result.x = x;
	result.y = y;
	result.z = z;
	return result;
}

// Swizzle for xzx
Vector3 Vector3::xzx()
{
	Vector3 result;
	result.x = x;
	result.y = z;
	result.z = x;
	return result;
}

// Swizzle for xzy
Vector3 Vector3::xzy()
{
	Vector3 result;
	result.x = x;
	result.y = z;
	result.z = y;
	return result;
}

// Swizzle for xzz
Vector3 Vector3::xzz()
{
	Vector3 result;
	result.x = x;
	result.y = z;
	result.z = z;
	return result;
}

// Swizzle for yxx
Vector3 Vector3::yxx()
{
	Vector3 result;
	result.x = y;
	result.y = x;
	result.z = x;
	return result;
}

// Swizzle for yxy
Vector3 Vector3::yxy()
{
	Vector3 result;
	result.x = y;
	result.y = x;
	result.z = y;
	return result;
}

// Swizzle for yxz
Vector3 Vector3::yxz()
{
	Vector3 result;
	result.x = y;
	result.y = x;
	result.z = z;
	return result;
}

// Swizzle for yyx
Vector3 Vector3::yyx()
{
	Vector3 result;
	result.x = y;
	result.y = y;
	result.z = x;
	return result;
}

// Swizzle for yyy
Vector3 Vector3::yyy()
{
	Vector3 result;
	result.x = y;
	result.y = y;
	result.z = y;
	return result;
}

// Swizzle for yyz
Vector3 Vector3::yyz()
{
	Vector3 result;
	result.x = y;
	result.y = y;
	result.z = z;
	return result;
}

// Swizzle for yzx
Vector3 Vector3::yzx()
{
	Vector3 result;
	result.x = y;
	result.y = z;
	result.z = x;
	return result;
}

// Swizzle for yzy
Vector3 Vector3::yzy()
{
	Vector3 result;
	result.x = y;
	result.y = z;
	result.z = y;
	return result;
}

// Swizzle for yzz
Vector3 Vector3::yzz()
{
	Vector3 result;
	result.x = y;
	result.y = z;
	result.z = z;
	return result;
}

// Swizzle for zxx
Vector3 Vector3::zxx()
{
	Vector3 result;
	result.x = z;
	result.y = x;
	result.z = x;
	return result;
}

// Swizzle for zxy
Vector3 Vector3::zxy()
{
	Vector3 result;
	result.x = z;
	result.y = x;
	result.z = y;
	return result;
}

// Swizzle for zxz
Vector3 Vector3::zxz()
{
	Vector3 result;
	result.x = z;
	result.y = x;
	result.z = z;
	return result;
}

// Swizzle for zyx
Vector3 Vector3::zyx()
{
	Vector3 result;
	result.x = z;
	result.y = y;
	result.z = x;
	return result;
}

// Swizzle for zyy
Vector3 Vector3::zyy()
{
	Vector3 result;
	result.x = z;
	result.y = y;
	result.z = y;
	return result;
}

// Swizzle for zyz
Vector3 Vector3::zyz()
{
	Vector3 result;
	result.x = z;
	result.y = y;
	result.z = z;
	return result;
}

// Swizzle for zzx
Vector3 Vector3::zzx()
{
	Vector3 result;
	result.x = z;
	result.y = z;
	result.z = x;
	return result;
}

// Swizzle for zzy
Vector3 Vector3::zzy()
{
	Vector3 result;
	result.x = z;
	result.y = z;
	result.z = y;
	return result;
}

// Swizzle for zzz
Vector3 Vector3::zzz()
{
	Vector3 result;
	result.x = z;
	result.y = z;
	result.z = z;
	return result;
}
//////////////// SWIZZLE ////////////////
