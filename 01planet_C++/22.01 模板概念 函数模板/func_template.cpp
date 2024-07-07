#include "func_template.h"

void test01() {
	// 咨塀糞箭晒
	cout << add(3.2, 1) << endl;

	cout << "！！！！！！！！！！！！！！" << endl;
	int x = 1;
	double y = 2.3;
	cout << add(x, y) << endl;
}

void test02() {
	int a1 = 2, a2 = 5;
	exchange(a1, a2);
	cout << "a1=" << a1 << ", a2=" << a2 << endl;

	cout << "！！！！！！！！！！！！！！" << endl;
	double b1 = 2.3, b2 = 5.1;
	exchange(b1, b2);
	cout << "b1=" << b1 << ", b2=" << b2 << endl;

	cout << "！！！！！！！！！！！！！！" << endl;
	string c1 = "ABC", c2 = "abcd";
	exchange(c1, c2);
	cout << "c1=" << c1 << ", c2=" << c2 << endl;

	cout << "！！！！！！！！！！！！！！" << endl;
	const char* d1 = "DEF", * d2 = "01planet";
	exchange(d1, d2);	// 住算議凪糞頁曾倖峺寞
	cout << "d1=" << d1 << ", d2=" << d2 << endl;
}