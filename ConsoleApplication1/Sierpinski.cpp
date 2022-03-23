#include "Sierpinski.h"
#include <cstdlib>
#include<glut.h>



void drawTriangle(GLfloat p1[2], GLfloat p2[2], GLfloat p3[2])
{
    glVertex2fv(p1);
    glVertex2fv(p2);
    glVertex2fv(p3);
}
void divide_triangle(GLfloat a[2], GLfloat b[2], GLfloat c[2], unsigned int m)
{
    GLfloat v0[2], v1[2], v2[2];
    int j;
    if (m > 0)
    {
        for (j = 0; j < 2; j++) v0[j] = (a[j] + b[j]) / 2;
        for (j = 0; j < 2; j++) v1[j] = (a[j] + c[j]) / 2;
        for (j = 0; j < 2; j++) v2[j] = (b[j] + c[j]) / 2;
        divide_triangle(a, v0, v1, m - 1);
        divide_triangle(c, v1, v2, m - 1);
        divide_triangle(b, v2, v0, m - 1);
    }
    else drawTriangle(a, b, c);
}

void DrawSierpinskiBySolid(GLfloat vertices[3][2], unsigned int divideCount)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    divide_triangle(vertices[0],vertices[1],vertices[2], divideCount);
    glEnd();
    glFlush();
}


void DrawSierpinskiByPoint(GLfloat vertices[3][2], GLfloat startPoint[3],unsigned int pointCount)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); 
    glBegin(GL_POINTS);

    for (unsigned int k = 0; k < pointCount; k++)
    {
        int index = rand() % 3;

        startPoint[0] = (startPoint[0] + vertices[index][0]) / 2.0;
        startPoint[1] = (startPoint[1] + vertices[index][1]) / 2.0;

        glVertex2fv(startPoint);

    }
    glEnd();
    glFlush(); 
}






