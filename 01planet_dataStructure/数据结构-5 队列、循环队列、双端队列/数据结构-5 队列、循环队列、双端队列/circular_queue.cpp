#include "circular_queue.h"

CQueue initCQueue() {
	CQueue cq;
	cq.data = new int[Max];
	cq.front = cq.rear = 0;
	return cq;
}

void enqueue(CQueue& cq, int x) {
	if ((cq.rear + 1) % Max == cq.front) return;		// 判满，牺牲一个存储位

	// 队尾入队
	cq.data[cq.rear] = x;
	cq.rear = (cq.rear++) % Max;		// cq.rear的范围限制在0~Max-1
}

void dequeue(CQueue& cq) {
	if (cq.rear == cq.front) return;		// 判空

	cq.front = (cq.front++) % Max;
}

int getFront(CQueue cq) {
	if (cq.rear == cq.front) cout << "队列为空" << endl;
	return cq.data[cq.front];
}