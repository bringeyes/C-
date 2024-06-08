#include "sortAlgorithm.h"

void countingSort(int arr[], int len, int max, int min) {
    if (len < 2) return;

    int len_c = max - min + 1;
    int* counting = new int[len_c];
    memset(counting, 0, sizeof(int) * len_c);     // ��ʼ������

    for (int i = 0; i < len; i++) {
        counting[arr[i] - min]++;       // ��Ӧλ�ü���+1
    }

    int n = 0;
    for (int j = 0; j < len_c; j++) {
        while (counting[j] > 0) {
            arr[n] = j + min;       // �����Ż�ԭ����
            counting[j]--;           // ����-1
            n++;
        }
    }
}

void quickSort(int arr[], unsigned int len) {
    if (len < 2) return;    // ����Ԫ��<2����������

    int mid = arr[0];       // �����ᣨ��׼����
    int left = 0, right = len - 1;
    int moving = 2;        // ��ǰӦ�ƶ���ָ�룬1-��ָ�룬2-��ָ�룬ȱʡȡֵ2��

    while (left < right) {
        if (moving == 2) {      // �ƶ���ָ��
            if (arr[right] >= mid) { right--; continue; }
            arr[left] = arr[right];
            left++;
            moving = 1;
        }
        else {                          // �ƶ���ָ��
            if (arr[left] < mid) { left++; continue; }
            arr[right] = arr[left];
            right--;
            moving = 2;
        }
    }
    arr[left] = mid;

    quickSort(arr, left);         // ������������
    quickSort(arr + left + 1, len - left - 1);      // ������������
}

void shellSort(int arr[], unsigned int len) {
    if (len < 2) return;

    int gap = len / 2;      // �����ڵ�Ԫ�ؼ��

    while (gap >= 1) {
        for (int i = 0; i < gap; i++) {     // �Ը�����ֱ�����
            for (int j = i + gap; j < len; j += gap) {      // ��ÿ���ڲ����в�������
                int key = arr[j];                 // ������Ԫ��
                int k = j - gap;                  // �����򲿷ֵ�ĩβԪ��λ��
                while (k >= 0 && arr[k] > key) {        // ��ǰ�������ҵ����ʵĲ���λ��
                    arr[k + gap] = arr[k];      // Ԫ�غ���
                    k -= gap;
                }
                arr[k + gap] = key;         // ���뵽��ȷ��λ��
            }
        }

        gap /= 2;
    }
}