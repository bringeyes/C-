#include "mycode.h"

void test01() {
	int a = 256;
	func(&a);
	printf("%p\t%p\n", a, &a);		// ֱ�Ӵ�a���������������Ϊ����a��һ����ַ

	int arr[3] = { 0 };
	printf("arr\t%p\tarr+1\t%p\n&arr\t%p\t&arr+1\t%p\narr[0]\t%p\t&arr[0]\t%p\n", arr, arr + 1, &arr, &arr + 1, arr[0], &arr[0]);
	cout << "arr[0]=" << arr[0] << endl;
}

void test02() {
	int arr[3] = { 0 };
	int(*p)[3] = &arr;		// ռ���ڴ�8B��(*p)����һ��ָ��p��int []����ָ���������
	// p=arr;		// �������÷��Ǵ���ģ�arr��int *���ͣ�ָ���һ��Ԫ�صĵ�ַ

	int* q[3];		// ָ�����飬���3�� int*��ռ���ڴ�3*8B������[]����������q������int* ����q�д�ŵ���������
	// ��������ȼ���[] > *
}

void test03() {
	int n = 3;
	int* p1 = (int*)malloc(sizeof(int) * n);
	// int *p1 = new int[n];
	for (int i = 0; i < 3; i++) { p1[i] = i * 10; cout << p1[i] << endl; }
}