/*

*/

#include <iostream>
using namespace std;

class CGirl {
public:
	int m_age;
	string m_name;
	char m_bz[3];
	static int m_yz;

	CGirl(const string& name, int age) {
		m_name = name; m_age = age; cout << "调用了CGirl(&name,age)构造函数。\n";
	}

	void showname() const
	{
		if (this == nullptr) return;		// 如果this指针为空，直接返回，防止程序崩溃
		cout << "姓名：" << "m_name" << endl;
	}

	void showage() const
	{
		cout << "年龄：" << m_age << endl;	// 只能访问静态成员
	}
};

int CGirl::m_yz = 9;		// 初始化类的静态成员变量
int aaa;
void func() {}

int main()
{
	CGirl g("PP", 22);
	cout << "对象g占用内存大小：" << sizeof(g) << endl;
	cout << "m_age地址：" << &g.m_age << endl;
	cout << "m_name地址：" << &g.m_name << endl;
	cout << "m_bz地址：" << &g.m_bz << endl;
	cout << "m_yz地址：" << &g.m_yz << endl;
	cout << "aaa地址：" << &aaa << endl;
	printf("成员函数showname的地址：%p\n", &CGirl::showname);
	printf("成员函数showage的地址：%p\n", &CGirl::showage);
	printf("普通函数func的地址：%p\n", &func);

	CGirl* g1 = nullptr;		// 创建一个空指针对象
	g1->showname();			// 用空指针对象调用成员函数
}

/*
char[3]、char[5]对齐8字节
int a,b 对齐8字节
地址连续

静态成员变量不占类的内存
与全局变量存放在一起（不一定连续）

类的成员函数分开存储，存放在内存四区的代码段中
与普通函数存放在一起

如果成员函数中没有用到非静态成员变量，就可以用空指针调用它（少见）

对象的地址是第一个非静态成员变量的地址，如果类中没有非静态成员变量，编译器会隐含的
增加一个1字节的占位成员
*/