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

int main()
{
	string a = "1", b = "2";
	Swap<string>(a, b);		// 如果不希望编译器自动推导，添加<xxx>指定
	cout << a << ", " << b << endl;
}

/*
在 C++98 添加关键字 typename 之前，C++使用关键字 class 来创建模板。
如果考虑向后兼容，函数模板应使用typename，而不是 class。
*/