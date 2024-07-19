#pragma once
#include <iostream>
using namespace std;

typedef struct dNode
{
	int data;
	dNode* next;		// 后继结点地址
	dNode* pre;		// 前驱结点地址
} dNode, * dList;

// 初始化链表
dList init_dList();

// 打印链表
void printList(dList l);

// 头插法
void head_insert(dList l, int x);

// 尾插法
void tail_insert(dList l, int x);

// 删除数据为 k 的结点
void delete_node(dList l, int k);

// 改结点值，由 k 改为 x
void update_node(dList l, int k, int x);