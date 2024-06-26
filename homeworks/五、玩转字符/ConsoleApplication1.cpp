/*
有三个任务:
1) 从界面上输入一个字母，显示该字母后面的字母，如果后面没有字母，给出提示。
2) 自定义一个函数，把字符的"0'~'9'转换为整数的 0~9。
    不允许用 if...else if...和switch语句。
函数原型:
int ctoi(const char ch); // ch 为字符'0'、'1'、'2'、….9'，返回值为整数 0、1、2、..9。
调用示例:
*/

#include <iostream>
using namespace std;

// 字符'0'~'9'到数字0~9的转换
int ctoi(const char ch);

// 加_避免和自带的函数重载
int _isalpha(int ch);   // 若ch是字母('A'-'Z', 'a'-'z")返回非0，否则返回0

int _isalnum(int ch);    // 若ch是字母('A'-'Z'，a'-'z')或数字('0'-'9')，返回非0，否则返回0.int .isdigit(int ch);// 若ch是数字('0'-'9')返回非0，否则返回0

int _islower(int ch);   // 若ch是小写字母('a'-'z')返回非0，否则返回0

int _isupper(int ch);   // 若ch是大写字母('A'-'Z')返回非0，否则返回0

int tolower(int ch);    // 若ch是大写字母('A'-'Z')，则返回它的小写字母('a'-'z')

int toupper(int ch);    // 若ch是小写字母('a'-'z')，则返回它的大写字母('A'-'Z’)。

// ASCII：大写字母 65~90 和小写字母 97~122 之间差了 32

int main()
{
    int ch = 'x';
    cout << _isalpha(ch) << endl;

    cout << _isalnum(ch) << endl;

    cout << _islower(ch) << endl;

    cout << _isupper(ch) << endl;

    cout << (char)tolower(ch) << endl;

    cout << (char)toupper(ch) << endl;
}

int ctoi(const char ch) {
    int num;
    if (ch >= '0' && ch <= '9') return num = ch - '0';
    else {
        cout << "请输入数字0~9！" << endl;
        return 0;
    }
}

int _isalpha(int ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) return ch;
    else return 0;
}

int _isalnum(int ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') 
        || (ch >= '0' && ch <= '9')) return ch;
    else return 0;
}

int _islower(int ch) {
    if (ch >= 'a' && ch <= 'z') return ch;
    else return 0;
}

int _isupper(int ch) {
    if (ch >= 'A' && ch <= 'Z') return ch;
    else return 0;
}

int tolower(int ch) {
    if (ch >= 'A' && ch <= 'Z') return ch + 32;
    else return ch;
}

int toupper(int ch) {
    if (ch >= 'a' && ch <= 'z') return ch - 32;
    else return ch;
}