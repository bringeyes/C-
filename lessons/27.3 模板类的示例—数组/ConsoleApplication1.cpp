/*

*/

#include <iostream>
#include <string>
using namespace std;

//#define MAXLEN 10

// 定长数组容器
template <class DataType, int len = 10>
class Array     // 数组类
{
private:
	DataType items[len];		// 数组元素
public:
	Array() {}		// memset(items, 0, sizeof(items)); // 默认构造函数
	~Array() {}		// 析构函数

	DataType& operator[](int ii) { return items[ii]; }	// 重载操作符[]，可以修改数组中的元素，形参为数组下标。
	const DataType& operator[](int ii)const { return items[ii]; }
};

// 变长数组容器
template <class DataType>
class Vector     // 数组类
{
private:
	int len;			// 数组大小
	DataType* items;		// 数组元素
public:
	// 默认构造函数
	Vector(int size = 10) :len(size) {
		items = new DataType[len];
	}
	~Vector() {			// 析构函数
		delete[] items; items = nullptr;
	}

	void resize(int size) {		// 扩展数组的内存空间
		if (size <= len) return;					// 只能往大扩展，不能缩小
		DataType* tmp = new DataType[size];		// 分配更大的内存空间
		for (int ii = 0; ii < len; ii++) tmp[ii] = items[ii];
		delete[] items;		// 释放原数组
		items = tmp;			// 指向新数组
		len = size;			// 更新数组长度
	}
	int size()const { return len; }		// 获取数组长度。

	DataType& operator[](int ii) {		// 重载操作符[]，可以修改数组中的元素，形参为数组下标。
		if (ii >= len) resize(ii + 10);	// 扩展数组。

		return items[ii];
	}

	// const约束的成员函数不用修改，因为它是只读的
	const DataType& operator[](int ii)const { return items[ii]; }
};

int main()
{
	//Array<double, 10> a1;
	Vector<double> a1(1);	// 创建模板类Vector的对象
	for (int ii = 0; ii < 10; ii++) {
		a1[ii] = ii + 1.1;
		cout << "a1[" << ii << "]=" << a1[ii] << endl;
	}

	//Array<string> a2;
	Vector<string> a2;
	for (int ii = 0; ii < 10; ii++) {
		a2[ii] = "NO.";	// + to_string(ii + 1);
		cout << "a2[" << ii << "]=" << a2[ii] << endl;
	}
}

/*
创建模板类的方法:
	1. 先写一个普通类，用具体的数据类型。
	2. 调试普通类。
	3. 把普通类改为模板类。

	DataType items[MAXLEN];
	memset(items, 0, sizeof(items));
	当 DataType 是 string 使用 memset 会清空指向堆区的指针，所以显示的时候会有问题
		但加上 + to_string(ii + 1) 问题就消失了？？

类模板可以有非通用类型参数:
	1) 通常是整型(C++20标准可以用其它);
	2) 实例化板时必须用常量表达式;
	3) 模板中不能修改参数的值。		// 不能len = 20;

Array类	优点：在栈上分配内存，易维护，执行速度快，合适小型数组。
		缺点：在程序中，不同的非通用类型参数将导致编译器生成不同的类。

构造函数的方法更通用，因为数据的大小是类的成员(而不是硬编码)，可以创建数组大小可变的类
*/