#pragma once
#include <iostream>
using namespace std;

template<class T>
class Pair
{
	T data[2];	// ���������Ա������ͨ����ʼ���б��ʼ����ֻ���ڹ��캯�����г�ʼ��
public:
	Pair(T first, T second) { data[0] = first, data[1] = second; }
	void setData(const T& x, const T& y);
	void show() { cout << "data[0]=" << data[0] << ", data[1]=" << data[1] << endl; }
};

typedef Pair<int> t1;		// ʹ�ñ������򻯴��루ʱ�������������������Ҫ����ģ�����

template<class T>
using t2 = Pair<T>;			// �൱�ڶ��������

template<typename T>		// ��������ʵ�ֳ�Ա��������Ҫ��ģ��
void Pair<T>::setData(const T& x, const T& y) { data[0] = x, data[1] = y; }

void test03();