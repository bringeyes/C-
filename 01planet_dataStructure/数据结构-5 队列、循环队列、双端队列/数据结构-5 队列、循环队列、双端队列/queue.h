#pragma once
#include <iostream>
using namespace std;

#define Max 100

// ˳�����
struct Queue {
	int* data;		// ָ��ģ�⿪����
	int front;
	int rear;
};

Queue initQueue();
