#include <iostream>
using namespace std;

void func1(int bh, string str)
{
    cout << "亲爱的" << bh << "号：" << str << endl;
}
void func2(int no, string message);     // func1 func2 为同类型函数

void biaobai(void (*pf)(int), int b)
{
    // 表白前的准备工作。
    cout << "表白前的准备工作已完成。\n";

    // 个性化表白
    // int b = 3;          // 方式1：由调用者函数提供实参
    pf(b);

    // 表白后的收尾工作。
    cout << "表白后的收尾工作已完成。\n";
}

void zs(int a)          // 张三的个性化表白
{
    cout << "我有一只小小鸟。\n";
}

void ls(int b)       // 李四的个性化表白
{
    cout << "我要先翻三个跟斗再表白。\n";
}

int main()
{
    // 声明普通指针时，必须提供指针的类型。同样，声明函数指针时，也必须提供函数类型，
    // 函数的类型是指返回值和参数列表（函数名和形参名不是）

    int bh = 3; string message = "我是一只傻傻鸟。";
    void (*pfa)(int, string) = func1;        // 函数名就是函数的地址
    pfa(bh, message);                        // 函数指针名(实参)，用函数指针调用函数，C++写法
    (*pfa)(bh, message);                    // C语言写法

    biaobai(zs, 3);             // 方式2：把实参从外面传进去
    biaobai(ls, 4);

}

// 给回调函数传递参数的方式：
// 1）由调用者函数提供实参
// 2）把实参从外面传进去
