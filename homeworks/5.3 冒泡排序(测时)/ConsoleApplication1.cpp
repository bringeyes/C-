/*

*/

#include <iostream>
#include <chrono>
using namespace std;

// 采用两层循环实现。
// 参数arr是待排序数组的首地址，len是数组元素的个数。
void bubblesort1(int arr[], int len);

// 采用递归实现。效率较低
void bubblesort2(int arr[], int len);

int main()
{
    int cpy[15] = { 0,1,2,3,4,5,6,7,8,9,11,10,9,8,7 }, arr[15];

    chrono::steady_clock::time_point start, end;    // start-计时开始，end-计时完成
    chrono::nanoseconds dt;     // 时间差
    start = chrono::steady_clock::now();        // 开始计时
    for (int i = 0; i < 1000000; i++) {             // 执行一百万次
        // 填入要测时的代码
        copy(cpy, cpy + 15, arr);
        bubblesort1(arr, 15);
    }
    end = chrono::steady_clock::now();          // 计时完成
    dt = end - start;                                       // 计算时间差
    cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    for (int ii = 0; ii < 15; ii++) cout << arr[ii] << " ";
    cout << endl;

    start = chrono::steady_clock::now();        // 开始计时
    for (int i = 0; i < 1000000; i++) {             // 执行一百万次
        // 填入要测时的代码
        copy(cpy, cpy + 15, arr);
        bubblesort2(arr, 15);
    }
    end = chrono::steady_clock::now();          // 计时完成
    dt = end - start;                                       // 计算时间差
    cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    for (int ii = 0; ii < 15; ii++) cout << arr[ii] << " ";
    cout << endl;
}

void bubblesort1(int arr[], int len) {
    if (len < 2) return;

    bool ifswap = false;
    while (len) {           // 这种情况while比for更高效一点
        ifswap = false;
        for (int ii = 0; ii < len - 1; ii++) {
            if (arr[ii] > arr[ii + 1]) {
                swap(arr[ii], arr[ii + 1]);
                ifswap = true;
            }
        }
        if (ifswap == false) return;
        len--;
    }
}

void bubblesort2(int arr[], int len) {
    if (len < 2) return;

    // 一次遍历数组，将最大的元素移动到最后
    for (int i = 0; i < len - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            // 交换 arr[i] 和 arr[i+1] 的值
            swap(arr[i], arr[i + 1]);
        }
    }

    // 对剩余的元素进行冒泡排序（递归调用）
    bubblesort2(arr, len - 1);
}