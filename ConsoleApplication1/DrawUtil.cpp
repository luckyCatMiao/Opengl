#include "DrawUtil.h"
#include<glut.h>
#include <math.h>
#include<stdio.h>
#include<stack>
using namespace std;
inline int max(float a, float b) { return a > b ? a : b; }
#define round(x) ((int)(x+0.5))
#define floatEqual(a,b) (fabs(a-b)<=0.01?1:0)
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
	glFlush();
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

//�����ɫ�Ƿ���ͬ
bool checkColor(GLfloat* c1, GLfloat* c2)
{
	return
			(fabs(c1[0] - c2[0]) < 0.01f &&
			fabs(c1[1] - c2[1]) < 0.01f &&
			fabs(c1[2] - c2[2]) < 0.01f);
}

//���ڵݹ������ͨ��ˮ��
void floodFill4Recur_(int x, int y, GLfloat* borderColor, GLfloat* fillColor)
{
	//���ٿռ�洢��������ɫ
	GLfloat* colors = new GLfloat[3];
	//��ȡ�������ص���ɫ
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, colors);
	if (checkColor(colors,borderColor)||checkColor(colors,fillColor))
	{
		//�������߽��������������˳�
		return;
	}
	else
	{
		//��䵱ǰ��ɫ
		glBegin(GL_POINTS);
		glColor3f(fillColor[0], fillColor[1], fillColor[2]);
		glVertex2i(x, y);
		glEnd();

		//����ͨ����ڽ�����,����չΪ����ͨ
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




//����ջ������ͨ��ˮ��
void floodFill4Stack(int x, int y, GLfloat* borderColor, GLfloat* fillColor)
{
	stack<Point> s;
	Point p = { x,y };
	s.push(p);//ѹ���ʼ�ڵ�
	while (!s.empty())
	{
		Point newP = s.top();
		s.pop();
		//���ٿռ�洢��������ɫ
		GLfloat* colors = new GLfloat[3];
		//��ȡ�������ص���ɫ
		glReadPixels(newP.x, newP.y, 1, 1, GL_RGB, GL_FLOAT, colors);
		if (checkColor(colors, borderColor) || checkColor(colors, fillColor))
		{
			continue;
		}
		else
		{
			//��䵱ǰ��ɫ
			glBegin(GL_POINTS);
			glColor3f(fillColor[0], fillColor[1], fillColor[2]);
			glVertex2i(newP.x, newP.y);
			glEnd();
			glFlush();

			//����ͨ����ڽ�����,����չΪ����ͨ
			s.push({newP.x + 1, newP.y});
			s.push({newP.x - 1, newP.y});
			s.push({newP.x, newP.y + 1});
			s.push({newP.x, newP.y - 1});
		}
	}

	glFlush();
}

//�������
const int winLeftMask = 0b0001;
const int winRightMask = 0b0010;
const int winTopMask = 0b1000;
const int winBottomMask = 0b0100;

GLubyte _encode(Point p, Point min, Point max) {
	GLubyte code = 0;
	//�Ըõ���б��룬ע������С�ڴ��ڲ���д��С�ڵ��ںʹ��ڵ��ڣ���Ϊ�ڲü�ʱ�ǰѲü��������ڱ߽�����
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
//Cohen-Sutherland����ü��㷨
void cohen_Sutherland_LineClip(Point& p1, Point& p2, Point min, Point max)
{	
	bool done = false;
	GLubyte code1, code2;
	while (!done)
	{
		//�����˵���б���
		code1 = _encode(p1,min,max);
		code2 = _encode(p2, min, max);

		//������˵㶼�����������òü�
		if ((code1 == 0) && (code2 == 0)) return;
		//������˵㶼���������Ҳ����������򲻲ü�
		if ((code1 & code2) != 0) return;

		//���ʱ��ȷ���ĸ��������ⲿ(Ҳ���������㶼���ⲿ������������һ����ֻҪѡ��һ������)
		if (code1 == 0)
		{
			swapPoint(&p1, &p2);
			swapCode(&code1, &code2);
		}
		//��ʱ��׺Ϊ1�ĵ��������ⲿ ��ʼ�ü� ˳��Ϊ��������


		float k = (float)(p2.y - p1.y) / (p2.x - p1.x);//����б��
		//ʹ��������жϸõ��Ƿ������������ Ȼ�����ֱ�߷�����������߽�Ľ��� 
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

		//��ʱֻ������һ���� ��Ҫ����һ�ֿ�ȷ���Ƿ����㶼�������� ������ദ������
	}
}