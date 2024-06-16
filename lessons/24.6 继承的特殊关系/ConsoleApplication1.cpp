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

class A {		// 基类
	friend ostream& operator <<(ostream& cout, A& a);
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;	// 基类中的m_c对派生类而言只是隐藏了，但实际存在且占用空间

public:
	A() :m_a(0), m_b(0), m_c(0)
	{
		cout << "调用了A()默认构造函数。\n";
	}
	A(int a, int b, int c) :m_a(a), m_b(b), m_c(c)
	{
		cout << "调用了A(int a,int b,int c)构造函数。\n";
	}
	A(const A& a) :m_a(a.m_a + 1), m_b(a.m_b + 1), m_c(a.m_c + 1)
	{
		cout << "调用了A(const A& a)拷贝构造函数。\n";
	}
	~A() { cout << "调用了A的析构函数。\n"; }

	void showA() { cout << "m_a=" << m_a << "，m_b=" << m_b << "，m_c=" << m_c << endl; }
};

class B :public A {		// 派生类
public:
	int m_d;

	B() :m_d(0), A()	// 派生类的默认构造函数，指明用基类的默认构造函数（不指名也无所谓）
	{
		cout << "调用了B()默认构造函数。\n";
	}
	B(int a, int b, int c, int d) :A(a, b, c), m_d(d)
	{
		cout << "调用了B(int a,int b,int c,int d)构造函数。\n";
	}
	B(const A& a, int d) :A(a), m_d(d)
	{
		cout << "调用了B(const A& a,int d)拷贝构造函数。\n";
	}

	~B() { cout << "调用了B的析构函数。\n"; }

	void showB() { cout << "m_d=" << m_d << endl; }
};

class C :public A
{
public:
	int m_a;

	void showA() { cout << "C.showA, m_a=" << m_a << endl; }
};

ostream& operator <<(ostream& cout, A& a) {
	cout << "m_a=" << a.m_a << "，m_b=" << a.m_b << "，m_c=" << a.m_c;
	return cout;
}

int main()
{
	B b1(1, 2, 3, 4);	// 调用基类3个参数的构造函数

	// 如果A a1=b1; 调用的是拷贝构造函数，会显示2,3,4
	A a1;
	a1.showA();
	a1 = b1;		// 调用编译器提供的默认赋值函数
	a1.showA();

	C c1;
	A* a2 = &c1;
	a2->m_a = 10;	// 数据类型决定了数据的操作方法，所以a2只能使用A类规定的方法
	a2->showA();		// 如果函数重名，也只能使用A类的成员函数
	cout << "c1.m_a=" << c1.m_a << endl;

	A& a3 = c1;
	cout << "a3: ";
	a3.showA();
}

/*
派生类和基类之间有一些特殊关系。
1) 如果继承方式是公有的，派生类对象可以使用基类成员。
2) 可以把派生类对象赋值给基类对象(包括私有成员)，但是，会舍弃非基类的成员。
3) 基类指针可以在不进行显式转换的情况下指向派生类对象。
	这样是安全的，但如果内存模型不匹配，可能导致程序崩溃，如：
	int ii; A* a2 = (A*) ii;
4) 基类引用可以在不进行显式转换的情况下引用派生类对象。

注意:
1) 基类指针或引用只能调用基类的方法，不能调用派生类的方法。
2) 可以用派生类构造基类。
3) 如果函数的形参是基类，实参可以用派生类。
4) C++要求指针和引用类型与赋给的类型匹配，这一规则对继承来说是例外。
	但是，这种例外只是单向的，不可以将基类对象和地址赋给派生类引用和指针(没有价值，没有讨论的必要)。
*/