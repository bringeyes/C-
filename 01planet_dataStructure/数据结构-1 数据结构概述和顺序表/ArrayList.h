#pragma once
#include <iostream>
using namespace std;
#define Max 100

typedef struct ArrayList
{
	int data[Max];
	int maxsize;		// �������
	int size;		// ʵ��Ԫ�ظ���
} Array;				// ������array���ؼ��֣�

Array* initArray();

bool add(Array* arr, int x);

void display(Array* arr);

// ���±�kλ�ò���Ԫ��
bool insert(Array* arr, int k, int x);

// ɾ��Ԫ��x
bool del(Array* arr, int x);