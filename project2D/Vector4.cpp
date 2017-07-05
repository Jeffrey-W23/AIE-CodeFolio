// #include, using, etc
#include "Vector4.h"

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 1;
}

//--------------------------------------------------------------------------------------
// Constructor for passing in four floats.
//--------------------------------------------------------------------------------------
Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Vector4::~Vector4()
{
}

//--------------------------------------------------------------------------------------
// Addition: Overloads the "+" operator so that Vector4s can be added together.
//
// Param:
//		rhs: The right hand side value being passed into the function that you want added.
// Return:
//		Returns a Vector4 value equel to the values you added together.
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator+(const Vector4& rhs)
{
	Vector4 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;
	result.w = w + rhs.w;

	return result;
}

//--------------------------------------------------------------------------------------
// Subtraction: Overloads the "-" operator so that Vector4s can be subtracted from each other.
//
// Param:
//		rhs: The right hand side value being passed into the function that you want subtract.
// Return:
//		Returns a Vector4 value equel to the values you subtract together.
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator-(const Vector4& rhs)
{
	Vector4 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;
	result.w = w - rhs.w;

	return result;
}

//--------------------------------------------------------------------------------------
// Divide: Overloads the "/" operator so that Vector4s can be Divided together.
//
// Param:
//		rhs: The right hand side value being passed into the function that you want Divide.
// Return:
//		Returns a Vector4 value equel to the values you Divide together.
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator/(const float rhs)
{
	Vector4 result;
	result.x = x / rhs;
	result.y = y / rhs;
	result.z = z / rhs;
	result.w = w / rhs;

	return result;
}

//--------------------------------------------------------------------------------------
// Multiply vector by float: Overloads the "*" operator so that Vector4s can be Multiplied by floats.
//
// Param:
//		rhs: The float you would like to be multiplied by the vector
// Return:
//		Returns a Vector4 value equel to the values you Multiplied by.
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator*(const float rhs)
{
	Vector4 result;
	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;
	result.w = w * rhs;

	return result;
}

//--------------------------------------------------------------------------------------
// Multiply float by vector: Overloads the "*" operator so that floats can be Multiplied by Vector4s.
//
// Param:
//		lhs: The float you would like to multiply by the Vector4.
//		rhs: The Vector4 you would like to be multiplied by the float.
// Return:
//		Returns a Vector4 value equel to the values you Multiplied by.
//
// (out side of class so we can order)
//--------------------------------------------------------------------------------------
Vector4 operator*(float lhs, const Vector4& rhs)
{
	Vector4 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;
	result.w = lhs * rhs.w;

	return result;
}

