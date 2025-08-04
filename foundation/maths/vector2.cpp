#include "./vector2.h"

#include <cstdio>

Vector2::Vector2(float x, float y) : x(x), y(y) {}

void Vector2::normalize() {
	float len = length();

	x /= len;
	y /= len;
}

Vector2 Vector2::normalized() const {
	if (x == 0 && y == 0) return Vector2(0.0f, 0.0f);

	float len = length();
	Vector2 normal = Vector2(x / len, y / len);

	return normal;
}

float Vector2::lengthSquared() const {
	return x * x + y * y;
}

float Vector2::length() const {
	return std::sqrt(lengthSquared());
}

String Vector2::str() const {
	char buffer[64];
	std::snprintf(buffer, sizeof(buffer), "(%.2f, %.2f)", x, y);
	return String(buffer);
}

Vector2 operator+(const Vector2& lhs, const Vector2& rhs) {
	return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

Vector2 operator-(const Vector2& lhs, const Vector2& rhs) {
	return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}
