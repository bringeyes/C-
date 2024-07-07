#pragma once
#include <iostream>
using namespace std;

template<class T>
class Input
{
	const char* msg;		// 提示信息
	T min;
	T max;

public:
	// 低级错误！构造函数必须是public
	Input(const char* msg, T min, T max) :msg(msg), min(min), max(max) {
		inputData();
	}

	void inputData() {
		// 提示->用户输入->合法->输出
		//			   ->不合法->重新提示
		T num = 0;
		bool is_input_valid = false;

		cout << msg << endl;		// 提示信息

		while (!is_input_valid) {
			cin >> num;
			if (num >= min && num <= max) is_input_valid = true;		// 输入合法就跳出循环
			else cout << "输入不在范围内，请重新输入：" << endl;
		}
		cout << "输出：\n" << num << endl;
	}
};

void test05();