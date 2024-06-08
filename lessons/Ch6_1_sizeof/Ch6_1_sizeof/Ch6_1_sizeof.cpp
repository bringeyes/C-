#include <iostream>

using namespace std;

int main()
{
    cout << "sizeof(int)=" << sizeof(int) << endl;      // 占用字节数
    cout << "sizeof(float)=" << sizeof(float) << endl;
    cout << "sizeof(double)=" << sizeof(double) << endl;
    cout << "sizeof(char)=" << sizeof(char) << endl;
    cout << "sizeof(bool)=" << sizeof(bool) << endl;
    // cout << "sizeof(string)=" << sizeof(string) << endl;    // 本质是C++的类，40字节没有意义

    // 还可以输出变量，可省略()
    // 实际开发更倾向于加()
    // 32位操作系统的值可能不同，单片机开发
    int i; cout << "sizeof(i)=" << sizeof(i) << endl;
    bool j; cout << "sizeof j=" << sizeof j << endl;

    int a = 0b101, b = 0B10001, c = -0b1100101;     // 2进制0b开头
    int d = 01734;      // 8进制0开头
    int e = 0x21d, f = 0X3f;        // 16进制0x开头
    cout << "a=" << a << endl;  // 输出为10进制

    // 整型修饰符
    // signed有符号的；unsigned无符号的
    // short短的，long长的
    cout << "sizeof(short)=" << sizeof(short) << endl;      // 一个字节有8位，short是2字节，最大2^16-1
    cout << "sizeof(long)=" << sizeof(long) << endl;        //4字节
    cout << "sizeof(unsigned)=" << sizeof(unsigned) << endl;    // 4字节
    cout << "sizeof(unsigned short)=" << sizeof(unsigned short) << endl;    // 2字节
    cout << "sizeof(unsigned long)=" << sizeof(unsigned long) << endl;
    cout << "sizeof(long long)=" << sizeof(long long) << endl;  // 8字节

    cout << "\nsizeof(float)=" << sizeof(float) << endl;  // 4字节
    cout << "sizeof(double)=" << sizeof(double) << endl;  // 8字节
    cout << "sizeof(long double)=" << sizeof(long double) << endl;  // 8字节，linux平台16字节

    // float 7位有效数字；double 15~16位有效数字；long double 不低于double
    float aa = 123456789.123456789f; cout << "\naa=" << aa << endl;  // 科学计数法。。
    // 最多显示小数点后6位？
    double bb = 123456789123456789.123456789; cout << "bb=" << bb << endl;
    long double cc = 123456789123456789.123456789;
    printf("aa=%lf\n", aa);     // 使用C中的方法显示全部位数
    printf("bb=%lf\n", bb);
    printf("cc=%lf\n", cc);
    // 浮点数存储方法和整数不一样，如无必要无需研究。
    // 实际开发中用整数代替浮点数，整数运算更快，精度更高
    
    cout << "\nsizeof(char)=" << sizeof(char) << endl;  // 本质是整数，ASCII码
    char a1 = 88;
    int a2 = 'X';
    cout << "\na1=" << a1 << endl;          // 运行显示X
    cout << "a1=" << (int)a1 << endl;       // 运行显示88
    cout << "a2=" << a2 << endl;
    cout << "a2=" << (char)a2 << endl;      // 运行显示X
    // char可以参与整数运算：'x'+3
    // 0是NULL空字符；10是换行键；13回车键

    // 转译
    // \0空字符；\n换行；\r回车
    // \t 水平制表（跳到下一个TAB）
    // \\   \'  \"  用于在字符串中表示

    // 原始字面量
    R"abc(字符串里包含\)abc";     // abc是标签，要成对出现

    string str = "<no>001\
        <name>PP\
        <weight>55\
        <age>22";               // 用 \ 连接多行字符串，但距离隔得很远
    cout << str << endl;

    string str1 = R"(           // 用 原始字面量 表示，换行对齐
        <no>001
        <name>PP
        <weight>55
        <age>22)";               
    cout << str1 << endl;
}  
 