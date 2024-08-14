#include "double_ended_chain_queue.h"

void D_CQueue::left_insert(int k) {
	D_Node* tmp = new D_Node(k);
	left->pre = tmp;
	tmp->pre = nullptr;
	tmp->next = left;
	left = tmp;		// ��ָ��ָ��ʵ����˽��
}

void D_CQueue::right_insert(int k) {
	right->data = k;
	D_Node* tmp = new D_Node;
	right->next = tmp;
	tmp->pre = right;
	tmp->next = nullptr;
	right = tmp;	// ��ָ��ָ��ʵ���Ҷ˽���next�ս��
}

void D_CQueue::left_delete() {
	if (left == right) { cout << "����Ϊ��" << endl; return; }

	D_Node* tmp = left;
	left = left->next;
	left->pre = nullptr;

	delete tmp;
	tmp = nullptr;
}

void D_CQueue::right_delete() {
	if (left == right) { cout << "����Ϊ��" << endl; return; }

	D_Node* tmp = right;
	right->pre->next = nullptr;
	right = right->pre;		// ɾ��right�Ľ�㣬����rightָ��ָ��֮ǰ�Ľ��
	delete tmp;
	tmp = nullptr;
}

void D_CQueue::printQueue() {
	if (left == right) { cout << "����Ϊ��" << endl; return; }

	D_Node* tmp = left;
	while (tmp->next) {
		cout << tmp->data << ' ';
		tmp = tmp->next;
	}
	cout << endl;
}