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
	int	m_name;

	CGirl(int bh, int name) :m_bh(bh), m_name(name)
	{
		cout << "调用了构造函数CGirl()\n";
	}
	~CGirl() { cout << "调用了析构函数~CGirl()\n"; }

	void* operator new(size_t size)	// 参数必须是size_t，返回值必须是void*
	{
		cout << "调用了类重载的全局new：" << size << "字节。\n";
		void* ptr = malloc(size);	// 申请内存。
		cout << "申请到的内存的地址是：" << ptr << endl;
		return ptr;
	}

	void operator delete(void* ptr)	// 参数必须是void*，返回值必须是void
	{
		cout << "调用了类重载的全局delete。\n";
		if (ptr == nullptr)return;	// 对空指针delete是安全的
		free(ptr);		// 释放内存
	}
};

ostream& operator<< (ostream& cout, const CGirl& g)		// 隐含了第一个参数：对象本身
{
	cout << "姓名：" << g.m_name << "，编号：" << g.m_bh;
	return cout;
}

void* operator new(size_t size)	// 参数必须是size_t，返回值必须是void*
{
	cout << "调用了全局重载的new：" << size << "字节。\n";
	void* ptr = malloc(size);	// 申请内存。
	cout << "申请到的内存的地址是：" << ptr << endl;
	return ptr;
}

void operator delete(void* ptr)	// 参数必须是void*，返回值必须是void
{
	cout << "调用了全局重载的delete。\n";
	if (ptr == nullptr)return;	// 对空指针delete是安全的
	free(ptr);		// 释放内存
}

int main()
{
	int* p1 = new int(3);
	cout << "p1=" << (void*)p1 << "，*p1=" << *p1 << endl;
	delete p1;

	CGirl* g1 = new CGirl(8, 321);
	cout << *g1 << endl;
}

/*
重载new
void* operator new(size_t size)	// 参数必须是size_t，返回值必须是void*
	void* ptr = malloc(size);

重载delete
void operator delete(void* ptr)	// 参数必须是void*，返回值必须是void
	free(ptr);

重载的 new 和 delete 可以是全局函数，也可以是类的成员函数。
为一个类重载 new 和 delete 时，尽管不必显式地使用 static，
	但实际上仍在创建 static 成员函数。
	在这两个函数中，不能访问非静态成员
编译器看到使用 new 创建自定义的类的对象时，它选择成员版本的 operator new()而不是全局版本的 new()。

new[] 和 delete[] 也可以重载 （实际开发中类用数组表示的情况不多见，需要自定义分配内存的情况基本没有）
*/