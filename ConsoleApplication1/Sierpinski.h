#pragma once
#include<glut.h>

void DrawSierpinskiByPoint(GLfloat vertices[3][2], GLfloat startPoint[3], unsigned int pointCount);
void DrawSierpinskiBySolid(GLfloat vertices[3][2], unsigned int divideCount);