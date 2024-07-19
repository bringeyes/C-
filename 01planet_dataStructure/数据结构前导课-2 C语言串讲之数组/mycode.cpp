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
	free(p1);
}

// void test04(int a[][10]) {
void test04(int(*a)[10]) {
	/*
	传入二维数组时，本质是传的是一维数组的地址，不能用int**，而是用int(*)[10]
	除非开数组时用的是 int** b = (int**)malloc(sizeof(int*) * 100); 模拟开二维数组
	才能使用 int** 传参
	*/
	printf("%d\n", a[0][0]);
}

void test05() {
	/*
	多维数组(>=2)以二维数组为例:
	本质:在内存线性存放的，多维数组都是一维数组，在这个特殊的一维数组中，每一个元素又是低一维的数组
	*/
	int arr[10][10] = { 0 };
	test04(arr);
	printf("&arr\t\t%p\t&arr+1\t\t%p\n&arr[0]\t\t%p\t&arr[0]+1\t%p\n&arr[0][0]\t%p\t&arr[0][0]+1\t%p\n", &arr, &arr + 1, &arr[0], &arr[0] + 1, &arr[0][0], &arr[0][0] + 1);
	cout << "arr\t" << arr << "\narr+1\t" << arr + 1 << endl;	// arr 与 &arr[0]等价
	int(*p1)[10][10] = &arr;	// &arr存的是二维数组的地址，所以p1是int(*)[10][10]
	int(*p2)[10] = arr;			// arr 与 &arr[0]等价，存的是一维数组的地址（数组名 == 第一个元素的内存地址），所以p2是int(*)[10]
	int* p3 = &arr[0][0];		// &arr[0][0]存放的是int类型的数据，所以p3是int*

	// 模拟申请二维数组
	int** b = (int**)malloc(sizeof(int*) * 100);
	for (int i = 0; i < 100; i++) {
		b[i] = (int*)malloc(sizeof(int) * 50);
		// 这样申请的不是二维数组，因为逐个申请b[i]不是连续的
	}
	// 释放
	for (int i = 0; i < 100; i++) {
		free(b[i]);
	}
	free(b);
}