#include <iostream>

using namespace std;

int main()
{
    // 语法：表达式一 ? 表达式二 : 表达式三
    // 先计算表达式一的值，如果真，结果为表达式二的值
    // 否则为表达式三的值
    int a = 7, b = 5, c = 0;
    c = a > b ? a : b;
    
    cout << "c=" << c << endl;

    // 可以嵌套使用
    int d;
    c = 11;
    d = (a > b ? a : b) > c ? (a > b ? a : b) : c;
    cout << "d=" << d << endl;
}
