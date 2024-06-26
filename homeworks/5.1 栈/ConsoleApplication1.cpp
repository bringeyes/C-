/*

*/

#include <iostream>
using namespace std;

typedef int ElemType;

struct SNode {
    ElemType data;
    SNode* next;
};

// ----------------------------------------

// 初始化链栈，返回值：失败返回nullptr，成功返回头结点的地址
SNode* InitStack();

// 销毁链栈
void DestroyStack(SNode*& head);

// 在链栈头部插入元素（头插法），返回值：false-失败，true-成功
bool Push(SNode* head, const ElemType& ee);

// 显示链栈中的全部元素
void PrintStack(const SNode* head);

// 求链栈表长，返回值：结点的个数，>=0
size_t StackLength(SNode* head);

// 删除链栈第一个结点。
bool Pop(SNode* head, ElemType& ee);

// ----------------------------------------

int main()
{
    // 初始化栈SS
    SNode* SS = InitStack();
    cout << "入栈10个元素(9, 8, ... , 0)。\n";
    for (int ii = 0; ii < 10; ii++) Push(SS, ii);
    PrintStack(SS);

    cout << "链栈的长度：" << StackLength(SS) << endl;

    ElemType ee = 0;
    Pop(SS, ee);
    PrintStack(SS);
    cout << "出栈的元素 ee=" << ee << endl;

    cout << "销毁链栈\n";
    DestroyStack(SS);
    PrintStack(SS);
    cout << "SS=" << SS << endl;
}

SNode* InitStack() {
    SNode* head = new (std::nothrow) SNode;     // 分配头结点
    if (head == nullptr) return nullptr;         // 内存不足，返回失败

    head->next = nullptr;
    return head;
}

void DestroyStack(SNode*& head) {
    if (head == nullptr) { cout << "链栈不存在。\n"; return; }
    SNode* tmp;

    while (head) {
        tmp = head->next;         // tmp 保存下一结点的地址
        delete head;                    // 释放当前结点
        head = tmp;                    // 指针移动到下一结点
    }
}

bool Push(SNode* head, const ElemType& ee) {   // 插入元素传引用 + const约束
    if (head == nullptr) { cout << "链栈不存在。\n"; return false; }

    SNode* tmp = new (std::nothrow) SNode;
    tmp->next = head->next;
    tmp->data = ee;
    head->next = tmp;

    return true;
}

void PrintStack(const SNode* head) {
    if (head == nullptr) { cout << "链栈不存在。\n"; return; }

    SNode* pp = head->next;      // 从第 1 个结点开始
    while (pp) {
        cout << pp->data << " ";      // 如果元素为结构体，这行代码要修改
        pp = pp->next;
    }
    cout << endl;
}

size_t StackLength(SNode* head) {
    if (head == nullptr) { cout << "链栈不存在。\n"; return 0; }

    SNode* pp = head->next;     // 头结点不算
    size_t length = 0;

    while (pp) {
        length++;
        pp = pp->next;
    }
    return length;
}

bool Pop(SNode* head, ElemType& ee) {    // 出栈需要把第一个元素拿出来用，然后删掉
    if (head == nullptr) { cout << "链栈不存在。\n"; return false; }
    if (head->next == nullptr) { cout << "链栈为空，没有结点。\n"; return false; }

    SNode* pp = head->next;     // 指向第一个结点
    ee = pp->data;                      // 保存结点的数据
    head->next = pp->next;

    delete pp;      // 删除第一个结点
    return true;
}