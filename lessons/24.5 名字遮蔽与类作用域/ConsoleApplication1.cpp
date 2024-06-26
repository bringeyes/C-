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
	//B b1;	// 调用基类默认构造函数
	//b1.showA(); b1.showB();

	//B b2(1, 2, 3, 4);	// 调用基类3个参数的构造函数
	//b2.showA(); b2.showB();

	//A a(10, 20, 30);	// 创建基类对象
	//B b3(a, 40);		// 调用基类的拷贝构造函数
	//b3.showA(); b3.showB();

	C c1;
	c1.A::m_a = 1; c1.m_a = 10;
	c1.showA(); c1.A::showA();
}

/*
如果派生类中的成员(包括成员变量和成员函数)和基类中的成员重名，
	通过派生类对象或者在派生类的成员函数中使用该成员时，
	将使用派生类新增的成员，而不是基类的。
注意：基类的成员函数和派生类的成员函数不会构成重载，如果派生类有同名函数，
	那么就会遮蔽基类中的所有同名函数。

类是一种作用域，每个类都有它自己的作用域，在这个作用域之内定义成员。
	在类的作用域之外，普通的成员只能通过对象(可以是对象本身，也可以是对象指针或对象引用)来访问，
	静态成员可以通过对象访问，也可以通过类访问。
在成员前面加类名和域解析符可以访问对象的成员。
	如果不存在继承关系，类名和域解析符可以省略不写。	(A::)
当存在继承关系时，基类的作用域嵌套派生类的作用域中。
	如果成员在派生类的作用域已经找到就不会在基类作用域中继续查找;
	如果没有找到，则继续在基类作用域中查找。

*/