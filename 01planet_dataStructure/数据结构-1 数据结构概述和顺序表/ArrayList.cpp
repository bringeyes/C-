#include "ArrayList.h"

Array* initArray() {
	ArrayList* arr = new ArrayList;
	memset(arr, 0, sizeof(ArrayList));		// ��ʼ��Ԫ��ȫ0
	arr->maxsize = Max;				// ��������ɵ���
	return arr;
}

bool add(Array* arr, int x) {
	if (arr->size >= arr->maxsize) return false;

	arr->data[arr->size++] = x;		// 0�±꿪ʼ������
	return true;
}

void display(Array* arr) {
	for (int i = 0; i < arr->size; i++) {
		cout << arr->data[i] << ' ';
	}
	cout << endl;
}

bool insert(Array* arr, int k, int x) {
	// �±겻�ԣ���size�ﵽ���ޣ�����false
	if (arr->size >= arr->maxsize || k >= (arr->size - 1) || k < 0) return false;

	// Ŀ���ַ��Դ��ַ���ֽ������ڴ���������memmove��
	memmove(&arr->data[k + 1], &arr->data[k], (arr->size - k) * sizeof(int));
	arr->size++;
	arr->data[k] = x;
	return true;
}

bool del(Array* arr, int x) {
	if (arr->size == 0) return false;	// ��˳�������ɾ

	for (int i = 0; i < arr->size; i++) {
		if (arr->data[i] == x) {
			memmove(&arr->data[i], &arr->data[i + 1], (arr->size - i) * sizeof(int));
			arr->size--;
			return true;
		}
	}
	return false;
}