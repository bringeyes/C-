/*
从界面上输入一个字符串，如果输入的是"abc"，反转后"cba"。
要求:
1) 反转的结果存放在另一字符串中。
2) 原地反转，不借助其它的字符串。
*/

#include <iostream>
using namespace std;

void strReverse1(char* ch);

void strReverse2(char* ch);

int main()
{
    char str[31] = "abcde";

    strReverse1(str);

    strReverse2(str);
}

void strReverse1(char* ch) {
    char reverse[31];
    memset(reverse, 0, sizeof(reverse));

    int j = 0;      // 反转后字符串的下标
    for (int i = strlen(ch) - 1; i >= 0; i--) {
        reverse[j++] = ch[i];
    }

    cout << reverse << endl;
}

void strReverse2(char* ch) {
    char tmp1;
    int len = strlen(ch);
    for (int i = 0; i < len/2; i++) {       // 需要注意，当字符串只有一个值时，不进入循环
        tmp1 = ch[i];
        ch[i] = ch[len - 1 - i];
        ch[len - 1 - i] = tmp1;
    }

    for (int i = 0; i < len; i++) {
        cout << ch[i] << ' ';
    }
}