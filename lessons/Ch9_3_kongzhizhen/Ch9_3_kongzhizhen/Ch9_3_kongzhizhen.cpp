﻿#include <iostream>
using namespace std;

int* func()
{
    int a = 3;
    cout << "a=" << a << ", &a=" << &a << endl;
    return &a;
}

void func1(int* no, string* str)
{
    if ((no == 0) || (str == 0)) return;        //  须判断形参指针是否为空指针
    // 保证程序的健壮性

    cout << "亲爱的" << *no << "号：" << *str << endl;
}

int main()
{
    int* p = 0;     // 空指针
    string* str = 0;
    // cout << "p=" << p << ", *p=" << *p;     // 出现警告，对空指针解引用程序会崩溃

    func1(p, str);
    delete p; delete str;

    // C++11建议用 nullptr 表示空指针，已经是 (void *)0。
    // 在Linux平台下，如果使用nullptr，编译需要加 -std=c++11 参数。

    //  野指针就是指针指向的不是一个有效(合法)的地址。在程序中，如果访问野指针，
    //  可能会造成程序的崩溃。出现野指针的情况主要有三种:
    //  1) 指针在定义的时候，如果没有进行初始化，它的值是不确定的（乱指一气）。
    //  2) 如果用指针指向了动态分配的内存，内存被释放后，指针不会置空，但是，指向的地址已失效。
    //  3) 指针指向的变量已超越变量作用域（变量的内存空间已被系统回收）。

    int* p1;         // 1) 未初始化的野指针

    int* p2 = new int(3);
    cout << "p2=" << p2 << ", *p2=" << *p2 << endl;
    delete p2;      // 2) 内存被释放后，指针不会置空
    // cout << "p2=" << p2 << ", *p2=" << *p2 << endl;      // 地址显示错乱，对指针 p2 解引用失败，没有显示结果

    int* p3 = func();   // 3) 指针指向函数的局部变量
    cout << "p3=" << p3 << ", *p3=" << *p3 << endl;         // 值乱七八糟
}

//  规避野指针的方法:
//  1) 指针在定义的时候，如果没地方指，就初始化为 nullptr。
//  2) 动态分配的内存被释放后，将其置为 nullptr。
//  3) 函数不要返回局部变量的地址。
//  注意 : 野指针的危害比空指针要大很多，在程序中，如果访问野指针，可能会造成程序的崩溃。
//  是可能，不是一定，程序的表现是不稳定，增加了调试程序的难度。“

