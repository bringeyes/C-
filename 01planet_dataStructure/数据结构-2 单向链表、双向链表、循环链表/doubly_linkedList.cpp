#include "doubly_linkedList.h"

dList init_dList() {
	dList l = new(nothrow) dNode;		// 使用new(std::nothrow)，分配失败时返回空指针，而不是抛出异常
	if (l == nullptr) return l;			// 内存分配失败

	// l->data = 0;	// l是头结点，不存放数据
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

// 头插法
void head_insert(dList l, int x) {
	if (l == nullptr) return;
	dList tmp = new dNode; tmp->data = x;

	if (l->next) l->next->pre = tmp;		// l有next结点（双链表非空）才处理指向tmp的前驱结点
	tmp->next = l->next;
	tmp->pre = l;
	l->next = tmp;
}

// 尾插法
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

	// 循环结束，要么找到k值，要么遍历结束也没找到
	// 这种写法效率更高
	dList p = l->next;

	while (p && p->data != k) {
		p = p->next;
	}
	if (p == nullptr) return;		// 为空就返回

	p->pre->next = p->next;
	if (p->next) p->next->pre = p->pre;
	delete p;
	p = nullptr;

	/*
	while (l->next && l->next->data != k) {
		l = l->next;
	}
	if (l->next == nullptr) return;		// 为空就返回

	dList tmp = l->next;
	l->next = tmp->next;
	if (tmp->next) tmp->next->pre = l;
	delete tmp;
	tmp = nullptr;		// 防止tmp成为野指针
	*/
}

void update_node(dList l, int k, int x) {
	if (l == nullptr) return;

	dList p = l->next;
	while (p && p->data != k) {
		p = p->next;
	}
	if (p == nullptr) return;		// 为空就返回

	p->data = x;
}