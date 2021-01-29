#include "DrawUtil.h"
#include<glut.h>
#include <math.h>
#include<stdio.h>
#include<stack>
#include<Eigen/Dense>

using namespace std;
using namespace Eigen;
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
bool cohen_Sutherland_LineClip(Point& p1, Point& p2, Point min, Point max)
{	
	GLubyte code1, code2;
	while (true)
	{
		//对两端点进行编码
		code1 = _encode(p1,min,max);
		code2 = _encode(p2, min, max);

		//如果两端点都在区域内则不用裁剪
		if ((code1 == 0) && (code2 == 0)) return true;
		//如果两端点都在区域外且不穿过区域则不裁剪
		if ((code1 & code2) != 0) return false;

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

		//需要多轮处理
	}
}

//点裁剪
bool pointClip(Point& point, Point min, Point max)
{
	return(point.x > min.x && point.x<max.x&& point.y>min.y && point.y < max.y);
}



//绘制二次插值曲线
void quadraticInterpolationCurve(Matrix<double, 3, 1> xdatas, Matrix<double, 3, 1> ydatas)
{
	Matrix3d m;
	m << 0, 0, 1,
		0.25, 0.5, 1,
		1, 1, 1;

	//画出控制点
	glPointSize(5);
	glColor3f(0, 1, 0);
	glBegin(GL_POINTS);
	for (int i = 0; i < 3; i++)
		glVertex2f(xdatas[i], ydatas[i]);
	glEnd();

	//计算出二次曲线的系数
	Matrix<double, 1, 3> xabc = m.inverse() * xdatas;
	Matrix<double, 1, 3> yabc = m.inverse() * ydatas;

	//绘制出所得曲线
	glColor3f(1, 0, 0);
	glPointSize(2);
	glBegin(GL_POINTS);
	for (double t = 0; t <= 1; t += 0.01f)
	{
		double x = xabc[0] * t * t + xabc[1] * t + xabc[2];
		double y = yabc[0] * t * t + yabc[1] * t + yabc[2];
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}


//绘制三次插值曲线
void cubicInterpolationCurve(Matrix<double, 4, 1> xdatas, Matrix<double, 4, 1> ydatas)
{
	//代入t值为0 1/3 2/3 1得出的矩阵
	Matrix4d m;
	m << 0, 0, 0, 1,
		pow(1 / 3.f, 3), pow(1 / 3.f, 2), 1 / 3.f, 1,
		pow(2 / 3.f, 3), pow(2 / 3.f, 2), 2 / 3.f, 1,
		1, 1, 1, 1;

	//画出控制点
	glPointSize(5);
	glColor3f(0, 1, 0);
	glBegin(GL_POINTS);
	for (int i = 0; i < 4; i++)
		glVertex2f(xdatas[i], ydatas[i]);
	glEnd();

	//计算出三次曲线的系数
	Matrix<double, 1, 4> xabc = m.inverse() * xdatas;
	Matrix<double, 1, 4> yabc = m.inverse() * ydatas;

	//绘制出所得曲线
	glColor3f(1, 0, 0);
	glPointSize(2);
	glBegin(GL_POINTS);
	for (double t = 0; t <= 1; t += 0.01f)
	{
		double x = xabc[0] * t * t * t + xabc[1] * t * t + xabc[2] * t + xabc[3];
		double y = yabc[0] * t * t * t + yabc[1] * t * t + yabc[2] * t + yabc[3];
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}


//绘制四次插值曲线
void quarticInterpolationCurve(Matrix<double, 5, 1> xdatas, Matrix<double, 5, 1> ydatas)
{
	Matrix<double,5,5> m;
	m << 0, 0, 0, 0,1,
		pow(1 / 4.f, 4), pow(1 / 4.f, 3), pow(1 / 4.f, 2),1 / 4.f, 1,
		pow(2 / 4.f, 4), pow(2 / 4.f, 3), pow(2 / 4.f, 2),2 / 4.f, 1,
		pow(3 / 4.f, 4), pow(3 / 4.f, 3), pow(3 / 4.f, 2), 3 / 4.f, 1,
		1, 1, 1, 1,1;


	//画出控制点
	glPointSize(5);
	glColor3f(0, 1, 0);
	glBegin(GL_POINTS);
	for (int i = 0; i < 5; i++)
		glVertex2f(xdatas[i], ydatas[i]);
	glEnd();

	//计算出四次曲线的系数
	Matrix<double, 1, 5> xabc = m.inverse() * xdatas;
	Matrix<double, 1, 5> yabc = m.inverse() * ydatas;

	//绘制出所得曲线
	glColor3f(1, 0, 0);
	glPointSize(2);
	glBegin(GL_POINTS);
	for (double t = 0; t <= 1; t += 0.01f)
	{
		double x = xabc[0] * t * t * t*t + xabc[1] * t * t*t + xabc[2] * t*t + xabc[3]*t+xabc[4];
		double y = yabc[0] * t * t * t * t + yabc[1] * t * t * t + yabc[2] * t * t + yabc[3] * t + yabc[4];
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}

//绘制hermite曲线(三次)
void hermiteCurve(Matrix<double, 4, 1> xdatas, Matrix<double, 4, 1> ydatas)
{
	//三次hermite曲线
	Matrix4d m;
	m << 0, 0, 0, 1,
		 1, 1, 1, 1,
		 0, 0, 1, 0,
		 3, 2, 1, 0;

	glPointSize(10);
	glColor3f(0, 1, 0);
	//画出控制点
	glBegin(GL_POINTS);
	for (int i = 0; i < 2; i++)
		glVertex2f(xdatas[i], ydatas[i]);
	glEnd();

	
	//画出头和尾的切线 根据dy/dx=(dy/dt)/(dx/dt)算出斜率，加上一个经过点得出直线方程
	double k1 = (double)ydatas[2] / xdatas[2];
	double x1 = xdatas[0] - 100;
	double y1 = k1 * ( x1- xdatas[0]) + ydatas[0];
	double x2 = xdatas[0] + 100;
	double y2 = k1 * (x2 - xdatas[0]) + ydatas[0];

	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();


	k1 = (double)ydatas[3] / xdatas[3];
	x1 = xdatas[1] - 100;
	y1 = k1 * (x1 - xdatas[1]) + ydatas[1];
	x2 = xdatas[1] + 100;
	y2 = k1 * (x2 - xdatas[1]) + ydatas[1];

	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();


	//计算出三次曲线的系数
	Matrix<double, 1, 4> xabc = m.inverse() * xdatas;
	Matrix<double, 1, 4> yabc = m.inverse() * ydatas;

	//绘制出所得曲线
	glColor3f(1, 0, 0);
	glPointSize(2);
	glBegin(GL_POINTS);
	for (double t = 0; t <= 1; t += 0.01f)
	{
		double x = xabc[0] * t * t * t + xabc[1] * t * t + xabc[2] * t + xabc[3];
		double y = yabc[0] * t * t * t + yabc[1] * t * t + yabc[2] * t + yabc[3];
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}


//绘制cardinal曲线(三次)
void cardinalCurve(Matrix<double, 4, 1> xdatas, Matrix<double, 4, 1> ydatas)
{
	//三次cardinal曲线
	Matrix4d m;
	m << 0, 0, 1, 0,
		 0, 0, 0, 1,
		 1, 1, 1, 1,
		 3, 2, 1, 0;

	//画出控制点
	glPointSize(10);
	glColor3f(0, 1, 0);
	glBegin(GL_POINTS);
	for (int i = 0; i < 4; i++)
		glVertex2f(xdatas[i], ydatas[i]);
	glEnd();

	//连接几个控制点
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glVertex2d(xdatas[0], ydatas[0]);
	glVertex2d(xdatas[2], ydatas[2]);
	glEnd();
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	glVertex2d(xdatas[1], ydatas[1]);
	glVertex2d(xdatas[3], ydatas[3]);
	glEnd();


	//计算出四个斜率 ，在t=0点x,y对t的导数，在t=1点x,y对t的导数 最后乘上一个额外系数q,可以通过这个系数调整曲线的'松紧度'
	//这里简单取1
	int q = 1;
	int kxt0 = (xdatas[2] - xdatas[0]) / 2*q;
	int kyt0 = (ydatas[2] - ydatas[0]) / 2*q;
	int kxt1 = (xdatas[3] - xdatas[1]) / 2*q;
	int kyt1 = (ydatas[3] - ydatas[1]) / 2*q;

	//覆盖数据为斜率
	xdatas[0] = kxt0;
	xdatas[3] = kxt1;
	ydatas[0] = kyt0;
	ydatas[3] = kyt1;

	//控制点乘上逆矩阵得出二次曲线的系数
	Matrix<double, 1, 4> xabc = m.inverse() * xdatas;
	Matrix<double, 1, 4> yabc = m.inverse() * ydatas;

	//绘制出所得曲线
	glColor3f(1, 0, 0);
	glPointSize(2);
	glBegin(GL_POINTS);
	for (double t = 0; t <= 1; t += 0.01f)
	{
		double x = xabc[0] * t * t * t + xabc[1] * t * t + xabc[2] * t + xabc[3];
		double y = yabc[0] * t * t * t + yabc[1] * t * t + yabc[2] * t + yabc[3];
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}



//绘制贝塞尔曲线(三次)
void bezierCurve(Matrix<double, 4, 1> xdatas, Matrix<double, 4, 1> ydatas)
{

	//画出控制点
	glPointSize(10);
	glColor3f(0, 1, 0);
	glBegin(GL_POINTS);
	for (int i = 0; i < 4; i++)
		glVertex2f(xdatas[i], ydatas[i]);
	glEnd();
	//连接控制点
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 4; i++)
	{
		glVertex2f(xdatas[i], ydatas[i]);
	}
	glEnd();


	//使用三次贝塞尔曲线公式进行计算画线
	glPointSize(1);
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	for (double t = 0; t <= 1; t += 0.01f)
	{
		double x =
			xdatas[0] * 1 * pow(t, 0) * pow(1 - t, 3) +
			xdatas[1] * 3 * pow(t, 1) * pow(1 - t, 2) +
			xdatas[2] * 3 * pow(t, 2) * pow(1 - t, 1) +
			xdatas[3] * 1 * pow(t, 3) * pow(1 - t, 0);

		double y =
			ydatas[0] * 1 * pow(t, 0) * pow(1 - t, 3) +
			ydatas[1] * 3 * pow(t, 1) * pow(1 - t, 2) +
			ydatas[2] * 3 * pow(t, 2) * pow(1 - t, 1) +
			ydatas[3] * 1 * pow(t, 3) * pow(1 - t, 0);

			glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}