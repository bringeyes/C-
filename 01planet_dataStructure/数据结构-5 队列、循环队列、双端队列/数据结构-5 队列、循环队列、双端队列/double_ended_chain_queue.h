#pragma once
#include <iostream>
using namespace std;

// 双端队列---双链表（用结构体实现，含函数）

// 队列结点
struct D_Node {
	int data;
	D_Node* pre;		// 前驱结点
	D_Node* next;	// 后继结点
	D_Node() :pre(nullptr), next(nullptr) {}
	D_Node(int value) :data(value), pre(nullptr), next(nullptr) {}
};

// 双端队列
struct D_CQueue {
	D_Node* left;
	D_Node* right;
	D_CQueue() {
		D_Node* head = new D_Node;
		left = right = head;
	}

	void left_insert(int k);
	void right_insert(int k);
	void left_delete();
	void right_delete();
	void printQueue();
};