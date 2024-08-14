#pragma once
#include <iostream>
using namespace std;
#define Max 10		//

typedef struct DQueue {
	int* data;
	int l;
	int r;
	int sum;	// ÔªËØ¸öÊý
};

DQueue initDQueue();

void left_insert(DQueue* q, int k);

void right_insert(DQueue* q, int k);

void left_delete(DQueue* q);

void right_delete(DQueue* q);

void printDQueue(DQueue* q);