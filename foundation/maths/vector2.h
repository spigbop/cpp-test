#ifndef VECTOR2_H
#define VECTOR2_H

#include "../string/string.h"
#include <cmath>

class Vector2 {
public:
	float x = 0.0f;
	float y = 0.0f;

	Vector2(float x, float y);

	void normalize();

	Vector2 normalized() const;
	float lengthSquared() const;
	float length() const;
	String str() const;

	friend Vector2 operator+(const Vector2& lhs, const Vector2& rhs);
	friend Vector2 operator-(const Vector2& lhs, const Vector2& rhs);
};

#endif
