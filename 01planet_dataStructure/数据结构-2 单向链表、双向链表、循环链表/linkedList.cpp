#include "linkedList.h"

linklist initList() {
	linklist l = new(nothrow) Node;		// 使用new(std::nothrow)，分配失败时返回空指针，而不是抛出异常
	if (l == nullptr) return l;			// 内存分配失败

	// l->data = 0;	// l是头结点，不存放数据
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

// 头插法
void head_insert(linklist l, int x) {
	if (l == nullptr) return;
	linklist tmp = new Node;
	tmp->next = l->next;
	tmp->data = x;
	l->next = tmp;
}

// 尾插法
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

	// 循环结束，要么找到k值，要么遍历结束也没找到
	while (l->next && l->next->data != k) {
		l = l->next;
	}
	if (l->next == nullptr) return;		// 为空就返回

	linklist tmp = l->next;
	l->next = tmp->next;
	delete tmp;
	tmp = nullptr;		// 防止tmp成为野指针
}

void update_node(linklist l, int k, int x) {
	if (l == nullptr) return;
	while (l->next && l->next->data != k) {
		l = l->next;
	}
	if (l->next == nullptr) return;		// 为空就返回

	l->next->data = x;
}