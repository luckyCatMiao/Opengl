#include "DrawUtil.h"
#include<glut.h>
#include <math.h>
#include<stdio.h>

inline int max(float a, float b) { return a > b ? a : b; }
#define round(x) ((int)(x+0.5))
#define π 3.14

//dda画线
void lineDDA(Point p1, Point p2)
{
	glColor3f(1, 0, 0);
	//glPointSize(2);
	glBegin(GL_POINTS);
	float xIncrease = p2.x - p1.x;
	float yIncrease = p2.y - p1.y;
	float xStep, yStep;
	//计算出该沿x轴增加还是朝y轴增加
	float count = max(fabsf(xIncrease), fabsf(yIncrease));

	//算出x和y的增量，其中大的为1，小的为小于1的一个数
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



//bresenham算法通过在决策参数中乘上一个dx来把运算都化成整数运算
//p(n+1)=p(n)+2dy-2dx*(y(k+1)-y(k))
void lineBresenham(Point p1,Point p2) {
	int x = p1.x; int y = p1.y;
	int dx = fabs(p2.x - p1.x); int dy = fabs(p2.y - p1.y);
	int p = 2 * dy - dx;//初始决策参数

	glBegin(GL_POINTS);
	glColor3f(0, 0, 0);
	glVertex2i(x, y);//画初始点
	for (int i = p1.x; i < p2.x; i++)
	{
		x++;
		if (p < 0)
		{
			p += 2 * dy;
		}
		else
		{	p += 2 * dy - 2 * dx;
			y++;
		}
		glVertex2i(x,y);
	}
	glEnd();
	glFlush();
}

//中点画线


//直接使用圆的笛卡尔坐标方程生成圆
void DrawSphere1(Point center,int  radius)
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


//使用极坐标生成圆
void DrawSphere2(Point center, int  radius)
{
	glBegin(GL_POINTS);
	glColor3f(0, 1, 0);
	glPointSize(1);
	for (int theta = 0; theta < 360; theta++)
	{
		int x = center.x + radius * cos((double)theta / 180 * π);
		int y = center.y + radius * sin((double)theta / 180 * π);
		glVertex2i(x, y);
		
	}

	glEnd();
	glFlush();

}


//使用对称性的极坐标
void DrawSphere3(Point center, int  radius)
{
	glBegin(GL_POINTS);
	glColor3f(0, 1, 1);
	glPointSize(1);
	for (int theta = 0; theta < 45; theta++)
	{
		int x =  radius * cos((double)theta / 180 * π);
		int y =  radius * sin((double)theta / 180 * π);
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