//--------------------------------------------------------------------------------------
// Allow negative vectors: overload the "-" operator to also allow negative vectors.
//
// Return:
//		Returns a negative Vector4.
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator-()
{
	Vector4 result;
	result.x = -x;
	result.y = -y;
	result.z = -z;
	result.w = -w;

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
bool Vector4::operator>(const Vector4 rhs)
{
	return (x > rhs.x && y > rhs.y && z > rhs.z && w > rhs.w);
}

// --------------------------------------------------------------------------------------
// Less then operator: Overloads the "<" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector to be checked against.
// Return:
//		Returns a bool of true or false for if the value is less then or not.
//--------------------------------------------------------------------------------------
bool Vector4::operator<(const Vector4 rhs)
{
	return (x < rhs.x && y < rhs.y && z < rhs.z && w < rhs.w);

}

//--------------------------------------------------------------------------------------
// Plus equal: Overloads the "+=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector you would like to increase incremently.
// Return:
//		Returns a Vector4.
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator+=(const Vector4& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;

	return *this;
}

//--------------------------------------------------------------------------------------
// Subtract equal: Overloads the "-=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector you would like to decrease incremently.
// Return:
//		Returns a Vector4.
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator-=(const Vector4& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	w -= rhs.w;

	return *this;
}

//--------------------------------------------------------------------------------------
// Multiply equal: Overloads the "*=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector you would like to decrease incremently.
// Return:
//		Returns a Vector4.
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator*=(const float rhs)
{
	Vector4 result;
	result.x = x *= rhs;
	result.y = y *= rhs;
	result.z = z *= rhs;
	result.w = w *= rhs;

	return result;
}

//--------------------------------------------------------------------------------------
// Divide equal: Overloads the "/=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector you would like to Divide incremently.
// Return:
//		Returns a Vector4.
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator/=(const float rhs)
{
	Vector4 result;
	result.x = x /= rhs;
	result.y = y /= rhs;
	result.z = z /= rhs;
	result.w = w /= rhs;

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
float& Vector4::operator[](const int rhs)
{
	if (rhs == 0)
		return x;
	else if (rhs == 1)
		return y;
	else if (rhs == 2)
		return z;
	else if (rhs == 3)
		return w;
	else
		return x;
}

//--------------------------------------------------------------------------------------
// Cast operator to float pointer
//--------------------------------------------------------------------------------------
Vector4::operator float*()
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
bool Vector4::operator==(const Vector4 rhs)
{
	return (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w);
}

//--------------------------------------------------------------------------------------
// Not Equal to operator: Overloads the "!=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector to be checked against.
// Return:
//		Returns a bool of true or false for if the value is equal to or not.
//--------------------------------------------------------------------------------------
bool Vector4::operator!=(const Vector4 rhs)
{
	return (x != rhs.x && y != rhs.y && z != rhs.z && w != rhs.w);
}

//--------------------------------------------------------------------------------------
// Greater then or equal to operator: Overloads the ">=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector to be checked against.
// Return:
//		Returns a bool of true or false for if the value is greater then or equal to or not.
//--------------------------------------------------------------------------------------
bool Vector4::operator>=(const Vector4 rhs)
{
	return (x >= rhs.x && y >= rhs.y && z >= rhs.z && w >= rhs.w);
}

//--------------------------------------------------------------------------------------
// Less then or equal to operator: Overloads the "<=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector to be checked against.
// Return:
//		Returns a bool of true or false for if the value is less then or equal or not.
//--------------------------------------------------------------------------------------
bool Vector4::operator<=(const Vector4 rhs)
{
	return (x <= rhs.x && y <= rhs.y && z <= rhs.z && w <= rhs.w);
}

//--------------------------------------------------------------------------------------
// Dot Product: Dot Product of two vectors.
//
// Param:
//		rhs: Vector4 you want the dot product of.
// Return:
//		Returns a float value of the dot product of the vector.
//--------------------------------------------------------------------------------------
float Vector4::dot(const Vector4& rhs)
{
	float result;
	result = x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
	return result;
}

//--------------------------------------------------------------------------------------
// Cross: Cross Product of two vectors is another Vector.
//
// Param:
//		rhs: Vector4 to do the corss product on.
// Return:
//		Returns a Vector4 value that is the new Vector.
//--------------------------------------------------------------------------------------
Vector4 Vector4::cross(const Vector4& rhs)
{
	Vector4 result;
	result.x = y * rhs.z - z * rhs.y;
	result.y = z * rhs.x - x * rhs.z;
	result.z = x * rhs.y - y * rhs.x;
	result.w = 0;

	return result;
}

//--------------------------------------------------------------------------------------
// Magnitude: Returns the length of this vector.
//
// Return:
//		Returns a float that is the length of the vector.
//--------------------------------------------------------------------------------------
float Vector4::magnitude()
{
	float result;
	result = sqrtf(x*x + y*y + z*z + w*w);
	return result;
}

//--------------------------------------------------------------------------------------
// MagnititudeSquared: Returns the squared length of this vector
//
// Return:
//		Returns a float that is the length of the vector.
//--------------------------------------------------------------------------------------
float Vector4::MagnititudeSquared()
{
	float result;
	result = x*x + y*y + z*z + w*w;
	return result;
}

//--------------------------------------------------------------------------------------
// Normalise: Makes this vector have a magnitude of 1. (It keeps the same direction)
// This function will change the current vector.
//--------------------------------------------------------------------------------------
void Vector4::normalise()
{
	float mag = magnitude();

	if (mag != 0)
	{
		x = x / mag;
		y = y / mag;
		z = z / mag;
		w = w / mag;
	}
}

//--------------------------------------------------------------------------------------
// Normalised: Makes this vector have a magnitude of 1. (It keeps the same direction) 
// This function will not change the current vector and a new one will be created.
//
// Param:
//		data: A Vector4 to be normalised.
// Return:
//		Returns a Vector4 of the normalised value.
//--------------------------------------------------------------------------------------
Vector4 Vector4::Normalised(Vector4 data)
{
	float mag = data.magnitude();

	Vector4 result;

	if (mag != 0)
	{
		result.x = data.x / mag;
		result.y = data.y / mag;
		result.z = data.z / mag;
		result.w = data.w / mag;

		return result;
	}

	return Vector4();
}

//--------------------------------------------------------------------------------------
// CalcNormal: Calculate the normal of a face.
//
// Param:
//		pos: Vector4 position.
// Return:
//		Returns a Vector4 value that is the normal of a face.
//--------------------------------------------------------------------------------------
Vector4 Vector4::CalcNormal(Vector4 pos1, Vector4 pos2)
{
	Vector4 vec1;
	Vector4 vec2;

	vec1.x = pos1.x - x;
	vec1.y = pos1.y - y;
	vec1.z = pos1.z - z;

	vec2.x = pos2.x - x;
	vec2.y = pos2.y - y;
	vec2.z = pos2.z - z;

	Vector4 res = vec1.cross(vec2);
	res.normalise();

	return res;
}

//--------------------------------------------------------------------------------------
// Min: Returns a vector that is made from the smallest components of two vectors.
//
// Param:
//		rhs: The second vector to compare to.
// Return:
//		Returns a Vector4 that is the smallest components of two vectors.
//--------------------------------------------------------------------------------------
Vector4 Vector4::Min(Vector4 rhs)
{
	Vector4 result;

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

	if (w < rhs.w)
		result.w = w;
	else
		result.w = rhs.w;

	return result;
}

//--------------------------------------------------------------------------------------
// Max: Returns a vector that is made from the largest components of two vectors.
//
// Param:
//		rhs: The second vector to compare to.
// Return:
//		Returns a Vector4 that is the largest components of two vectors.
//--------------------------------------------------------------------------------------
Vector4 Vector4::Max(Vector4 rhs)
{
	Vector4 result;

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

	if (w > rhs.w)
		result.w = w;
	else
		result.w = rhs.w;

	return result;
}

//--------------------------------------------------------------------------------------
// Clamp: Stop a vector at a max length.
//
// Param:
//		min: The minimum of the vector.
//		max: The maximum of the vector.
// Return:
//		Returns a Vector4 clamped at the maxlength.
//--------------------------------------------------------------------------------------
Vector4 Vector4::Clamp(Vector4 min, Vector4 max)
{
	Vector4 result;

	result = this->Max(min);
	result = result.Min(max);

	return result;
}

//--------------------------------------------------------------------------------------
// Lerp: Linearly interpolates between vectors a and b by t.
//
// Param:
//		a: Vector4
//		b: Vector4
//		t: Float 
// Return:
//		Returns a Vector4 
//--------------------------------------------------------------------------------------
Vector4 Vector4::Lerp(Vector4 a, Vector4 b, float t)
{
	return (a + b) * t;
}

//--------------------------------------------------------------------------------------
// Distance: Returns the distance between a and b.
//
// Param:
//		a: Vector4
//		b: Vector4
// Return:
//		Returns a float which is the distance between a and b.
//--------------------------------------------------------------------------------------
float Vector4::Distance(Vector4 pos1, Vector4 pos2)
{
	Vector4 diff = pos1 - pos2;
	return diff.magnitude();
}

//--------------------------------------------------------------------------------------
// Bezier: A function to calculate a bezier curves.
//
// Param:
//		t: A float representing time.
//		a: Vector4 point.
//		b: Vector4 point.
//		c: Vector4 point.
// Return:
//		Returns a Vector4 value of the Bezier curve.
//--------------------------------------------------------------------------------------
Vector4 Vector4::Bezier(float t, Vector4 a, Vector4 b, Vector4 c)
{
	Vector4 result;
	Vector4 ab = Lerp(a, b, t);
	Vector4 bc = Lerp(b, c, t);
	result = Lerp(ab, bc, t);

	return result;
}

//--------------------------------------------------------------------------------------
// hermiteCurve: A function to calculate a hermite Curve.
//
// Param:
//		point0: Vector4 point.
//		tangent0: Vector4 tangent.
//		point1: Vector4 point.
//		tangent1: Vector4 tangent.
//		t: A float representing time.
// Return:
//		Returns a Vector4 value of the hermite curve.
//--------------------------------------------------------------------------------------
Vector4 Vector4::hermiteCurve(Vector4 point0, Vector4 tangent0, Vector4 point1, Vector4 tangent1, float t)
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
// Swizzle: Switch around the values of x, y, z and w to every possible combo.
//
// Return:
//		Returns a Vector4 value with the applied changes.
//--------------------------------------------------------------------------------------
//////////////// SWIZZLE ////////////////
// Swizzle for wwww
Vector4 Vector4::wwww()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = w;
	result.w = w;
	return result;
}

// Swizzle for wwwx
Vector4 Vector4::wwwx()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = w;
	result.w = x;
	return result;
}

