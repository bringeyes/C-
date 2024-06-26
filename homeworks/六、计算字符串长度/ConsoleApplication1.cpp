/*
从界面上输入一个字符串(C风格)，计算字符串的长度。
如果输入的是“abcde"，显示的结果是 5
其它要求:
1) 把计算字符串长度的功能封装成一个函数。
2) 采用 for 循环，用数组表示法和临时变量计数。
3) 采用 while 循环，用指针表示法和临时变量计数。
4) 不用临时变量计数，用递归实现(奇巧淫技)
*/

#include <iostream>
#include <chrono>
using namespace std;

// 功能与 strlen() 相同
// int char_len(char* ch);

int char_len(char ch[]);

int main()
{
    char ch[20] = "abcde";      // 或用memset(ch, 0, sizeof(ch)) 初始化
    char* p = ch;
    cout << char_len(p) << endl;
}

// 采用 for 循环，用数组表示法和临时变量计数。
//int char_len(char* ch) {
//    int len = 0;
//    for (len = 0; ch[len] != 0; len++) {}
//    return len;
//}

// 采用 while 循环，用指针表示法和临时变量计数。
int char_len(char ch[]) {
    int len = 0;
    char* p = ch;
    while (*p++)  len++;
    //while (*p) {   // 可以优化，*p 有内容就是true
    //    len++;
    //    p++;
    //}

    return len;
}

//// 不用临时变量计数，用递归实现（奇巧淫技）
//int char_len(char* str) {
//    if (*str == 0) return 0;    // 递归终止的条件。
//
//    str++;              // 后移一个字符。
//
//    int len = char_len(str) + 1;    // 递归调用自己，递归每增加一层，字符串长度加1。
//
//    return len;
//}
