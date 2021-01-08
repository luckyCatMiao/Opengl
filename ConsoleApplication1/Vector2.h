#pragma once
#include <glut.h>
#ifndef Vector2_H
#define Vector2_H
class Vector2
{
public:
	GLdouble x, y;
	Vector2(GLdouble x, GLdouble y)
	{
		this->x = x;
		this->y = y;
	}
};

Vector2& distance(Vector2& v1, Vector2& v2);
#endif // !1