// Swizzle for wwwy
Vector4 Vector4::wwwy()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = w;
	result.w = y;
	return result;
}

// Swizzle for wwwz
Vector4 Vector4::wwwz()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = w;
	result.w = z;
	return result;
}

// Swizzle for wwxw
Vector4 Vector4::wwxw()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = x;
	result.w = w;
	return result;
}

// Swizzle for wwxx
Vector4 Vector4::wwxx()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = x;
	result.w = x;
	return result;
}

// Swizzle for wwxy
Vector4 Vector4::wwxy()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = x;
	result.w = y;
	return result;
}

// Swizzle for wwxz
Vector4 Vector4::wwxz()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = x;
	result.w = z;
	return result;
}

// Swizzle for wwyw
Vector4 Vector4::wwyw()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = y;
	result.w = w;
	return result;
}

// Swizzle for wwyx
Vector4 Vector4::wwyx()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = y;
	result.w = x;
	return result;
}

// Swizzle for wwyy
Vector4 Vector4::wwyy()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = y;
	result.w = y;
	return result;
}

// Swizzle for wwyz
Vector4 Vector4::wwyz()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = y;
	result.w = z;
	return result;
}

// Swizzle for wwzw
Vector4 Vector4::wwzw()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = z;
	result.w = w;
	return result;
}

// Swizzle for wwzx
Vector4 Vector4::wwzx()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = z;
	result.w = x;
	return result;
}

// Swizzle for wwzy
Vector4 Vector4::wwzy()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = z;
	result.w = y;
	return result;
}

// Swizzle for wwzz
Vector4 Vector4::wwzz()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = z;
	result.w = z;
	return result;
}

// Swizzle for wxww
Vector4 Vector4::wxww()
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = w;
	result.w = w;
	return result;
}

// Swizzle for wxwx
Vector4 Vector4::wxwx()
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = w;
	result.w = x;
	return result;
}

// Swizzle for wxwy
Vector4 Vector4::wxwy()
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = w;
	result.w = y;
	return result;
}

// Swizzle for wxwz
Vector4 Vector4::wxwz()
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = w;
	result.w = z;
	return result;
}

// Swizzle for wxxw
Vector4 Vector4::wxxw()
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = x;
	result.w = w;
	return result;
}

// Swizzle for wxxx
Vector4 Vector4::wxxx()
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = x;
	result.w = x;
	return result;
}

// Swizzle for wxxy
Vector4 Vector4::wxxy()
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = x;
	result.w = y;
	return result;
}

// Swizzle for wxxz
Vector4 Vector4::wxxz()
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = x;
	result.w = z;
	return result;
}

// Swizzle for wxyw
Vector4 Vector4::wxyw()
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = y;
	result.w = w;
	return result;
}

