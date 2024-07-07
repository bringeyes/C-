/*
指针的用处：
1. 数据共享，空间中的值不影响地址
2. 方便操作，例如申请内存，需要指针
3. 搞一些复杂的数据结构，例如链表

int a[3] 中的a 相当于 保存了第一个元素内存地址的指针，是一个指针常量
*/

#include <iostream>
#include "mycode.h"
using namespace std;

int main()
{
	// test01();
	// test02();
	test03();
}