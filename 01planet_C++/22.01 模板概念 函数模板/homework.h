#pragma once
#include <iostream>
using namespace std;

template<class T>
class Input
{
	const char* msg;		// ��ʾ��Ϣ
	T min;
	T max;

public:
	// �ͼ����󣡹��캯��������public
	Input(const char* msg, T min, T max) :msg(msg), min(min), max(max) {
		inputData();
	}

	void inputData() {
		// ��ʾ->�û�����->�Ϸ�->���
		//			   ->���Ϸ�->������ʾ
		T num = 0;
		bool is_input_valid = false;

		cout << msg << endl;		// ��ʾ��Ϣ

		while (!is_input_valid) {
			cin >> num;
			if (num >= min && num <= max) is_input_valid = true;		// ����Ϸ�������ѭ��
			else cout << "���벻�ڷ�Χ�ڣ����������룺" << endl;
		}
		cout << "�����\n" << num << endl;
	}
};

void test05();