#pragma once
#include <iostream>
using namespace std;

typedef struct Node
{
	int data;
	Node* next;		// 后继结点地址
} Node, * linklist;

// 初始化链表
linklist initList();

// 打印链表
void printList(linklist l);

// 头插法
void head_insert(linklist l, int x);

// 尾插法
void tail_insert(linklist l, int x);

// 删除数据为 k 的结点
void delete_node(linklist l, int k);

// 改结点值，由 k 改为 x
void update_node(linklist l, int k, int x);