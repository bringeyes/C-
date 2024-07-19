#include "mycode.h"

void test01() {
	test a1 = { 1,2.2 };
	cout << "a1.a=" << a1.a << ", a1.b=" << a1.b << endl;

	test1 p1 = &a1;
	p1->a = 3; p1->b = 4.4;
	cout << "p1->a=" << p1->a << ", p1->b" << p1->b << endl;
}

void test02(int a, int* b) {
	a++;
	// b++;
	(*b)++;
}
void test03() {
	int a = 1, b = 1;
	cout << "&b=" << &b << endl;
	test02(a, &b);
	cout << "a=" << a << ", b=" << b << ", &b=" << &b << endl;
}