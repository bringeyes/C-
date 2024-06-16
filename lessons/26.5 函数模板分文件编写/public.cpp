#include "public.h"

void Swap(int a, int b)		// 普通函数
{
	cout << "使用了普通函数 Swap(int a, int b)\n";
}

template <>					// 具体化的函数模版
void Swap(int a, int b) {
	cout << "使用了具体化的函数模版 Swap(int a, int b)\n";
}