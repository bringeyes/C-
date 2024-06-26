/*

*/

#include <iostream>
using namespace std;

typedef int ElemType;

struct LNode{
    ElemType data;              // 存放结点的数据元素
    struct LNode* next;       // 指向下一个结点的指针
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

// ----------------------------------------

int main()
{
    // 链表只需要保存 头结点地址 就行
    LNode* LL = InitList();     // new了一个地址返回给LL

    for (int ii = 0; ii < 10; ii++) {
        PushFront(LL, ii);
    }
    PrintList(LL);

    PopFront(LL);
    PrintList(LL);

    PopBack(LL);
    PrintList(LL);

    LNode* pp = LocateElem(LL, 5);
    cout << "pp=" << pp << "\npp->data=" << pp->data << endl;

    InsertNextNode(pp, 100);
    PrintList(LL);

    InsertPriorNode(pp, 200);
    PrintList(LL);

    DeleteNode(LocateElem(LL, 1));
    PrintList(LL);

    DeleteNode(LocateElem(LL, 2));
    PrintList(LL);

    PopBack(LL);
    PrintList(LL);

    PopFront(LL);
    PrintList(LL);

    int n = 3;
    cout << "链表中第" << n << "个结点：" << LocateNode(LL, n) 
        << "  该结点data：" << LocateNode(LL, n)->data << "\n";

    cout << "链表长度：" << ListLength(LL) << "\n";

    cout << "LL=" << LL << "\nLL->next=" << LL->next << endl;
    ClearList(LL); 
    PrintList(LL);
    cout << "清空链表后：\nLL=" << LL << "\nLL->next=" << LL->next << endl;
    DestroyList(LL);
    cout << "摧毁链表后：\nLL=" << LL << endl;   // 摧毁后LL为nullptr
}

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

    LNode* tmp = head->next, *tmp_next;

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

// 在指定结点pp之后插入元素ee
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