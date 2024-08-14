#include "chain_queue.h"

Queue initQueue() {
	Queue q;
	q.next = nullptr;
	q.rear = nullptr;
	return q;
}

// 入队：带尾指针的尾插法
void enqueue(Queue& q, int x) {
	Queue* tmp = new Queue;
	tmp->next = nullptr;
	tmp->data = x;

	if (q.next != nullptr) q.rear->next = tmp;
	else q.next = tmp;		// 插入首元时要考虑头结点的next指针
	q.rear = tmp;			// 更新尾指针
}

// 出队：删除首元结点
void dequeue(Queue& q) {
	if (q.next == nullptr) return;
	Queue* tmp = q.next;
	q.next = tmp->next;
	delete tmp;
	tmp = nullptr;

	// 删完时如果队列为空，要置空尾指针
	if (q.next == nullptr) q.rear = nullptr;
}

int getFront(Queue q) {
	if (q.next == nullptr) { cout << "队列为空" << endl; return 0; };
	return q.next->data;
}