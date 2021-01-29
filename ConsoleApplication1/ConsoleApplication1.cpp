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
#include<Eigen/Dense>
#include<cmath>

using namespace std;
using namespace Eigen;


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
	//gluPerspective(45, 1, 0, 100);
	gluOrtho2D(0, 500, 0, 500);
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
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//glTranslatef(-1, -1, -20);
	//glColor3f(0, 1, 0);
	//glBegin(GL_LINES);
	////绘制出旋转轴
	//glVertex3f(-25, -30, -25);
	//glVertex3f(20, 15, 20);
	//glEnd();
	//glColor3f(1, 0, 0);
	//for (int i = 0; i < 36; i++)
	//{
	//	//逆变换
	//	glTranslatef(5, 0, 5);
	//	glRotatef(-45, 0, 0, 1);
	//	glRotatef(45, 1, 0, 0);
	//	glRotatef(10, 0, 1, 0);
	//	//再绕x轴顺时针旋转45度使旋转轴与y轴重合
	//	glRotatef(-45, 1, 0, 0);
	//	//先绕z轴逆时针旋转45度使旋转轴位于yz平面上
	//	glRotatef(45, 0, 0, 1);
	//	//先将旋转轴平移至经过原点
	//	glTranslatef(-5, 0, -5);
	//	glutWireCube(1);
	//}




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

	//glFlush();
}



void test2()
{

	//二次插值曲线
	//控制点的数据 为列向量
	//Matrix<double,3,1> xdatas = { 100,200,400 };
	//Matrix<double, 3, 1> ydatas = { 200,400,350 };
	//quadraticInterpolationCurve(xdatas, ydatas);



	//三次的情况，此时需要四个点来确定一条曲线
	//控制点的数据 为列向量
	//Matrix<double, 4, 1> xdatas = { 100,200,300,400 };
	//Matrix<double, 4, 1> ydatas = { 200,400,200,400 };
	//cubicInterpolationCurve(xdatas, ydatas);


	//四次的情况，此时需要五个点来确定一条曲线
	//代入t值为0 1/4 2/4 3/4 1得出的矩阵
	//控制点的数据 为列向量
	Matrix<double, 5, 1> xdatas;
	xdatas << 50, 150, 250, 350, 450;
	Matrix<double, 5, 1> ydatas;
	ydatas << 200, 400, 200, 400, 300;
	quarticInterpolationCurve(xdatas, ydatas);


	//控制点的数据 为列向量 前两个为点的位置，后两个为导数
	//Matrix<double, 4, 1> xdatas = { 50,450,200,200 };
	//Matrix<double, 4, 1> ydatas = { 100,100,20,-500 };
	//hermiteCurve(xdatas, ydatas);

	//三次cardinal曲线
	//控制点的数据 为四个点
	//Matrix<double, 4, 1> xdatas = { 100,200,300,400 };
	//Matrix<double, 4, 1> ydatas = { 100,200,400,150 };
	//cardinalCurve(xdatas, ydatas);


	//三次贝塞尔曲线
	//控制点的数据 为四个点
	//Matrix<double, 4, 1> xdatas = { 100,200,300,400 };
	//Matrix<double, 4, 1> ydatas = { 100,300,400,150 };
	//bezierCurve(xdatas, ydatas);
}

void eigenTest()
{
	//用MatrixXd类创建一个2*2矩阵 并依次指定元素
	MatrixXd m1(2, 2);
	m1(0, 0) = 2;
	m1(1, 0) = 0;
	m1(0, 1) = 0;
	m1(1, 1) = 2;

	//使用Matrix3d创建一个3*3的方阵,用重载过的<<运算符来初始化它
	Matrix3d m3;
	m3 << 1, 2, 3,
		4, 5, 6,
		7, 8, 9;

	//MatrixXd::Random创建一个3*3的随机矩阵，每个矩阵元素取-1~1的随机值
	MatrixXd m2 = MatrixXd::Random(3, 3);

	//MatrixXd::Random创建一个3*3的常量矩阵，每个矩阵元素都是1
	MatrixXd m4 = MatrixXd::Constant(3, 3, 1);


	//用Matrix模板创建一个元素类型为float,4*4的矩阵
	Matrix<float, 4, 4> matrix4f;


	//返回矩阵的行列数
	m1.rows();
	m1.cols();

	//两个矩阵的加减乘运算,直接使用重载过的+-*号即可
	Matrix2d a;
	a << 1, 2,
		3, 4;
	MatrixXd b(2, 2);
	b << 2, 3,
		1, 4;
	std::cout << "a + b =\n" << a + b << std::endl;
	std::cout << "a - b =\n" << a - b << std::endl;
	std::cout << "a * b =\n" << a * b << std::endl;

	//分别是返回转置矩阵,共轭矩阵,伴随矩阵,带有inplace后缀的方法不返回值，直接变换该矩阵
	m1.transpose();
	m1.conjugate();
	m1.adjoint();

	m1.transposeInPlace();
	m1.adjointInPlace();


	//创建一个三维向量
	Vector3d v1(1, 2, 3);

	//矩阵右乘向量
	cout << m2 * v1 << endl;

	//创建两个三维向量并进行点积和叉积
	Vector3d v(1, 2, 3);
	Vector3d w(0, 1, 2);

	v.dot(w);
	v.cross(w);




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


	//test1();

	test2();

	//eigenTest();



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

