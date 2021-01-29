#pragma once
#ifndef _DrawUtil
#define _DrawUtil


#include "MathStruct.h"
#include<glut.h>
#include<Eigen/Dense>
using namespace Eigen;

//»­Ïß
void lineDDA(Point p1,Point p2);
void lineBresenham(Point p1, Point p2);
void lineMidPoint(Point p1, Point p2);

//»­Ïß
void sphereSimple(Point center, int  radius);
void spherePolarCoord(Point center, int  radius);
void spherePolarCoord2(Point center, int  radius);
void sphereBresenham(Point center, int radius);
void sphereMidPoint(Point center, int radius);

//Ìî³ä
void floodFill4Stack(int x, int y, GLfloat* borderColor, GLfloat* fillColor);
void floodFill4Recur(int x, int y, GLfloat* borderColor, GLfloat* fillColor);


//²Ã¼ô
bool cohen_Sutherland_LineClip(Point& p1, Point& p2, Point min, Point max);
bool pointClip(Point& point, Point min, Point max);


//²åÖµÇúÏß
void quadraticInterpolationCurve(Matrix<double, 3, 1> xdatas, Matrix<double, 3, 1> ydatas);
void cubicInterpolationCurve(Matrix<double, 4, 1> xdatas, Matrix<double, 4, 1> ydatas);
void quarticInterpolationCurve(Matrix<double, 5, 1> xdatas, Matrix<double, 5, 1> ydatas);
void hermiteCurve(Matrix<double, 4, 1> xdatas, Matrix<double, 4, 1> ydatas);
void cardinalCurve(Matrix<double, 4, 1> xdatas, Matrix<double, 4, 1> ydatas);
void bezierCurve(Matrix<double, 4, 1> xdatas, Matrix<double, 4, 1> ydatas);
#endif // !MathStruct