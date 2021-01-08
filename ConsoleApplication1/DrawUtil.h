#pragma once
#ifndef _DrawUtil
#define _DrawUtil
#endif // !MathStruct

#include "MathStruct.h"
void lineDDA(Point p1,Point p2);
void lineBresenham(Point p1, Point p2);
void lineMidPoint(Point p1, Point p2);

void drawSphere1(Point center, int  radius);
void drawSphere2(Point center, int  radius);
void drawSphere3(Point center, int  radius);