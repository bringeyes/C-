#include <iostream>
using namespace std;

int main()
{
    int a[5] = { 3,5,7,3,9 }; 
    for (int ii = -2; ii < 5; ii++)         // 数组的越界，表明数组的下标被解释成了指针，本质是野指针
    {
        cout << "a[" << ii << "]的地址是：" << &a[ii] << endl;
        cout << "a[" << ii << "]的值是：" << a[ii] << endl;
    }

    // 解决方法：
    // 1. 写程序小心点
    // 2. 用C++标准库封装好的数组，肯定不会越界
}
