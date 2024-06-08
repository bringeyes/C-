#include <iostream>

using namespace std;

void func(const int* no, const string* str);        // 声明也必须包含const

void func1(int a, int b, int c, int* max, int* min);

int main()
{
    int a = 3, b = 8, c = 5, m ,n;
    func1(a, b, c, &m, &n);
    cout << "m=" << m << "\tn=" << n << endl;

    int bh = 3;             // 超女的编号
    string message = "我是一只傻傻鸟";
    func(&bh, &message);

    // 变量和指向变量的指针就像同一枚硬币的两面。（但多个指针可以指向同一个地址）
    // &a==p，得到地址
    // a==*p，得到值
    
    //// 1. 常量指针（最常用）
    const int* p = &a;
    // 常量指针不能通过引用的方式修改内存地址中的值，
    // *p = 12;    // 会报错，表达式必须是可修改的左值，因为定义为了常量
    
    a = 12;     // 但原始的变量名是可以修改的
    cout << "a=" << a << ", *p=" << *p << endl;
    p = &b;
    // *p = 2   // 就算p重新指向了b，也不能通过引用修改内存地址中的值
    cout << "b=" << b << ", *p=" << *p << endl;


    //// 2. 指针常量（几乎不用）
    int* const p2 = &a;      // 必须赋初始值，否则编译报错
    *p2 = 13;                     // 可以通过引用修改内存地址中的值
    // p2 = &b;                 // 不能重新指向，否则会编译报错
    cout << "a=" << a << ", *p2=" << *p2 << endl;
    // C++编译器把指针常量做了一些特别的处理，有一个新的名字：引用。


    //// 3. 常指针常量（几乎不用）
    const int* const p3 = &a;
    // p3 = &b;    // 指向的对象不可改变
    // *p3 = b;     // 也不可以通过引用修改值
    // 新名字：常引用
}

void func(const int* no, const string* str)     // 希望(实)参数值不修改
{
    // 需要返回的值不止一个时；
    // 这里形参只需要传入两个指针变量，大小均为8字节，共16；
    // 而如果用普通形参，则需要一个int，一个string，共44字节。因此节省内存开销
    
    // *no = 8;
    // *str = "我有一只小小鸟。";
    cout << "亲爱的" << *no << "号：" << *str << endl;
}

void func1(int a, int b, int c, int* max, int* min)
{
    // 让max存储a,b,c中的最大者，让min存储a,b,c中的最小者
    *max = a > b ? a : b;                // 取a和b中的大者
    *min = a < b ? a : b;                 // 取a和b中的小者
    *max = *max > c ? *max : c;     // 取*max和c中的大者
    *min = *min < c ? *min : c;       // 取*max和c中的小者
}