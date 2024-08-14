#pragma once
#include <iostream>
using namespace std;

#define Max 100

// 顺序队列
struct Queue {
	int* data;		// 指针模拟开数组
	int front;
	int rear;
};

Queue initQueue();
