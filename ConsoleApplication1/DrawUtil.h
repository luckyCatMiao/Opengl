#pragma once
#ifndef _DrawUtil
#define _DrawUtil
#endif // !MathStruct

#include "MathStruct.h"
void lineDDA(Point p1,Point p2);
void lineBresenham(Point p1, Point p2);
void lineMidPoint(Point p1, Point p2);

void sphereSimple(Point center, int  radius);
void spherePolarCoord(Point center, int  radius);
void spherePolarCoord2(Point center, int  radius);
void sphereBresenham(Point center, int radius);
void sphereMidPoint(Point center, int radius);