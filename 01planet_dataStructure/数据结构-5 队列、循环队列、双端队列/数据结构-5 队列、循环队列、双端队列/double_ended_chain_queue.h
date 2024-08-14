#pragma once
#include <iostream>
using namespace std;

// ˫�˶���---˫�����ýṹ��ʵ�֣���������

// ���н��
struct D_Node {
	int data;
	D_Node* pre;		// ǰ�����
	D_Node* next;	// ��̽��
	D_Node() :pre(nullptr), next(nullptr) {}
	D_Node(int value) :data(value), pre(nullptr), next(nullptr) {}
};

// ˫�˶���
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