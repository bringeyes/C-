#pragma once
#include <iostream>
using namespace std;

/*
* C����д����������ʱ��Ҫ��struct test a1
typedef struct test {
	int a;
	double b;
}test;
typedef struct test {
	int a;
	double b;
}* test1;
��C++��ֻ��ʹ�ú��ߣ���Ϊ�﷨������ϸ񣬲��������ͬ���Ľṹ�壩
typedef struct test {
	int a;
	double b;
} test, * test1;

*/
typedef struct test {
	int a;
	double b;
} test, * test1;		// ��int a, *b���ƣ��������˽ṹ����һ����������

void test01();

void test02();
void test03();