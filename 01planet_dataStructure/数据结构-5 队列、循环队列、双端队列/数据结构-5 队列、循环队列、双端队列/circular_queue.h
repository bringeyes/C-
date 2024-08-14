#pragma once
#include <iostream>
using namespace std;
#define Max 10		// 队列容量：Max-1

// 顺序循环队列
struct CQueue {
	int* data;		// 指针模拟开数组
	int front;
	int rear;
};

CQueue initCQueue();

// 入队在队尾 cq.data[rear] = k;
void enqueue(CQueue& cq, int x);

void dequeue(CQueue& cq);

int getFront(CQueue cq);