#include <iostream>

using namespace std;

int main()
{
    double a = 1.2;
    int b = -3.6;     // int除数不能为0，否则严重错误，int向0取整（舍弃小数部分）
    int c = 1.2;
    cout << a/b << '\n' << c/ (float)b << endl;  // (float)会把c和b都转换为浮点数计算

    cout << c % b << endl;  // 取模运算%只能针对int，求余数，取模分母也不能为0
    // 赋值的时候保证等式两边类型相同

    int i = 10;
    int j = 10;
    int i1 = i++;       // 先执行，再+1
    int j1 = ++j;       // 先+1，再执行
    cout << "i=" << i << '\n' << "i1=" << i1 << endl;
    cout << "j=" << j << '\n' << "j1=" << j1 << endl;
    cout << "j=" << ++ j << '\n' << "j1=" << ++j1 << endl;
    // --和++同理
}
