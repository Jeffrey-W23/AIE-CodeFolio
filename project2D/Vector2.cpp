// #include, using, etc
#include "Vector2.h"

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
Vector2::Vector2()
{
	x = 0;
	y = 0;
}

//--------------------------------------------------------------------------------------
// Constructor for passing in two floats.
//--------------------------------------------------------------------------------------
Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Vector2::~Vector2()
{
}

//--------------------------------------------------------------------------------------
// Addition: Overloads the "+" operator so that Vector2s can be added together.
//
// Param:
//		rhs: The right hand side value being passed into the function that you want added.
// Return:
//		Returns a Vector2 value equel to the values you added together.
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator+(const Vector2& rhs)
{
	Vector2 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;

	return result;
}

//--------------------------------------------------------------------------------------
// Subtraction: Overloads the "-" operator so that Vector2s can be subtracted from each other.
//
// Param:
//		rhs: The right hand side value being passed into the function that you want subtract.
// Return:
//		Returns a Vector2 value equel to the values you subtract together.
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator-(const Vector2& rhs)
{
	Vector2 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;

	return result;
}

//--------------------------------------------------------------------------------------
// Divide: Overloads the "/" operator so that Vector2s can be Divided together.
//
// Param:
//		rhs: The right hand side value being passed into the function that you want Divide.
// Return:
//		Returns a Vector2 value equel to the values you Divide together.
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator/(const float rhs)
{
	Vector2 result;
	result.x = x / rhs;
	result.y = y / rhs;

	return result;
}

//--------------------------------------------------------------------------------------
// Multiply vector by float: Overloads the "*" operator so that Vector2s can be Multiplied by floats.
//
// Param:
//		rhs: The float you would like to be multiplied by the vector
// Return:
//		Returns a Vector2 value equel to the values you Multiplied by.
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator*(const float rhs)
{
	Vector2 result;
	result.x = x * rhs;
	result.y = y * rhs;

	return result;
}

//--------------------------------------------------------------------------------------
// Multiply float by vector: Overloads the "*" operator so that floats can be Multiplied by Vector2s.
//
// Param:
//		lhs: The float you would like to multiply by the Vector2.
//		rhs: The Vector2 you would like to be multiplied by the float.
// Return:
//		Returns a Vector2 value equel to the values you Multiplied by.
//
// (out side of class so we can order)
//--------------------------------------------------------------------------------------
Vector2 operator*(float lhs, const Vector2& rhs)
{
	Vector2 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;

	return result;
}

