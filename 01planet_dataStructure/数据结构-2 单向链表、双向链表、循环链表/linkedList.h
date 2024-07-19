#pragma once
#include <iostream>
using namespace std;

typedef struct Node
{
	int data;
	Node* next;		// ��̽���ַ
} Node, * linklist;

// ��ʼ������
linklist initList();

// ��ӡ����
void printList(linklist l);

// ͷ�巨
void head_insert(linklist l, int x);

// β�巨
void tail_insert(linklist l, int x);

// ɾ������Ϊ k �Ľ��
void delete_node(linklist l, int k);

// �Ľ��ֵ���� k ��Ϊ x
void update_node(linklist l, int k, int x);