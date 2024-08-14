#include "circular_queue.h"

CQueue initCQueue() {
	CQueue cq;
	cq.data = new int[Max];
	cq.front = cq.rear = 0;
	return cq;
}

void enqueue(CQueue& cq, int x) {
	if ((cq.rear + 1) % Max == cq.front) return;		// ����������һ���洢λ

	// ��β���
	cq.data[cq.rear] = x;
	cq.rear = (cq.rear++) % Max;		// cq.rear�ķ�Χ������0~Max-1
}

void dequeue(CQueue& cq) {
	if (cq.rear == cq.front) return;		// �п�

	cq.front = (cq.front++) % Max;
}

int getFront(CQueue cq) {
	if (cq.rear == cq.front) cout << "����Ϊ��" << endl;
	return cq.data[cq.front];
}