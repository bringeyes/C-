/*

*/

#include <iostream>
#include <chrono>
using namespace std;

// 插入排序
void insertsort(int arr[], unsigned int len);

int main()
{
    int len = 20;
    int cpy[20] = { 13, 2, 15, 8, 10, 19, 1, 20, 4, 3, 5, 9, 18, 11, 12, 14, 17, 6, 7, 16 };
    int arr[20];

    //chrono::steady_clock::time_point start, end;    // start-计时开始，end-计时完成
    //chrono::nanoseconds dt;     // 时间差
    //start = chrono::steady_clock::now();        // 开始计时
    //for (int i = 0; i < 1000000; i++) {             // 执行一百万次
    //    // 填入要测时的代码

    //}
    //end = chrono::steady_clock::now();          // 计时完成
    //dt = end - start;                                       // 计算时间差
    //cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    copy(cpy, cpy + len, arr);
    insertsort(arr, len);

    for (int ii = 0; ii < len; ii++) cout << arr[ii] << " ";
    cout << endl;
}

void insertsort(int arr[], unsigned int len) {
    if (len < 2) return;    // 无需排序，返回

    int key;    // 被插入元素
    int j;         // 已排序部分的末尾元素位置

    // 从第二个元素开始，依次将元素插入已排序的部分中
    for (int i = 1; i < len; i++) {
        key = arr[i];
        j = i - 1;

        // 向前遍历已排序部分，找到合适的插入位置
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];    // 元素后移
            j--;
        }

        arr[j + 1] = key;   // 插入到正确的位置
    }
}
