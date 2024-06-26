/*
int strcmp(const char *str1, const char *str2 )
功能:比较 str1和str2 的大小。
返回值:相等返回0，str1大于 str2 返回1，str1 小于 str2 返回-1;

int strncmp(const char *str1,const char *str2 ,const size t n)
功能:比较 str1和 str2前n个字符的大小。
返回值:相等返回0，str1大于str2返回1，str1 小于str2 返回-1;
*/

#include <iostream>
using namespace std;

int mystrcmp(const char* str1, const char* str2);

int mystrncmp(const char* str1, const char* str2, const size_t n);

int main()
{
    char str1[] = "abc", str2[] = "abc1";
    cout << mystrcmp(str1, str2) << '\n';
    cout << mystrncmp(str1, str2, 3);
}

int mystrcmp(const char* str1, const char* str2) {
    size_t pos = 0;     // 数组下标

    while (true) {
        if (str1[pos] > str2[pos]) return 1;
        if (str1[pos] < str2[pos]) return -1;
        if (str1[pos] == 0 && str2[pos] == 0) return 0;
        pos++;
    }
}

int mystrncmp(const char* str1, const char* str2, const size_t n) {

    for (size_t pos = 0; pos < n; pos++) {
        if (str1[pos] > str2[pos]) return 1;
        if (str1[pos] < str2[pos]) return -1;
        if (str1[pos] == 0 && str2[pos] == 0) return 0;
    }
    return 0;
}