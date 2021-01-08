#pragma once
#ifndef _DrawUtil
#define _DrawUtil


#include "MathStruct.h"
#include<glut.h>

//����
void lineDDA(Point p1,Point p2);
void lineBresenham(Point p1, Point p2);
void lineMidPoint(Point p1, Point p2);

//����
void sphereSimple(Point center, int  radius);
void spherePolarCoord(Point center, int  radius);
void spherePolarCoord2(Point center, int  radius);
void sphereBresenham(Point center, int radius);
void sphereMidPoint(Point center, int radius);

//���
void floodFill4Stack(int x, int y, GLfloat* borderColor, GLfloat* fillColor);
void floodFill4Recur(int x, int y, GLfloat* borderColor, GLfloat* fillColor);


#endif // !MathStruct