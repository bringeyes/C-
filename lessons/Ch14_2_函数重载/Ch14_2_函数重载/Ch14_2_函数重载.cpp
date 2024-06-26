#include <iostream>
using namespace std;

void myswap(int& a, int& b) {
    int tmp = a; a = b; b = tmp;
}

void myswap(string& a, string& b) {     // 交换两个字符串变量的值
    string tmp = a; a = b; b = tmp;
}

int main()
{
    int a = 3, b = 5;
    myswap(a, b);
    cout << "a=" << a << ", b=" << b << endl;

    string c = "略略略", d = "啦啦啦";
    myswap(c, d);
    cout << "c=" << c << ", d=" << d << endl;

}

// 函数重载，函数名相同，特征不同。完成相似任务