#include "test.h"

void test01() {
	CQueue c1 = initCQueue();
	for (int i = 0; i < 11; i++) {
		enqueue(c1, i);
		cout << getFront(c1) << '\t' << c1.rear << endl;
	}
	for (int i = 0; i < 11; i++) {
		dequeue(c1);
		cout << getFront(c1) << '\t' << c1.front << endl;
	}
}

void test02() {
	Queue q = initQueue();
	for (int i = 0; i < 5; i++) {
		enqueue(q, i);
		cout << getFront(q) << endl;
	}
	for (int i = 0; i < 5; i++) {
		dequeue(q);
		cout << getFront(q) << endl;
	}
}

void test03() {
	DQueue q = initDQueue();
	for (int i = 0; i < 4; i++) {
		left_insert(&q, i);
	}
	printDQueue(&q);

	for (int i = 0; i < 5; i++) {
		right_insert(&q, i * 2);
	}
	printDQueue(&q);

	for (int i = 0; i < 7; i++) {
		left_delete(&q);
	}
	printDQueue(&q);

	for (int i = 0; i < 7; i++) {
		right_delete(&q);
	}
	printDQueue(&q);

	cout << "END" << endl;
}

void test04() {
	D_CQueue q;
	for (int i = 0; i < 5; i++) {
		q.left_insert(i);
	}
	q.printQueue();

	for (int i = 0; i < 4; i++) {
		q.right_insert(i * 2);
	}
	q.printQueue();

	for (int i = 0; i < 7; i++) {
		q.right_delete();
	}
	q.printQueue();

	for (int i = 0; i < 7; i++) {
		q.left_delete();
	}
	q.printQueue();
}