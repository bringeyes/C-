#pragma once
#include <iostream>
using namespace std;

#define MAX 100

// ˳��ջ Sequential stack
typedef struct
{
	int* data;		// ����
	int top;			// ջ����ָ�롱--�������±�
} SStack;

SStack initSStack();

void push(SStack& s, int x);

void pop(SStack& s);

int getTop(SStack s);