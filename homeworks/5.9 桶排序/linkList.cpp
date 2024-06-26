#include "linkList.h"

LNode* InitList() {
    LNode* head = new (std::nothrow) LNode;     // 分配头结点

    if (head == nullptr)return nullptr;         // 内存不足，返回失败

    // 结构体用 . 访问成员，结构体指针用 -> 访问成员
    head->next = nullptr;       // 头结点的下一结点暂时不存在，置空

    return head;        // 返回头结点
}

void DestroyList(LNode*& head) {
    // 销毁链表是指释放链表全部的结点，包括头结点。
    LNode* tmp;

    while (head) {
        tmp = head->next;         // tmp 保存下一结点的地址
        delete head;                    // 释放当前结点
        head = tmp;                    // 指针移动到下一结点
    }
}

bool PushFront(LNode* head, const ElemType& ee) {   // 插入元素传引用 + const约束
    // 检查输入合法性
    if (head == nullptr) { cout << "链表不存在。\n"; return false; }

    // 分配一块新地址
    LNode* tmp = new (std::nothrow) LNode;

    // 调整结点指向
    tmp->next = head->next;
    head->next = tmp;

    // 赋值
    tmp->data = ee;

    return true;
}

void PrintList(const LNode* head) {
    // 检查输入合法性
    if (head == nullptr) { cout << "链表不存在。\n"; return; }

    LNode* pp = head->next;      // 从第 1 个结点开始

    while (pp) {
        cout << pp->data << " ";      // 如果元素为结构体，这行代码要修改
        pp = pp->next;
    }

    cout << endl;
}

size_t ListLength(LNode* head) {
    // 检查输入合法性
    if (head == nullptr) { cout << "链表不存在。\n"; return 0; }

    LNode* pp = head->next;     // 头结点不算
    size_t length = 0;

    while (pp) {
        length++;
        pp = pp->next;
    }
    return length;

    //if (head == nullptr) return 0;
    //return ListLength(head->next) + 1;      // 包括头结点
}

bool PopFront(LNode* head) {
    // 检查输入合法性
    if (head == nullptr) { cout << "链表不存在。\n"; return false; }
    if (head->next == nullptr) { cout << "链表为空，没有结点。\n"; return false; }

    LNode* pp = head->next;     // 指向第一个结点
    head->next = pp->next;

    delete pp;      // 删除第一个结点
    return true;
}

bool PopBack(LNode* head) {
    // 检查输入合法性
    if (head == nullptr) { cout << "链表不存在。\n"; return false; }
    if (head->next == nullptr) { cout << "链表为空，没有结点。\n"; return false; }

    LNode* pp = head->next;     // 指向第一个结点
    while (pp->next->next) {
        pp = pp->next;
    }
    delete pp->next;             // 删除最后一个结点
    pp->next = nullptr;         // 倒数第二个结点指向空
    return true;
}

void ClearList(LNode* head) {
    // 检查输入合法性
    if (head == nullptr) { cout << "链表不存在。\n"; return; }
    if (head->next == nullptr) { cout << "链表已经为空，没有结点。\n"; return; }

    LNode* tmp = head->next, * tmp_next;

    while (tmp) {
        tmp_next = tmp->next;         // tmp_next 保存下一结点的地址
        delete tmp;                            // 释放当前结点
        tmp = tmp_next;                    // 指针移动到下一结点
    }

    head->next = nullptr;
}

LNode* LocateElem(const LNode* head, const ElemType& ee) {  // 传常量引用，不复制，提高效率
    // 检查输入合法性
    if (head == nullptr) { cout << "链表不存在。\n"; return nullptr; }
    if (head->next == nullptr) { cout << "链表为空，没有结点。\n"; return nullptr; }

    LNode* pp = head->next;     // 从第一个结点开始
    while (pp) {
        // 如果元素是结构体，以下代码要修改成比较关键字
        if (pp->data == ee) return pp;
        pp = pp->next;
    }
    return pp;      // 没找到返回nulltpr
}

LNode* LocateNode(LNode* head, unsigned int n) {
    // 检查输入合法性
    if (head == nullptr) { cout << "链表不存在。\n"; return nullptr; }

    LNode* pp = head;
    unsigned int ii = 0;
    while (pp && ii < n) {
        pp = pp->next;
        ii++;
    }
    if (pp == nullptr)
        cout << "位置" << n << "不合法，超过了表长。\n";

    return pp;
}

bool InsertNextNode(LNode* pp, const ElemType& ee) {
    // 检查输入合法性
    if (pp == nullptr) { cout << "结点不存在，无法插入。\n"; return false; }

    LNode* tmp = new LNode;
    tmp->data = ee;
    tmp->next = pp->next;
    pp->next = tmp;

    return true;
}

bool InsertPriorNode(LNode* pp, const ElemType& ee) {
    // 检查输入合法性
    if (pp == nullptr) { cout << "结点不存在，无法插入。\n"; return false; }

    // 偷梁换柱
    LNode* tmp = new LNode;
    tmp->data = pp->data;
    tmp->next = pp->next;
    pp->data = ee;
    pp->next = tmp;

    return true;
}

bool DeleteNode(LNode* pp) {
    // 检查输入合法性
    if (pp == nullptr) { cout << "结点不存在，无法删除。\n"; return false; }

    // 偷梁换柱法，前提是pp下一结点存在
    if (pp->next) {
        LNode* tmp = pp->next;
        pp->data = tmp->data;
        pp->next = tmp->next;
        delete tmp;
        return true;
    }
    return false;   // 如果pp是最后一个结点，在函数外调用PopBack()函数
}

bool PushOrder(LNode* head, const ElemType& ee) {
    if (head == nullptr) { cout << "链表不存在。\n"; return false; }
    if (head->next == nullptr) return PushFront(head, ee);      // 如果第一个结点为空，直接插入; 

    // 因为是单链表，当找到>=ee的结点时停止，需要保存前驱结点地址
    LNode* pp_pre = head;            // 被比较结点的前驱结点
    LNode* pp = pp_pre->next;     // 被比较结点
    LNode* tmp = new LNode;      // 要插入的结点

    while (pp) {
        if (pp->data >= ee) {        // 如果不为空，从第一个结点起开始比较大小
            tmp->data = ee;
            tmp->next = pp;
            pp_pre->next = tmp;
            return true;                    // 找到合适位置插入后返回
        }
        else {
            pp_pre = pp_pre->next;
            pp = pp->next;
        }
    }

    // 如果遍历结束，pp指向了nullptr，则把tmp插入到链表末尾
    if (pp == nullptr) {
        tmp->data = ee;
        tmp->next = nullptr;
        pp_pre->next = tmp;
        return true;
    }
    return false;
}

void MergeList(LNode* La, LNode* Lb, LNode* Lc) {
    LNode* pa = La->next;
    LNode* pb = Lb->next;

    LNode* pp;

    while (pa && pb) {
        // 取pa，pb的较小者
        if (pa->data <= pb->data) {
            pp = pa;
            pa = pa->next;
        }
        else {
            pp = pb;
            pb = pb->next;
        }

        // 把较小的结点pp追加到Lc中
        Lc->next = pp;
        Lc = Lc->next;
    }

    // 把链表pa或pb的其它元素追加到Lc中
    if (pa) Lc->next = pa;
    if (pb) Lc->next = pb;

    // 链表La和Lb的结点已全部转移给了Lc，需置空，否则DestroyList()会引起重复释放结点
    La->next = Lb->next = nullptr;
}