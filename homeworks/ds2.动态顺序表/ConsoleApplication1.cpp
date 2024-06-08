/*

*/

#include <iostream>
#include <chrono>
using namespace std;

#define INITSIZE 5          // 顺序表的初始大小
#define EXTSIZE 3          // 每次扩展元素的个数
typedef int ElemType;     // 给数据元素的数据类型起个别名

struct SeqList {
    ElemType* data;          // 静态数组存储顺序表的元素
    unsigned int maxsize;                 // 顺序表的当前容量
    size_t length;                  // 有效元素的个数
};


// 清空顺序表
void ClearList(SeqList& LL) {
    memset(LL.data, 0, LL.maxsize * sizeof(ElemType));
    LL.length = 0;
}

// 初始化顺序表
void InitList(SeqList& LL) {
    LL.maxsize = INITSIZE;      // 容量初始化
    LL.data = new ElemType[LL.maxsize];     // 给数组分配内存空间
    ClearList(LL);                      // 清空顺序表
}

// 销毁顺序表
void DestroyList(SeqList& LL) {
    delete[] LL.data;        // 释放数组的内存空间
    LL.data = nullptr;      // 指针置空
    LL.maxsize = 0;
    LL.length = 0;
}

// 扩展顺序表的内存空间
bool ExtList(SeqList& LL) {
    // (std::nothrow)是为了不抛出异常
    ElemType* newdata = new (std::nothrow)ElemType[LL.maxsize + EXTSIZE];
    // 如果分配失败，返回 0
    if (newdata == nullptr) return false;

    // 把新分配的内存清空
    memset(newdata, 0, sizeof(ElemType) * (LL.maxsize + EXTSIZE));

    // 释放原来的内存空间
    delete[] LL.data;
    // 分配新地址
    LL.data = newdata;

    // 重置maxsize变量
    LL.maxsize += EXTSIZE;

    return true;
}

bool InsertList(SeqList& LL, const size_t pos, const ElemType ee);

void DisplayList(SeqList& LL) {
    for (int ii = 0; ii < LL.length; ii++) cout << LL.data[ii] << endl;
}


int main()
{
    SeqList L1;
    InitList(L1);
    for (ElemType ee = 1; ee < 11; ee++) {
        InsertList(L1, ee, ee + 1);
        cout << "L1.data[" << ee - 1 << "]=" << L1.data[ee - 1] << endl;
    }
    
    ClearList(L1);
    DisplayList(L1);
}


bool InsertList(SeqList& LL, const size_t pos, const ElemType ee) {
    // 如果空间不够了，扩展内存空间
    if (LL.length == LL.maxsize) {
        if (ExtList(LL) == false) { cout << "扩展顺序表失败。\n"; return false; }
    }

    // 检查输入合法性
    if (pos<1 || pos>LL.length + 1) {
        cout << "插入位置非法，应在 1-" << LL.length + 1 << "之间。\n"; return false;
    }

    // 如果不是在末端插入，复制插入位置之后的部分
    if (pos < LL.length + 1)
        memcpy(&LL.data[pos], &LL.data[pos - 1], (LL.length - pos + 1) * sizeof(ElemType));

    memcpy(&LL.data[pos - 1], &ee, sizeof(ElemType));       // 采用memcpy是为了兼容ee为结构体的情况

    LL.length++;        // 表长加 1

    return true;
}