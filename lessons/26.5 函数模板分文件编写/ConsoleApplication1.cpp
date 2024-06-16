/*

*/

#include <iostream>
#include "public.h"
using namespace std;

int main()
{
	Swap(1, 3);		// 将使用普通函数
	Swap('c', 'd');	// 将使用函数模板
	Swap<>(1, 3);	// 将使用具体化的函数模板
}

/*
函数模板只是函数的描述，没有实体，创建函数模板的代码放在头文件中。

函数模板的具体化有实体，编译的原理和普通函数一样，
	所以，声明放在头文件中，定义放在源文件中。
*/