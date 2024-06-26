/*

*/

#include <iostream>
#include <string>
using namespace std;

class CGirl
{
	friend ostream& operator<< (ostream& cout, const CGirl& g);
private:
	string m_boys[3];
public:
	string m_name;
	CGirl() {
		m_name = "西施";
		for (int i = 1; i < 4; i++) {
			m_boys[i - 1] = "友人" + to_string(i);
		}
	}

	// 返回参数为引用，可以当作变量使用
	string& operator[](int i) { return m_boys[i - 1]; }
	// 常对象只能用常函数，实际开发中都要有
	const string& operator[](int i) const { return m_boys[i - 1]; }
};

ostream& operator<< (ostream& cout, const CGirl& g)		// 隐含了第一个参数：对象本身
{
	cout << "姓名：" << g.m_name;
	for (int i = 1; i < 4; i++) cout << "，男友" << i << "：" << g.m_boys[i - 1];
	return cout;
}

int main()
{
	CGirl g1;
	g1[1] = "张三";
	cout << g1 << endl;
	cout << "第1任男朋友：" << g1[1] << endl;

	const CGirl g2 = g1;
	cout << g2 << endl;
	cout << "第1任男朋友：" << g2[1] << endl;
}

/*
如果对象中有数组，重载下标运算符[，操作对象中的数组将像操作普通数组一样方便
下标运算符必须以成员函数的形式进行重载。
下标运算符重载函数的语法:
	返回值类型 &perator[](参数);
	或者:
	const 返回值类型 &operator[](参数) const;
*/