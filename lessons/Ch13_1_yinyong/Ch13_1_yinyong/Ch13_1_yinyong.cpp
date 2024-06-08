#include <iostream>
using namespace std;

struct st_girl  // 定义超女结构体
{
    int no;
    string str;
};  

void func1(st_girl girl)      // 传值。
{
    girl.no = 8;
    girl.str = "我有一只小小鸟。";
    cout << "亲爱的" << girl.no << "号：" << girl.str << endl;
}

void func2(st_girl* girl)    // 传指针
{
    girl->no = 8;
    girl->str = "我有一只小小鸟。";
    cout << "亲爱的" << girl->no << "号：" << girl->str << endl;
}

void func3(st_girl& girl)   // 传引用，好处是不用定义指针就能使用函数，也不需要解引用
{
    girl.no = 8;
    girl.str = "我有一只小小鸟。";
    cout << "亲爱的" << girl.no << "号：" << girl.str << endl;
}

// 在函数中改变指针的值，需要使用二级指针
void func11(int** p)         // 传地址，实参是指针的地址，形参是二级指针。
{
    *p = new int(3);         // p是二级指针，存放指针的地址。
    cout << "func11内存的地址是:" << *p << "，内存中的值是:" << **p << endl;
}

// 更容易理解
void func22(int*& p)     // 传引用，实参是指针，形参是一级指针的别名。
{
    p = new int(3);        // p是一级指针的别名。
    cout << "func22内存的地址是:" << p << "，内存中的值是:" << *p << endl;
}

void func4(const int& no, const string& str)
{
    cout << "亲爱的" << no << "号：" << str << endl;
}

int main()
{
    /* // 引用的数据类型要与原变量名的数据类型相同。
    int a = 3;
    int& ra = a;    // 引用必须在声明时初始化，初始化后不可改变
    cout << "&a=" << &a << "\ta=" << a << endl;
    cout << "&ra=" << &ra << "\tra=" << ra << endl;

    int b = 5;
    ra = b;         // 当a使用
    cout << "&b=" << &b << "\tb=" << b << endl;
    cout << "&ra=" << &ra << "\tra=" << ra << endl; */

    int bh = 3;
    string message = "我是一只傻傻鸟。";

    st_girl girl1 = { 3,"我是一只傻傻鸟。" };
    func1(girl1);
    // func2(&girl1);   
    func3(girl1);       // 传引用的代码更简洁
    cout << "显示 girl1\n";
    cout << "亲爱的" << girl1.no << "号：" << girl1.str << endl;

    int* p = nullptr;
    func11(&p);
    func22(p);

}
// 引用的本质是指针常量的伪装
//      在定义的同时必须初始化，否则没有意义。
//      可以通过解引用的方法修改内存地址中的值。
// int* const ra = &a;

// 回顾二级指针：如果想在子函数中改变指针的值，就要用二级指针，
//                       例如在子函数中动态分配内存
