// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<glut.h>
#include "DrawUtil.h"
#include "MathStruct.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
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
	gluPerspective(45, 1, 0, 100);
	//gluOrtho2D(0, 500, 0, 500);
	//glEnable(GL_BLEND);
	//glBlendFunc(0.5, 0.5);
}


void test1() {

	//二维几何变换
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

	////opengl平移变换
	////绘制变换前的矩形
	//glColor3f(1, 0, 0);
	//glRecti(100, 100,200,200);
	////重置矩阵变换栈
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	////构建平移矩阵
	//glTranslatef(200, 0, 0);
	////绘制变换后的矩形
	//glColor3f(0, 1, 0);
	//glRecti(100, 100, 200, 200);


	////opengl旋转变换
	////绘制变换前的矩形
	//glColor3f(1, 0, 0);
	//glRecti(100, 100, 200, 200);
	////重置矩阵变换栈
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	////构建旋转矩阵
	//glRotatef(30, 0, 0, 1);
	////绘制变换后的矩形
	//glColor3f(0, 1, 0);
	//glRecti(100, 100, 200, 200);


	//opengl缩放变换
	////绘制变换前的矩形
	//glColor3f(1, 0, 0);
	//glRecti(100, 100, 200, 200);
	////重置矩阵变换栈
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	////构建缩放矩阵
	//glScalef(0.5, 0.5, 0);
	////绘制变换后的矩形
	//glColor3f(0, 1, 0);
	//glRecti(100, 100, 200, 200);


	////opengl绕中心旋转变换
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	////逆旋转矩阵，即把物体移动回原来的位置
	//glTranslatef(150, 150,0);
	////复合旋转矩阵
	//glRotatef(45, 0, 0, 1);
	////构建平移矩阵将物体中心移动到原点
	//glTranslatef(-150, -150, 0);
	//glColor3f(1, 0, 0);
	//glRecti(100, 100, 200, 200);




	////opengl对称于指定轴
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	////画出该轴作为参考
	//glColor3f(0, 0, 1);
	//glBegin(GL_LINES);
	//glVertex2i(0, -50);
	//glVertex2i(500, 450);
	//glEnd();
	////画出原矩形
	//glColor3f(1, 0, 0);
	//glRecti(400, 200, 450, 250);


	//// 逆平移回原位置
	//glTranslatef(50, 0, 0);
	////逆旋转45
	//glRotatef(-45, 0, 0, 1);
	////乘上对称矩阵
	//GLfloat arr[16] =
	//{
	//    -1,0,0,0,
	//    0,1,0,0,
	//    0,0,1,0,
	//    0,0,0,1

	//};
	//glMultMatrixf(arr);
	////旋转45度使其重合于y轴(也可以重合于x轴，只要之后进行对应的逆变换即可)
	//glRotatef(45, 0, 0, 1);
	////先把对称轴平移到原点
	//glTranslatef(-50, 0, 0);
	//glColor3f(0, 1, 0);
	//glRecti(400, 200, 450, 250);


	//opengl绕指定点旋转2
	//假设绕点(200,200)旋转360度
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	//for (int i = 0; i < 36; i++)
	//{
	//    glColor3f(1-1/36.f*i, 1/36.f*i, 0);
	//    glRecti(100, 100, 120, 120);
	//    //画出参考线
	//    glColor3f(0, 0, 0);
	//    glBegin(GL_LINES);
	//    glVertex2f(200, 200);
	//    glVertex2f(110, 110);
	//    glEnd();
	//    glTranslatef(200, 200, 0);
	//    glRotatef(10, 0, 0, 1);
	//    glTranslatef(-200, -200, 0);
	//}


	//opengl绕指定点旋转3
	//假设绕点(200,200)旋转360度
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	//for (int i = 0; i < 36; i++)
	//{
	//    glColor3f(1-1/36.f*i, 1/36.f*i, 0);
	//    glRecti(100, 100, 120, 120);
	//    //画出参考线
	//    glColor3f(0, 0, 0);
	//    glBegin(GL_LINES);
	//    glVertex2f(200, 200);
	//    glVertex2f(110, 110);
	//    glEnd();
	//    glTranslatef(200, 200, 0);
	//    glRotatef(10, 0, 0, 1);
	//    glTranslatef(-200, -200, 0);
	//}

	////opengl斜切变换
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


	//glFlush();


	//opengl三维几何变换  
	//opengl三维平移
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//glTranslatef(-1, 0, -10);
	//glColor3f(1, 0, 0);
	//glutWireCube(1);

	//glTranslatef(3, 0, 0);
	//glColor3f(0, 1, 0);
	//glutWireCube(1);

	//opengl三维缩放
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//glTranslatef(-1, 0, -10);
	//glColor3f(1, 0, 0);
	//glutWireCube(1);
	//
	//glScalef(1.5, 1.5, 1.5);
	//glColor3f(0, 1, 0);
	//glutWireCube(1);


	//opengl三维旋转(绕平行于坐标轴的轴旋转)
	//此例为原点绕经过(0,0,-5)垂直于xz平面的旋转轴进行旋转
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	////为了方便查看效果，将整体向z轴负向平移10个单位
	//glTranslatef(0, 0, -10);
	//for (int i = 0; i < 18; i++)
	//{
	//	//进行逆平移
	//	glTranslatef(0, 0, -5);
	//	//进行所需的旋转
	//	glRotatef(20, 0, 1, 0);
	//	//将坐标轴平移至与y轴重合
	//	glTranslatef(0, 0, 5);
	//	glColor3f(1, 0, 0);
	//	glutWireCube(1);
	//}



	//opengl三维旋转(绕不平行于坐标轴的轴旋转)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-1, -1, -20);
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	//绘制出旋转轴
	glVertex3f(-25, -30, -25);
	glVertex3f(20, 15, 20);
	glEnd();
	glColor3f(1, 0, 0);
	for (int i = 0; i < 36; i++)
	{
		//逆变换
		glTranslatef(5, 0, 5);
		glRotatef(-45, 0, 0, 1);
		glRotatef(45, 1, 0, 0);
		glRotatef(10, 0, 1, 0);
		//再绕x轴顺时针旋转45度使旋转轴与y轴重合
		glRotatef(-45, 1, 0, 0);
		//先绕z轴逆时针旋转45度使旋转轴位于yz平面上
		glRotatef(45, 0, 0, 1);
		//先将旋转轴平移至经过原点
		glTranslatef(-5, 0, -5);
		glutWireCube(1);
	}









	//测试
	//glPointSize(20);
	//glColor3f(1, 0, 0);
	//glBegin(GL_POINTS);
	//glVertex2f(0, 0);
	//glEnd();
	//
	//for (int i = 0; i < 50; i++) {
	//
	//	glTranslatef(0, 200, 0);
	//	glRotatef(10, 0, 0, 1);
	//	glTranslatef(0, -200, 0);
	//	glBegin(GL_POINTS);
	//	glVertex2f(0, 0);
	//	glEnd();
	//}


	//三维对称于某个平面

	glFlush();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//gradientLineTest();//测试渐变色直线
	//gradientTriangleTest(); //测试渐变三角形


	//Point p1 = { 20,20 };
	//Point p2 = { 190,150 };
	//lineDDA(p2,p1 ); //测试DDA算法
	//lineBresenham(p1, p2);  //测试Bresenham算法


	//测试画圆
	//Point p3 = { 100,100 };
	//sphereBresenham(p3, 50);
	//sphereMidPoint(p3, 50);

	//测试漫水法，需要先定义边界
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

	//测试裁剪
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

	vector<Vector2>* vectors = new vector<Vector2>();
	vectors->push_back(*v1);
	vectors->push_back(*v2);
	vectors->push_back(*v3);
	vectors->push_back(*v4);

	Matrix2D* matrix = new Matrix2D();
	matrix->translate(50, 50);
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
	glVertex2f(20, 120);
	glEnd();

}