#pragma once
#include <iostream>
using namespace std;

// 传入指针就节省了空间（如果传入数据较大，普通传参会复制一份占用空间）
template<class T>
void func(T* p) { cout << *p << endl; }

void test01();

void test02();

void test03();