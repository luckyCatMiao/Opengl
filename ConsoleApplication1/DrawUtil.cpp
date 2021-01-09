#include "DrawUtil.h"
#include<glut.h>
#include <math.h>
#include<stdio.h>
#include<stack>
using namespace std;
inline int max(float a, float b) { return a > b ? a : b; }
#define round(x) ((int)(x+0.5))
#define floatEqual(a,b) (fabs(a-b)<=0.01?1:0)
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
	glFlush();
}



//bresenham算法通过在决策参数中乘上一个dx来把运算都化成整数运算
//p(n+1)=p(n)+2dy-2dx*(y(k+1)-y(k))
void lineBresenham(Point p1,Point p2) {
	int x = p1.x; int y = p1.y;
	int dx = fabs(p2.x - p1.x); int dy = fabs(p2.y - p1.y);
	int p = 2 * dy - dx;//初始决策参数

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

//中点画线 类似bresenham算法 也是使用递进决策函数 不过是用中点来决策 (下一个点是在中点上方还是下方)
//代码将小数化整之后似乎和bresenham是完全一样的 只是推导过程不同
void lineMidPoint(Point p1, Point p2)
{
	int x = p1.x; int y = p1.y;
	int dx = fabs(p2.x - p1.x); int dy = fabs(p2.y - p1.y);
	int p = 2 * dy - dx;//初始决策参数

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


//直接使用圆的笛卡尔坐标方程生成圆
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


//使用极坐标生成圆
void spherePolarCoord(Point center, int  radius)
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
void spherePolarCoord2(Point center, int  radius)
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

//使用Bresenham算法画圆
void sphereBresenham(Point center, int radius) {
	int x = 0; int y = radius;
	int p = 3-2*radius;//初始决策参数

	glBegin(GL_POINTS);
	glColor3f(0, 0, 0);
	while (x <= y) //计算90度到45度的圆弧然后使用八路对称
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

//使用中点算法画圆
void sphereMidPoint(Point center, int radius) {
	int x = 0; int y = radius;
	int p = 1-  radius;//初始决策参数

	glBegin(GL_POINTS);
	glColor3f(0, 0, 0);
	while (x <= y) //计算90度到45度的圆弧然后使用八路对称
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

//检查颜色是否相同
bool checkColor(GLfloat* c1, GLfloat* c2)
{
	return
			(fabs(c1[0] - c2[0]) < 0.01f &&
			fabs(c1[1] - c2[1]) < 0.01f &&
			fabs(c1[2] - c2[2]) < 0.01f);
}

//基于递归的四连通漫水法
void floodFill4Recur_(int x, int y, GLfloat* borderColor, GLfloat* fillColor)
{
	//开辟空间存储读出的颜色
	GLfloat* colors = new GLfloat[3];
	//读取所在像素的颜色
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, colors);
	if (checkColor(colors,borderColor)||checkColor(colors,fillColor))
	{
		//触碰到边界和已填充区域则退出
		return;
	}
	else
	{
		//填充当前颜色
		glBegin(GL_POINTS);
		glColor3f(fillColor[0], fillColor[1], fillColor[2]);
		glVertex2i(x, y);
		glEnd();

		//四连通填充邻近区域,可扩展为八连通
		floodFill4Recur_(x + 1, y, borderColor, fillColor);
		floodFill4Recur_(x - 1, y, borderColor, fillColor);
		floodFill4Recur_(x, y + 1, borderColor, fillColor);
		floodFill4Recur_(x, y - 1, borderColor, fillColor);
	}
	glFlush();
}
void floodFill4Recur(int x,int y, GLfloat* borderColor, GLfloat* fillColor)
{
	floodFill4Recur_(x, y, borderColor, fillColor);
}




//基于栈的四连通漫水法
void floodFill4Stack(int x, int y, GLfloat* borderColor, GLfloat* fillColor)
{
	stack<Point> s;
	Point p = { x,y };
	s.push(p);//压入初始节点
	while (!s.empty())
	{
		Point newP = s.top();
		s.pop();
		//开辟空间存储读出的颜色
		GLfloat* colors = new GLfloat[3];
		//读取所在像素的颜色
		glReadPixels(newP.x, newP.y, 1, 1, GL_RGB, GL_FLOAT, colors);
		if (checkColor(colors, borderColor) || checkColor(colors, fillColor))
		{
			continue;
		}
		else
		{
			//填充当前颜色
			glBegin(GL_POINTS);
			glColor3f(fillColor[0], fillColor[1], fillColor[2]);
			glVertex2i(newP.x, newP.y);
			glEnd();
			glFlush();

			//四连通填充邻近区域,可扩展为八连通
			s.push({newP.x + 1, newP.y});
			s.push({newP.x - 1, newP.y});
			s.push({newP.x, newP.y + 1});
			s.push({newP.x, newP.y - 1});
		}
	}

	glFlush();
}

//区域编码
const int winLeftMask = 0b0001;
const int winRightMask = 0b0010;
const int winTopMask = 0b1000;
const int winBottomMask = 0b0100;

GLubyte _encode(Point p, Point min, Point max) {
	GLubyte code = 0;
	//对该点进行编码，注意这里小于大于不能写成小于等于和大于等于，因为在裁剪时是把裁剪点设置在边界线上
	if (p.x < min.x) code |= winLeftMask;
	if (p.x > max.x) code |= winRightMask;
	if (p.y < min.y) code |= winBottomMask;
	if (p.y > max.y) code |= winTopMask;

	return code;
	
}

void swapPoint(Point* p1, Point* p2)
{
	Point temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void swapCode(GLubyte* v1, GLubyte* v2)
{
	GLubyte temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}
//Cohen-Sutherland编码裁剪算法
void cohen_Sutherland_LineClip(Point& p1, Point& p2, Point min, Point max)
{	
	bool done = false;
	GLubyte code1, code2;
	while (!done)
	{
		//对两端点进行编码
		code1 = _encode(p1,min,max);
		code2 = _encode(p2, min, max);

		//如果两端点都在区域内则不用裁剪
		if ((code1 == 0) && (code2 == 0)) return;
		//如果两端点都在区域外且不穿过区域则不裁剪
		if ((code1 & code2) != 0) return;

		//这个时候确定哪个点是在外部(也可能两个点都在外部，但是至少有一个，只要选定一个就行)
		if (code1 == 0)
		{
			swapPoint(&p1, &p2);
			swapCode(&code1, &code2);
		}
		//此时后缀为1的点在区域外部 开始裁剪 顺序为左右下上


		float k = (float)(p2.y - p1.y) / (p2.x - p1.x);//计算斜率
		//使用与操作判断该点是否在相关区域中 然后根据直线方程依次求与边界的交点 
		if (code1 & winLeftMask)
		{
			p1.y += (min.x - p1.x) * k;
			p1.x = min.x;
		}
		else if (code1 & winRightMask)
		{
			p1.y += (max.x - p1.x) * k;
			p1.x = max.x;
		}
		else if (code1 & winBottomMask)
		{
			p1.x+=(min.y-p1.y)/k;
			p1.y = min.y;
		}
		else if (code1 & winTopMask)
		{
			p1.x += (max.y-p1.y)/k;
			p1.y = max.y;
		}

		//此时只处理完一个点 还要再来一轮看确定是否两点都在区域内 不过最多处理两轮
	}
}