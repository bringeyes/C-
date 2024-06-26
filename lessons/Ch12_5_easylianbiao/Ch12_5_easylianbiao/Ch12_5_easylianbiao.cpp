#include <iostream>
using namespace std;

struct st_girl
{
    int no;
    string name;
    struct st_girl* next;   // 下一个超女节点的地址，如果本节点是最后一条记录，填nullptr。
};

int main()
{
    st_girl *head = nullptr, *tail = nullptr, *tmp = nullptr;
    // *head 头指针，*tail 尾指针，*tmp 临时指针
    
    // 分配第一个节点
    tmp = new st_girl;
    *(tmp) = { 1, "西施",nullptr };   // C++11标准的初始化
    // 或 tmp = new st_girl( { 1, "西施",nullptr } );
    head = tail = tmp;

    tmp = new st_girl({ 6, "冰冰",nullptr });
    tail->next = tmp;   // 把上一个节点的next指针指向新节点
    tail = tmp;             // 移动尾指针，让尾指针指向刚分配出来的新节点

    tmp = new st_girl({ 3, "幂幂",nullptr });
    tail->next = tmp;   // 把上一个节点的next指针指向新节点
    tail = tmp;             // 移动尾指针，让尾指针指向刚分配出来的新节点

    tmp = head;         // 从头节点开始。
    while (tmp != nullptr)      // 指到最后一个的next为空了
    {
        cout << "no=" << tmp->no << "name=" << tmp->name << "tmp->next=" << tmp->next << endl;
        tmp = tmp->next;    // 顺着next指向后面
    }

    // 释放链表
    // *head : { 1, "西施",nullptr }
    while (head != nullptr)
    {
        tmp = head;                 // 让临时节点指向头节点
        head = head->next;      // 头节点后移
        delete tmp;                 // 删除临时节点
    }   
}
