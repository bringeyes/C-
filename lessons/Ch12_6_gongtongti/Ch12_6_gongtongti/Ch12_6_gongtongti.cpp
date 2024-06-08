#include <iostream>
using namespace std;

union udata
{
    int         a;
    double  b;
    char      c[21]; 
    // 同一时间只能存放一种数据类型
    // 占用内存大小为最大成员的内存大小（内存对齐），这里占用24字节
    // 全部成员使用同一块内存
    // 共同体中的值为最后被赋值的那个成员的值。
};

//union         
//{
//    int         a;
//    double  b;
//    char      c[21];
//} data1;        // 创建匿名共同体并初始化，VS不行，Linux可以

struct girl
{
    int age;
    double weight;
    union               // 匿名共同体可以嵌入结构体，成员直接调用 girl.a
    {
        int a;
        double b;
    };
} girl1{ 22,46.5};

int main()
{
    udata data;     // 定义共同体变量
    cout << "&data.a=" << (void*) & data.a << endl;
    cout << "&data.b=" << &data.b << endl;
    cout << "&data.c=" << &data.c << endl;

    data.a = 3;
    data.b = 8.8;
    strcpy_s(data.c, "我是一只傻傻鸟。");
    cout << "data.a=" << data.a << endl;
    cout << "data.b=" << data.b << endl;
    cout << "data.c=" << data.c << endl;        // 最后赋值的值正常，其余乱七八糟

    girl1.a = 6;
    cout << "girl1.a=" << girl1.a << endl;
}

// union应用场景：
// 1. 数据项使用多种格式，但不同时使用时，节省内存空间（嵌入式系统）
// 2. 用于回调函数的参数（相当于支持多种数据类型）