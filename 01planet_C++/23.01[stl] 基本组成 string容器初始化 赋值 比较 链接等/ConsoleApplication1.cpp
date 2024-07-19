/*
STL基本组成
STL从广义上讲分为三类
1.容器(Container)，是一种数据结构，
	如list，vector,和deques，以模板类的方法提供。
	为了访问容器中的数据，可以使用由容器类输出的迭代器;
2.迭代器(lterator)，提供了访问容器中对象的方法。
	例如，可以使用一对迭代器指定list或vector中的一定范围的对象。
	迭代器就如同一个指针。事实上，C++的指针也是一种迭代器。
	但是，迭代器也可以是那些定义了operator*()以及其他类似于指针的操作符地方法的类对象;
3.算法(Algorithm)，是用来操作容器中的数据的模板函数。
	例如，STL用sort()来对一个vector中的数据进行排序，
	用find()来搜索一个list中的对象函数本身与他们操作的数据的结构和类型无关，
	因此他们可以在从简单数组到高度复杂容器的任何数据结构上使用:
*/

#include <iostream>
#include "mycode.h"
using namespace std;

int main()
{
	// test01();
	// test02();
	// test03();
	// test04();
	// test05();
	// test06();
	// test07();
	// test08();
	// test09();
	// test10();
	test11();
}