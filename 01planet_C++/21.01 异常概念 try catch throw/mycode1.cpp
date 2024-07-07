#include "mycode1.h"

double Div(double x, double y) {
	if (y == 0) throw "除以了0";		// 抛出异常
	return x / y;
}

double add(double x, double y) {
	if (x > 0) {
		MyException myex;
		throw myex;
	}
	return x + y;
}

void test01() {
	try {
		cout << Div(1, 0) << endl;
	}
	/*catch (...) { cout << "出错了！" << endl; }*/
	catch (const char* msg) { cerr << msg << endl; }		// 显示throw抛出的异常信息

	try {
		cout << add(1, -3) << endl;
	}
	catch (exception& e) { cout << e.what() << endl; }
}

int array_index(int* arr, int n, int index) {
	if (index < 0) throw underflow;
	if (index > n - 1) throw overflow;
	return arr[index];
}

void test02() {
	int* arr = new int[10];
	memset(arr, 0, sizeof(int) * 10);
	try {
		cout << array_index(arr, 10, 6) << endl;
		// cout << array_index(arr, 10, -1) << endl;
		cout << array_index(arr, 10, 10) << endl;
	}
	catch (index e) {
		if (e == underflow) cout << "下标过小" << endl;
		else if (e == overflow) cout << "下标过大" << endl;
	}
}