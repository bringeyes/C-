#include <iostream>
using namespace std;

struct st_t
{
    int a;
    int* p;
};

int main()
{
    st_t stt;
    stt.a = 3;
    stt.p = new int[100];

    cout << "sizeof(stt)=" << sizeof(stt) << endl;      // 显示16字节 8*2 内存对齐
    // delete[] stt.p;     // 注意delete[] 释放动态分配的内存

    cout << "调用前：stt.a=" << stt.a << "stt.p=" << stt.p << endl;
    memset(&stt, 0, sizeof(st_t));      // 同时清空指针

    // 如果前面没有 delete[]
    stt.a = 0;
    memset(stt.p, 0, 100 * sizeof(int));    // 需要分两步清空
                                                            // 清空stt.p指向内存中的内容，而不清空指针
    cout << "调用后：stt.a=" << stt.a << "stt.p=" << stt.p << endl;
    // 后果：1. 先释放后清空，stt.p变成空指针，后续对stt.p的操作变为对空指针操作；
    // 2. stt.p指向的内存没被释放，产生了内存泄漏，堆中内存越来越少，整个系统越来越慢，程序崩溃

}

// 如果结构体中的指针指向的是动态分配的内存地址:
// 对结构体用 sizeof 运算可能没有意义。
// 对结构体用 memset() 函数可能会造成内存泄露 ！！

// 使用结构体，用 memset() 要小心
// 不是自己定义的结构体也要小心！C++中的string！
// 所以结构体中也尽量不要用 string!!