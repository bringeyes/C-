#pragma once
#include <iostream>
using namespace std;

#define MAX 100

// 顺序栈 Sequential stack
typedef struct
{
	int* data;		// 数组
	int top;			// 栈顶“指针”--本质是下标
} SStack;

SStack initSStack();

void push(SStack& s, int x);

void pop(SStack& s);

int getTop(SStack s);