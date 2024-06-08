/*

*/

#include <iostream>
#include <chrono>
using namespace std;

// 生成 len 个不重复的随机整数，取值范围 min ~ max，填充 arr[]
void rrand(int arr[], const size_t len, int max, int min = 0);

// 冒泡排序
void bubbleSort(int arr[], int len);

// 希尔排序+冒泡排序
// 当数组长度len>200左右时，效率甚至优于插入排序
void shellSort1(int arr[], unsigned int len);

// 插入排序
void insertSort(int arr[], unsigned int len);

// 希尔排序+插入排序
// 当数组长度len>60左右时，希尔排序的效率高于插入排序
void shellSort2(int arr[], unsigned int len);

int main()
{
    srand(time(0));   // 随机数种子，time(0)当前时间，1970-1-1到现在的秒数，作为随机数种子
    int len = 200;
    int* cpy = new int[len];
    int* arr = new int[len];
    rrand(cpy, len, len, 1);
    //for (int ii = 0; ii < len; ii++)
    //    cout << cpy[ii] << ' ';
    //cout << endl;

    chrono::steady_clock::time_point start, end;    // start-计时开始，end-计时完成
    chrono::nanoseconds dt;     // 时间差

    // -----------------------------------------------------------
    // 冒泡排序
    //start = chrono::steady_clock::now();        // 开始计时
    //for (int i = 0; i < 100000; i++) {             // 执行十万次
    //    // 填入要测时的代码
    //    copy(cpy, cpy + len, arr);
    //    bubbleSort(arr, len);
    //}
    //end = chrono::steady_clock::now();          // 计时完成
    //dt = end - start;                                       // 计算时间差
    //cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    //for (int ii = 0; ii < len; ii++) cout << arr[ii] << " ";
    //cout << endl;

    // -----------------------------------------------------------
    // 希尔+冒泡排序
    start = chrono::steady_clock::now();        // 开始计时
    for (int i = 0; i < 100000; i++) {             // 执行十万次
        // 填入要测时的代码
        copy(cpy, cpy + len, arr);
        shellSort1(arr, len);
    }
    end = chrono::steady_clock::now();          // 计时完成
    dt = end - start;                                       // 计算时间差
    cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    //for (int ii = 0; ii < len; ii++) cout << arr[ii] << " ";
    //cout << endl;

    // -----------------------------------------------------------
    // 插入排序
    start = chrono::steady_clock::now();        // 开始计时
    for (int i = 0; i < 100000; i++) {             // 执行十万次
        // 填入要测时的代码
        copy(cpy, cpy + len, arr);
        insertSort(arr, len);
    }
    end = chrono::steady_clock::now();          // 计时完成
    dt = end - start;                                       // 计算时间差
    cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    //for (int ii = 0; ii < len; ii++) cout << arr[ii] << " ";
    //cout << endl;

    // -----------------------------------------------------------
    // 希尔+插入排序
    start = chrono::steady_clock::now();        // 开始计时
    for (int i = 0; i < 100000; i++) {             // 执行十万次
        // 填入要测时的代码
        copy(cpy, cpy + len, arr);
        shellSort2(arr, len);
    }
    end = chrono::steady_clock::now();          // 计时完成
    dt = end - start;                                       // 计算时间差
    cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    //for (int ii = 0; ii < len; ii++) cout << arr[ii] << " ";
    //cout << endl;

    // -----------------------------------------------------------
    delete[] cpy;
    delete[] arr;
}

void shellSort1(int arr[], unsigned int len) {
    if (len < 2) return;

    int gap = len / 2;      // 分组内的元素间隔
    bool ifswap;

    while (gap >= 1) {
        for (int i = 0; i < gap; i++) {     // 对各分组分别排序
            while (true) {
                ifswap = false;
                for (int j = i; j + gap < len; j += gap) {      // 在每组内部进行冒泡排序
                    if (arr[j] > arr[j + gap]) {
                        swap(arr[j], arr[j + gap]);
                        ifswap = true;
                    }
                }
                if (ifswap == false) break;
            }
        }

        gap /= 2;
    }
}

void shellSort2(int arr[], unsigned int len) {
    if (len < 2) return;

    int gap = len / 2;      // 分组内的元素间隔

    while (gap >= 1) {
        for (int i = 0; i < gap; i++) {     // 对各分组分别排序
            for (int j = i + gap; j < len; j += gap) {      // 在每组内部进行插入排序
                int key = arr[j];                 // 被插入元素
                int k = j - gap;                  // 已排序部分的末尾元素位置
                while (k >= 0 && arr[k] > key) {        // 向前遍历，找到合适的插入位置
                    arr[k + gap] = arr[k];      // 元素后移
                    k -= gap;
                }
                arr[k + gap] = key;         // 插入到正确的位置
            }
        }

        gap /= 2;
    }
}

void bubbleSort(int arr[], int len) {
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

void insertSort(int arr[], unsigned int len) {
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

void rrand(int arr[], const size_t len, int max, int min) {
    if (len > (max - min + 1) || len == 0) return;       // 合法性检查

    int tmp, count = 0, jj = 0;
    while (count < len) {                        // 达到 len 跳出循环
        tmp = rand() % (max - min + 1) + min;          // 范围内的随机数
        for (jj = 0; jj < count; jj++) {        // 如果完整遍历，jj = count
            if (tmp == arr[jj]) break;
        }
        if (jj == count) {          // 包含 jj = 0 的情况
            arr[jj] = tmp;
            count++;
        }
    }
}