#include <iostream>
using namespace std;

int main()
{
    char a;             cout << "sizeof(char)=" << sizeof(char) << endl;            // 1字节
    short b;            cout << "sizeof(short)=" << sizeof(short) << endl;         // 2字节
    int c;                cout << "sizeof(int)=" << sizeof(int) << endl;                 // 4字节
    double d;         cout << "sizeof(double)=" << sizeof(double) << endl;    // 8字节
    
    cout << "a的地址是：" << (void*)&a << endl;
    cout << "a的地址+1是：" << (void*)(&a + 1) << endl;      // 注意优先级

    cout << "b的地址是：" << (void*)&b << endl;
    cout << "b的地址+1是：" << (void*)(&b + 1) << endl;      // 地址增量与数据类型占用字节数相同

    cout << "c的地址是：" << (void*)&c << endl;
    cout << "c的地址+1是：" << (void*)(&c + 1) << endl;

    cout << "d的地址是：" << (void*)&d << endl;
    cout << "d的地址+1是：" << (void*)(&d + 1) << endl;

    int a2[5] = { 3,5,7,3,9 };      // 不能与a重名
    cout << "a2的值：" << a2 << endl;
    cout << "a2的地址是：" << &a2 << endl;
    for (int ii = 0; ii < 5; ii++)
    {
        cout << "a2[" << ii << "]的地址是：" << &a2[ii] << endl;
        // 数组在内存中占用的空间连续
    }
    
    int* p = a2;
    cout << "p的值：" << p << endl;
    for (int ii = 0; ii < 5; ii++)
    {
        cout << "p+" << ii << "的值是：" << p+ii << endl;
        cout << "*(p+" << ii << ")的值是：" << *(p + ii) << endl;
        // 通过指针的算术运算，可以得到数组每个元素的地址，解引用得到元素值
        // C++编译器把  数组名[下标] 解释为 *(数组首地址 + 下标)
    }

    // 数组名不一定会被解释为地址
    //      在多数情况下，C++将数组名解释为数组的第0个元素的地址，
    //      但是，将sizeof运算符用于数据名时，将返回整个数组占用内存空间的字节数。
    // 可以修改指针的值，但数组名是常量，不可修改。（可以p++，但不可以a2++）

}
