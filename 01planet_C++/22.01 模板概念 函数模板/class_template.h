#pragma once
#include <iostream>
using namespace std;

template<class T>
class Pair
{
	T data[2];	// 对于数组成员，不能通过初始化列表初始化，只能在构造函数体中初始化
public:
	Pair(T first, T second) { data[0] = first, data[1] = second; }
	void setData(const T& x, const T& y);
	void show() { cout << "data[0]=" << data[0] << ", data[1]=" << data[1] << endl; }
};

typedef Pair<int> t1;		// 使用别名来简化代码（时间久了容易遗忘），需要放在模板类后

template<class T>
using t2 = Pair<T>;			// 相当于对类起别名

template<typename T>		// 放在类外实现成员函数，需要加模板
void Pair<T>::setData(const T& x, const T& y) { data[0] = x, data[1] = y; }

void test03();