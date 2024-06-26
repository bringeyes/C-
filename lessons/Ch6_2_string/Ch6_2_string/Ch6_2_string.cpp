#include <iostream>

using namespace std;

int main()
{
    string message = "消息发送中...";     // string类
    string str = "111\n"
        "222\n"
        "333";
    cout << message + "发送成功" << endl;
    cout << str << endl;

    // bool类型的本质是unsigned char，
    // 把里面的数据强制为8
    bool b = false;
    char* c = (char*)&b; 
    *c = 255;   // 256，b为0
    cout << "b=" << b << endl;

    // 数据类型的转换
    char a1 = 30;
    int b1 = 2000;
    long long c1 = 12000000000;

    // 较低类型自动向较高类型转换，longlong容量最大精度最高
    cout << "a1+b1+c1=" << a1 + b1 + c1 << endl;

    // 含有浮点型操作数时，所以操作数转换为浮点型
    cout << "8/5=" << 8.0/5 << endl;

    // 赋值运算不一致时，右值降低为左值类型
    int a2 = 23.44;     // 23

    // 赋值运算，右值超出左值的表示范围，会把右值截断后赋值
    unsigned int e = 4294967295;    // 无符号整型的最大值
    cout << "e=" << e << endl;
    cout << "e+1=" << e+1 << endl;

    // 强制类型转换   (数据类型)表达式
    // 使用强制转换编译器将不警告 
}
