#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;

struct LNode {
    ElemType data;              // ��Ž�������Ԫ��
    struct LNode* next;       // ָ����һ������ָ��
};

// ��ʼ����������ֵ��ʧ�ܷ���nullptr���ɹ�����ͷ���ĵ�ַ
LNode* InitList();

// ��������
void DestroyList(LNode*& head);

// ������ͷ������Ԫ�أ�ͷ�巨��������ֵ��false-ʧ�ܣ�true-�ɹ�
bool PushFront(LNode* head, const ElemType& ee);

// ��ʾ�����е�ȫ��Ԫ��
void PrintList(const LNode* head);

// �������������ֵ�����ĸ�����>=0
size_t ListLength(LNode* head);

// ɾ�������һ����㡣
bool PopFront(LNode* head);

// ɾ�����һ�����
bool PopBack(LNode* head);

// ��������ͷ�ͷ��������ȫ�����
void ClearList(LNode* head);

// ����Ԫ�ض�Ӧ�Ľ���ַ���������Ԫ��Ч�ʺܵͣ���Ҫ��������������������ʺϲ��ң�
LNode* LocateElem(const LNode* head, const ElemType& ee);

// ��ȡ�����е�n����㣬�ɹ����ؽ���ַ��ʧ�ܷ���nullptr
// n����ȡ0����ʾͷ���
LNode* LocateNode(LNode* head, unsigned int n);

// ��ָ�����pp֮�����Ԫ��ee
bool InsertNextNode(LNode* pp, const ElemType& ee);

// ��ָ�����pp֮ǰ����Ԫ��ee
bool InsertPriorNode(LNode* pp, const ElemType& ee);

// ɾ��ָ�����pp
bool DeleteNode(LNode* pp);

// ��Ԫ������ز���������
bool PushOrder(LNode* head, const ElemType& ee);

// �鲢������������������ϲ�Ϊһ����������
void MergeList(LNode* La, LNode* Lb, LNode* Lc);