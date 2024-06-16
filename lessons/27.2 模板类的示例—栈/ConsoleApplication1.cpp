/*

*/

#include <iostream>
using namespace std;

//typedef double DataType;

template <class DataType>
class Stack     // 栈类
{
private:
	DataType* items;     // 栈数组
	int stackSize;  // 栈实际大小
	int top;        // 栈顶指针
public:
	Stack(DataType size) :stackSize(size), top(0) {
		items = new DataType[stackSize];		// 分配栈数组内存。
	}

	~Stack() {
		delete[] items; items = nullptr;
	}

	bool isEmpty() const {	// 判断栈是否为空。
		return top == 0;
	}
	bool ifFull()const {		// 判断栈是否已满。
		return top == stackSize;
	}
	bool push(const DataType& item) {		// 元素入栈
		if (top < stackSize) { items[top++] = item; return true; }
		return false;
	}
	bool pop(DataType& item) {	// 元素出栈
		if (top > 0) { item = items[--top]; return true; }
		return false;
	}
};

int main()
{
	Stack<double> ss(5);		// 创建栈对象，大小是5
	for (int ii = 1; ii <= 5; ii++) {
		ss.push(ii + 0.1);
	}

	// 元素出栈
	double item;
	while (!ss.isEmpty()) {
		ss.pop(item);
		cout << "item=" << item << endl;
	}
}

/*
创建模板类的方法:
	1. 先写一个普通类，用具体的数据类型。
	2. 调试普通类。
	3. 把普通类改为模板类。
*/