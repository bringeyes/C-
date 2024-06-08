/*
有两个任务:
1) 为了支持把C风格的字符串转换成数字，C++提供了以下四个函数:
    int atoi(const char * String);        // 把C风格字符串转换为 int 整数。
    long atol(const char * String);     // 把C风格字符串转换为 long long 整数。
    long long atoll(const char * String);   // 把C风格字符串转换为 long 整数。
    double atof(const char* String);        // 把C风格字符串转换为 double 浮点数。

注意: a) 如果字符串中间有非法字符，后面的内容将丢弃; 
        b) 如果字符串的第一个字符非法，将返回 0.
*/

#include <iostream>
using namespace std;

int c2int(char* ch, int radix);

int main()
{
    //cout << atoi("12345") << endl;
    //cout << atoi("12a45") << endl;
    //cout << atoi("123456789123") << endl;   // 出错，超过了int范围
    //cout << atoll("123456789123") << endl;

    char str[30] = "10010";
    cout << c2int(str, 2);
}

int c2int(char* ch, int radix) {     // 传入C风格字符串和进制基数，转换为十进制int
    int result = 0;
    for (int i = 0, len = strlen(ch); i < len; i++) {
        if (ch[i] < '0' || ch[i]>'9') { cout << "字符串非法（包含非数字字符）。\n"; break; }
        if (radix == 2 && ch[i] > '1') { cout << "字符串非法（只能是0和1）。\n"; break; }
        result *= radix;
        result += ch[i] - '0';
    }
    return result;
}