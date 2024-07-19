#include "linkedList.h"

linklist initList() {
	linklist l = new(nothrow) Node;		// ʹ��new(std::nothrow)������ʧ��ʱ���ؿ�ָ�룬�������׳��쳣
	if (l == nullptr) return l;			// �ڴ����ʧ��

	// l->data = 0;	// l��ͷ��㣬���������
	l->next = nullptr;
	return l;
}

void printList(linklist l) {
	if (l == nullptr) return;
	while (l->next) {
		cout << l->next->data << ' ';
		l = l->next;
	}
	cout << endl;
}

// ͷ�巨
void head_insert(linklist l, int x) {
	if (l == nullptr) return;
	linklist tmp = new Node;
	tmp->next = l->next;
	tmp->data = x;
	l->next = tmp;
}

// β�巨
void tail_insert(linklist l, int x) {
	if (l == nullptr) return;
	while (l->next) {
		l = l->next;
	}
	linklist tmp = new Node;
	tmp->data = x;
	tmp->next = nullptr;
	l->next = tmp;
}

void delete_node(linklist l, int k) {
	if (l == nullptr) return;

	// ѭ��������Ҫô�ҵ�kֵ��Ҫô��������Ҳû�ҵ�
	while (l->next && l->next->data != k) {
		l = l->next;
	}
	if (l->next == nullptr) return;		// Ϊ�վͷ���

	linklist tmp = l->next;
	l->next = tmp->next;
	delete tmp;
	tmp = nullptr;		// ��ֹtmp��ΪҰָ��
}

void update_node(linklist l, int k, int x) {
	if (l == nullptr) return;
	while (l->next && l->next->data != k) {
		l = l->next;
	}
	if (l->next == nullptr) return;		// Ϊ�վͷ���

	l->next->data = x;
}