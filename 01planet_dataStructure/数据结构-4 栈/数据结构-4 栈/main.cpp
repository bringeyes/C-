﻿/*
栈---线性逻辑结构
顺序栈--->数组
链栈--->链表

栈的本质：限制在一端进行操作的线性表（“堆栈”）
栈顶、栈底、空栈

物理中的堆栈：在CPU中一块专门区域就是堆栈

操作：增删查，不存在改（只能进出入栈，不能对栈内元素操作）
栈顶用“指针”标记位置，栈底a[0]

空栈要么a[0]，要么a[-1]，前者满栈指针指向最上面元素的更上方位置，后者满栈指针指向最上面元素
*/

#include <iostream>
#include "test.h"
using namespace std;

int main()
{
	// test01();
	test02();
}