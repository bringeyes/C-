/*

*/

#include <iostream>
using namespace std;

template <typename T>
void Swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T Add(T a, T b) {
	return a + b;
}

template <typename T1, typename T2>
void show(T1 no, T2 message) {
	cout << "亲爱的" << no << "号：" << message << endl;
}
template <typename T>
void show(T message) {
	cout << message << endl;
}

class CGirl
{
public:
	template <typename T>
	CGirl(T a) {
		cout << "a=" << a << endl;
	}

	template <typename T>
	void show(T b) {
		cout << "b=" << b << endl;
	}
};

int main()
{
	//CGirl g("西施");
	//g.show(3); g.show("西施");

	//string s1 = "西施", s2 = "23岁";
	//auto s3 = Add(s1, s2);
	//cout << s3 << endl;

	//int a = 20; char b = 10;
	//auto c = Add<int>(a, b);
	//cout << c << endl;

	short bh = 3;	// 超女编号
	const char* message = "我是一只小小鸟。";	// 消息内容
	show(bh, message);
	show(bh);
}

/*
注意：
1) 可以为类的成员函数创建模板，但不能是虚函数和析构函数。
2) 使用函数模板时，必须明确数据类型，确保实参与函数模板能匹配上。
	（函数必须有形参，否则只能显式指定函数模版数据类型：Swap<int>();）
3) 使用函数模板时，推导的数据类型必须适应函数模板中的代码。
	比如 T+T 可以对int, string等有用，但不对 class 有用
4) 使用函数模板时，如果是自动类型推导，不会发生隐式类型转换，
	如果显式指定了函数模板的数据类型，可以隐式类型转换。
5) 函数模板支持多个通用数据类型的参数。
6) 函数模板支持重载，可以有非通用数据类型的参数。
*/