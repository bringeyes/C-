#include <iostream>
using namespace std;

int main()
{
    int* arr = new int[8];      // 创建8个元素的整形数组

    for (int ii = 0; ii < 8; ii++) {
        arr[ii] = 100 + ii;
        cout << "arr[" << ii << "]=" << arr[ii] << endl;
    }

    delete[] arr;                  // 释放一维数组内存


    int* a = new(nothrow) int[1000000000];

    if (a == nullptr) cout << "分配内存失败。\n";
    else {
        a[1000000] = 8;
        cout << a[1000000];
        delete[] a;
    }

}

//  注意:
//      动态创建的数组没有数组名，不能用 sizeof 运算符。
//      可以用数组表示法和指针表示法两种方式使用动态创建的数组。
//      必须使用 delete[] 来释放动态数组的内存(不能只用 delete，否则只会释放 [0] 位置的空间)
//      不要用 delete[] 来释放不是 new[] 分配的内存。（例如栈上的普通数组）
//      不要用 delete[] 释放同一个内存块两次(否则等同于操作野指针)。
//      对空指针用 delete[] 是安全的(释放内存后，应该把指针置空nullptr，防止误操作)。
//      声明普通数组的时候，数组长度可以用变量，相当于在栈上动态创建数组，并且不需要释放。
//      如果内存不足，调用 new 会产生异常，导致程序中止; 
//          如果在 new 关键字后面加 (std::nothrow)，则返回 nullptr ，不会产生异常
//      为什么用 delete[] 释放数组的时候，不需要指定数组的大小? 
//          因为系统会自动跟踪已分配数组的内存。
