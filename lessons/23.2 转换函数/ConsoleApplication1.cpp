/*

*/

#include <iostream>
#include <string>
using namespace std;

class CGirl
{
	friend ostream& operator<< (ostream& cout, const CGirl& g);
public:
	int	m_bh;
	double m_weight;
	string	m_name;

	CGirl() { m_name = "西施"; m_bh = 5; m_weight = 50.1; }

	explicit operator int() { return m_bh; }
	explicit operator double() { return m_weight; }
	operator string() { return m_name; }
};

ostream& operator<< (ostream& cout, const CGirl& g)		// 隐含了第一个参数：对象本身
{
	cout << "编号：" << g.m_bh << "，姓名：" << g.m_name << "，体重：" << g.m_weight;
	return cout;
}

int main()
{
	CGirl g1;

	// 隐式转换，编译器根据左值类型，选择调用哪个转换函数
	int a = g1; cout << "a=" << a << endl;	// 如果只explicit了 int()，会使用double()
	// 显式转换，两种写法
	double b = (double)g1; cout << "b=" << b << endl;
	string c = string(g1); cout << "c=" << c << endl;

	// short d = g1;	// 存在二义性，int double 都能转换到 short
}

/*
构造函数只用于从某种类型到类类型的转换，如果要进行相反的转换，可以使用特殊的运算符函数-转换函数。
语法:	operator 数据类型();

注意:转换函数必须是类的成员函数;不能指定返回值类型;不能有参数。

可以让编译器决定选择转换函数(隐式转换)，可以像使用强制类型转换那样使用它们(显式转换)
如果隐式转换存在二义性，编译器将报错。
在 C++98 中，关键字 explicit 不能用于转换函数，但 C++11消除了这种限制，可以将转换函数声明为显式的。
还有一种方法是:用一个功能相同的非转换函数替换转换函数，只有当函数被显式的调用时才会执行。
	int ii=girl.to intO;

警告:应谨慎的使用隐式转换函数。通常，最好选择仅在被显式地调用时才会执行的成员函数。

总结，转换函数在实际开发中不常用：
1. 使用它不见得能让代码简化多少，优雅多少；
2. 使用有风险，例如用explicit 禁用了int()的隐式转换，但可能运行时使用double()
3. 转换函数不能带参数，但普通成员函数可以
*/