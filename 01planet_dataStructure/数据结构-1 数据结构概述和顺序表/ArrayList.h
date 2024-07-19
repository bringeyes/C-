#pragma once
#include <iostream>
using namespace std;
#define Max 100

typedef struct ArrayList
{
	int data[Max];
	int maxsize;		// 最大容量
	int size;		// 实际元素个数
} Array;				// 不能用array，关键字？

Array* initArray();

bool add(Array* arr, int x);

void display(Array* arr);

// 在下标k位置插入元素
bool insert(Array* arr, int k, int x);

// 删除元素x
bool del(Array* arr, int x);