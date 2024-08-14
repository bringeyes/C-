#include "sstack.h"

SStack initSStack() {
	SStack s;
	s.data = new int[MAX];
	s.top = -1;
	return s;
}

void push(SStack& s, int x) {
	if (s.top == MAX - 1) return;	// ��ջ����

	s.top++;
	s.data[s.top] = x;
}

void pop(SStack& s) {
	if (s.top == -1) return;		// ��ջΪ��

	s.top--;
}

int getTop(SStack s) {
	if (s.top == -1) return 0;	// ��ջΪ��
	return s.data[s.top];
}