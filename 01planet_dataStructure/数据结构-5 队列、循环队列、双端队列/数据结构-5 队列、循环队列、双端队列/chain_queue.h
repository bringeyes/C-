#pragma once
#include <iostream>
using namespace std;
#define Max 10		// 队列容量：Max-1

/*
链式队列不需要判满--->没有假溢出--->没必要整循环链式队列
*/

// 链式队列（带头结点单链表）
struct Queue {
	int data;
	Queue* next;		// 后继结点
	Queue* rear;		// 队尾指针
};

Queue initQueue();

// 入队：带尾指针的尾插法
void enqueue(Queue& q, int x);

// 出队：删除首元结点
void dequeue(Queue& q);

int getFront(Queue q);