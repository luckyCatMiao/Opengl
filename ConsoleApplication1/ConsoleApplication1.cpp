// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<gl/glut.h>
#include "DrawUtil.h"
#include "MathStruct.h"

void display();
void init();



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(400, 400);
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
    gluOrtho2D(0, 100, 0, 100);

}



void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0.4,0.2);
    glBegin(GL_LINES);
    glVertex2i(10, 10);
    glVertex2i(90, 40);
    glEnd();
    Point p1 = { 20,20 };
    Point p2 = { 90,50 };
    lineDDA(p2,p1 );
    glFlush();

    


}

