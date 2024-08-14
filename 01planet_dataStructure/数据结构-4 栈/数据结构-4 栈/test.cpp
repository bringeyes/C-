#include "test.h"

void test01() {
	SStack s1 = initSStack();
	for (int i = 0; i < 3; i++) {
		push(s1, i);
		cout << getTop(s1) << endl;
	}
	for (int i = 0; i < 4; i++) {
		pop(s1);
		cout << getTop(s1) << endl;
	}
}

void test02() {
	CStack c1 = initCStack();
	for (int i = 0; i < 3; i++) {
		push(c1, i);
		cout << getTop(c1) << endl;
	}
	for (int i = 0; i < 4; i++) {
		pop(c1);
		cout << getTop(c1) << endl;
	}
}