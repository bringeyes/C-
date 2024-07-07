/*

*/

#include <iostream>
using namespace std;

#define PI 3.14
#define INC(x) x++
// #define SQR(n) n*n		// 只做表达式的拼接 10 + 10 * 10 + 10
#define SQR(n) (n)*(n)	// 所有参数使用()改变优先级
#define DIGIT(c) ((c)>='0'&&(c)<='9')
#define ADD(a,b) (a)+(b)

int main()
{
	//double r;		// 圆的半径
	//cin >> r;
	//cout << PI * r * r;		// 输出面积

	//int num = 100;
	//INC(num);
	//cout << num << endl;

	//int num = 10; ;
	//cout << SQR(num) << endl;
	//int r2 = SQR(5 + 5);
	//cout << r2 << endl;

	//char ch1 = 'a';
	//cout << DIGIT(ch1) << endl;		// 返回0
	////#undef DIGIT		// 使用后再用DIGTI 编译报错
	//char ch2 = '8';
	//cout << DIGIT(ch2) << endl;		// 返回1

	int a1 = 10, a2 = 20;
	cout << ADD(a1, a2) << endl;
}