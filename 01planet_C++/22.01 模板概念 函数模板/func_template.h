#pragma once
#include <iostream>
using namespace std;

// ����ģ��
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

// ����ģ����� 01 02
void test01();

void test02();