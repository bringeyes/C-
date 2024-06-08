#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;

struct LNode {
    ElemType data;              // 存放结点的数据元素
    struct LNode* next;       // 指向下一个结点的指针
};

// 初始化链表，返回值：失败返回nullptr，成功返回头结点的地址
LNode* InitList();

// 销毁链表
void DestroyList(LNode*& head);

// 在链表头部插入元素（头插法），返回值：false-失败，true-成功
bool PushFront(LNode* head, const ElemType& ee);

// 显示链表中的全部元素
void PrintList(const LNode* head);

// 求链表表长，返回值：结点的个数，>=0
size_t ListLength(LNode* head);

// 删除链表第一个结点。
bool PopFront(LNode* head);

// 删除最后一个结点
bool PopBack(LNode* head);

// 清空链表，释放头结点以外的全部结点
void ClearList(LNode* head);

// 查找元素对应的结点地址（链表查找元素效率很低，需要遍历，所以链表根本不适合查找）
LNode* LocateElem(const LNode* head, const ElemType& ee);

// 获取链表中第n个结点，成功返回结点地址，失败返回nullptr
// n可以取0，表示头结点
LNode* LocateNode(LNode* head, unsigned int n);

// 在指定结点pp之后插入元素ee
bool InsertNextNode(LNode* pp, const ElemType& ee);

// 在指定结点pp之前插入元素ee
bool InsertPriorNode(LNode* pp, const ElemType& ee);

// 删除指定结点pp
bool DeleteNode(LNode* pp);

// 把元素有序地插入链表中
bool PushOrder(LNode* head, const ElemType& ee);

// 归并链表，将两个升序链表合并为一个升序链表
void MergeList(LNode* La, LNode* Lb, LNode* Lc);