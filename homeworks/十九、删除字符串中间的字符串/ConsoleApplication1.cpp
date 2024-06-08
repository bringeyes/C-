/*

*/
#define _CRT_SECURE_NO_WARNINGS     // 使用C风格字符串操作的函数需要定义此宏
#include <iostream>
#include <chrono>
using namespace std;

// aaxyxyzzaa   aaxyzaa     aaaa    可能存在嵌套出现，使用while删除
void deletestr(char* str, const char* substr);

int main()
{
    chrono::steady_clock::time_point start, end;    // start-计时开始，end-计时完成
    chrono::nanoseconds dt;     // 时间差
    start = chrono::steady_clock::now();        // 开始计时
    for (int i = 0; i < 1000000; i++) {             // 执行一百万次
        // 填入要测时的代码

    }
    end = chrono::steady_clock::now();          // 计时完成
    dt = end - start;                                       // 计算时间差
    cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    // a b x x  y z z c  x y  z   d   \0
    // 0 1 2 3 4 5 6 7 8 9 10 11 12
    // len = 12; p - str = 3; lensub = 3; memmove(p, p + lensub, len - (p - str) - lensub+1);
    char str1[] = { "abxxyzyzcxyzd" };
    deletestr(str1, "xyz");
    cout << '=' << str1 << '=';
}

void deletestr(char* str, const char* substr) {
    if (str == 0 || substr == 0) return;

    char* p = strstr(str, substr);       // 用 strstr() 在目标串中查找子串

    size_t len = strlen(str);
    size_t lensub = strlen(substr);

    if (lensub == 0) return;        // 子串内容不能为空，否则死循环，无意义

    while (p) {         // 如果找到子串
        memmove(p, p + lensub, len - (p - str) - lensub + 1);   // 从目标串中删除子串
        p = strstr(str, substr);        // 继续查找子串
    }
}