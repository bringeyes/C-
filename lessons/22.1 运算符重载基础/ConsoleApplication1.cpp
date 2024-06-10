/*

*/

#include <iostream>
using namespace std;

class CGirl
{
	friend CGirl& operator+(CGirl& g, int score);
	friend CGirl& operator+(int score, CGirl& g);
	friend CGirl& operator+(CGirl& g1, CGirl& g2);
private:
	int m_age;
	int m_score;
public:
	string m_name;
	CGirl() { m_name = "西施"; m_age = 23; m_score = 30; }

	void show() {
		cout << "姓名：" << m_name << "，年龄：" << m_age
			<< "，评分：" << m_score << endl;
	}

	CGirl& operator-(int score) {
		m_score -= score;
		return *this;	// 返回this指针的解引用，也就是对象自己
	}
};

CGirl& operator+(CGirl& g, int score) {
	g.m_score += score;
	return g;	// 返回this指针的解引用，也就是对象自己
}
CGirl& operator+(int score, CGirl& g) {
	g.m_score += score;
	return g;	// 返回this指针的解引用，也就是对象自己
}
CGirl& operator+(CGirl& g1, CGirl& g2) {
	g1.m_score += g2.m_score;
	return g1;	// 返回this指针的解引用，也就是对象自己
}

int main()
{
	CGirl g;
	g = g - 20 - 5 - 3 + g;		// 本质是函数的多次调用，从左到右依次运算
	g.show();
}

/*
运算符重载函数的语法:返回值 operator 运算符(参数列表);
运算符重载函数的返回值类型要与运算符本身的含义一致。
非成员函数版本的重载运算符函数:形参个数与运算符的操作数个数相同;
成员函数版本的重载运算符函数:形参个数比运算符的操作数个数少一个，其中的一个操作数隐式传递了调用对象。
如果同时重载了非成员函数和成员函数版本，会出现二义性。

注意：
1)返回自定义数据类型的引用可以让多个运算符表达式串联起来。(不要返回局部变量的引用)
2)重载函数参数列表中顺序决定了操作数的位置。		很重要！
3)重载函数的参数列表中至少有一个是用户自定义的类型，防止程序员为内置数据类型重载运算符。
4)如果运算符重载既可以是成员函数也可以是全局函数，应该优先考虑成员函数，这样更符合运算符重载的初衷。
5)重载函数不能违背运算符原来的含义和优先级。
6)不能创建新的运算符。
7)以下运算符不可重载:
	sizeof		sizeof 运算符
	.			成员运算符
	.*			成员指针运算符
	::			作用域解析运算符
	?:			条件运算符
	typeid		一个 RTTI 运算符
	const_cast			强制类型转换运算符
	dynamic_cast			强制类型转换运算符
	reinterpret_cast		强制类型转换运算符
	static_cast			强制类型转换运算符
8)以下运算符只能通过成员函数进行重载:
	前三个很重要！！
	=			赋值运算符
	()			函数调用运算符
	[]			下标运算符
	->			通过指针访问类成员的运算符
*/