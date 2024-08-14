#include "circular_linkedList.h"

cList init_cList() {
	cList l = new(nothrow) cNode;		// 使用new(std::nothrow)，分配失败时返回空指针，而不是抛出异常
	if (l == nullptr) return l;			// 内存分配失败

	l->next = l;			// 初始化指向头结点自己
	return l;
}

// 头结点不包含数据（哨兵结点）
void printList(cList l) {
	if (l == nullptr) return;

	cList tmp = l->next;
	while (tmp != l) {
		cout << tmp->data << ' ';
		tmp = tmp->next;
	}
	cout << endl;
}

// 头插法（不再考虑后继结点是否空）
void head_insert(cList l, int x) {
	if (l == nullptr) return;
	cList tmp = new cNode; tmp->data = x;

	tmp->next = l->next;
	l->next = tmp;
}

// 尾插法（尾结点的next指向头结点）
void tail_insert(cList l, int x) {
	if (l == nullptr) return;

	cList head = l;
	while (l->next != head) {
		l = l->next;
	}
	cList tmp = new cNode; tmp->data = x;

	tmp->next = head;
	l->next = tmp;
}

// 删除结点（要多考虑只有一个结点的情况）
void delete_node(cList l, int k) {
	if (l == nullptr) return;
	// 如果循环链表只有一个元素
	if (l->next == l) {
		if (l->data == k) {
			delete l;
			l = nullptr;
			return;
		}
		else return;
	}

	// 循环结束，要么找到k值，要么遍历结束也没找到
	// 这种写法效率更高
	while (l->next != l && l->next->data != k) {
		l = l->next;
	}
	if (l->next == l) return;		// 没找到就返回

	cList tmp = l->next;
	l->next = tmp->next;
	delete tmp;
	tmp = nullptr;
}

// 更新结点（要多考虑只有一个结点的情况）
void update_node(cList l, int k, int x) {
	if (l == nullptr) return;
	// 如果循环链表只有一个元素
	if (l->next == l) {
		if (l->data == k) {
			l->data = x;
			return;
		}
		else return;
	}

	cList p = l->next;
	while (p != l && p->data != k) {
		p = p->next;
	}
	if (p == l) return;		// 没找到就返回

	p->data = x;
}