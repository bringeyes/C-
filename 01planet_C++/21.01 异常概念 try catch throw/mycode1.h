#pragma once
#include <iostream>
#include <exception>
using namespace std;

enum index { underflow, overflow };

class MyException : public exception
{
public:
	// 重写了 what() 函数，返回值 const char *
	const char* what() const throw()		// throw()表示该函数不会抛出异常
	{
		return "my test exception";
	}
};

double Div(double x, double y);

double add(double x, double y);

void test01();

int array_index(int* arr, int n, int index);

void test02();