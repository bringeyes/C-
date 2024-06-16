#pragma once
#include <iostream>
using namespace std;

void Swap(int a, int b);		// 普通函数

template <typename T>		// 函数模板
void Swap(T a, T b)
{
	cout << "使用了函数模版 Swap(T a, T b)\n";
}

template <>					// 具体化的函数模版
void Swap(int a, int b);