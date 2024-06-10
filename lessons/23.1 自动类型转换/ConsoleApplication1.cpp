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

	CGirl() { m_name = "西施"; m_bh = 5; m_weight = 50; cout << "调用了CGirl()\n"; }
	// explicit CGirl(int bh)
	CGirl(int bh) {		// 构造函数具备了转换的性质
		m_name.clear(); m_bh = bh; m_weight = 0;
		cout << "调用了CGirl(int bh)\n";
	}
	//CGirl(double weight, int age = 0) {		// 构造函数具备了转换的性质
	//	m_name.clear(); m_bh = 0; m_weight = weight;
	//	cout << "调用了CGirl(double weight)\n";
	//}
};

ostream& operator<< (ostream& cout, const CGirl& g)		// 隐含了第一个参数：对象本身
{
	cout << "编号：" << g.m_bh << "，姓名：" << g.m_name << "，体重：" << g.m_weight;
	return cout;
}

void func1(CGirl g) {
	cout << g << endl;
}
CGirl func2() {
	return 7.7;
}

int main()
{
	//CGirl g1(3);				// 常规写法
	//CGirl g2 = CGirl(3);		// 显示转换	调用1次
	//CGirl g3 = 3;			// 隐式转换	调用1次
	CGirl g4;				// 创建对象
	g4 = 3.3;		// 用CGirl(3)创建临时对象，再赋值给g4（这种写法就像把 int 3 转换成 CGirl 类一样）
	cout << g4 << endl;

	func1(3);
	CGirl g5 = func2();
	cout << g5 << endl;
}

/*
把只有一个参数的构造函数称为转换函数，如果多参数从第二个之后有默认值，也视为转换函数

注意：
1) 一个类可以有多个转换函数。
2) 多个参数的构造函数，除第一个参数外，如果其它参数都有缺省值，也可以作为转换函数。
3) CGirl(int)的隐式转换的场景:
	将 CGir 对象初始化为 int 值时。
	将 int 值赋给 CGirl 对象时。
	将 int 值传递给接受 CGirl 参数的函数时。
	返回值被声明为 CGirl 的函数试图返回 int 值时。
	在上述任意一种情况下，使用可转换为 int 类型的内置类型时
4) 如果自动类型转换有二义性，编译将报错。

将构造函数用作自动类型转换函数似乎是一项不错的特性，
但有时候会导致意外的类型转换。explicit 关键字用于关闭这种自动特性，但仍允许显示转换。
	explicit CGirl(int bh);
	CGirl g=8;			// 错误。
	CGirl g=CGirl(8);	// 显示转换，可以。
	CGirl g=(CGirl)8;	// 显示转换，可以。
在实际开发中，如果强调的是构造，建议使用 explicit，如果强调的是类型转换，则不使用explicit
*/