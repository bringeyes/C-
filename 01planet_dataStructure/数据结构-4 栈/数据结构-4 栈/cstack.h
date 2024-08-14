#pragma once
#include <iostream>
using namespace std;

// 链栈 Chain stack（不用判满，判空）
typedef struct CStack
{
	int data;		// 数据
	CStack* next;	// 下一结点
} CStack;

// 用头插法的链栈（头结点这端为栈顶，不需要遍历）
CStack initCStack();

void push(CStack& s, int x);

void pop(CStack& s);

int getTop(CStack s);