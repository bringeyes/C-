/*

*/

#include <iostream>
#include <string>
using namespace std;

class CGirl
{
	friend ostream& operator<< (ostream& cout, const CGirl& g);
public:
	int		m_bh;
	string	m_name;
	int* m_ptr;

	CGirl() { m_ptr = nullptr; }
	~CGirl() { if (m_ptr) delete m_ptr; }	// 释放内存空间

	CGirl& operator=(const CGirl& g) {
		if (this == &g) return *this;	// 防止g1=g1;这种情况重复操作
		m_bh = g.m_bh; m_name = g.m_name;

		if (g.m_ptr == nullptr) {
			if (m_ptr != nullptr) { delete m_ptr; m_ptr = nullptr; }
		}
		else {
			// 如果目标对象指针为空，先分配内存
			if (m_ptr == nullptr) m_ptr = new int;
			// 把源对象内存中的数据复制到目标对象的内存中
			memcpy(m_ptr, g.m_ptr, sizeof(int));
		}

		return *this;	// 解引用，返回对象
	}
};

ostream& operator<< (ostream& cout, const CGirl& g)		// 隐含了第一个参数：对象本身
{
	cout << "姓名：" << g.m_name << "，编号：" << g.m_bh
		<< "，m_ptr=" << g.m_ptr << "，*m_ptr=" << *g.m_ptr;
	return cout;
}

int main()
{
	CGirl g1, g2;
	g1.m_bh = 8; g1.m_name = "西施"; g1.m_ptr = new int(3);
	cout << g1 << endl;
	g2 = g1;		// 对象赋值，多对多
	cout << g2 << endl;
}

/*
对象的赋值运算是用一个已经存在的对象，给另一个已经存在的对象赋值。
如果类的定义中没有重载赋值函数，编译器就会提供一个默认赋值函数。
如果类中重载了赋值函数，编译器将不提供默认赋值函数。
重载赋值函数的语法:	类名 & operator=(const 类名 & 源对象);

注意:
编译器提供的默认赋值函数，是一种浅赋值行为。
如果对象中不存在堆区内存空间，默认重载赋值函数可以满足需求，否则需要深复制。
赋值运算和拷贝构造不同:拷贝构造是指原来的对象不存在，用已存在的对象进行构造;
	赋值运算是指已经存在了两个对象，把其中一个对象的成员变量的值赋给另一个对象的成员变量。
*/