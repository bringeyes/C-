/*

*/

#include <iostream>
using namespace std;

//class CAllComers		// 海选报名者类(基类)
//{
//protected:
//	int m_a;
//
//private:
//	int m_b;
//
//public:
//	string m_name;
//	string m_tel;
//	CAllComers() { m_name = "XXX"; m_tel = "不详"; m_a = 1; m_b = 2; }
//
//	// 报名时需要唱一首歌
//	void sing() { cout << "我是一只小小鸟。\n"; }
//	void setname(const string name) { m_name = name; }
//	void setTel(const string tel) { m_tel = tel; }
//};
//
//class CGirl1 :public CAllComers		// 超女类(派生类)
//{
//public:
//	int m_bh;
//
//	CGirl1() { m_bh = 8; }
//
//	void show() {
//		cout << "编号：" << m_bh << "，姓名：" << m_name << "，联系方式：" << m_tel << endl;
//	}
//};
//class CGirl2 :protected CAllComers		// 超女类(派生类)
//{
//public:
//	int m_bh;
//
//	CGirl2() { m_bh = 8; }
//
//	void show() {
//		cout << "编号：" << m_bh << "，姓名：" << m_name << "，联系方式：" << m_tel << endl;
//	}
//	void showvalue() { cout << m_a << endl; }
//};
//class CGirl3 :private CAllComers		// 超女类(派生类)
//{
//public:
//	int m_bh;
//
//	CGirl3() { m_bh = 8; }
//
//	void show() {
//		cout << "编号：" << m_bh << "，姓名：" << m_name << "，联系方式：" << m_tel << endl;
//	}
//	void showvalue() { cout << m_a << endl; }
//};
//
////——————————————————————
class A {
public:
	int m_a = 1;
protected:
	int m_b = 2;
private:
	int m_c = 3;	// 基类中的m_c对派生类而言只是隐藏了，但实际存在且占用空间

public:
	A() {
		cout << "调用了A的构造函数。"
			<< "\nA的this指针是：" << this
			<< "\nA中m_a的地址是：" << &m_a
			<< "\nA中m_b的地址是：" << &m_b
			<< "\nA中m_c的地址是：" << &m_c << endl;
	}
	~A() { cout << "调用了A的析构函数。\n"; }

	int using_m_c() { return m_c; }

	void show() {
		cout << "m_c=" << m_c << endl;
	}
};

class B :public A {
public:
	int m_d = 40;

	B() {
		cout << "调用了B的构造函数。"
			<< "\nB的this指针是：" << this
			<< "\nB中m_a的地址是：" << &m_a
			<< "\nB中m_b的地址是：" << &m_b
			<< "\nB中m_d的地址是：" << &m_d << endl;;
	}
	~B() { cout << "调用了B的析构函数。\n"; }
};

// 重载 new 和 delete 操作符，用以跟踪对象在创建和销毁时，内存的分配和释放情况
void* operator new(size_t size) {
	void* ptr = malloc(size);
	cout << "申请到的内存地址：" << ptr << "，大小是：" << size << endl;
	return ptr;
}
void operator delete(void* ptr) {
	if (ptr == 0) return;	// 对空指针delete是安全的
	free(ptr);
	cout << "释放了内存。\n";
}

int main()
{
	cout << "基类A占用的内存大小是：" << sizeof(A) << endl;
	cout << "派生类B占用的内存大小是：" << sizeof(B) << endl;

	B* b = new B;
	delete b;

	//———————奇技淫巧———————
	B* p = new B;
	*((int*)p + 2) = 99;	// 直接用指针访问基类私有成员
	p->show();
}

/*

*/