// Swizzle for wxyx
Vector4 Vector4::wxyx()
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = y;
	result.w = x;
	return result;
}

// Swizzle for wxyy
Vector4 Vector4::wxyy()
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = y;
	result.w = y;
	return result;
}

// Swizzle for wxyz
Vector4 Vector4::wxyz()
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = y;
	result.w = z;
	return result;
}

// Swizzle for wxzw
Vector4 Vector4::wxzw()
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = z;
	result.w = w;
	return result;
}

// Swizzle for wxzx
Vector4 Vector4::wxzx()
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = z;
	result.w = x;
	return result;
}

// Swizzle for wxzy
Vector4 Vector4::wxzy()
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = z;
	result.w = y;
	return result;
}

// Swizzle for wxzz
Vector4 Vector4::wxzz()
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = z;
	result.w = z;
	return result;
}

// Swizzle for wyww
Vector4 Vector4::wyww()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = w;
	result.w = w;
	return result;
}

// Swizzle for wywx
Vector4 Vector4::wywx()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = w;
	result.w = x;
	return result;
}

// Swizzle for wywy
Vector4 Vector4::wywy()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = w;
	result.w = y;
	return result;
}

// Swizzle for wywz
Vector4 Vector4::wywz()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = w;
	result.w = z;
	return result;
}

// Swizzle for wyxw
Vector4 Vector4::wyxw()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = x;
	result.w = w;
	return result;
}

// Swizzle for wyxx
Vector4 Vector4::wyxx()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = x;
	result.w = x;
	return result;
}

// Swizzle for wyxy
Vector4 Vector4::wyxy()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = x;
	result.w = y;
	return result;
}

// Swizzle for wyxz
Vector4 Vector4::wyxz()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = x;
	result.w = z;
	return result;
}

// Swizzle for wyyw
Vector4 Vector4::wyyw()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = y;
	result.w = w;
	return result;
}

// Swizzle for wyyx
Vector4 Vector4::wyyx()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = y;
	result.w = x;
	return result;
}

// Swizzle for wyyy
Vector4 Vector4::wyyy()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = y;
	result.w = y;
	return result;
}

// Swizzle for wyyz
Vector4 Vector4::wyyz()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = y;
	result.w = z;
	return result;
}

// Swizzle for wyzw
Vector4 Vector4::wyzw()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = z;
	result.w = w;
	return result;
}

// Swizzle for wyzx
Vector4 Vector4::wyzx()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = z;
	result.w = x;
	return result;
}

// Swizzle for wyzy
Vector4 Vector4::wyzy()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = z;
	result.w = y;
	return result;
}

// Swizzle for wyzz
Vector4 Vector4::wyzz()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = z;
	result.w = z;
	return result;
}

// Swizzle for wzww
Vector4 Vector4::wzww()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = w;
	result.w = w;
	return result;
}

// Swizzle for wzwx
Vector4 Vector4::wzwx()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = w;
	result.w = x;
	return result;
}

// Swizzle for wzwy
Vector4 Vector4::wzwy()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = w;
	result.w = y;
	return result;
}

// Swizzle for wzwz
Vector4 Vector4::wzwz()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = w;
	result.w = z;
	return result;
}

// Swizzle for wzxw
Vector4 Vector4::wzxw()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = x;
	result.w = w;
	return result;
}

// Swizzle for wzxx
Vector4 Vector4::wzxx()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = x;
	result.w = x;
	return result;
}

// Swizzle for wzxy
Vector4 Vector4::wzxy()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = x;
	result.w = y;
	return result;
}

// Swizzle for wzxz
Vector4 Vector4::wzxz()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = x;
	result.w = z;
	return result;
}

// Swizzle for wzyw
Vector4 Vector4::wzyw()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = y;
	result.w = w;
	return result;
}

// Swizzle for wzyx
Vector4 Vector4::wzyx()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = y;
	result.w = x;
	return result;
}

// Swizzle for wzyy
Vector4 Vector4::wzyy()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = y;
	result.w = y;
	return result;
}

// Swizzle for wzyz
Vector4 Vector4::wzyz()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = y;
	result.w = z;
	return result;
}

// Swizzle for wzzw
Vector4 Vector4::wzzw()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = z;
	result.w = w;
	return result;
}

// Swizzle for wzzx
Vector4 Vector4::wzzx()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = z;
	result.w = x;
	return result;
}

// Swizzle for wzzy
Vector4 Vector4::wzzy()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = z;
	result.w = y;
	return result;
}

// Swizzle for wzzz
Vector4 Vector4::wzzz()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = z;
	result.w = z;
	return result;
}

// Swizzle for xwww
Vector4 Vector4::xwww()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = w;
	result.w = w;
	return result;
}

// Swizzle for xwwx
Vector4 Vector4::xwwx()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = w;
	result.w = x;
	return result;
}

// Swizzle for xwwy
Vector4 Vector4::xwwy()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = w;
	result.w = y;
	return result;
}

// Swizzle for xwwz
Vector4 Vector4::xwwz()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = w;
	result.w = z;
	return result;
}

// Swizzle for xwxw
Vector4 Vector4::xwxw()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = x;
	result.w = w;
	return result;
}

// Swizzle for xwxx
Vector4 Vector4::xwxx()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = x;
	result.w = x;
	return result;
}

// Swizzle for xwxy
Vector4 Vector4::xwxy()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = x;
	result.w = y;
	return result;
}

