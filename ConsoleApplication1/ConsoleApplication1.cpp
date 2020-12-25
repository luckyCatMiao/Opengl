// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<gl/glut.h>
#include "DrawUtil.h"
#include "MathStruct.h"

void display();
void init();
void gradientLineTest();
void gradientTriangleTest();

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


    /*Point p1 = { 20,20 };
    Point p2 = { 190,150 };
    lineDDA(p2,p1 );*/ //测试DDA算法

    //DrawSphere1({ 100,100 }, 50);
    DrawSphere3({ 100,100 }, 50);

    
    glFlush();

    


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