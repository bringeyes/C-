#include <iostream>
using namespace std;

int func1() {         // 返回的是值
    int ii = 3;
    return ii;
}

const int& func2(int& ra) {      // 返回的是引用
    ra++;
    cout << "ra的地址是：" << &ra << "\tra=" << ra << endl;
    return ra;
}

int main()
{
    int a = func1(); cout << "a的地址是：" << &a << "\ta=" << a << endl;
    const int& b = func2(a); cout << "b的地址是：" << &b << "\tb=" << b << endl;    // 在函数调用完，ii被释放，b成了野指针

    // func2(a) = 10;       // 返回的引用被利用
    // 不想被利用，需要在函数声明时加 const 约束返回值

    cout << "a的地址是：" << &a << "\ta=" << a << endl;
    cout << "b的地址是：" << &b << "\tb=" << b << endl;

}

// 如果返回的是一个结构体，将把整个结构体拷贝到临时的位置。
// 如果返回引用不会拷贝内存。

// 使用引用的基本原则：
//      被引用变量的生命周期一定要比引用长！

// 函数返回引用的意义？以后再说