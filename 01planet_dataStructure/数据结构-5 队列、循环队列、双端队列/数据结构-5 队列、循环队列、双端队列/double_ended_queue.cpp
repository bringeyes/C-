#include "double_ended_queue.h"

DQueue initDQueue() {
	DQueue q;
	q.data = new int[Max];
	q.l = q.r = 0;
	q.sum = 0;
	return q;
}

void left_insert(DQueue* q, int k) {
	if (q == nullptr || q->sum == Max) return;

	q->l = (q->l - 1 + Max) % Max;
	q->data[q->l] = k;
	q->sum++;
}

void right_insert(DQueue* q, int k) {
	if (q == nullptr || q->sum == Max) return;

	q->data[q->r] = k;
	q->r = (q->r + 1) % Max;
	q->sum++;
}

void left_delete(DQueue* q) {
	if (q == nullptr || q->sum == 0) return;

	q->l = (q->l + 1) % Max;
	q->sum--;
}

void right_delete(DQueue* q) {
	if (q == nullptr || q->sum == 0) return;

	q->r = (q->r - 1 + Max) % Max;
	q->sum--;
}

void printDQueue(DQueue* q) {
	if (q == nullptr) return;
	if (q->sum == 0) { cout << "¶ÓÁĞÎª¿Õ" << endl; return; }

	int l = q->l;
	for (int i = 0; i < q->sum; i++) {
		cout << q->data[l] << ' ';
		l = (l + 1) % Max;
	}
	cout << endl;
}