#include "sortAlgorithm.h"

void countingSort(int arr[], int len, int max, int min) {
    if (len < 2) return;

    int len_c = max - min + 1;
    int* counting = new int[len_c];
    memset(counting, 0, sizeof(int) * len_c);     // 初始化置零

    for (int i = 0; i < len; i++) {
        counting[arr[i] - min]++;       // 对应位置计数+1
    }

    int n = 0;
    for (int j = 0; j < len_c; j++) {
        while (counting[j] > 0) {
            arr[n] = j + min;       // 把数放回原数组
            counting[j]--;           // 计数-1
            n++;
        }
    }
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