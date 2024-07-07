/*
& 按位与
按位与 主要用途
	1.清零
	如果想将一个单元清零，即使其全部二进制位为0，只要与一个各位都为零的数值相与，结果为零。
	2.取一个数的指定位
	比如取数 X=1010 1110 的低4位，只需要个数Y，令Y的低4位为1，其余位为0书即Y=0000 1111，然后将x与Y进行按位与《算X&Y=0000 1110)即可得到X的指定位，
	3.判断奇偶
	只要根据最未位是0还是1来决定，为0就是偶数，为1就是奇数。因此可以用if((a&1)== 0)代替if(a%2== 0)来判断a是不是偶数。

| 按位或
按位或 主要用途
	常用来对一个数据的某些位设置为1
	比如将数 X=1010 1110 的低4位设置为1,只需要另找一个数Y，令Y的低4位为1，其余位为0即Y=0000 1111，然后将x与Y进行按位或运算(X|Y=1010 1111)即可得到。

^ 按位异或
相同为0，不同为1
按位异或 主要用途
	1.翻转指定位
	比如将数 X=1010 1110 的低4位进行翻转，只需要与 Y=0000 1111 进行异或(X^Y=1010 0001)
	2.与0相异或值不变
	例如:1010 1110^0000 0000=1010 1110
	3.交换两个数
	a^=b;b^=a;a^=b;

~ 按位取反

<< 左移

>> 右移
*/

#include <iostream>
#include <bitset>
using namespace std;

bool ifOdd(int num) {
	if ((num & 1) == 1) { cout << "奇数" << endl; return true; }
	else { cout << "偶数" << endl; return false; }
}

void printBinary(unsigned int n) {
	std::bitset<8> binary(n);
	std::cout << binary << std::endl;
}

int main()
{
	int a = 11;
	a = a & ~1;		// 使一个数的最低位为0
	ifOdd(a);

	printBinary(a);			// 0000 1010
	int b = 3;				// 0000 0011
	printBinary(b);
	printBinary(a ^= b);	// 0000 1001
	printBinary(b ^= a);	// 0000 1010	换为a
	/*
	b = b ^ (a ^ b)
	  = (b ^ b) ^ a
	  = 0 ^ a
	  = a
	*/
	printBinary(a ^= b);	// 0000 0011	换为b
	/*
	a = (a ^ b) ^ a
	  = (a ^ a) ^ b
	  = 0 ^ b
	  = b
	*/
}