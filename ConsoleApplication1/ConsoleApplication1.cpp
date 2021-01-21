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
    glutInitWindowPosition(500, 500);
    glutInitWindowSize(500, 500);
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
    gluOrtho2D(0, 500, 0, 500);
    //glEnable(GL_BLEND);
    //glBlendFunc(0.5, 0.5);
}


void test1() {

    //��ά���α任
        //glViewport(0, 0, 100, 100);
        //glMatrixMode(GL_MODELVIEW);
        //glLoadIdentity();
        //glRotatef(30, 0, 0, 1);
        //glColor3f(1, 0, 0);
        //glBegin(GL_TRIANGLES);
        //glVertex2f(10, 10);
        //glVertex2f(200, 50);
        //glVertex2f(100,150);
        //glEnd();

        //glViewport(100, 100, 200, 200);
        //glBegin(GL_TRIANGLES);
        //glVertex2f(10, 10);
        //glVertex2f(200, 50);
        //glVertex2f(100, 150);
        //glEnd();
        //glFlush();

    ////openglƽ�Ʊ任
    ////���Ʊ任ǰ�ľ���
    //glColor3f(1, 0, 0);
    //glRecti(100, 100,200,200);
    ////���þ���任ջ
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    ////����ƽ�ƾ���
    //glTranslatef(200, 0, 0);
    ////���Ʊ任��ľ���
    //glColor3f(0, 1, 0);
    //glRecti(100, 100, 200, 200);


    ////opengl��ת�任
    ////���Ʊ任ǰ�ľ���
    //glColor3f(1, 0, 0);
    //glRecti(100, 100, 200, 200);
    ////���þ���任ջ
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    ////������ת����
    //glRotatef(30, 0, 0, 1);
    ////���Ʊ任��ľ���
    //glColor3f(0, 1, 0);
    //glRecti(100, 100, 200, 200);


    //opengl���ű任
    ////���Ʊ任ǰ�ľ���
    //glColor3f(1, 0, 0);
    //glRecti(100, 100, 200, 200);
    ////���þ���任ջ
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    ////�������ž���
    //glScalef(0.5, 0.5, 0);
    ////���Ʊ任��ľ���
    //glColor3f(0, 1, 0);
    //glRecti(100, 100, 200, 200);


    ////opengl��������ת�任
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    ////����ת���󣬼��������ƶ���ԭ����λ��
    //glTranslatef(150, 150,0);
    ////������ת����
    //glRotatef(45, 0, 0, 1);
    ////����ƽ�ƾ������������ƶ���ԭ��
    //glTranslatef(-150, -150, 0);
    //glColor3f(1, 0, 0);
    //glRecti(100, 100, 200, 200);




    ////opengl�Գ���ָ����
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    ////����������Ϊ�ο�
    //glColor3f(0, 0, 1);
    //glBegin(GL_LINES);
    //glVertex2i(0, -50);
    //glVertex2i(500, 450);
    //glEnd();
    ////����ԭ����
    //glColor3f(1, 0, 0);
    //glRecti(400, 200, 450, 250);


    //// ��ƽ�ƻ�ԭλ��
    //glTranslatef(50, 0, 0);
    ////����ת45
    //glRotatef(-45, 0, 0, 1);
    ////���϶Գƾ���
    //GLfloat arr[16] =
    //{
    //    -1,0,0,0,
    //    0,1,0,0,
    //    0,0,1,0,
    //    0,0,0,1

    //};
    //glMultMatrixf(arr);
    ////��ת45��ʹ���غ���y��(Ҳ�����غ���x�ᣬֻҪ֮����ж�Ӧ����任����)
    //glRotatef(45, 0, 0, 1);
    ////�ȰѶԳ���ƽ�Ƶ�ԭ��
    //glTranslatef(-50, 0, 0);
    //glColor3f(0, 1, 0);
    //glRecti(400, 200, 450, 250);


    //opengl��ָ������ת2
    //�����Ƶ�(200,200)��ת360��
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();

    //for (int i = 0; i < 36; i++)
    //{
    //    glColor3f(1-1/36.f*i, 1/36.f*i, 0);
    //    glRecti(100, 100, 120, 120);
    //    //�����ο���
    //    glColor3f(0, 0, 0);
    //    glBegin(GL_LINES);
    //    glVertex2f(200, 200);
    //    glVertex2f(110, 110);
    //    glEnd();
    //    glTranslatef(200, 200, 0);
    //    glRotatef(10, 0, 0, 1);
    //    glTranslatef(-200, -200, 0);
    //}


        

    //opengl��ָ������ת3
    //�����Ƶ�(200,200)��ת360��
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    for (int i = 0; i < 36; i++)
    {
        glColor3f(1-1/36.f*i, 1/36.f*i, 0);
        glRecti(100, 100, 120, 120);
        //�����ο���
        glColor3f(0, 0, 0);
        glBegin(GL_LINES);
        glVertex2f(200, 200);
        glVertex2f(110, 110);
        glEnd();
        glTranslatef(200, 200, 0);
        glRotatef(10, 0, 0, 1);
        glTranslatef(-200, -200, 0);
    }


    
    ////openglб�б任
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();

    //glColor3f(0, 0, 1);
    //glRecti(100, 100, 200, 200);

    //GLfloat arr[16] =
    //{
    //    1,0,0,0,
    //    1,1,0,0,
    //    0,0,1,0,
    //    0,0,0,1
    //};
    //glMultMatrixf(arr);
    //glColor3f(0, 1, 1);
    //glRecti(100, 100, 200, 200);


    glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //gradientLineTest();//���Խ���ɫֱ��
    //gradientTriangleTest(); //���Խ���������


    //Point p1 = { 20,20 };
    //Point p2 = { 190,150 };
    //lineDDA(p2,p1 ); //����DDA�㷨
    //lineBresenham(p1, p2);  //����Bresenham�㷨


    //���Ի�Բ
    //Point p3 = { 100,100 };
    //sphereBresenham(p3, 50);
    //sphereMidPoint(p3, 50);
    
    //������ˮ������Ҫ�ȶ���߽�
    //GLfloat* borderColor = new GLfloat[3]{0,0,0};
    //GLfloat* fillColor = new GLfloat[3]{ 1,0,0 };
    //glColor3f(borderColor[0], borderColor[1], borderColor[2]);
    //glBegin(GL_LINE_LOOP);
    //    glVertex2f(20,20);
    //    glVertex2f(150, 20);
    //    glVertex2f(150, 150);
    //    glVertex2f(0, 150);
    //glEnd();
    //glFlush();


    ////floodFill4Recur(75, 75, borderColor, fillColor);
    //floodFill4Stack(75, 75, borderColor, fillColor);

    //delete(borderColor);
    //delete(fillColor);

    //���Բü�
     //Point p1 = { 20,20 };
     //Point p2 = { 190,150 };
     //Point min = { 50,50 };
     //Point max = { 100,100 };
     //glColor3f(0, 0, 0);
     //glRecti(min.x, min.y, max.x, max.y);
     ////lineDDA(p1, p2);
     //cohen_Sutherland_LineClip(p1, p2, min, max);
     //lineDDA(p1, p2);


    test1();

    

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