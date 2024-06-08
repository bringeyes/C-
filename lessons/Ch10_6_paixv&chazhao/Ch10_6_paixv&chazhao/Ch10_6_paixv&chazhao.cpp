#include <iostream>
using namespace std;

//  1)  如果函数的返回值 < 0，那么p1所指向元素会被排在p2所指向元素的前面。
//  2)  如果函数的返回值 == 0，那么p1所指向元素与p2所指向元素的顺序不确定
//  3)  如果函数的返回值 >0，那么p1所指向元素会被排在p2所指向元素的后面。
int compasc(const void* p1, const void* p2)     // 回调函数，从小到大排序
{
    //if (*((int*)p1) <    *((int*)p2)) return -1;       // *((int*)p1，先把 void 指针转换为 int 指针，然后再解引用
    //if (*((int*)p1) ==  *((int*)p2)) return 0;
    //if (*((int*)p1) >    *((int*)p2)) return 1;
    return *((int*)p1) - *((int*)p2);       // 只用一行代码即可
}

int compdesc(const void* p1, const void* p2)     // 从大到小排序
{
    return *((int*)p2) - *((int*)p1);
}

int search(int arr[], int len, int key)     // 对升序数组查找
{
    int low = 0, high = len - 1, mid;   // 初始化，覆盖查找范围

    while (low <= high)
    {
        mid = (low + high) / 2;     // 折半查找法
         
        if (arr[mid] == key) return mid;                // 查找成功。
        else if (arr[mid] > key) high = mid - 1;    // 继续在前半区查找
        else low = mid + 1;                                 // 继续在后半区查找
    }
    return -1;          // 查找失败
}

int main()
{
    int a[8] = { 4,3,5,1,2,6,9,8 };

    qsort(a, sizeof(a) / sizeof(int), sizeof(int), compdesc);

    for (int ii = 0; ii < 8; ii++) {
        cout << "a[" << ii << "]=" << a[ii] << endl;
    }

    qsort(a, sizeof(a) / sizeof(int), sizeof(int), compasc);    // 第三个形参，是因为qsort() 函数不知道数组的数据类型

    for (int ii = 0; ii < 8; ii++) {
        cout << "a[" << ii << "]=" << a[ii] << endl;
    }

    int key = 9;        // 要查找的元素
    cout << "元素" << key << "在数组a中的位置：" << search(a, sizeof(a) / sizeof(int), key);
}

// 回调函数的作用就在于，当不是简单的升序降序排序时，满足复杂需求
