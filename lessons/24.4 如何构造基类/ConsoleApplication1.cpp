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

ostream& operator <<(ostream& cout, A& a) {
	cout << "m_a=" << a.m_a << "，m_b=" << a.m_b << "，m_c=" << a.m_c;
	return cout;
}

int main()
{
	B b1;	// 调用基类默认构造函数
	b1.showA(); b1.showB();

	B b2(1, 2, 3, 4);	// 调用基类3个参数的构造函数
	b2.showA(); b2.showB();

	A a(10, 20, 30);	// 创建基类对象
	B b3(a, 40);		// 调用基类的拷贝构造函数
	b3.showA(); b3.showB();
}

/*
派生类构造函数的要点如下:
1)创建派生类对象时，程序首先调用基类构造函数，然后再调用派生类构造函数。
2)如果没以指定基类构造函数，将使用基类的默认构造函数。

3)可以用初始化列表指明要使用的基类构造函数。

4)基类构造函数负责初始化被继承的数据成员;派生类构造函数主要用于初始化新增的数据成员。
5)派生类的构造函数总是调用一个基类构造函数，包括拷贝构造函数。
*/