// Swizzle for xwxz
Vector4 Vector4::xwxz()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = x;
	result.w = z;
	return result;
}

// Swizzle for xwyw
Vector4 Vector4::xwyw()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = y;
	result.w = w;
	return result;
}

// Swizzle for xwyx
Vector4 Vector4::xwyx()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = y;
	result.w = x;
	return result;
}

// Swizzle for xwyy
Vector4 Vector4::xwyy()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = y;
	result.w = y;
	return result;
}

// Swizzle for xwyz
Vector4 Vector4::xwyz()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = y;
	result.w = z;
	return result;
}

// Swizzle for xwzw
Vector4 Vector4::xwzw()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = z;
	result.w = w;
	return result;
}

// Swizzle for xwzx
Vector4 Vector4::xwzx()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = z;
	result.w = x;
	return result;
}

// Swizzle for xwzy
Vector4 Vector4::xwzy()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = z;
	result.w = y;
	return result;
}

// Swizzle for xwzz
Vector4 Vector4::xwzz()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = z;
	result.w = z;
	return result;
}

// Swizzle for xxww
Vector4 Vector4::xxww()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = w;
	result.w = w;
	return result;
}

// Swizzle for xxwx
Vector4 Vector4::xxwx()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = w;
	result.w = x;
	return result;
}

// Swizzle for xxwy
Vector4 Vector4::xxwy()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = w;
	result.w = y;
	return result;
}

// Swizzle for xxwz
Vector4 Vector4::xxwz()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = w;
	result.w = z;
	return result;
}

// Swizzle for xxxw
Vector4 Vector4::xxxw()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = x;
	result.w = w;
	return result;
}

// Swizzle for xxxx
Vector4 Vector4::xxxx()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = x;
	result.w = x;
	return result;
}

// Swizzle for xxxy
Vector4 Vector4::xxxy()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = x;
	result.w = y;
	return result;
}

// Swizzle for xxxz
Vector4 Vector4::xxxz()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = x;
	result.w = z;
	return result;
}

// Swizzle for xxyw
Vector4 Vector4::xxyw()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = y;
	result.w = w;
	return result;
}

// Swizzle for xxyx
Vector4 Vector4::xxyx()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = y;
	result.w = x;
	return result;
}

// Swizzle for xxyy
Vector4 Vector4::xxyy()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = y;
	result.w = y;
	return result;
}

// Swizzle for xxyz
Vector4 Vector4::xxyz()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = y;
	result.w = z;
	return result;
}

// Swizzle for xxzw
Vector4 Vector4::xxzw()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = z;
	result.w = w;
	return result;
}

// Swizzle for xxzx
Vector4 Vector4::xxzx()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = z;
	result.w = x;
	return result;
}

// Swizzle for xxzy
Vector4 Vector4::xxzy()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = z;
	result.w = y;
	return result;
}

// Swizzle for xxzz
Vector4 Vector4::xxzz()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = z;
	result.w = z;
	return result;
}

// Swizzle for xyww
Vector4 Vector4::xyww()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = w;
	result.w = w;
	return result;
}

// Swizzle for xywx
Vector4 Vector4::xywx()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = w;
	result.w = x;
	return result;
}

// Swizzle for xywy
Vector4 Vector4::xywy()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = w;
	result.w = y;
	return result;
}

// Swizzle for xywz
Vector4 Vector4::xywz()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = w;
	result.w = z;
	return result;
}

// Swizzle for xyxw
Vector4 Vector4::xyxw()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = x;
	result.w = w;
	return result;
}

// Swizzle for xyxx
Vector4 Vector4::xyxx()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = x;
	result.w = x;
	return result;
}

// Swizzle for xyxy
Vector4 Vector4::xyxy()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = x;
	result.w = y;
	return result;
}

// Swizzle for xyxz
Vector4 Vector4::xyxz()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = x;
	result.w = z;
	return result;
}

// Swizzle for xyyw
Vector4 Vector4::xyyw()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = y;
	result.w = w;
	return result;
}

// Swizzle for xyyx
Vector4 Vector4::xyyx()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = y;
	result.w = x;
	return result;
}

// Swizzle for xyyy
Vector4 Vector4::xyyy()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = y;
	result.w = y;
	return result;
}

// Swizzle for xyyz
Vector4 Vector4::xyyz()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = y;
	result.w = z;
	return result;
}

// Swizzle for xyzw
Vector4 Vector4::xyzw()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = z;
	result.w = w;
	return result;
}

// Swizzle for xyzx
Vector4 Vector4::xyzx()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = z;
	result.w = x;
	return result;
}

// Swizzle for xyzy
Vector4 Vector4::xyzy()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = z;
	result.w = y;
	return result;
}

// Swizzle for xyzz
Vector4 Vector4::xyzz()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = z;
	result.w = z;
	return result;
}

// Swizzle for xzww
Vector4 Vector4::xzww()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = w;
	result.w = w;
	return result;
}

// Swizzle for xzwx
Vector4 Vector4::xzwx()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = w;
	result.w = x;
	return result;
}

// Swizzle for xzwy
Vector4 Vector4::xzwy()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = w;
	result.w = y;
	return result;
}

// Swizzle for xzwz
Vector4 Vector4::xzwz()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = w;
	result.w = z;
	return result;
}

// Swizzle for xzxw
Vector4 Vector4::xzxw()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = x;
	result.w = w;
	return result;
}

// Swizzle for xzxx
Vector4 Vector4::xzxx()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = x;
	result.w = x;
	return result;
}

