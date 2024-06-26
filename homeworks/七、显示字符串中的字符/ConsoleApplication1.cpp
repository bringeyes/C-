/*
从界面上输入一个字符串(C风格)，把字符串中的每个字符显示出来，
如果输入的是"abc”，要求:
1) 正序显示:a b c
2) 逆序显示:c b a
求字符串的长度可以利用上一题的成果，也可以直接用strlen()函数，关注性能的细节。“
*/

#include <iostream>
using namespace std;

void display(char* ch);     // 传递字符型数组得用char*，传的是字符型数组名

int main()
{
    char str[10] = "abc";
    display(str);
}

void display(char* ch) {
                                                                                // 假定字符串数组长度100
    /* for (int i = 0; i < strlen(ch); i < len; i++) {          // 循环10000次
        cout << ch[i] << ' ';
    }*/

    // strlen()没必要放在循环条件中，会每次调用
   /* for (int i = 0, len = strlen(ch); i < len; i++) {         // 循环200次，strlen()会循环100次找到长度
        cout << ch[i] << ' ';
    }*/

    // *pos非空
    for (char* pos = ch; *pos; pos++) cout << *pos << " ";      // 循环100次

    for (int i = strlen(ch) - 1; i >= 0; i--) {         // 逆序显示代码只有这一种
        cout << ch[i] << ' ';
}

