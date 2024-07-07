#pragma once
#include <iostream>
using namespace std;

// 外部类
class OuterClass
{
public:
	class InnerClass
	{
	public:
		void func();
	};

	InnerClass obj;

	// 外部类func方法
	void func() {
		cout << "OuterClass func()" << endl;
		obj.func();
	}
};

// 普通函数func
void func();

void test01();