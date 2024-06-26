/*

*/

#include <iostream>
using namespace std;

class CALLComers
{
public:
	int m_bh;

	virtual void show();
	virtual void show(int a1) { cout << "调用了基类show(int a1)函数。\n"; }
};

class CGirl :public CALLComers
{
public:
	int m_age = 0;

	void show() { cout << "CGirl::show():我是" << m_bh << "号，" << m_age << "岁。\n"; }
	void show(int a2) { cout << "调用了派生类show(int a2)函数。\n"; }
};

void CALLComers::show() { cout << "CALLComers::show():我是" << m_bh << "号。\n"; }

int main()
{
	//CGirl g1;
	//g1.m_bh = 8;
	//g1.m_age = 23;
	//g1.show();
	//CALLComers* pa = &g1;
	//pa->show();

	CALLComers a;	a.m_bh = 3;
	CGirl g;			g.m_bh = 8; g.m_age = 23;

	CALLComers* p;		// 声明基类指针
	p = &g;	p->show(3);
	p->CALLComers::show(3);
	//p = &a; p->show();	// 指向基类对象，使用基类的成员函数和数据
	//p = &g; p->show();	// 指向派生类对象，使用派生类的成员函数和数据

	//CALLComers& ra = a;	ra.show();
	//CALLComers& rg = g;	rg.show();
}

/*
如果基类的成员函数是虚函数，当用基类指针指向派生类对象时，会调用派生类中同门的成员函数
	通过派生类中的同名成员函数，就能访问派生类对象的成员变量
	基类指针只能调用基类的成员函数，不能调用派生类的成员函数。
有了虚函数，基类指针指向基类对象时就使用基类的成员函数和数据，指向派生类对象时就使用派生类的成员函数和数据，
	基类指针表现出了多种形式，这种现象称为多态。
基类引用也可以使用多态

注意:
1) 只需要在基类的函数声明中加上 virtual 关键字，函数定义时不能加。
2) 在派生类中重定义虚函数时，函数特征要相同。(函数名、参数表一致(参数名可以不一致)，否则是派生类中的新函数，不构成多态）
3) 当在基类中定义了虚函数时，如果派生类没有重定义该函数，那么将使用基类的虚函数。
4) 在派生类中重定义了虚函数的情况下，如果想使用基类的函数，可以加类名和域解析符。
5) 如果要在派生类中重新定义基类的函数，则将它设置为虚函数;
	否则，不要设置为虚函数，有两方面的好处:
		首先普通函数效率更高;
		其次，指出不要重新定义该函数。（表明程序意图）
*/