#include "sstack.h"

SStack initSStack() {
	SStack s;
	s.data = new int[MAX];
	s.top = -1;
	return s;
}

void push(SStack& s, int x) {
	if (s.top == MAX - 1) return;	// ¶ÑÕ»ÒÑÂú

	s.top++;
	s.data[s.top] = x;
}

void pop(SStack& s) {
	if (s.top == -1) return;		// ¶ÑÕ»Îª¿Õ

	s.top--;
}

int getTop(SStack s) {
	if (s.top == -1) return 0;	// ¶ÑÕ»Îª¿Õ
	return s.data[s.top];
}