#pragma once
#include <iostream>
using namespace std;

// ��ջ Chain stack�������������пգ�
typedef struct CStack
{
	int data;		// ����
	CStack* next;	// ��һ���
} CStack;

// ��ͷ�巨����ջ��ͷ������Ϊջ��������Ҫ������
CStack initCStack();

void push(CStack& s, int x);

void pop(CStack& s);

int getTop(CStack s);