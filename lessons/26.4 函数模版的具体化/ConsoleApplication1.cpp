/*

*/

#include <iostream>
using namespace std;

class CGirl
{
public:
	int m_bh;
	string m_name;
	int m_rank;

	//template <typename T>
	//CGirl(T a) {
	//	cout << "a=" << a << endl;
	//}
	CGirl(int rank) :m_rank(rank) {};

	template <typename T>
	void show(T b) {
		cout << "b=" << b << endl;
	}
};

void Swap(int a, int b) {
	cout << "使用了普通函数 Swap(int a, int b)\n";
}
//void Swap(string a, string b) {
//	cout << "使用了普通函数 Swap(string a, string b)\n";
//}

// 交换的模板函数
template <typename T>
void Swap(T a, T b) {
	T tmp = a;
	a = b;
	b = tmp;
	cout << "使用了函数模版 Swap(T& a, T& b)\n";
}

// 具体化函数
// template<> void Swap(CGirl& g1, CGirl& g2)
//template<>
//void Swap<CGirl>(CGirl& g1, CGirl& g2) {
//	int tmp = g1.m_rank;
//	g1.m_rank = g2.m_rank;
//	g2.m_rank = tmp;
//	cout << "使用了具体化的函数模板 Swap<CGirl>(CGirl& g1, CGirl& g2)\n";
//}
//
//template<>
//void Swap<string>(string& g1, string& g2) {
//	cout << "使用了具体化的函数模板 Swap<string>(string& g1, string& g2)\n";
//}

//————————————————————————————————————————————————————————

int main()
{
	//CGirl g1(1), g2(3);
	//Swap(g1, g2);
	//cout << g1.m_rank << ", " << g2.m_rank << endl;

	Swap(1.1, 3.3);		// 使用了函数模板
	//Swap(1.1, 3.3);	// 空模板参数，绕过普通函数
	//string s1 = "西施", s2 = "23岁";
	//Swap(s1, s2);
}

//————————————————————————————————————————————————————————

/*
函数声明和定义可以分开，但声明和定义都不能省略模版标签

对于给定的函数名，可以有普通函数、函数模板和具体化的函数模板，以及它们的重载版本。

编译器使用各种函数的规则:
1) 优先级：普通函数(重载) > 具体化 > 常规模板。
2) 如果希望使用函数模板，可以用空模板参数强制使用函数模板。
3) 如果函数模板能产生更好的匹配，将优先于非模板函数。
	Swap(1.1, 3.3);
	函数模板的double比普通函数的int更合适

注意，常量不能被引用
*/