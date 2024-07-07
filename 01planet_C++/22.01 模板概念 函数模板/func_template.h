#pragma once
#include <iostream>
using namespace std;

// 函数模板
template<typename T, class H>
auto add(T& x, H& y) {
	return x + y;
}

template<typename T, class H>
auto add(const T& x, const H& y) {
	return x + y;
}

template<typename T>
void exchange(T& x, T& y) {
	T tmp = x;
	x = y;
	y = tmp;
}

// 函数模板测试 01 02
void test01();

void test02();