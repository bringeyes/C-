#pragma once
#include <iostream>
using namespace std;

void Swap(int a, int b);		// ��ͨ����

template <typename T>		// ����ģ��
void Swap(T a, T b)
{
	cout << "ʹ���˺���ģ�� Swap(T a, T b)\n";
}

template <>					// ���廯�ĺ���ģ��
void Swap(int a, int b);