//--------------------------------------------------------------------------------------
// Allow negative vectors: overload the "-" operator to also allow negative vectors.
//
// Return:
//		Returns a negative Vector2.
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator-()
{
	Vector2 result;
	result.x = -x;
	result.y = -y;

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
bool Vector2::operator>(const Vector2 rhs)
{
	return (x > rhs.x && y > rhs.y);
}

// --------------------------------------------------------------------------------------
// Less then operator: Overloads the "<" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector to be checked against.
// Return:
//		Returns a bool of true or false for if the value is less then or not.
//--------------------------------------------------------------------------------------
bool Vector2::operator<(const Vector2 rhs)
{
	return (x < rhs.x && y < rhs.y);

}

//--------------------------------------------------------------------------------------
// Plus equal: Overloads the "+=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector you would like to increase incremently.
// Return:
//		Returns a Vector2.
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator+=(const Vector2& rhs)
{
	x += rhs.x;
	y += rhs.y;

	return *this;
}

//--------------------------------------------------------------------------------------
// Subtract equal: Overloads the "-=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector you would like to decrease incremently.
// Return:
//		Returns a Vector2.
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator-=(const Vector2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;

	return *this;
}

//--------------------------------------------------------------------------------------
// Multiply equal: Overloads the "*=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector you would like to decrease incremently.
// Return:
//		Returns a Vector2.
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator*=(const float rhs)
{
	Vector2 result;
	result.x = x *= rhs;
	result.y = y *= rhs;

	return result;
}

//--------------------------------------------------------------------------------------
// Divide equal: Overloads the "/=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector you would like to Divide incremently.
// Return:
//		Returns a Vector2.
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator/=(const float rhs)
{
	Vector2 result;
	result.x = x /= rhs;
	result.y = y /= rhs;

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
float& Vector2::operator[](const int rhs)
{
	if (rhs == 0)
		return x;
	else if (rhs == 1)
		return y;
	else
		return x;
}

//--------------------------------------------------------------------------------------
// Cast operator to float pointer
//--------------------------------------------------------------------------------------
Vector2::operator float*()
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
bool Vector2::operator==(const Vector2 rhs)
{
	return (x == rhs.x && y == rhs.y);
}

//--------------------------------------------------------------------------------------
// Not Equal to operator: Overloads the "!=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector to be checked against.
// Return:
//		Returns a bool of true or false for if the value is equal to or not.
//--------------------------------------------------------------------------------------
bool Vector2::operator!=(const Vector2 rhs)
{
	return (x != rhs.x && y != rhs.y);
}

//--------------------------------------------------------------------------------------
// Greater then or equal to operator: Overloads the ">=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector to be checked against.
// Return:
//		Returns a bool of true or false for if the value is greater then or equal to or not.
//--------------------------------------------------------------------------------------
bool Vector2::operator>=(const Vector2 rhs)
{
	return (x >= rhs.x && y >= rhs.y);
}

//--------------------------------------------------------------------------------------
// Less then or equal to operator: Overloads the "<=" operator so that it can be used with Vectors.
//
// Param:
//		rhs: The Vector to be checked against.
// Return:
//		Returns a bool of true or false for if the value is less then or equal or not.
//--------------------------------------------------------------------------------------
bool Vector2::operator<=(const Vector2 rhs)
{
	return (x <= rhs.x && y <= rhs.y);
}

//--------------------------------------------------------------------------------------
// Dot Product: Dot Product of two vectors.
//
// Param:
//		rhs: Vector2 you want the dot product of.
// Return:
//		Returns a float value of the dot product of the vector.
//--------------------------------------------------------------------------------------
float Vector2::dot(const Vector2& rhs)
{
	float result;
	result = x * rhs.x + y * rhs.y;
	return result;
}

//--------------------------------------------------------------------------------------
// Magnitude: Returns the length of this vector.
//
// Return:
//		Returns a float that is the length of the vector.
//--------------------------------------------------------------------------------------
float Vector2::magnitude()
{
	float result;
	result = sqrtf(x*x + y*y);
	return result;
}

//--------------------------------------------------------------------------------------
// MagnititudeSquared: Returns the squared length of this vector
//
// Return:
//		Returns a float that is the length of the vector.
//--------------------------------------------------------------------------------------
float Vector2::MagnititudeSquared()
{
	float result;
	result = x*x + y*y;
	return result;
}

//--------------------------------------------------------------------------------------
// Normalise: Makes this vector have a magnitude of 1. (It keeps the same direction)
// This function will change the current vector.
//--------------------------------------------------------------------------------------
void Vector2::normalise()
{
	float mag = magnitude();

	if (mag != 0)
	{
		x = x / mag;
		y = y / mag;
	}
}

//--------------------------------------------------------------------------------------
// Normalised: Makes this vector have a magnitude of 1. (It keeps the same direction) 
// This function will not change the current vector and a new one will be created.
//
// Param:
//		data: A Vector2 to be normalised.
// Return:
//		Returns a Vector2 of the normalised value.
//--------------------------------------------------------------------------------------
Vector2 Vector2::Normalised(Vector2 data)
{
	float mag = data.magnitude();

	Vector2 result;

	if (mag != 0)
	{
		result.x = data.x / mag;
		result.y = data.y / mag;
		
		return result;
	}

	return Vector2();
}

//--------------------------------------------------------------------------------------
// CalcNormal: Calculate the normal of a face.
//
// Param:
//		pos: Vector2 position.
// Return:
//		Returns a Vector2 value that is the normal of a face.
//--------------------------------------------------------------------------------------
Vector2 Vector2::CalcNormal(Vector2 pos)
{
	Vector2 vec;
	Vector2 res;

	vec.x = pos.x - x;
	vec.y = pos.y - y;
	vec.normalise();

	res.x = vec.y;
	res.y = -vec.x;

	return res;
}

//--------------------------------------------------------------------------------------
// Min: Returns a vector that is made from the smallest components of two vectors.
//
// Param:
//		rhs: The second vector to compare to.
// Return:
//		Returns a Vector2 that is the smallest components of two vectors.
//--------------------------------------------------------------------------------------
Vector2 Vector2::Min(Vector2 rhs)
{
	Vector2 result;

	if (x < rhs.x)
		result.x = x;
	else
		result.x = rhs.x;

	if (y < rhs.y)
		result.y = y;
	else
		result.y = rhs.y;

	return result;
}

//--------------------------------------------------------------------------------------
// Max: Returns a vector that is made from the largest components of two vectors.
//
// Param:
//		rhs: The second vector to compare to.
// Return:
//		Returns a Vector2 that is the largest components of two vectors.
//--------------------------------------------------------------------------------------
Vector2 Vector2::Max(Vector2 rhs)
{
	Vector2 result;

	if (x > rhs.x)
		result.x = x;
	else
		result.x = rhs.x;

	if (y > rhs.y)
		result.y = y;
	else
		result.y = rhs.y;

	return result;
}

//--------------------------------------------------------------------------------------
// Clamp: Stop a vector at a max length.
//
// Param:
//		min: The minimum of the vector.
//		max: The maximum of the vector.
// Return:
//		Returns a Vector2 clamped at the maxlength.
//--------------------------------------------------------------------------------------
Vector2 Vector2::Clamp(Vector2 min, Vector2 max)
{
	Vector2 result;

	result = this->Max(min);
	result = result.Min(max);

	return result;
}

//--------------------------------------------------------------------------------------
// Lerp: Linearly interpolates between vectors a and b by t.
//
// Param:
//		a: Vector2
//		b: Vector2
//		t: Float 
// Return:
//		Returns a Vector2 
//--------------------------------------------------------------------------------------
Vector2 Vector2::Lerp(Vector2 a, Vector2 b, float t)
{
	return (a + b) * t;
}

//--------------------------------------------------------------------------------------
// Distance: Returns the distance between a and b.
//
// Param:
//		a: Vector2
//		b: Vector2
// Return:
//		Returns a float which is the distance between a and b.
//--------------------------------------------------------------------------------------
float Vector2::Distance(Vector2 pos1, Vector2 pos2)
{
	Vector2 diff =  pos1 - pos2;
	return diff.magnitude(); // change for vector 3 and 4
}

//--------------------------------------------------------------------------------------
// Bezier: A function to calculate a bezier curves.
//
// Param:
//		t: A float representing time.
//		a: Vector2 point.
//		b: Vector2 point.
//		c: Vector2 point.
// Return:
//		Returns a Vector2 value of the Bezier curve.
//--------------------------------------------------------------------------------------
Vector2 Vector2::Bezier(float t, Vector2 a, Vector2 b, Vector2 c)
{
	Vector2 result;
	Vector2 ab = Lerp(a, b, t);
	Vector2 bc = Lerp(b, c, t);
	result = Lerp(ab, bc, t);

	return result;
}

//--------------------------------------------------------------------------------------
// hermiteCurve: A function to calculate a hermite Curve.
//
// Param:
//		point0: Vector2 point.
//		tangent0: Vector2 tangent.
//		point1: Vector2 point.
//		tangent1: Vector2 tangent.
//		t: A float representing time.
// Return:
//		Returns a Vector2 value of the hermite curve.
//--------------------------------------------------------------------------------------
Vector2 Vector2::hermiteCurve(Vector2 point0, Vector2 tangent0, Vector2 point1, Vector2 tangent1, float t) 
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
// Swizzle: Switch around the values of x and y to every possible combo.
//
// Return:
//		Returns a Vector2 value with the applied changes.
//--------------------------------------------------------------------------------------
//////////////// SWIZZLE ////////////////
// Swizzle for xx
Vector2 Vector2::xx()
{
	Vector2 result;
	result.x = x;
	result.y = x;
	return result;
}

// Swizzle for xy
Vector2 Vector2::xy()
{
	Vector2 result;
	result.x = x;
	result.y = y;
	return result;
}

// Swizzle for yx
Vector2 Vector2::yx()
{
	Vector2 result;
	result.x = y;
	result.y = x;
	return result;
}

// Swizzle for yy
Vector2 Vector2::yy()
{
	Vector2 result;
	result.x = y;
	result.y = y;
	return result;
}
//////////////// SWIZZLE ////////////////