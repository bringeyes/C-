/*

*/

#include <iostream>
using namespace std;

typedef int ElemType;

struct QNode {
    ElemType data;     // 存放结点的数据元素
    QNode* next;       // 指向下一个结点的指针
};

struct LinkQueue {
    QNode* head, * tail;
};

// ----------------------------------------

// 初始化队列，返回值：失败返回nullptr，成功返回头结点的地址
LinkQueue* InitQueue();

// 销毁队列
void DestroyQueue(LinkQueue*& QQ);

// 在队列尾部插入元素，返回值：false-失败，true-成功
bool Push(LinkQueue* QQ, const ElemType& ee);

// 显示队列中的全部元素
void PrintQueue(const LinkQueue* QQ);

// 求队列表长，返回值：结点的个数，>=0
size_t QueueLength(const LinkQueue* QQ);

// 删除队列第一个结点。
bool Pop(const LinkQueue* QQ);

// 清空队列，释放头结点以外的全部结点
void ClearQueue(LinkQueue* QQ);

// ----------------------------------------

int main()
{
    LinkQueue* QQ = InitQueue();
    cout << "QQ->head=" << QQ->head << "  QQ->tail=" << QQ->tail << endl;

    for (int ii = 0; ii < 10; ii++) {
        Push(QQ, ii);
    }
    PrintQueue(QQ);

    for (int ii = 0; ii < 5; ii++) {
        Pop(QQ);
    }
    PrintQueue(QQ);

    ClearQueue(QQ);
    PrintQueue(QQ);
    cout << "清空完毕。\n";

    DestroyQueue(QQ);
    PrintQueue(QQ);
    cout << "QQ=" << QQ << endl;
}

LinkQueue* InitQueue() {
    QNode* head = new (std::nothrow) QNode;
    if (head == nullptr)return nullptr;         // 内存不足，返回失败

    head->next = nullptr;

    LinkQueue* QQ = new LinkQueue;
    QQ->head = QQ->tail = head;         // 头尾结点相同

    return QQ;
}

void DestroyQueue(LinkQueue*& QQ) {
    // 销毁队列是指释放队列全部的结点，包括头结点。
    QNode* head = QQ->head;
    QNode* tmp;

    while (head) {
        tmp = head->next;         // tmp 保存下一结点的地址
        delete head;                    // 释放当前结点
        head = tmp;                    // 指针移动到下一结点
    }
    delete QQ;
    QQ = nullptr;
}

bool Push(LinkQueue* QQ, const ElemType& ee) {      // 在队列末尾入队
    if (QQ == nullptr) { cout << "队列不存在。\n"; return false; }    // 检查输入合法性

    QNode* tmp = new (std::nothrow) QNode;      // 分配新结点
    QQ->tail->next = tmp;
    tmp->data = ee;
    tmp->next = nullptr;
    QQ->tail = tmp;             // 调整尾指针

    return true;
}

void PrintQueue(const LinkQueue* QQ) {
    // 检查输入合法性
    if (QQ == nullptr) { cout << "队列不存在。\n"; return; }

    QNode* pp = QQ->head->next;      // 从第 1 个结点开始

    while (pp) {
        cout << pp->data << " ";      // 如果元素为结构体，这行代码要修改
        pp = pp->next;
    }

    cout << endl;
}

size_t QueueLength(const LinkQueue* QQ) {
    if (QQ == nullptr) { cout << "队列不存在。\n"; return 0; }    // 检查输入合法性

    QNode* pp = QQ->head->next;     // 头结点不算
    size_t length = 0;

    while (pp) {
        length++;
        pp = pp->next;
    }
    return length;
}

bool Pop(const LinkQueue* QQ) {
    // 检查输入合法性
    if (QQ == nullptr) { cout << "队列不存在。\n"; return false; }
    if (QQ->head->next == nullptr) { cout << "队列为空，没有结点。\n"; return false; }

    QNode* pp = QQ->head->next;     // 指向第一个结点
    QQ->head->next = pp->next;

    delete pp;      // 删除第一个结点
    return true;
}

void ClearQueue(LinkQueue* QQ) {
    // 检查输入合法性
    if (QQ == nullptr) { cout << "队列不存在。\n"; return; }
    if (QQ->head->next == nullptr) { cout << "队列已经为空，没有结点。\n"; return; }

    QNode* tmp = QQ->head->next, * tmp_next;

    while (tmp) {
        tmp_next = tmp->next;         // tmp_next 保存下一结点的地址
        delete tmp;                            // 释放当前结点
        tmp = tmp_next;                    // 指针移动到下一结点
    }

    QQ->head->next = nullptr;
    QQ->tail = QQ->head;
}