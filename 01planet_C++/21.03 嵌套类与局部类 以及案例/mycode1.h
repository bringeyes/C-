#pragma once
#include <iostream>
using namespace std;

// �ⲿ��
class OuterClass
{
public:
	class InnerClass
	{
	public:
		void func();
	};

	InnerClass obj;

	// �ⲿ��func����
	void func() {
		cout << "OuterClass func()" << endl;
		obj.func();
	}
};

// ��ͨ����func
void func();

void test01();