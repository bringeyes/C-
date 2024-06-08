/*

*/

#include <iostream>
using namespace std;

typedef int ElemType;

struct LNode {      // 双链表的结点
    ElemType data;
    LNode* prior, * next;       // 前驱和后继结点的指针
};

// ----------------------------------------

// 初始化链表，返回值：失败返回nullptr，成功返回头结点的地址
LNode* InitList();

// 销毁链表
void DestroyList(LNode*& head);

// 在链表头部插入元素（头插法），返回值：false-失败，true-成功
bool PushFront(LNode* head, const ElemType& ee);

// 显示链表中的全部元素
void PrintList(const LNode* head);

// 求链表表长，返回值：结点的个数，>=0
size_t ListLength(const LNode* head);

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
LNode* LocateNode(const LNode* head, unsigned int n);


// 在指定结点pp之后插入元素ee
bool InsertNextNode(LNode* pp, const ElemType& ee);

// 在指定结点pp之前插入元素ee
bool InsertPriorNode(LNode* pp, const ElemType& ee);

// 删除指定结点pp
bool DeleteNode(LNode* pp);

// ----------------------------------------

int main()
{
    LNode* head = InitList();
    for (int ii =0;ii<10;ii++) PushFront(head, ii);
    PrintList(head);
    cout << "表长：" << ListLength(head) << "\n";

    //for (int ii = 0; ii < 10; ii++) {
    //    PopBack(head);
    //    PrintList(head);
    //}
    //cout << "开始清空\n";
    //ClearList(head);
    //PrintList(head);

    LNode* pp = LocateElem(head, 6);
    cout << "pp=" << pp << " pp->data=" << pp->data << endl;

    pp = LocateNode(head, 6);
    cout << "pp=" << pp << " pp->data=" << pp->data << endl;

    InsertNextNode(pp, 100);
    PrintList(head);

    InsertPriorNode(LocateNode(head, 1), 200);
    PrintList(head);

    DeleteNode(LocateNode(head, 2));
    PrintList(head);
}

// ----------------------------------------

LNode* InitList() {
    LNode* head = new (std::nothrow) LNode;
    if (head == nullptr) { cout << "内存不足，生成头结点失败。\n"; return nullptr; }

    head->prior = head->next = nullptr;
    return head;
}

void DestroyList(LNode*& head) {
    if (head == nullptr) { cout << "链表不存在。\n"; return; }

    LNode* tmp;
    while (head) {
        tmp = head->next;
        delete head;
        head = tmp;
    }
}

bool PushFront(LNode* head, const ElemType& ee) {
    if (head == nullptr) { cout << "链表不存在。\n"; return false; }

    LNode* tmp = new (std::nothrow) LNode;
    tmp->next = head->next;
    tmp->prior = head;
    tmp->data = ee;

    head->next = tmp;

    // 如果插入前链表为空，直接返回
    if (tmp->next == nullptr) return true;

    // 否则修改下一结点的prior
    tmp->next->prior = tmp;
    return true;
}

void PrintList(const LNode* head) {
    if (head == nullptr) { cout << "链表不存在。\n"; return; }
    if (head->next == nullptr) { cout << "链表为空。\n"; return; }

    LNode* tmp = head->next;
    while (tmp) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}

size_t ListLength(const LNode* head) {
    if (head == nullptr) { cout << "链表不存在。\n"; return 0; }

    int count = 0;
    LNode* pp = head->next;
    while (pp) {
        count++;
        pp = pp->next;
    }
    return count;
}

bool PopFront(LNode* head) {
    if (head == nullptr) { cout << "链表不存在。\n"; return false; }
    if (head->next == nullptr) { cout << "链表为空。\n"; return false; }

    LNode* tmp = head->next;
    head->next = tmp->next;
    if (tmp->next == nullptr) { delete tmp;  return true; }
    tmp->next->prior = head;
    delete tmp;
    return true;
}

bool PopBack(LNode* head) {
    if (head == nullptr) { cout << "链表不存在。\n"; return false; }
    if (head->next == nullptr) { cout << "链表为空。\n"; return false; }

    LNode* tmp = head->next;
    while (tmp->next) {         // 遍历至最后一个结点
        tmp = tmp->next;
    }
    tmp->prior->next = nullptr;     // 修改倒数第二个结点的next指向
    delete tmp;         // 释放最后一个结点
    return true;
}

void ClearList(LNode* head) {
    if (head == nullptr) { cout << "链表不存在。\n"; return; }
    if (head->next == nullptr) { cout << "链表已经为空。\n"; return; }

    LNode* pp = head->next, * pp_next;
    while (pp) {
        pp_next = pp->next;
        delete pp;
        pp = pp_next;
    }
    head->next = nullptr;
}

LNode* LocateElem(const LNode* head, const ElemType& ee) {
    if (head == nullptr) { cout << "链表不存在。\n"; return nullptr; }
    if (head->next == nullptr) { cout << "链表为空。\n"; return nullptr; }

    LNode* pp = head->next;
    while (pp) {
        if (pp->data == ee) return pp;
        pp = pp->next;
    }
    cout << "输入的查找项不存在\n";
    return nullptr;
}

LNode* LocateNode(const LNode* head, unsigned int n) {
    if (head == nullptr) { cout << "链表不存在。\n"; return nullptr; }

    unsigned int count = 0;
    LNode* pp = (LNode*)head;
    while (pp && count < n) {
        pp = pp->next;
        count++;
    }
    if (pp == nullptr) cout << "要查找的结点超出链表长度\n";
    return pp;
}

bool InsertNextNode(LNode* pp, const ElemType& ee) {
    if (pp == nullptr) { cout << "要插入的结点位置不存在。\n"; return false; }

    LNode* tmp = new LNode;
    tmp->prior = pp;
    tmp->next = pp->next;
    tmp->data = ee;

    if (pp->next != nullptr) pp->next->prior = tmp;      // pp不为最后一个结点
    pp->next = tmp;

    return true;
}

bool InsertPriorNode(LNode* pp, const ElemType& ee) {
    if (pp == nullptr) { cout << "要插入的结点位置不存在。\n"; return false; }
    if (pp->prior == nullptr) { cout << "插入位置非法，此处为头结点。\n"; return false; }

    LNode* tmp = new LNode;
    tmp->prior = pp->prior;
    tmp->next = pp;
    tmp->data = ee;
    pp->prior->next = tmp;  // 前驱结点
    pp->prior = tmp;    // 后继结点
    return true;
}

bool DeleteNode(LNode* pp) {
    if (pp == nullptr) { cout << "要删除的结点不存在。\n"; return false; }
    if (pp->prior == nullptr) { cout << "删除位置非法，此处为头结点。\n"; return false; }

    LNode* tmp = pp->prior;
    tmp->next = pp->next;   // 前驱结点

    if (pp->next != nullptr) pp->next->prior = tmp;     // 后继结点
    delete pp;
    pp = nullptr;

    return true;
}