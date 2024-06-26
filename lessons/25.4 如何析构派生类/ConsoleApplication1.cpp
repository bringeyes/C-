/*

*/

#include <iostream>
using namespace std;

class A
{
public:
	A() { cout << "调用了基类的构造函数A()。\n"; }
	virtual ~A() { cout << "调用了基类的析构函数~A()。\n"; }

	virtual void func() { cout << "调用了基类的func()。\n"; }
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
	A* a = new B;
	delete a;
}

/*
派生类析构函数执行完后，会自动调用基类的析构函数
基类指针指向派生类对象，在析构的时候只会执行基类的析构函数
	后果很严重！如果派生类申请了内存，将得不到释放（一般把释放程序写在派生类的析构函数中）
	解决方法：声明基类析构函数为虚函数 virtual ~A()
	C++编译器会自动处理不同名的（基类和派生类）析构函数，因此不必担忧析构函数的多态使用

构造函数和析构函数不能继承
赋值运算符函数、友元函数不能继承

析构函数可能被手工调用，因此销毁指针后，需要置空
	delete ptr;
	ptr = nullptr;
	delete 空指针是安全的，但 delete 野指针会导致程序的崩溃
	如果多次调用析构函数，没有置空，代码就会操作野指针！！！
对于基类来说，即使不需要析构函数，也应该提供一个空虚析构函数
*/