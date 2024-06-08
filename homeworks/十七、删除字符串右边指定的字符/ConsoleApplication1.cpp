/*

*/

#include <iostream>
#include <chrono>
using namespace std;

// 删除最右侧的所有cc字符
void deleterchr(char* str, const int cc = ' ');

int main()
{
    //chrono::steady_clock::time_point start, end;    // start-计时开始，end-计时完成
    //chrono::nanoseconds dt;     // 时间差
    //start = chrono::steady_clock::now();        // 开始计时
    //for (int i = 0; i < 1000000; i++) {             // 执行一百万次
    //    // 填入要测时的代码

    //}
    //end = chrono::steady_clock::now();          // 计时完成
    //dt = end - start;                                       // 计算时间差
    //cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    char str1[] = "abc de   ";
    cout << '=' << str1 << "=\n";
    deleterchr(str1);
    cout << '=' << str1 << "=\n";       // 注意不要用'=\n'
}

void deleterchr(char* str, const int cc) {      // 默认实参只能被定义一次，放在声明中
    if (str == 0) return;       // 如果传进来的是空地址，直接返回，防止程序崩溃

    char* p = str;          // 指向字符串首地址
    char* piscc = 0;    // 右侧全是字符cc的第一个位置

    while (*p) {   // p遍历str
        if (*p == cc && piscc == 0) piscc = p;      // 记下字符cc的第一个位置
        if (*p != cc) piscc = 0;     // 如果遍历到非cc字符，piscc置0
        p++;
    }

    if (piscc != 0) *piscc = 0;
}