#pragma once
#include "Vector2.h"
#include <vector>
using std::vector;
class Matrix2D
{
public:
	int matrix[3][3] = 
	{	{1,0,0},
		{0,1,0},
		{0,0,1}
	};
	Matrix2D()
	{
	}
	void apply(Vector2& v2)
	{
		//齐次乘法，把向量提升到三阶
		double v3[3] = { v2.x,v2.y,1 };
		double x = 0, y = 0;
		for (int i = 0; i < 3; i++)
		{
			x += matrix[0][i] * v3[i];
			y += matrix[1][i] * v3[i];
		}
		v2.x = x;
		v2.y = y;
	}

	void apply(vector<Vector2> arr)
	{
		for (Vector2& v : arr)
		{
			apply(v);
		}
		
	}



	void translate(double x,double y)
	{
		matrix[0][2] = x;
		matrix[1][2] = y;
	}
};

