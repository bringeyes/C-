/*

*/

#include <iostream>
#include <chrono>
using namespace std;

// 展示数组
void desplay(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

// 生成 len 个不重复的随机整数，取值范围 min ~ max，填充 arr[]
void rrand(int arr[], const size_t len, int max, int min = 0);

// 希尔排序
void shellSort(int arr[], unsigned int len);

// 快速排序（任意长度的数组都比希尔排序快）
void quickSort(int arr[], unsigned int len);

// 快速排序（GPT1）速度和希尔排序接近
void quickSort1(int arr[], unsigned int len);

// -----------------------------------------------------------
// 快速排序（GPT2）
void swap1(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low + (high - low) / 2]; // 选择中间的元素作为pivot
    int i = low - 1; // 初始化左边界
    int j = high + 1; // 初始化右边界

    while (true) {
        // 找到左边大于pivot的元素
        do {
            i++;
        } while (arr[i] < pivot);

        // 找到右边小于pivot的元素
        do {
            j--;
        } while (arr[j] > pivot);

        // 如果左边界大于等于右边界，则分区完成
        if (i >= j)
            return j;

        // 交换元素
        swap1(arr[i], arr[j]);
    }
}

void quickSort2(int arr[], int low, int high) {
    if (low < high) {
        // 对数组进行划分，获取分区点
        int pi = partition(arr, low, high);

        // 对左边的子数组进行快速排序
        quickSort2(arr, low, pi);

        // 对右边的子数组进行快速排序
        quickSort2(arr, pi + 1, high);
    }
}

// 对外接口
void quickSort2(int arr[], unsigned int len) {
    quickSort2(arr, 0, len - 1);
}

// -----------------------------------------------------------

int main()
{
    srand(time(0));   // 随机数种子，time(0)当前时间，1970-1-1到现在的秒数，作为随机数种子

    int len = 500;
    int* cpy = new int[len];
    int* arr = new int[len];
    rrand(cpy, len, len, 1);

   /* desplay(cpy, len);*/
    cout << "数组长度：" << len << endl;

    // -----------------------------------------------------------

    chrono::steady_clock::time_point start, end;    // start-计时开始，end-计时完成
    chrono::nanoseconds dt;     // 时间差
    
    // -----------------------------------------------------------
    // 希尔排序
    cout << "希尔排序：" << endl;

    start = chrono::steady_clock::now();        // 开始计时
    for (int i = 0; i < 100000; i++) {             // 执行十万次
        // 填入要测时的代码
        copy(cpy, cpy + len, arr);
        shellSort(arr, len);
    }
    end = chrono::steady_clock::now();          // 计时完成
    dt = end - start;                                       // 计算时间差
    cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    /*desplay(arr, len);*/
    cout << endl;
    
    // -----------------------------------------------------------
    // 快速排序
    cout << "快速排序：" << endl;

    start = chrono::steady_clock::now();        // 开始计时
    for (int i = 0; i < 100000; i++) {             // 执行十万次
        // 填入要测时的代码
        copy(cpy, cpy + len, arr);
        quickSort(arr, len);
    }
    end = chrono::steady_clock::now();          // 计时完成
    dt = end - start;                                       // 计算时间差
    cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    /*desplay(arr, len);*/
    cout << endl;

    // -----------------------------------------------------------
    // 快速排序（GPT）
    cout << "快速排序（GPT）：" << endl;

    start = chrono::steady_clock::now();        // 开始计时
    for (int i = 0; i < 100000; i++) {             // 执行十万次
        // 填入要测时的代码
        copy(cpy, cpy + len, arr);
        quickSort1(arr, len);
    }
    end = chrono::steady_clock::now();          // 计时完成
    dt = end - start;                                       // 计算时间差
    cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    cout << endl;

    // -----------------------------------------------------------
    // 快速排序（GPT2）
    cout << "快速排序（GPT2）：" << endl;

    start = chrono::steady_clock::now();        // 开始计时
    for (int i = 0; i < 100000; i++) {             // 执行十万次
        // 填入要测时的代码
        copy(cpy, cpy + len, arr);
        quickSort2(arr, len);
    }
    end = chrono::steady_clock::now();          // 计时完成
    dt = end - start;                                       // 计算时间差
    cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    desplay(arr, len);

    // -----------------------------------------------------------
    delete[] cpy;
    delete[] arr;
}

void quickSort(int arr[], unsigned int len) {
    if (len < 2) return;    // 数组元素<2个不用排序

    int mid = arr[0];       // 中心轴（基准数）
    int left = 0, right = len - 1;
    int moving = 2;        // 当前应移动的指针，1-左指针，2-右指针，缺省取值2。

    while (left < right) {
        if (moving == 2) {      // 移动右指针
            if (arr[right] >= mid) { right--; continue; }
            arr[left] = arr[right];
            left++;
            moving = 1;
        }
        else {                          // 移动左指针
            if (arr[left] < mid) { left++; continue; }
            arr[right] = arr[left];
            right--;
            moving = 2;
        }
    }
    arr[left] = mid;

    quickSort(arr, left);         // 对左区间排序
    quickSort(arr + left + 1, len - left - 1);      // 对右区间排序
}

void shellSort(int arr[], unsigned int len) {
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

void quickSort1(int arr[], unsigned int len) {
    if (len < 2) return;    // 数组元素<2个不用排序

    int pivot = arr[len / 2]; // 选择中间元素作为基准点
    int i = 0, j = len - 1;

    // 分区过程
    while (i < j) {
        // 在左侧找到大于等于基准值的元素
        while (arr[i] < pivot) {
            i++;
        }
        // 在右侧找到小于等于基准值的元素
        while (arr[j] > pivot) {
            j--;
        }
        // 如果找到的两个元素仍然在基准点的左右两侧，则交换它们
        if (i <= j) {       // 此处需要<=，避免只剩下两个元素的分组进入死循环
            if (i != j) swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // 递归调用对分区后的两个子数组进行排序
    quickSort1(arr, j + 1);
    quickSort1(arr + i, len - i);
}