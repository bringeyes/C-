#include "chain_queue.h"

Queue initQueue() {
	Queue q;
	q.next = nullptr;
	q.rear = nullptr;
	return q;
}

// ��ӣ���βָ���β�巨
void enqueue(Queue& q, int x) {
	Queue* tmp = new Queue;
	tmp->next = nullptr;
	tmp->data = x;

	if (q.next != nullptr) q.rear->next = tmp;
	else q.next = tmp;		// ������ԪʱҪ����ͷ����nextָ��
	q.rear = tmp;			// ����βָ��
}

// ���ӣ�ɾ����Ԫ���
void dequeue(Queue& q) {
	if (q.next == nullptr) return;
	Queue* tmp = q.next;
	q.next = tmp->next;
	delete tmp;
	tmp = nullptr;

	// ɾ��ʱ�������Ϊ�գ�Ҫ�ÿ�βָ��
	if (q.next == nullptr) q.rear = nullptr;
}

int getFront(Queue q) {
	if (q.next == nullptr) { cout << "����Ϊ��" << endl; return 0; };
	return q.next->data;
}