#pragma once
#include <iostream>
using namespace std;

typedef struct dNode
{
	int data;
	dNode* next;		// ��̽���ַ
	dNode* pre;		// ǰ������ַ
} dNode, * dList;

// ��ʼ������
dList init_dList();

// ��ӡ����
void printList(dList l);

// ͷ�巨
void head_insert(dList l, int x);

// β�巨
void tail_insert(dList l, int x);

// ɾ������Ϊ k �Ľ��
void delete_node(dList l, int k);

// �Ľ��ֵ���� k ��Ϊ x
void update_node(dList l, int k, int x);