#include "class_template.h"

void test03() {
	Pair<int> a1(1, 2);		// 使用的时候要指定参数类型
	a1.show();

	cout << "——————————————" << endl;
	Pair<double> a2(1.1, 2.2);		// 使用的时候要指定参数类型
	a2.setData(3.3, 4.4);
	a2.show();

	cout << "——————————————" << endl;
	t1 b1(3, 4);			// typedef Pair<int> t1;
	b1.show();

	cout << "——————————————" << endl;
	t2<double> b2(3.2, 2.1);		// template<class T> using t2 = Pair<T>;
	b2.show();
}