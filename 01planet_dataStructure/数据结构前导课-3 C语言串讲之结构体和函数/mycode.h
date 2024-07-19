#pragma once
#include <iostream>
using namespace std;

/*
* C语言写法，否则定义时需要：struct test a1
typedef struct test {
	int a;
	double b;
}test;
typedef struct test {
	int a;
	double b;
}* test1;
或（C++中只能使用后者，因为语法规则更严格，不允许出现同名的结构体）
typedef struct test {
	int a;
	double b;
} test, * test1;

*/
typedef struct test {
	int a;
	double b;
} test, * test1;		// 和int a, *b类似，更表明了结构体是一种数据类型

void test01();

void test02();
void test03();