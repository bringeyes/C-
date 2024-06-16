/*

*/

#include <iostream>
using namespace std;

template <class T1, class T2 = int>	// 指定缺省的数据类型
class AA
{
public:
	T1 m_a;		// 通用类型用于成员变量
	T2 m_b;

	AA() {}		// 默认构造函数

	AA(T1 a, T2 b) :m_a(a), m_b(b) {}	// 通用类型用于成员函数的参数

	T1 get_a()
	{
		T1 a = 1;		// 通用类型用于成员函数的代码
		return m_a + a;
	}

	T2 get_b();
};

template <class T1, class T2>
T2 AA<T1, T2>::get_b()
{
	T1 b = 2;		// 通用类型用于成员函数的代码
	return m_b + b;
}

int main()
{
	AA<int, double> a;		// 必须指明数据类型
	a.m_a = 3; a.m_b = 4;
	cout << a.get_a() << endl;
	cout << a.get_b() << endl;

	AA<int, double>* pa1 = new AA<int, double>;		// 使用默认构造函数
	AA<int, double>* pa2 = new AA<int, double>(10, 5.2);		// 使用带参数的构造函数
	cout << pa1->get_a() << endl;
	cout << pa2->get_b() << endl;

	auto b = pa1;

	delete pa1;
	delete pa2;
}

/*
函数模板建议用 typename 描述通用数据类型，类板建议用class。

注意:
1) 在创建对象的时候，必须指明具体的数据类型。
2) 使用类模板时，数据类型必须适应类模板中的代码。
3) 类模板可以为通用参数指定缺省的数据类型(C++11标准的函数模板也可以)。
4) 类的成员函数可以在类外实现。
	template <class T1, class T2>	// 不能在类外部定义模板参数，即class T2 = int
	T2 AA<T1, T2>::get_b()
	{
		T1 b = 2;		// 通用类型用于成员函数的代码
		return m_b + b;
	}
5) 可以用 new 创建模板对象。
	AA<int, double>* pa2 = new AA<int, double>(10, 5.2);
	AA是模板名，加上具体的数据类型 AA<int, double> 才是类名
6) 在程序中，模板类的成员函数使用了才会创建。
*/