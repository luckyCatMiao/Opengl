#include "DrawUtil.h"
#include<gl/glut.h>
#include <math.h>

inline int max(float a, float b) { return a > b ? a : b; }
#define round(x) ((int)(x+0.5))
void lineDDA(Point p1, Point p2)
{
	glBegin(GL_POINTS);
	float xIncrease = p2.x - p1.x;
	float yIncrease = p2.y - p1.y;
	float xStep, yStep;
	float count = max(fabsf(xIncrease), fabsf(yIncrease));

	xStep = xIncrease / count;
	yStep = yIncrease / count;

	float startX = p1.x;
	float startY = p1.y;
	for (int i = 0; i < count; i++)
	{
		glVertex2i(round(startX), round(startY));
		startX += xStep;
		startY += yStep;
	}

	glEnd();
}
