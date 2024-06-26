/*

*/

#include <iostream>
using namespace std;

class CAllComers		// 海选报名者类(基类)
{
protected:
	int m_a;

private:
	int m_b;

public:
	string m_name;
	string m_tel;
	CAllComers() { m_name = "XXX"; m_tel = "不详"; m_a = 1; m_b = 2; }

	// 报名时需要唱一首歌
	void sing() { cout << "我是一只小小鸟。\n"; }
	void setname(const string name) { m_name = name; }
	void setTel(const string tel) { m_tel = tel; }
};

class CGirl1 :public CAllComers		// 超女类(派生类)
{
public:
	int m_bh;

	CGirl1() { m_bh = 8; }

	void show() {
		cout << "编号：" << m_bh << "，姓名：" << m_name << "，联系方式：" << m_tel << endl;
	}
};
class CGirl2 :protected CAllComers		// 超女类(派生类)
{
public:
	int m_bh;

	CGirl2() { m_bh = 8; }

	void show() {
		cout << "编号：" << m_bh << "，姓名：" << m_name << "，联系方式：" << m_tel << endl;
	}
	void showvalue() { cout << m_a << endl; }
};
class CGirl3 :private CAllComers		// 超女类(派生类)
{
public:
	int m_bh;

	CGirl3() { m_bh = 8; }

	void show() {
		cout << "编号：" << m_bh << "，姓名：" << m_name << "，联系方式：" << m_tel << endl;
	}
	void showvalue() { cout << m_a << endl; }
};

//——————————————————————
class A {
public:
	int m_a = 1;
protected:
	int m_b = 2;
private:
	int m_c = 3;

	int using_m_c() { return m_c; }
};

class B :public A {
public:
	using A::m_b;	// 把m_b的权限修改为公有的
private:
	using A::m_a;	// 把m_a的权限修改为私有的
};

int main()
{
	//CGirl1 g1;
	//g1.setname("西施");
	//g1.show();

	//CGirl2 g2;
	//g2.showvalue();

	//CGirl3 g3;
	//g3.showvalue();

	B b;
	//b.m_a = 11;
	b.m_b = 21;
}

/*
公有、保护的成员/成员函数可以被继承，但私有不能
继承方式（权限由高到低）：
	:public		基类公有仍为公有，保护仍为保护（不作改变，基类能展示的仍能展示）
	:protected	基类公有变为保护，保护仍为保护（不能展示基类信息）
	:private		基类公有、保护，在派生类变为私有（基类继承过来的不能再次继承）
1) 总之继承方式指定了基类成员在派生类中的访问权限的最高要求，如protected方式下，曾经的public成员访问权限在派生类中将不低于protected

2) 不管继承方式如何，基类中的 private 成员在派生类中始终不能使用(不能在派生类的成员函数中访问或调用)。

3) 如果希望基类的成员能够被派生类继承并且毫无障碍地使用，那么这些成员只能声明为 public或 protected;只有那些不希望在派生类中使用的成员才声明为private。
4) 如果希望基类的成员既不向外暴露(不能通过对象访问)，还能在派生类中使用，那么只能声明为 protected。

由于 private 和 protected 继承方式会改变基类成员在派生类中的访问权限，导致继承关系复杂，
	所以在实际开发中，一般使用 public。

在派生类中，可以通过基类的公有成员函数间接访问基类的私有成员。

使用 using 关键字可以改变基类成员在派生类中的访问权限。
注意:using 只能改变基类中 public和 protected 成员的访问权限，
	不能改变 private 成员的访问权限，因为基类中 private 成员在派生类中是不可见的，
	根本不能使用。
*/