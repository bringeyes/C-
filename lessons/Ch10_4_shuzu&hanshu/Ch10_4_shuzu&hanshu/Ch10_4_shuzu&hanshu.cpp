#include <iostream>
using namespace std;

void func(int arr[], int len);

int main()
{
    int a[5] = { 3,4,5,6,7 };
    for (int ii = 0; ii < 5; ii++) {
        cout << "a[" << ii << "]的值是：" << a[ii] << endl;
    }

    int* p = &a[2];
    cout << p[0] << endl;           // 把指针当数组使用
    cout << p[1] << endl;
    cout << p[2] << endl;

    // 奇技淫巧~
    char b[20];         // 占用20字节
    int* p2 = (int*)b;          // 把char型地址强制转换为 int 型，20字节可以容纳5个

    for (int ii = 0; ii < 5; ii++) {
        cout << "p2[" << ii << "]的地址是：" << &p2[ii] << endl;
    }


    func(a, sizeof(a) / sizeof(int));



}

void func(int arr[], int len)           // 当数组传入函数时，必须要传入数组的长度，
                                                  // 否则无法在函数内部通过 sizeof(arr[])/sizeof(int) 得到长度
                                                  // 因为当arr[]传入函数后，实际上是指针，而指针大小 8字节，不能反应数组大小
{ 
    for (int ii = 0; ii < len; ii++) {
        cout << "arr[" << ii << "]的值为：" << arr[ii] << endl;                 // 用数组表示法操作指针，arr是指针
        cout << "*(arr+" << ii << ")的值为：" << *(arr + ii) << endl;       // 指针表示法，*(地址 + 下标) 的形式对地址解引用
    }
}