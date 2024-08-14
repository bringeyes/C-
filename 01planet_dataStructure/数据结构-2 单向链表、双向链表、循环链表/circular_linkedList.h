#pragma once
#include <iostream>
using namespace std;

// 带头结点的循环单链表的结点结构
typedef struct cNode
{
	int data;
	cNode* next;		// 后继结点地址
} cNode, * cList;

// 初始化链表
cList init_cList();

// 打印链表
void printList(cList l);

// 头插法
void head_insert(cList l, int x);

// 尾插法
void tail_insert(cList l, int x);

// 删除数据为 k 的结点
void delete_node(cList l, int k);

// 改结点值，由 k 改为 x
void update_node(cList l, int k, int x);