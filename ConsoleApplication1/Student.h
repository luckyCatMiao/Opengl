#pragma once
#include <string>
using namespace std;
class Student
{
public:
	string name;
	Student& test(const Student& s) {
		return *this;
	}

};

