#pragma once
#include <iostream>
#include <exception>
using namespace std;

enum index { underflow, overflow };

class MyException : public exception
{
public:
	// ��д�� what() ����������ֵ const char *
	const char* what() const throw()		// throw()��ʾ�ú��������׳��쳣
	{
		return "my test exception";
	}
};

double Div(double x, double y);

double add(double x, double y);

void test01();

int array_index(int* arr, int n, int index);

void test02();