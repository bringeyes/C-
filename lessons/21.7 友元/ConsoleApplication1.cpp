/*

*/

#include <iostream>
using namespace std;

class CGirl;

class CBoy // 超女的男友类
{
public:
	//void func(const CGirl& g)
	//{
	//	// 注意参数是常对象，只能调用常函数
	//	cout << "我女朋友的姓名是：" << g.m_name << endl;
	//	cout << "我女朋友的年龄是：" << g.m_age << endl;
	//	g.showage();
	//}

	void func1(const CGirl& g);
	void func2(const CGirl& g);
};

class CGirl {
	//friend int main();
	//friend class CBoy;
	friend void CBoy::func1(const CGirl& g);
public:
	string m_name;	// 姓名

	CGirl() {
		m_name = "西施"; m_age = 23;
	}

	void showname() { cout << "姓名：" << m_name << endl; }

private:
	int m_age;	// 年龄

	void showage() const { cout << "年龄：" << m_age << endl; }
};

void CBoy::func1(const CGirl& g) { cout << "我女朋友的年龄是：" << g.m_age << endl; }
void CBoy::func2(const CGirl& g) { cout << "我女朋友的姓名是：" << g.m_name << endl; }

int main()
{
	CGirl g;
	g.showname();

	CBoy b;
	b.func1(g);
	b.func2(g);
}

/*
声明友元的代码放在类中什么地方都可以，一般最上面

友元关系不能被继承。
友元关系是单向的，不具备交换性。

声明友元函数需要把目标函数在类外定义 如CBoy::func1(const CGirl& g)
	并保证目标函数所在类的定义，在声明友元的类的声明和定义之间
*/