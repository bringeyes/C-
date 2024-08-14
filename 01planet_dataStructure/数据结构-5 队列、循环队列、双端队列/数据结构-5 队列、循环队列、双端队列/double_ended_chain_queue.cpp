#include "double_ended_chain_queue.h"

void D_CQueue::left_insert(int k) {
	D_Node* tmp = new D_Node(k);
	left->pre = tmp;
	tmp->pre = nullptr;
	tmp->next = left;
	left = tmp;		// 左指针指向实际左端结点
}

void D_CQueue::right_insert(int k) {
	right->data = k;
	D_Node* tmp = new D_Node;
	right->next = tmp;
	tmp->pre = right;
	tmp->next = nullptr;
	right = tmp;	// 右指针指向实际右端结点的next空结点
}

void D_CQueue::left_delete() {
	if (left == right) { cout << "队列为空" << endl; return; }

	D_Node* tmp = left;
	left = left->next;
	left->pre = nullptr;

	delete tmp;
	tmp = nullptr;
}

void D_CQueue::right_delete() {
	if (left == right) { cout << "队列为空" << endl; return; }

	D_Node* tmp = right;
	right->pre->next = nullptr;
	right = right->pre;		// 删除right的结点，并把right指针指向之前的结点
	delete tmp;
	tmp = nullptr;
}

void D_CQueue::printQueue() {
	if (left == right) { cout << "队列为空" << endl; return; }

	D_Node* tmp = left;
	while (tmp->next) {
		cout << tmp->data << ' ';
		tmp = tmp->next;
	}
	cout << endl;
}