/*

*/

#include <iostream>
using namespace std;

class CGirl {
public:
	string m_name;
	int m_age;

	CGirl(const string& name, int age) {
		m_name = name; m_age = age; cout << "调用了CGirl(&name,age)构造函数。\n";
	}

	void show() const
	{
		cout << "姓名：" << m_name << "，年龄：" << m_age << endl;
	}

	// 比较两个超女的年龄，返回年龄更小的那位
	const CGirl& pk(const CGirl& g) const
	{
		if (g.m_age < m_age) return g;
		return *this;
	}

	int aa;
	void func(int aa) {
		this->aa = aa;
	}
};

int main()
{
	CGirl g1("冰冰", 23), g2("PP", 22), g3("QQ", 20), g4("西施", 26);
	const CGirl& g = g1.pk(g2).pk(g3).pk(g4);
	g.show();
}