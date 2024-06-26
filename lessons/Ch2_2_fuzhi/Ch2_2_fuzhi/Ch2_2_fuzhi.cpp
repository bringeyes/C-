#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int b = { 20 };     // C++11标准，在Linux平台下，编译需要加-std=c++11参数
    int c{ 3 };
    int d = (40);   // C++标准的初始化赋值
    int e(12);
    b += a;
    c *= a;
    d /= a;
    e %= a;
    cout << "b=" << b << "\nc=" << c 
        << "\nd=" << d << "\ne=" << e << endl; 

    // string只能用=赋值
    // 浮点数不能使用%=
    // =赋值运算符可以连续使用
    a = c = 30;
    /* = 两边操作数的数据类型不同，C++将自动转换数据类型，
        可能损失精度，也可能超出取值范围，如果转换不成功，编译会报错 */

}
