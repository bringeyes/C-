#include "ArrayList.h"

Array* initArray() {
	ArrayList* arr = new ArrayList;
	memset(arr, 0, sizeof(ArrayList));		// 初始化元素全0
	arr->maxsize = Max;				// 最大容量可调整
	return arr;
}

bool add(Array* arr, int x) {
	if (arr->size >= arr->maxsize) return false;

	arr->data[arr->size++] = x;		// 0下标开始放数据
	return true;
}

void display(Array* arr) {
	for (int i = 0; i < arr->size; i++) {
		cout << arr->data[i] << ' ';
	}
	cout << endl;
}

bool insert(Array* arr, int k, int x) {
	// 下标不对，或size达到上限，返回false
	if (arr->size >= arr->maxsize || k >= (arr->size - 1) || k < 0) return false;

	// 目标地址，源地址，字节数（内存连续，用memmove）
	memmove(&arr->data[k + 1], &arr->data[k], (arr->size - k) * sizeof(int));
	arr->size++;
	arr->data[k] = x;
	return true;
}

bool del(Array* arr, int x) {
	if (arr->size == 0) return false;	// 空顺序表，不用删

	for (int i = 0; i < arr->size; i++) {
		if (arr->data[i] == x) {
			memmove(&arr->data[i], &arr->data[i + 1], (arr->size - i) * sizeof(int));
			arr->size--;
			return true;
		}
	}
	return false;
}