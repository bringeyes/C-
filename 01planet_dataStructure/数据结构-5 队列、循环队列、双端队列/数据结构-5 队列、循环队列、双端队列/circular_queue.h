#pragma once
#include <iostream>
using namespace std;
#define Max 10		// ����������Max-1

// ˳��ѭ������
struct CQueue {
	int* data;		// ָ��ģ�⿪����
	int front;
	int rear;
};

CQueue initCQueue();

// ����ڶ�β cq.data[rear] = k;
void enqueue(CQueue& cq, int x);

void dequeue(CQueue& cq);

int getFront(CQueue cq);