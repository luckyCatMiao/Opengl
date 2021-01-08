#include "DrawUtil.h"
#include<glut.h>
#include <math.h>
#include<stdio.h>

inline int max(float a, float b) { return a > b ? a : b; }
#define round(x) ((int)(x+0.5))
#define �� 3.14

//dda����
void lineDDA(Point p1, Point p2)
{
	glColor3f(1, 0, 0);
	//glPointSize(2);
	glBegin(GL_POINTS);
	float xIncrease = p2.x - p1.x;
	float yIncrease = p2.y - p1.y;
	float xStep, yStep;
	//���������x�����ӻ��ǳ�y������
	float count = max(fabsf(xIncrease), fabsf(yIncrease));

	//���x��y�����������д��Ϊ1��С��ΪС��1��һ����
	xStep = xIncrease / count;
	yStep = yIncrease / count;

	float startX = p1.x;
	float startY = p1.y;
	for (int i = 0; i < count; i++)
	{
		glVertex2i(round(startX), round(startY));
		startX += xStep;
		startY += yStep;
	}

	glEnd();
}



//bresenham�㷨ͨ���ھ��߲����г���һ��dx�������㶼������������
//p(n+1)=p(n)+2dy-2dx*(y(k+1)-y(k))
void lineBresenham(Point p1,Point p2) {
	int x = p1.x; int y = p1.y;
	int dx = fabs(p2.x - p1.x); int dy = fabs(p2.y - p1.y);
	int p = 2 * dy - dx;//��ʼ���߲���

	glBegin(GL_POINTS);
	glColor3f(0, 0, 0);
	for (int i = p1.x; i <=p2.x; i++)
	{
		glVertex2i(x, y);
		x++;
		if (p < 0)
		{
			p += 2 * dy;
		}
		else
		{	p += 2 * dy - 2 * dx;
			y++;
		}
	}
	glEnd();
	glFlush();
}

//�е㻭�� ����bresenham�㷨 Ҳ��ʹ�õݽ����ߺ��� ���������е������� (��һ���������е��Ϸ������·�)
//���뽫С������֮���ƺ���bresenham����ȫһ���� ֻ���Ƶ����̲�ͬ
void lineMidPoint(Point p1, Point p2)
{
	int x = p1.x; int y = p1.y;
	int dx = fabs(p2.x - p1.x); int dy = fabs(p2.y - p1.y);
	int p = 2 * dy - dx;//��ʼ���߲���

	glBegin(GL_POINTS);
	glColor3f(0, 0, 0);
	for (int i = p1.x; i <=p2.x; i++)
	{
		glVertex2i(x, y);
		x++;
		if (p < 0)
		{
			
			p += 2 * dy;
		}
		else
		{
			p += 2 * dy - 2 * dx;
			y++;
		}
	}
	glEnd();
	glFlush();
}


//ֱ��ʹ��Բ�ĵѿ������귽������Բ
void sphereSimple(Point center,int  radius)
{
	glBegin(GL_POINTS);
	glColor3f(1, 0, 0);
	int left = center.x - radius;
	int right = center.x + radius;
	for (int i = left; i <= right; i++)
	{
		int y = sqrt(pow(radius, 2) - pow(i - center.x, 2)) + center.y;
		glVertex2i(i, y);
		glVertex2i(i, center.y*2-y);
	}

	glEnd();
	
}


//ʹ�ü���������Բ
void spherePolarCoord(Point center, int  radius)
{
	glBegin(GL_POINTS);
	glColor3f(0, 1, 0);
	glPointSize(1);
	for (int theta = 0; theta < 360; theta++)
	{
		int x = center.x + radius * cos((double)theta / 180 * ��);
		int y = center.y + radius * sin((double)theta / 180 * ��);
		glVertex2i(x, y);
		
	}

	glEnd();
	glFlush();

}


//ʹ�öԳ��Եļ�����
void spherePolarCoord2(Point center, int  radius)
{
	glBegin(GL_POINTS);
	glColor3f(0, 1, 1);
	glPointSize(1);
	for (int theta = 0; theta < 45; theta++)
	{
		int x =  radius * cos((double)theta / 180 * ��);
		int y =  radius * sin((double)theta / 180 * ��);
		glVertex2i(center.x+x, center.y+y);
		glVertex2i(center.x+x, center.y+-y);
		glVertex2i(center.x+-x,center.y+ y);
		glVertex2i(center.x+-x,center.y+ -y);
		glVertex2i(center.x+y, center.y+x);
		glVertex2i(center.x+y, center.y+-x);
		glVertex2i(center.x+-y,center.y+ x);
		glVertex2i(center.x+-y,center.y+ -x);
	}
	glEnd();
	glFlush();

}

//ʹ��Bresenham�㷨��Բ
void sphereBresenham(Point center, int radius) {
	int x = 0; int y = radius;
	int p = 3-2*radius;//��ʼ���߲���

	glBegin(GL_POINTS);
	glColor3f(0, 0, 0);
	while (x <= y) //����90�ȵ�45�ȵ�Բ��Ȼ��ʹ�ð�·�Գ�
	{
		glVertex2i(center.x + x, center.y + y);
		glVertex2i(center.x + x, center.y + -y);
		glVertex2i(center.x + -x, center.y + y);
		glVertex2i(center.x + -x, center.y + -y);
		glVertex2i(center.x + y, center.y + x);
		glVertex2i(center.x + y, center.y + -x);
		glVertex2i(center.x + -y, center.y + x);
		glVertex2i(center.x + -y, center.y + -x);

		if (p < 0)
		{
			p += 4 * x + 6;
		}
		else {
			p += 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
	glEnd();
	glFlush();
}

//ʹ���е��㷨��Բ
void sphereMidPoint(Point center, int radius) {
	int x = 0; int y = radius;
	int p = 1-  radius;//��ʼ���߲���

	glBegin(GL_POINTS);
	glColor3f(0, 0, 0);
	while (x <= y) //����90�ȵ�45�ȵ�Բ��Ȼ��ʹ�ð�·�Գ�
	{
		glVertex2i(center.x + x, center.y + y);
		glVertex2i(center.x + x, center.y + -y);
		glVertex2i(center.x + -x, center.y + y);
		glVertex2i(center.x + -x, center.y + -y);
		glVertex2i(center.x + y, center.y + x);
		glVertex2i(center.x + y, center.y + -x);
		glVertex2i(center.x + -y, center.y + x);
		glVertex2i(center.x + -y, center.y + -x);

		if (p < 0)
		{
			p += 2 * x + 3;
		}
		else {
			p += 2 * (x - y) + 5;
			y--;
		}
		x++;
	}
	glEnd();
	glFlush();
}