#include "mycode.h"

void test01() {
	int a = 256;
	func(&a);
	printf("%p\t%p\n", a, &a);		// 直接传a，编译器错误地认为整数a是一个地址

	int arr[3] = { 0 };
	printf("arr\t%p\tarr+1\t%p\n&arr\t%p\t&arr+1\t%p\narr[0]\t%p\t&arr[0]\t%p\n", arr, arr + 1, &arr, &arr + 1, arr[0], &arr[0]);
	cout << "arr[0]=" << arr[0] << endl;
}

void test02() {
	int arr[3] = { 0 };
	int(*p)[3] = &arr;		// 占用内存8B。(*p)声明一个指针p，int []表明指向的是数组
	// p=arr;		// 这样的用法是错误的，arr是int *类型，指向第一个元素的地址

	int* q[3];		// 指针数组，存放3个 int*，占用内存3*8B。先用[]声明了数组q，再用int* 声明q中存放的数据类型
	// 运算符优先级：[] > *
}

void test03() {
	int n = 3;
	int* p1 = (int*)malloc(sizeof(int) * n);
	// int *p1 = new int[n];
	for (int i = 0; i < 3; i++) { p1[i] = i * 10; cout << p1[i] << endl; }
}