// Swizzle for xzxy
Vector4 Vector4::xzxy()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = x;
	result.w = y;
	return result;
}

// Swizzle for xzxz
Vector4 Vector4::xzxz()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = x;
	result.w = z;
	return result;
}

// Swizzle for xzyw
Vector4 Vector4::xzyw()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = y;
	result.w = w;
	return result;
}

// Swizzle for xzyx
Vector4 Vector4::xzyx()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = y;
	result.w = x;
	return result;
}

// Swizzle for xzyy
Vector4 Vector4::xzyy()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = y;
	result.w = y;
	return result;
}

// Swizzle for xzyz
Vector4 Vector4::xzyz()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = y;
	result.w = z;
	return result;
}

// Swizzle for xzzw
Vector4 Vector4::xzzw()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = z;
	result.w = w;
	return result;
}

// Swizzle for xzzx
Vector4 Vector4::xzzx()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = z;
	result.w = x;
	return result;
}

// Swizzle for xzzy
Vector4 Vector4::xzzy()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = z;
	result.w = y;
	return result;
}

// Swizzle for xzzz
Vector4 Vector4::xzzz()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = z;
	result.w = z;
	return result;
}

// Swizzle for ywww
Vector4 Vector4::ywww()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = w;
	result.w = w;
	return result;
}

// Swizzle for ywwx
Vector4 Vector4::ywwx()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = w;
	result.w = x;
	return result;
}

// Swizzle for ywwy
Vector4 Vector4::ywwy()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = w;
	result.w = y;
	return result;
}

// Swizzle for ywwz
Vector4 Vector4::ywwz()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = w;
	result.w = z;
	return result;
}

// Swizzle for ywxw
Vector4 Vector4::ywxw()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = x;
	result.w = w;
	return result;
}

// Swizzle for ywxx
Vector4 Vector4::ywxx()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = x;
	result.w = x;
	return result;
}

// Swizzle for ywxy
Vector4 Vector4::ywxy()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = x;
	result.w = y;
	return result;
}

// Swizzle for ywxz
Vector4 Vector4::ywxz()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = x;
	result.w = z;
	return result;
}

// Swizzle for ywyw
Vector4 Vector4::ywyw()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = y;
	result.w = w;
	return result;
}

// Swizzle for ywyx
Vector4 Vector4::ywyx()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = y;
	result.w = x;
	return result;
}

// Swizzle for ywyy
Vector4 Vector4::ywyy()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = y;
	result.w = y;
	return result;
}

// Swizzle for ywyz
Vector4 Vector4::ywyz()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = y;
	result.w = z;
	return result;
}

// Swizzle for ywzw
Vector4 Vector4::ywzw()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = z;
	result.w = w;
	return result;
}

// Swizzle for ywzx
Vector4 Vector4::ywzx()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = z;
	result.w = x;
	return result;
}

// Swizzle for ywzy
Vector4 Vector4::ywzy()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = z;
	result.w = y;
	return result;
}

// Swizzle for ywzz
Vector4 Vector4::ywzz()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = z;
	result.w = z;
	return result;
}

// Swizzle for yxww
Vector4 Vector4::yxww()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = w;
	result.w = w;
	return result;
}

// Swizzle for yxwx
Vector4 Vector4::yxwx()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = w;
	result.w = x;
	return result;
}

// Swizzle for yxwy
Vector4 Vector4::yxwy()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = w;
	result.w = y;
	return result;
}

// Swizzle for yxwz
Vector4 Vector4::yxwz()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = w;
	result.w = z;
	return result;
}

// Swizzle for yxxw
Vector4 Vector4::yxxw()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = x;
	result.w = w;
	return result;
}

// Swizzle for yxxx
Vector4 Vector4::yxxx()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = x;
	result.w = x;
	return result;
}

// Swizzle for yxxy
Vector4 Vector4::yxxy()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = x;
	result.w = y;
	return result;
}

// Swizzle for yxxz
Vector4 Vector4::yxxz()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = x;
	result.w = z;
	return result;
}

// Swizzle for yxyw
Vector4 Vector4::yxyw()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = y;
	result.w = w;
	return result;
}

// Swizzle for yxyx
Vector4 Vector4::yxyx()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = y;
	result.w = x;
	return result;
}

// Swizzle for yxyy
Vector4 Vector4::yxyy()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = y;
	result.w = y;
	return result;
}

// Swizzle for yxyz
Vector4 Vector4::yxyz()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = y;
	result.w = z;
	return result;
}

// Swizzle for yxzw
Vector4 Vector4::yxzw()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = z;
	result.w = w;
	return result;
}

// Swizzle for yxzx
Vector4 Vector4::yxzx()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = z;
	result.w = x;
	return result;
}

// Swizzle for yxzy
Vector4 Vector4::yxzy()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = z;
	result.w = y;
	return result;
}

// Swizzle for yxzz
Vector4 Vector4::yxzz()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = z;
	result.w = z;
	return result;
}

// Swizzle for yyww
Vector4 Vector4::yyww()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = w;
	result.w = w;
	return result;
}

// Swizzle for yywx
Vector4 Vector4::yywx()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = w;
	result.w = x;
	return result;
}

// Swizzle for yywy
Vector4 Vector4::yywy()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = w;
	result.w = y;
	return result;
}

// Swizzle for yywz
Vector4 Vector4::yywz()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = w;
	result.w = z;
	return result;
}

