#include "test.h"

void test04() {
	int arr1[5] = { 1,5,7,3,3 };
	cout << getMax<int>(arr1, 5) << endl;
	cout << getMin<int>(arr1, 5) << endl;
	cout << getMean<int>(arr1, 5) << endl;
}