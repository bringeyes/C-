#include "cstack.h"

CStack initCStack() {
	CStack c;
	c.next = nullptr;
	return c;
}

// Í·²å·¨
void push(CStack& s, int x) {
	CStack* tmp = new CStack;
	tmp->data = x;

	tmp->next = s.next;
	s.next = tmp;
}

void pop(CStack& s) {
	if (s.next == nullptr) return;		// Á´Õ»Îª¿Õ

	CStack* tmp = s.next;
	s.next = tmp->next;
	delete tmp;
	tmp = nullptr;
}

int getTop(CStack s) {
	if (s.next == nullptr) return 999;		// Á´Õ»Îª¿Õ

	return s.next->data;
}