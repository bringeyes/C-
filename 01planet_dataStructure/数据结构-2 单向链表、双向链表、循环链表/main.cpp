/*
顺序表：	随机存取：直接根据下标找到元素，不灵活
链表：	不支持随机存取，只能通过遍历找数据，非常灵活
os：	磁盘管理：隐式链接管理---基于链表
*/

#include <iostream>

#include "doubly_linkedList.h"
#include "linkedList.h"
#include "circular_linkedList.h"
#include "test.h"
using namespace std;

int main()
{
	// test01();

	// test02_time();
	// test02();
	test03();
}