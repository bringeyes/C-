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
	int	m_age;

	void operator()(string str) {
		cout << "在类中重载()：" << str << endl;
	}
};

ostream& operator<< (ostream& c1, const CGirl& g)		// 隐含了第一个参数：对象本身
{
	cout << "年龄：" << g.m_age << "，编号：" << g.m_bh;
	return c1;
}

void show(string str) {
	cout << "普通函数：" << str << endl;
}

int main()
{
	CGirl g1;
	g1("我是一只小小鸟");

	show("我是一只小小鸟");	// 调用全局函数
	CGirl show;
	show("我是一只小小鸟");	// 函数对象与全局函数重名，根据作用域范围选择
	::show("我是一只小小鸟");	// 此时在函数名前加 :: 就可调用全局函数
}

/*
括号运算符()也可以重载，对象名可以当成函数来使用(函数对象、仿函数)
括号运算符重载函数的语法:
	返回值类型 operator()(参数列表);

注意:
	括号运算符必须以成员函数的形式进行重载。
	括号运算符重载函数具备普通函数全部的特征。
	如果函数对象与全局函数同名，按作用域规则选择调用的函数。

函数对象的用途:
1)表面像函数，部分场景中可以代替函数，在 STL中得到广泛的应用;
2)函数对象本质是类，可以用成员变量存放更多的信息;
3)函数对象有自己的数据类型;
4)可以提供继承体系。
*/