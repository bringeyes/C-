/*

*/

#include <iostream>
using namespace std;

// 采用两层循环实现。
// 参数arr是待排序数组的首地址，len是数组元素的个数。
void bubblesort1(int arr[], int len);

// 采用递归实现。
void bubblesort2(int arr[], int len);

int main()
{
    int arr[10] = { 3,1,6,7,9,4,5 };
    bubblesort1(arr, 7);
    for (int ii = 0; ii < 7; ii++) cout << arr[ii] << " ";
    cout << endl;
}

void bubblesort1(int arr[], int len) {
    if (len < 2) return;

    // 每次循环，记录最大数
    // 当最大数在末尾，需遍历个数减1
    int a, b, max;
    while (len) {
        max = arr[0];
        for (int ii = 0; ii < len - 1; ii++) {
            a = arr[ii]; b = arr[ii + 1];

            if (a < b) { arr[ii] = a; arr[ii + 1] = b; }
            else { arr[ii] = b; arr[ii + 1] = a; }

            max = max > arr[ii + 1] ? max : arr[ii + 1];    // 记录最大数
        }
        if (arr[len - 1] == max) len--;
    }
}

void bubblesort2(int arr[], int len) {

}