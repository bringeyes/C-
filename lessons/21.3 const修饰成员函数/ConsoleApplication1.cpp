/*

*/

#include <iostream>
using namespace std;

class CGirl {
public:
	mutable string m_name;		// mutable 突破成员函数的const约束
	int m_age;

	CGirl(const string& name, int age) {
		m_name = name; m_age = age; cout << "调用了CGirl(&name,age)构造函数。\n";
	}

	void show1() const		// 只能调用含const的成员函数
	{
		m_name = "PPshow1";
		cout << "姓名：" << m_name << "，年龄：" << m_age << endl;
		show2();
	}

	void show2() const
	{
		m_name = "PPshow2";
		cout << "姓名：" << m_name << "，年龄：" << m_age << endl;
	}

	void show3()
	{
		m_name = "PPshow2";
		cout << "姓名：" << m_name << "，年龄：" << m_age << endl;
		show2();
	}
};

int main()
{
	CGirl g1("冰冰", 23);
	g1.show3();

	const CGirl g2("冰冰", 23);		// const修饰的对象(常对象)，只能调用const修饰的成员函数
	g2.show1();
}

// 对构造/析构函数不能加修饰符