/*

*/

#include <iostream>
#include <string>
using namespace std;

class CGirl
{
	friend ostream& operator<< (ostream& cout, const CGirl& g);
public:
	int	m_bh;
	int	m_age;
	static char* m_pool;		// 内存池的起始地址，用char*的好处是指针+1对应一个字节

	// 初始化内存池
	static bool initpool() {
		m_pool = (char*)malloc(18);		// 向系统申请18字节的内存	1+8+1+8
		if (m_pool == 0) return false;	// 如果申请失败，返回false
		memset(m_pool, 0, 18);			// 初始化为0
		cout << "内存池的起始地址：" << (void*)m_pool << endl;
		return true;
	}

	// 释放内存池
	static void freepool() {
		if (m_pool == 0) return;		// 如果内存池为空，不需要释放，返回
		free(m_pool);
		cout << "内存池已释放。\n";
	}

	CGirl(int bh, int age) :m_bh(bh), m_age(age)
	{
		cout << "调用了构造函数CGirl()\n";
	}
	~CGirl() { cout << "调用了析构函数~CGirl()\n"; }

	void* operator new(size_t size)	// 参数必须是size_t（unsigned long long），返回值必须是void*
	{
		if (m_pool[0] == 0) {
			cout << "分配了第一块内存：" << (void*)(m_pool + 1) << endl;
			m_pool[0] = 1;		// 把第一个位置标记为已分配。
			return m_pool + 1;
		}
		if (m_pool[9] == 0) {
			cout << "分配了第一块内存：" << (void*)(m_pool + 10) << endl;
			m_pool[9] = 1;		// 把第二个位置标记为已分配。
			return m_pool + 10;
		}

		// 如果以上两个位置都不可用，那就直接向系统申请内存
		void* ptr = malloc(size);
		cout << "向系统申请到内存：" << ptr << endl;
		return ptr;
	}

	void operator delete(void* ptr)	// 参数必须是void*，返回值必须是void
	{
		if (ptr == 0) return;
		if (ptr == m_pool + 1) {
			cout << "释放了第一块内存。\n";
			m_pool[0] = 0;
			return;
		}
		if (ptr == m_pool + 10) {
			cout << "释放了第二块内存。\n";
			m_pool[9] = 0;
			return;
		}

		free(ptr);		// 内存池外用free释放
		cout << "释放了向系统申请的内存。\n";
	}
};

ostream& operator<< (ostream& cout, const CGirl& g)		// 隐含了第一个参数：对象本身
{
	cout << "年龄：" << g.m_age << "，编号：" << g.m_bh;
	return cout;
}

char* CGirl::m_pool = 0;		// 初始化内存池指针

int main()
{
	// 初始化内存池
	if (CGirl::initpool() == false) { cout << "初始化内存池失败。\n"; return -1; }

	CGirl* p1 = new CGirl(1, 27);
	cout << "p1的地址：" << p1 << '\t' << *p1 << endl;

	CGirl* p2 = new CGirl(3, 23);
	cout << "p2的地址：" << p2 << '\t' << *p2 << endl;

	CGirl* p3 = new CGirl(7, 17);
	cout << "p3的地址：" << p3 << '\t' << *p3 << endl;

	delete p1;
	CGirl* p4 = new CGirl(9, 11);
	cout << "p4的地址：" << p4 << '\t' << *p4 << endl;
	delete p2;
	delete p3;
	delete p4;

	CGirl::freepool();		// 释放内存池

	CGirl* p5 = new CGirl(1, 27);
	cout << "p5的地址：" << p5 << '\t' << *p5 << endl;
	delete p5;
}

/*
简单内存池 18字节 包含：
1字节 第一块内存标志位		8字节 第一块内存，存放类对象
1字节 第二块内存标志位		8字节 第二块内存，存放类对象

如果内存池已满，要向系统申请malloc(size_t)
释放时同样区分是否已满
*/