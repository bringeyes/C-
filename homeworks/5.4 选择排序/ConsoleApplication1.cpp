/*

*/

#include <iostream>
#include <chrono>
using namespace std;

void selectsort1(int arr[], int len);

int main()
{
    int len = 20;
    int cpy[20] = { 13, 2, 15, 8, 10, 19, 1, 20, 4, 3, 5, 9, 18, 11, 12, 14, 17, 6, 7, 16 };
    int arr[20];

    chrono::steady_clock::time_point start, end;    // start-计时开始，end-计时完成
    chrono::nanoseconds dt;     // 时间差
    start = chrono::steady_clock::now();        // 开始计时
    for (int i = 0; i < 1000000; i++) {             // 执行一百万次
        // 填入要测时的代码
        copy(cpy, cpy + len, arr);
        selectsort1(arr, len);
    }
    end = chrono::steady_clock::now();          // 计时完成
    dt = end - start;                                       // 计算时间差
    cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    

    for (int ii = 0; ii < len; ii++) cout << arr[ii] << " ";
    cout << endl;
}

// 用交换元素位置的方式
void selectsort1(int arr[], int len) {
    if (len < 2) return;

    int min, max, pos_min = 0, pos_max = 0, head = 0, tail = len - 1;
    while (tail > head) {
        max = min = arr[head];
        pos_max = pos_min = head;

        for (int ii = head+1; ii <= tail; ii++) {
            if (arr[ii] > max) {
                max = arr[ii]; pos_max = ii;
            }
            if (arr[ii] < min) {
                min = arr[ii]; pos_min = ii;
            }
        }

        if (pos_max != tail) {
            arr[pos_max] = arr[tail];
            arr[tail] = max;
        }
        if (pos_min != head) {
            // 如果在交换最小值前，最小值已经因为最大值的交换换到了原先最大值的位置
            // 则应该在如今最小值的位置，也就是 arr[pos_max] 处存放 head 元素
            if (pos_min == tail) arr[pos_max] = arr[head];
            else arr[pos_min] = arr[head];

            arr[head] = min;
        }

        head++; tail--;
    }
}