/*

*/

#include <iostream>
using namespace std;

string func1()
{
	return "西施";
}

double func2(int a, double b, const char* c, float d, short e, long f) {
	cout << "a=" << a << ",b=" << b << ",c=" << c << ",d=" << d << ",e=" << e << ",f=" << f << endl;
	return 5.5;
}

int main()
{
	/*auto a = 3 + 1;		cout << "a=" << a << "\ttypeid(a)=" << typeid(a).name() << endl;
	auto b = 3.3 * 1;	cout << "b=" << b << "\ttypeid(b)=" << typeid(b).name() << endl;
	auto c = func1();		cout << "c=" << c << "\ttypeid(c)=" << typeid(c).name() << endl;*/

	double (*pf)(int, double, const char*, float, short, long);	// 声明函数指针pf
	pf = func2;
	pf(1, 2, "西施", 3, 4, 5);
	auto pf1 = func2;	// 编译器自动推导类型为函数指针，很方便
}

/*
注意:
1) auto 声明的变量必须在定义时初始化。
2) 初始化的右值可以是具体的数值，也可以是表达式和函数的返回值等。
3) auto 不能作为函数的形参类型。
4) auto 不能直接声明数组。
5) auto 不能定义类的非静态成员变量。

不要滥用 auto，auto 在编程时真正的用途如下:
1) 代替冗长复杂的变量声明。	（比如函数指针的声明，并且当函数声明改变时，auto的函数指针声明不用变）
2) 在模板中，用于声明依赖模板参数的变量。
3) 函数模板依赖模板参数的返回值。
4) 用于lambda 表达式中。
*/