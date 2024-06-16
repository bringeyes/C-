/*

*/

#include <iostream>
using namespace std;

//class CAllComers		// 海选报名者类(基类)
//{
//protected:
//	int m_a;
//
//private:
//	int m_b;
//
//public:
//	string m_name;
//	string m_tel;
//	CAllComers() { m_name = "XXX"; m_tel = "不详"; m_a = 1; m_b = 2; }
//
//	// 报名时需要唱一首歌
//	void sing() { cout << "我是一只小小鸟。\n"; }
//	void setname(const string name) { m_name = name; }
//	void setTel(const string tel) { m_tel = tel; }
//};
//
//class CGirl1 :public CAllComers		// 超女类(派生类)
//{
//public:
//	int m_bh;
//
//	CGirl1() { m_bh = 8; }
//
//	void show() {
//		cout << "编号：" << m_bh << "，姓名：" << m_name << "，联系方式：" << m_tel << endl;
//	}
//};
//class CGirl2 :protected CAllComers		// 超女类(派生类)
//{
//public:
//	int m_bh;
//
//	CGirl2() { m_bh = 8; }
//
//	void show() {
//		cout << "编号：" << m_bh << "，姓名：" << m_name << "，联系方式：" << m_tel << endl;
//	}
//	void showvalue() { cout << m_a << endl; }
//};
//class CGirl3 :private CAllComers		// 超女类(派生类)
//{
//public:
//	int m_bh;
//
//	CGirl3() { m_bh = 8; }
//
//	void show() {
//		cout << "编号：" << m_bh << "，姓名：" << m_name << "，联系方式：" << m_tel << endl;
//	}
//	void showvalue() { cout << m_a << endl; }
//};
//
////——————————————————————

class A {		// 基类1
public:
	int m_a = 0;

	A() { cout << "A()\n"; }
	~A() { cout << "~A()\n"; }
};

class A1 :virtual public A		// 基类1
{
public:
	int m_a1 = 10;

	A1() { cout << "A1()\n"; }
	~A1() { cout << "~A1()\n"; }
};

class A2 :virtual public A		// 基类2
{
public:
	int m_b = 20;

	A2() { cout << "A2()\n"; }
	~A2() { cout << "~A2()\n"; }
};

class B :public A1, public A2 {		// 派生类
public:
	int m_c = 30;

	B() { cout << "B()\n"; }
	~B() { cout << "~B()\n"; }
};

int main()
{
	B b;
	b.m_a = 80;
	cout << "m_a=" << b.m_a << "，m_b=" << b.m_b << "，m_c=" << b.m_c << endl;
	cout << "&b.A1::A::m_a=" << &b.A1::A::m_a << "，b.A1::A::m_a=" << b.A1::A::m_a << endl;
	cout << "&b.A2::m_a=" << &b.A2::m_a << "，b.A2::m_a=" << b.A2::m_a << endl;
}

/*
虚继承可以解决菱形继承的二义性和数据冗余的问题。

有了多继承，就存在菱形继承，有了菱形继承就有虚继承，增加了复杂性。

不提倡使用多继承，只有在比较简单和不出现二义性的情况时才使用多继承，
	能用单一继承解决的问题就不要使用多继承。
如果继承的层次很多、关系很复杂，程序的编写、调试和维护工作都会变得更加困难，
	由于这个原因，C++之后的很多面向对象的编程语言，例如Java、C#、PHP 等，都不支持多继承。
*/