// Swizzle for yyxw
Vector4 Vector4::yyxw()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = x;
	result.w = w;
	return result;
}

// Swizzle for yyxx
Vector4 Vector4::yyxx()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = x;
	result.w = x;
	return result;
}

// Swizzle for yyxy
Vector4 Vector4::yyxy()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = x;
	result.w = y;
	return result;
}

// Swizzle for yyxz
Vector4 Vector4::yyxz()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = x;
	result.w = z;
	return result;
}

// Swizzle for yyyw
Vector4 Vector4::yyyw()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = y;
	result.w = w;
	return result;
}

// Swizzle for yyyx
Vector4 Vector4::yyyx()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = y;
	result.w = x;
	return result;
}

// Swizzle for yyyy
Vector4 Vector4::yyyy()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = y;
	result.w = y;
	return result;
}

// Swizzle for yyyz
Vector4 Vector4::yyyz()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = y;
	result.w = z;
	return result;
}

// Swizzle for yyzw
Vector4 Vector4::yyzw()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = z;
	result.w = w;
	return result;
}

// Swizzle for yyzx
Vector4 Vector4::yyzx()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = z;
	result.w = x;
	return result;
}

// Swizzle for yyzy
Vector4 Vector4::yyzy()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = z;
	result.w = y;
	return result;
}

// Swizzle for yyzz
Vector4 Vector4::yyzz()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = z;
	result.w = z;
	return result;
}

// Swizzle for yzww
Vector4 Vector4::yzww()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = w;
	result.w = w;
	return result;
}

// Swizzle for yzwx
Vector4 Vector4::yzwx()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = w;
	result.w = x;
	return result;
}

// Swizzle for yzwy
Vector4 Vector4::yzwy()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = w;
	result.w = y;
	return result;
}

// Swizzle for yzwz
Vector4 Vector4::yzwz()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = w;
	result.w = z;
	return result;
}

// Swizzle for yzxw
Vector4 Vector4::yzxw()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = x;
	result.w = w;
	return result;
}

// Swizzle for yzxx
Vector4 Vector4::yzxx()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = x;
	result.w = x;
	return result;
}

// Swizzle for yzxy
Vector4 Vector4::yzxy()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = x;
	result.w = y;
	return result;
}

// Swizzle for yzxz
Vector4 Vector4::yzxz()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = x;
	result.w = z;
	return result;
}

// Swizzle for yzyw
Vector4 Vector4::yzyw()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = y;
	result.w = w;
	return result;
}

// Swizzle for yzyx
Vector4 Vector4::yzyx()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = y;
	result.w = x;
	return result;
}

// Swizzle for yzyy
Vector4 Vector4::yzyy()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = y;
	result.w = y;
	return result;
}

// Swizzle for yzyz
Vector4 Vector4::yzyz()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = y;
	result.w = z;
	return result;
}

// Swizzle for yzzw
Vector4 Vector4::yzzw()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = z;
	result.w = w;
	return result;
}

// Swizzle for yzzx
Vector4 Vector4::yzzx()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = z;
	result.w = x;
	return result;
}

// Swizzle for yzzy
Vector4 Vector4::yzzy()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = z;
	result.w = y;
	return result;
}

// Swizzle for yzzz
Vector4 Vector4::yzzz()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = z;
	result.w = z;
	return result;
}

// Swizzle for zwww
Vector4 Vector4::zwww()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = w;
	result.w = w;
	return result;
}

// Swizzle for zwwx
Vector4 Vector4::zwwx()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = w;
	result.w = x;
	return result;
}

// Swizzle for zwwy
Vector4 Vector4::zwwy()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = w;
	result.w = y;
	return result;
}

// Swizzle for zwwz
Vector4 Vector4::zwwz()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = w;
	result.w = z;
	return result;
}

// Swizzle for zwxw
Vector4 Vector4::zwxw()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = x;
	result.w = w;
	return result;
}

// Swizzle for zwxx
Vector4 Vector4::zwxx()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = x;
	result.w = x;
	return result;
}

// Swizzle for zwxy
Vector4 Vector4::zwxy()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = x;
	result.w = y;
	return result;
}

// Swizzle for zwxz
Vector4 Vector4::zwxz()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = x;
	result.w = z;
	return result;
}

// Swizzle for zwyw
Vector4 Vector4::zwyw()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = y;
	result.w = w;
	return result;
}

// Swizzle for zwyx
Vector4 Vector4::zwyx()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = y;
	result.w = x;
	return result;
}

// Swizzle for zwyy
Vector4 Vector4::zwyy()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = y;
	result.w = y;
	return result;
}

// Swizzle for zwyz
Vector4 Vector4::zwyz()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = y;
	result.w = z;
	return result;
}

// Swizzle for zwzw
Vector4 Vector4::zwzw()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = z;
	result.w = w;
	return result;
}

// Swizzle for zwzx
Vector4 Vector4::zwzx()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = z;
	result.w = x;
	return result;
}

// Swizzle for zwzy
Vector4 Vector4::zwzy()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = z;
	result.w = y;
	return result;
}

// Swizzle for zwzz
Vector4 Vector4::zwzz()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = z;
	result.w = z;
	return result;
}

// Swizzle for zxww
Vector4 Vector4::zxww()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = w;
	result.w = w;
	return result;
}

// Swizzle for zxwx
Vector4 Vector4::zxwx()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = w;
	result.w = x;
	return result;
}

