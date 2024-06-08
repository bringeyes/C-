#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// C风格字符串

int main()
{
    string str = "XYZ";
    cout << "str[0]=" << (int)str[0] << endl;   // 转换为ASCII码
    cout << "str[1]=" << (int)str[1] << endl;
    cout << "str[2]=" << (int)str[2] << endl;
    cout << "str[3]=" << (int)str[3] << endl;   // 最后一个是0，空字符
    //  因为字符串需要用0结尾，所以在声明字符数组的时候，要预留多一个字节用来存放0。

    char name[21] = { 0 };  // 声明一个最多存放20个英文字符或10个中文字符的字符串
    // 未初始化的字符串危害极大！
    cout << "name=" << name << endl;    // 输出乱码，因为C/C++字符串以0结束，哪怕超出范围也会继续寻找

    // 清空字符串
    memset(name, 0, sizeof(name));      // 把全部元素置为0
    // name[0]=0;       // 不规范，有隐患，不推荐
    cout << "name=" << name << endl;

    // 赋值
    strcpy(name, "hello");      // (char* dest, const char* src)形参表
    //  功 能 :   将参数 src 字符串拷贝至参数 dest 所指的地址。
    //  返回值 : 返回参数 dest 的字符串起始地址。
    //  复制完字符串后，会在 dest 后追加 0。
    //  如果参数 dest 所指的内存空间不够大，会导致数组的越界。

    cout << "name=" << name << endl;
    cout << "name[0]=" << (int)name[0] << endl;
    cout << "name[1]=" << (int)name[1] << endl;
    cout << "name[2]=" << (int)name[2] << endl;
    cout << "name[3]=" << (int)name[3] << endl;
    cout << "name[4]=" << (int)name[4] << endl;     // 前几个ASCII码显示正确
    cout << "name[5]=" << (int)name[5] << endl;     // 后边为0
    cout << "name[6]=" << (int)name[6] << endl;
    cout << "name[7]=" << (int)name[7] << endl;
}

//  初始化字符串的方法：
    // char name[11];                        // 可以存放 10 个字符，没有初始化，里面是垃圾值。
    //        char name[11] = "hello";          // 初始内容为 hello，系统会自动添加 0。
    //        char namel[]    = {"hello"};           // 初始内容为 helo，系统会自动添加 0,数组长度是 6。
    //        char name[11] = { "hello" };      // 初始内容为 hello，系统会自动添加 0。
    //        char name[11]{ "hello" };          // 初始内容为 hello，系统会自动添加 0。C++11 标准。
    // char name[11] = { 0 };              // 把全部的元素初始化为 0。
    // 最常用的是第一种和最后一种


