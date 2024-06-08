/*

*/

#include <iostream>
#include <chrono>
using namespace std;

void deletelchr(char* str, const int cc = ' ');

int main()
{
    char str1[] = "aaaabcde";
    deletelchr(str1, 'a');
    cout << '=' << str1 << '=';
}

void deletelchr(char* str, const int cc) {
    if (str == 0) return;

    char* p = str;
    char* pissc = 0;    // 第一次遇到非cc字符的位置

    while (*p==cc) p++;

    // memcpy()没有考虑内存重叠的情况，如果内存重叠，其行为不确定
    memmove(str, p, sizeof(str) - (p - str) + 1);    // +1把结尾标志0也拷过来
}