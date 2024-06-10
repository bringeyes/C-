/*

*/

#include <iostream>
using namespace std;

class CGirl
{
	int m_age;
	int m_yz;
	int m_score;
public:
	string m_name;
	CGirl(string name, int age, int yz, int score)
		:m_name(name), m_age(age), m_yz(yz), m_score(score) {}

	void show() {
		cout << "姓名：" << m_name << "，年龄：" << m_age
			<< "，颜值：" << m_yz << "，评分：" << m_score << endl;
	}

	// 比较两个超女的商业价值
	bool operator==(const CGirl& g1)
	{
		if ((m_age + m_yz + m_score) == (g1.m_age + g1.m_yz + g1.m_score)) return true;
		else return false;
	}
	bool operator> (const CGirl& g1)
	{
		// 此处符号是 < 因为设定三个变量值越小，商业价值越大
		if ((m_age + m_yz + m_score) < (g1.m_age + g1.m_yz + g1.m_score)) return true;
		else return false;
	}
	bool operator< (const CGirl& g1)
	{
		if ((m_age + m_yz + m_score) > (g1.m_age + g1.m_yz + g1.m_score)) return true;
		else return false;
	}
};

int main()
{
	CGirl g1("西施", 1, 2, 3), g2("冰冰", 3, 3, 1);
	if (g1 == g2)
		cout << g1.m_name << "和" << g2.m_name << "的商业价值相同。\n";
	else if (g1 < g2)
		cout << g2.m_name << "的商业价值更大。\n";
	else
		cout << g1.m_name << "的商业价值更大。\n";
}

/*
重载关系运算符(==、!=、>、>=、<、<=)用于比较两个自定义数据类型的大小。
可以使用非成员函数和成员函数两种版本，建议采用成员函数版本。
*/