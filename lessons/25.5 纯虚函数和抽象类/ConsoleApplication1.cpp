/*

*/

#include <iostream>
using namespace std;

class A
{
public:
	A() { cout << "调用了基类的构造函数A()。\n"; }
	virtual ~A() = 0 { cout << "调用了基类的析构函数~A()。\n"; }

	virtual void func() = 0 { cout << "调用了基类的func()。\n"; }
};

class B :public A
{
public:
	B() { cout << "调用了派生类的构造函数B()。\n"; }
	~B() { cout << "调用了派生类的析构函数~B()。\n"; }

	void func() { cout << "调用了派生类的func()。\n"; }
};

void operator delete(void* ptr) {
	if (ptr == nullptr) return;
	cout << "执行了delete。\n";
	//delete ptr;		// 这样写是错的，会循环调用
	free(ptr);
}

int main()
{
	B b;
	A* a = &b;
	a->func();
}

/*
纯虚函数是一种特殊的虚函数，在某些情况下，基类中不能对虚函数给出有意义的实现，把它声明为纯虚函数。
纯虚函数只有函数名、参数和返回值类型，没有函数体，具体实现留给该派生类去做。
	语法:virtual 返回值类型 函数名(参数列表)=0;
纯虚函数在基类中为派生类保留一个函数的名字，以便派生类它进行重定义。
	如果在基类中没有保留函数名字，则无法支持多态性。
含有纯虚函数的类被称为抽象类，不能实例化对象，可以创建指针和引用。
	派生类必须重定义抽象类中的纯虚函数，否则也属于抽象类。

纯虚析构函数必须有代码实现
	virtual ~A() = 0 { ... }
纯虚析构函数的意义：
	有时候，想使一个类成为抽象类，但刚好又没有任何纯虚函数，怎么办?
	方法很简单:在想要成为抽象类的类中声明一个纯虚析构函数。
*/