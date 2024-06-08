#include <iostream>

using namespace std;

int main()
{
    int a , b;
    b = a = 2, a * 2;       // 没有赋值，不改变
    b = (a = 2, a * 2);

    cout << "a=" << a
        << "\nb=" << b
        << endl;

    int m, n, k, l;
    m = n = k = 10;     // 赋值运算从右到左
    m = 4, n = 3, k = 2;
    l = m * n / k;          // 算数运算从左到右
    cout << "l=" << l
        << endl;

    // 如果不确定运算符的优先级，可以加括号
    // 多用括号，让代码可读性更好

}
