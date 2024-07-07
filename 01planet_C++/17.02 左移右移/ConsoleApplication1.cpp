/*
a << 100 比 a * 2^100 快得多
*/

#include <iostream>
#include <bitset>
using namespace std;

void printBinary(unsigned int n) {
	std::bitset<8> binary(n);
	std::cout << binary << std::endl;
}

void swap(int& a, int& b) {
	a ^= b;
	b ^= a;
	a ^= b;
	cout << "a=" << a << "，b=" << b << endl;
}

int main()
{
	//int a = 11 >> 1;	// a=5，就是N/2向下取整
	//int b = -11;	printBinary(b);	// 1111 0101
	//b >>= 1;		printBinary(b);	// 1111 1010	补码：取反+1
	//cout << a << '\t' << b << endl;

	int a = 2, b = 3;
	swap(a, b);
}