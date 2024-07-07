/*
条件编译作用
1.屏蔽跨平台差异
在大规模开发过程中，特别是跨平台和系统的软件里，可以在编译时通过条件编译设置编译环境。
2.包含程序功能模块
可以使用 #ifdef实现包含程序的不同的功能模块,
3.开关调试信息
调试程序时，常常希望输出一些所需的信息以便追踪程序的运行。而在调试完成后不再输出这些信息，可以通过条件编译控制。
4.防止头文件重复包含
头文件(.h)可以被头文件或 CPP 文件包含。由于头文件包含可以嵌套，CPP 文件就有可能多次包含同一个头文件;或者不同的 CPP 文件都包含同一个头文件,编译时就可能出现重复包含(重复定义)的问题。
*/

#include <iostream>
using namespace std;

#define PRINT
#define com 0
#define ARRSIZE(arr) (sizeof(arr)/sizeof(arr[0]))		// 数组总元素个数
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int main()
{
	//	cout << "测试条件编译1\n";
	//#ifdef PRINT
	//	cout << "PRINT has defined" << endl;
	//#else
	//	cout << "PRINT not define" << endl;
	//#endif // PRINT
	//
	//	cout << "测试条件编译2\n";
	//#if com
	//	cout << "Start compile" << endl;
	//#elif 1
	//	cout << "2222" << endl;
	//#else
	//	cout << "else" << endl;
	//#endif

//	cout << "测试条件编译3\n";
//#error compile error here!

	//int arr1[10];
	//cout << ARRSIZE(arr1) << endl;

	int a = 1, b = 3;
	cout << MAX(a + 3, b) << endl;
}