#pragma once
#include <iostream>
using namespace std;
#define Max 10		// ����������Max-1

/*
��ʽ���в���Ҫ����--->û�м����--->û��Ҫ��ѭ����ʽ����
*/

// ��ʽ���У���ͷ��㵥����
struct Queue {
	int data;
	Queue* next;		// ��̽��
	Queue* rear;		// ��βָ��
};

Queue initQueue();

// ��ӣ���βָ���β�巨
void enqueue(Queue& q, int x);

// ���ӣ�ɾ����Ԫ���
void dequeue(Queue& q);

int getFront(Queue q);