#include "cstack.h"

CStack initCStack() {
	CStack c;
	c.next = nullptr;
	return c;
}

// ͷ�巨
void push(CStack& s, int x) {
	CStack* tmp = new CStack;
	tmp->data = x;

	tmp->next = s.next;
	s.next = tmp;
}

void pop(CStack& s) {
	if (s.next == nullptr) return;		// ��ջΪ��

	CStack* tmp = s.next;
	s.next = tmp->next;
	delete tmp;
	tmp = nullptr;
}

int getTop(CStack s) {
	if (s.next == nullptr) return 999;		// ��ջΪ��

	return s.next->data;
}