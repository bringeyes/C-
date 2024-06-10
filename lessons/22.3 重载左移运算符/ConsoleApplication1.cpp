/*

*/

#include <iostream>
using namespace std;

class CGirl
{
	//friend ostream& operator<< (ostream& cout, const CGirl& g);
private:
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

	ostream& operator<< (ostream& cout)		// 隐含了第一个参数：对象本身
	{
		cout << "姓名：" << m_name << "，年龄：" << m_age
			<< "，颜值：" << m_yz << "，评分：" << m_score << endl;
		return cout;
	}
};

//ostream& operator<< (ostream& cout, const CGirl& g)
//{
//	cout << "姓名：" << g.m_name << "，年龄：" << g.m_age
//		<< "，颜值：" << g.m_yz << "，评分：" << g.m_score << endl;
//	return cout;
//}

int main()
{
	CGirl g1("西施", 1, 2, 3), g2("冰冰", 3, 3, 1);
	g1 << cout << endl;
}

/*
左移运算符的重载只能用全局函数方式，不能用成员函数，不然cout得写在对象右边
*/