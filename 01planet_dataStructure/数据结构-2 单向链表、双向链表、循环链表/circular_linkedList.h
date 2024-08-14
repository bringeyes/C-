#pragma once
#include <iostream>
using namespace std;

// ��ͷ����ѭ��������Ľ��ṹ
typedef struct cNode
{
	int data;
	cNode* next;		// ��̽���ַ
} cNode, * cList;

// ��ʼ������
cList init_cList();

// ��ӡ����
void printList(cList l);

// ͷ�巨
void head_insert(cList l, int x);

// β�巨
void tail_insert(cList l, int x);

// ɾ������Ϊ k �Ľ��
void delete_node(cList l, int k);

// �Ľ��ֵ���� k ��Ϊ x
void update_node(cList l, int k, int x);