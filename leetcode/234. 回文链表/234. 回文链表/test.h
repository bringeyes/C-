#pragma once
#include <iostream>
#include "solution.h"
using namespace std;

// 测试自己的方法
void test01();

// 测试官方方法：先复制到数组，然后用双指针法比较值
void test02();

// 测试官方方法：递归，设定一个前向的指针
// 当下一个递归返回true且当前结点值和前向指针的值相等时返回true，否则false
// 递归终止条件：当前结点为空节点，返回true
void test03();

// 测试官方方法
void test04();