// Swizzle for zxwy
Vector4 Vector4::zxwy()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = w;
	result.w = y;
	return result;
}

// Swizzle for zxwz
Vector4 Vector4::zxwz()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = w;
	result.w = z;
	return result;
}

// Swizzle for zxxw
Vector4 Vector4::zxxw()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = x;
	result.w = w;
	return result;
}

// Swizzle for zxxx
Vector4 Vector4::zxxx()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = x;
	result.w = x;
	return result;
}

// Swizzle for zxxy
Vector4 Vector4::zxxy()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = x;
	result.w = y;
	return result;
}

// Swizzle for zxxz
Vector4 Vector4::zxxz()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = x;
	result.w = z;
	return result;
}

// Swizzle for zxyw
Vector4 Vector4::zxyw()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = y;
	result.w = w;
	return result;
}

// Swizzle for zxyx
Vector4 Vector4::zxyx()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = y;
	result.w = x;
	return result;
}

// Swizzle for zxyy
Vector4 Vector4::zxyy()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = y;
	result.w = y;
	return result;
}

// Swizzle for zxyz
Vector4 Vector4::zxyz()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = y;
	result.w = z;
	return result;
}

// Swizzle for zxzw
Vector4 Vector4::zxzw()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = z;
	result.w = w;
	return result;
}

// Swizzle for zxzx
Vector4 Vector4::zxzx()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = z;
	result.w = x;
	return result;
}

// Swizzle for zxzy
Vector4 Vector4::zxzy()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = z;
	result.w = y;
	return result;
}

// Swizzle for zxzz
Vector4 Vector4::zxzz()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = z;
	result.w = z;
	return result;
}

// Swizzle for zyww
Vector4 Vector4::zyww()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = w;
	result.w = w;
	return result;
}

// Swizzle for zywx
Vector4 Vector4::zywx()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = w;
	result.w = x;
	return result;
}

// Swizzle for zywy
Vector4 Vector4::zywy()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = w;
	result.w = y;
	return result;
}

// Swizzle for zywz
Vector4 Vector4::zywz()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = w;
	result.w = z;
	return result;
}

// Swizzle for zyxw
Vector4 Vector4::zyxw()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = x;
	result.w = w;
	return result;
}

// Swizzle for zyxx
Vector4 Vector4::zyxx()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = x;
	result.w = x;
	return result;
}

// Swizzle for zyxy
Vector4 Vector4::zyxy()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = x;
	result.w = y;
	return result;
}

// Swizzle for zyxz
Vector4 Vector4::zyxz()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = x;
	result.w = z;
	return result;
}

// Swizzle for zyyw
Vector4 Vector4::zyyw()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = y;
	result.w = w;
	return result;
}

// Swizzle for zyyx
Vector4 Vector4::zyyx()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = y;
	result.w = x;
	return result;
}

// Swizzle for zyyy
Vector4 Vector4::zyyy()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = y;
	result.w = y;
	return result;
}

// Swizzle for zyyz
Vector4 Vector4::zyyz()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = y;
	result.w = z;
	return result;
}

// Swizzle for zyzw
Vector4 Vector4::zyzw()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = z;
	result.w = w;
	return result;
}

// Swizzle for zyzx
Vector4 Vector4::zyzx()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = z;
	result.w = x;
	return result;
}

// Swizzle for zyzy
Vector4 Vector4::zyzy()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = z;
	result.w = y;
	return result;
}

// Swizzle for zyzz
Vector4 Vector4::zyzz()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = z;
	result.w = z;
	return result;
}

// Swizzle for zzww
Vector4 Vector4::zzww()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = w;
	result.w = w;
	return result;
}

// Swizzle for zzwx
Vector4 Vector4::zzwx()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = w;
	result.w = x;
	return result;
}

// Swizzle for zzwy
Vector4 Vector4::zzwy()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = w;
	result.w = y;
	return result;
}

// Swizzle for zzwz
Vector4 Vector4::zzwz()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = w;
	result.w = z;
	return result;
}

// Swizzle for zzxw
Vector4 Vector4::zzxw()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = x;
	result.w = w;
	return result;
}

// Swizzle for zzxx
Vector4 Vector4::zzxx()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = x;
	result.w = x;
	return result;
}

// Swizzle for zzxy
Vector4 Vector4::zzxy()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = x;
	result.w = y;
	return result;
}

// Swizzle for zzxz
Vector4 Vector4::zzxz()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = x;
	result.w = z;
	return result;
}

// Swizzle for zzyw
Vector4 Vector4::zzyw()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = y;
	result.w = w;
	return result;
}

// Swizzle for zzyx
Vector4 Vector4::zzyx()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = y;
	result.w = x;
	return result;
}

// Swizzle for zzyy
Vector4 Vector4::zzyy()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = y;
	result.w = y;
	return result;
}

// Swizzle for zzyz
Vector4 Vector4::zzyz()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = y;
	result.w = z;
	return result;
}

// Swizzle for zzzw
Vector4 Vector4::zzzw()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = z;
	result.w = w;
	return result;
}

// Swizzle for zzzx
Vector4 Vector4::zzzx()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = z;
	result.w = x;
	return result;
}

// Swizzle for zzzy
Vector4 Vector4::zzzy()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = z;
	result.w = y;
	return result;
}

// Swizzle for zzzz
Vector4 Vector4::zzzz()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = z;
	result.w = z;
	return result;
}
//////////////// SWIZZLE ////////////////