/*

*/

#include <iostream>
#include <string>
using namespace std;

class CGirl
{
	friend ostream& operator<< (ostream& cout, const CGirl& g);
public:
	int	m_ranking;
	string	m_name;

	CGirl() { m_name = "西施"; m_ranking = 5; }

	// 实现++前置功能
	CGirl& operator++() {			// 一元运算符都没有参数
		m_ranking++;
		return *this;
	}
	// 实现++后置功能
	CGirl operator++(int) {			// 返回值不能为引用，临时对象没有引用
		CGirl tmp = *this;
		m_ranking++;
		return tmp;
	}
};

ostream& operator<< (ostream& cout, const CGirl& g)		// 隐含了第一个参数：对象本身
{
	cout << "排名：" << g.m_ranking << "，姓名：" << g.m_name;
	return cout;
}

int main()
{
	CGirl g1;
	cout << g1 << endl;

	CGirl g2 = g1++;
	cout << g2 << endl;

	CGirl g3 = ++++g1;
	cout << g3 << endl;

	//int a = 0;
	//cout << a << endl;
}

/*

*/