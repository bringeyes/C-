/*

*/

#include <iostream>
using namespace std;

template <typename T1, typename T2>
auto func1(T1 x, T2 y) -> decltype(x + y)
{
	decltype(x + y) tmp = x + y;
	cout << "tmp=" << tmp << "，typeid(tmp)=" << typeid(tmp).name() << endl;
	return tmp;
}

//int func2() {
//	cout << "调用了func2()。\n";
//	return 3;
//}

int main()
{
	/*short a = 5;
	short b = 10;
	short& ra = a;

	decltype(a) a2 = a;			// 类型与 a 相同
	decltype(ra) da1 = b;		// da是short&，定义时须指明引用对象

	decltype(func2()) fa = b;		// 填函数调用func2()，得到返回值类型
	decltype(func2)* pa1 = func2;		// 填函数名func2，得到函数类型，pa是函数指针
	pa1();

	decltype(++a) da2 = b;		// 规则3，表达式是左值，类型为(++a)类型的引用
	decltype((a)) da3 = b;		// 同上，类型为(a)类型的引用
	decltype((func2)) pa2 = func2;		// 同上，类型为函数的引用
	pa2();		// 函数的引用也可调用函数

	auto aa = func2();		// auto 会执行表达式

	typedef decltype(func2)* func2Type;
	func2Type func3 = func2;
	func3(); */

	//——————————————————————————

	func1(1.2, 3);
}

/*
1) decltype 关键字
	在 C++11 中，decltype 操作符，用于查询表达式的数据类型。
	decltype 分析表达式并得到它的类型，不会计算执行表达式。
		函数调用也一种表达式，因此不必担心在使用 decltype 时执行了函数。

语法: decltype(expression) var;
	1) 如果 expression 是一个没有用括号括起来的标识符，则 var 的类型与该标识符的类型相同，包括 const 等限定符。
	2) 如果 expression 是一个函数调用，则 var 的类型与函数的返回值类型相同(函数不能返回 void 但可以返回 void *)。
	3) 如果 expression 表达式是一个左值(能取地址)(要排除第一种情况)、或者用括号括起来的标识符那么 var 的类型是 expression 的引用。
	4) 如果上面的条件都不满足，则var的类型与 expression 的类型相同。

实际使用 decltype()的时候，返回类型要么是值的类型，要么是引用，多猜两下

声明函数指针的3种方法：
	int (*funcPtr)(int, int) = func;	// 可以不初始化

	decltype(func)* funcPtr = func;

	auto funcPtr = func;

decltype() 和 auto 的区别：
	decltype()不会执行表达式，但 auto 会执行
*/

/*
函数后置返回类型
auto func1(T1 x, T2 y) -> decltype(x + y)

C++14标准，可以只使用auto	（不需要后置返回类型了）
	auto func1(T1 x, T2 y)
*/