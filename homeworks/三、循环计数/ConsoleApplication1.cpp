/*
有两个任务:
1) 采用一个 while 循环，把1到 100 之间的数值累加起来。
2) 采用一个 for 循环，把用户每次从键盘输入的数值累加起来，
        如果总和超过了 5000，循环结束。
*/

#include <iostream>
using namespace std;

int count_sum1();   // 使用 while 求和
int count_sum2();   // 使用 for 求和

int main()
{
    count_sum1();
    
    count_sum2();
    
}

int count_sum1() {
    int ii = 1, sum = 0;
    while (ii < 101) {
        sum += ii++;
    }
    cout << sum << "\n";
    return sum;
}

int count_sum2() {
    int sum = 0, n;
    cout << "请输入求和尾值："; cin >> n;
    for (int ii = 1; ii <= n; ii++) {
        sum += ii;
    }
    cout << sum;
    return sum;
}
