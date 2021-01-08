// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<glut.h>
#include "DrawUtil.h"
#include "MathStruct.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Vector2.h"
#include "Matrix2D.h"
using namespace std;


void display();
void init();
void gradientLineTest();
void gradientTriangleTest();
void drawRect();

int main(int argc, char** argv)
{    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(200, 200);
    glutCreateWindow("title");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

}
void init()
{
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 200, 0, 200);
    //glEnable(GL_BLEND);
    //glBlendFunc(0.5, 0.5);
}



void display()
{
    glClear(GL_COLOR_BUFFER_BIT);


    //glColor3f(1, 0,0);
    //glBegin(GL_LINES);
    //glVertex2i(10, 10);
    //glVertex2i(190, 140);
    //glEnd();

    //gradientLineTest();//测试渐变色直线
    //gradientTriangleTest(); //测试渐变三角形


    Point p1 = { 20,20 };
    Point p2 = { 190,150 };
    //lineDDA(p2,p1 ); //测试DDA算法
    //lineBresenham(p1, p2);  //测试Bresenham算法


    Point p3 = { 100,100 };
    //sphereBresenham(p3, 50);
    sphereMidPoint(p3, 50);
    


}

void drawRect() {

    
    Vector2* v1 = new Vector2(50, 50);
    Vector2* v2 = new Vector2(100, 50);
    Vector2* v3 = new Vector2(100, 100);
    Vector2* v4 = new Vector2(50, 100);

    vector<Vector2>* vectors=new vector<Vector2>();
    vectors->push_back(*v1);
    vectors->push_back(*v2);
    vectors->push_back(*v3);
    vectors->push_back(*v4);

    Matrix2D* matrix = new Matrix2D();
    matrix->translate(50,50);
    matrix->apply(*vectors);


    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2d((*vectors)[0].x, (*vectors)[0].y);
    glVertex2d((*vectors)[1].x, (*vectors)[1].y);
    glVertex2d((*vectors)[2].x, (*vectors)[2].y);
    glVertex2d((*vectors)[3].x, (*vectors)[3].y);
    glEnd();

    delete (v1); delete(v2); delete(v3); delete(v4); delete(vectors);
}


void gradientLineTest() {

    glShadeModel(GL_SMOOTH);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex2f(50, 50);
    glColor3f(0, 1, 0);
    glVertex2f(150, 150);
    glEnd();

}

void gradientTriangleTest() {

    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex2f(50, 50);
    glColor3f(0, 1, 0);
    glVertex2f(150, 150);
    glColor3f(0, 0, 1);
    glVertex2f(20,120);
    glEnd();

}