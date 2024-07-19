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
	free(p1);
}

// void test04(int a[][10]) {
void test04(int(*a)[10]) {
	/*
	�����ά����ʱ�������Ǵ�����һά����ĵ�ַ��������int**��������int(*)[10]
	���ǿ�����ʱ�õ��� int** b = (int**)malloc(sizeof(int*) * 100); ģ�⿪��ά����
	����ʹ�� int** ����
	*/
	printf("%d\n", a[0][0]);
}

void test05() {
	/*
	��ά����(>=2)�Զ�ά����Ϊ��:
	����:���ڴ����Դ�ŵģ���ά���鶼��һά���飬����������һά�����У�ÿһ��Ԫ�����ǵ�һά������
	*/
	int arr[10][10] = { 0 };
	test04(arr);
	printf("&arr\t\t%p\t&arr+1\t\t%p\n&arr[0]\t\t%p\t&arr[0]+1\t%p\n&arr[0][0]\t%p\t&arr[0][0]+1\t%p\n", &arr, &arr + 1, &arr[0], &arr[0] + 1, &arr[0][0], &arr[0][0] + 1);
	cout << "arr\t" << arr << "\narr+1\t" << arr + 1 << endl;	// arr �� &arr[0]�ȼ�
	int(*p1)[10][10] = &arr;	// &arr����Ƕ�ά����ĵ�ַ������p1��int(*)[10][10]
	int(*p2)[10] = arr;			// arr �� &arr[0]�ȼۣ������һά����ĵ�ַ�������� == ��һ��Ԫ�ص��ڴ��ַ��������p2��int(*)[10]
	int* p3 = &arr[0][0];		// &arr[0][0]��ŵ���int���͵����ݣ�����p3��int*

	// ģ�������ά����
	int** b = (int**)malloc(sizeof(int*) * 100);
	for (int i = 0; i < 100; i++) {
		b[i] = (int*)malloc(sizeof(int) * 50);
		// ��������Ĳ��Ƕ�ά���飬��Ϊ�������b[i]����������
	}
	// �ͷ�
	for (int i = 0; i < 100; i++) {
		free(b[i]);
	}
	free(b);
}