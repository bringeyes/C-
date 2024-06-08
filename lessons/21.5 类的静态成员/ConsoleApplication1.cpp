/*

*/

#include <iostream>
using namespace std;

class CGirl {
	static int m_age;
public:
	string m_name;

	CGirl(const string& name, int age) {
		m_name = name; m_age = age; cout << "调用了CGirl(&name,age)构造函数。\n";
	}

	void showname() {
		cout << "姓名：" << m_name << endl;
	}

	static void showage() {
		cout << "年龄：" << m_age << endl;	// 只能访问静态成员
	}
};

int CGirl::m_age = 9;		// 初始化类的静态成员变量

int main()
{
	/*cout << "CGirl::m_age=" << CGirl::m_age << endl;*/
	CGirl::showage();
	CGirl g1("冰冰", 23);
	g1.showage();
}

/*
静态成员虽然声明在类中，但它是全局的，属于整个程序，不属于具体的对象
静态成员变量在程序中只有一份(生命周期与程序运行期相同，存放在静态存储区的)，
	不论是否创建了类的对象，也不论创建了多少个类的对象。
在静态成员函数中，只能访问静态成员，不能访问非静态成员。
静态成员函数中没有 this 指针。
在非静态成员函数中，可以访问静态成员。（正常访问）

私有静态成员在类外无法访问。很重要！！(如果没有这个约束，类的静态成员与全局变量和全局函数就没有区别了)

*/