#include "mycode1.h"

// �ڲ���func����
void OuterClass::InnerClass::func() {
	cout << "InnerClass func()" << endl;
}

void func() {
	cout << "func()" << endl;

	// �ֲ���
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

	cout << "������������������������" << endl;
	OuterClass::InnerClass b1;
	b1.func();

	cout << "������������������������" << endl;
	func();
}