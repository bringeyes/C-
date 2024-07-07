/*
全局变量初始化=0,
*/

#include <iostream>
using namespace std;

int a;
string b;
double c;
char d;

int main()
{
	int e;
	int& e1 = e;
	cout << a << '|' << b << '|' << c << '|' << d << '|' << e1 << endl;
}