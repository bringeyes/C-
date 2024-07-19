#include "doubly_linkedList.h"

dList init_dList() {
	dList l = new(nothrow) dNode;		// ʹ��new(std::nothrow)������ʧ��ʱ���ؿ�ָ�룬�������׳��쳣
	if (l == nullptr) return l;			// �ڴ����ʧ��

	// l->data = 0;	// l��ͷ��㣬���������
	l->next = nullptr;
	l->pre = nullptr;
	return l;
}

void printList(dList l) {
	if (l == nullptr) return;
	while (l->next) {
		cout << l->next->data << ' ';
		l = l->next;
	}
	cout << endl;
}

// ͷ�巨
void head_insert(dList l, int x) {
	if (l == nullptr) return;
	dList tmp = new dNode; tmp->data = x;

	if (l->next) l->next->pre = tmp;		// l��next��㣨˫����ǿգ��Ŵ���ָ��tmp��ǰ�����
	tmp->next = l->next;
	tmp->pre = l;
	l->next = tmp;
}

// β�巨
void tail_insert(dList l, int x) {
	if (l == nullptr) return;

	while (l->next) {
		l = l->next;
	}
	dList tmp = new dNode; tmp->data = x;

	tmp->next = nullptr;
	tmp->pre = l;
	l->next = tmp;
}

void delete_node(dList l, int k) {
	if (l == nullptr) return;

	// ѭ��������Ҫô�ҵ�kֵ��Ҫô��������Ҳû�ҵ�
	// ����д��Ч�ʸ���
	dList p = l->next;

	while (p && p->data != k) {
		p = p->next;
	}
	if (p == nullptr) return;		// Ϊ�վͷ���

	p->pre->next = p->next;
	if (p->next) p->next->pre = p->pre;
	delete p;
	p = nullptr;

	/*
	while (l->next && l->next->data != k) {
		l = l->next;
	}
	if (l->next == nullptr) return;		// Ϊ�վͷ���

	dList tmp = l->next;
	l->next = tmp->next;
	if (tmp->next) tmp->next->pre = l;
	delete tmp;
	tmp = nullptr;		// ��ֹtmp��ΪҰָ��
	*/
}

void update_node(dList l, int k, int x) {
	if (l == nullptr) return;

	dList p = l->next;
	while (p && p->data != k) {
		p = p->next;
	}
	if (p == nullptr) return;		// Ϊ�վͷ���

	p->data = x;
}