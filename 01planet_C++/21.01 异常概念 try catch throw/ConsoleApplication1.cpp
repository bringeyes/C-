/*
throw 抛出的数据可以有各种类型：int、const char*、enum 等
通过 try{} catch(数据类型 xxx){} 可以捕捉对应类型的出错
可以自定义错误类型，方法：继承exception类，改写what()函数（返回值为const char*）
	通过 catch(exception& e) 捕捉，用 e.what() 显示错误信息
*/

#include <iostream>
#include "mycode1.h"
using namespace std;

int main()
{
	// test01();
	test02();
}