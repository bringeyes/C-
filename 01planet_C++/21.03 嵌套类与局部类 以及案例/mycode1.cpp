#include "mycode1.h"

// 坪何窃func圭隈
void OuterClass::InnerClass::func() {
	cout << "InnerClass func()" << endl;
}

void func() {
	cout << "func()" << endl;

	// 蕉何窃
	class LocalClass
	{
	public:
		int num;
		void setNum(int n) { num = n; }
		void show() { cout << "num=" << num << endl; }
	};

	LocalClass lc;
	lc.setNum(5); lc.show();
}

void test01() {
	OuterClass a1;
	a1.func();

	cout << "！！！！！！！！！！！！" << endl;
	OuterClass::InnerClass b1;
	b1.func();

	cout << "！！！！！！！！！！！！" << endl;
	func();
}