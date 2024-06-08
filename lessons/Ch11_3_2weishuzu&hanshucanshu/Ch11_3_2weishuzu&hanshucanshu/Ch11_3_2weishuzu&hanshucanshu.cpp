#include <iostream>
using namespace std;

// 回顾指针类型：
// int* p;          // 整型指针
// int* p[3];      // 一维整型指针数组，元素是3个整型指针（p[0]、p[1]、p[2]）
// int* p();        // 函数 p (p不是指针)，的返回值是整型的地址
// int (*p)(int, int);      //  函数指针，返回值是整型
 
// int (*p)[5]      // 数组指针（行指针），注意与指针数组区别
                        // 这样做的原因是用()给*p更高的优先级，否则就变成了指针数组

void func(int(*p)[3], int len)            // 把二维数组传入函数
// 或 void func(int p[][3], int len);    //两种写法
{
    for (int ii = 0; ii < len; ii++) 
    {
        for (int jj = 0; jj < 3; jj++)
        {
            cout << "p[" << ii << "][" << jj << "]=" << p[ii][jj] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int a[10] = { 0 };
    cout << "数组a第0个元素的地址：" << a << endl;
    cout << "数组a的地址：" << &a << endl;
    cout << "数组a第0个元素的地址+1：" << a + 1 << endl;  // 增量4
    cout << "数组a的地址+1：" << &a + 1 << endl;              // 增量40

    int* p1 = a;
    int(*p2)[10] = &a;      // 行指针长度要与初始化对象一样，否则不能初始化

    int bh[2][3] = {1,2,3,4,5,6};
    int(*p)[3] = bh;        // 这样可以
    // int(*p) = bh;        // 这样不行

    func(p, 2);
}
