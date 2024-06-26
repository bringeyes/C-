/*
从界面上输入一个整数，把它转换为十进制和二进制的C风格的字符串。
*/

#include <iostream>
using namespace std;

void int2str();

int main()
{
    int2str();
}

// 输入量类型为int
void int2str() {
    int value, ii = 0, radix = 10;
    cout << "请输入一个整数："; cin >> value;
    cout << "请选择（2-二进制；10-十进制）"; cin >> radix; 

    char result[20];    // 存放字符
    memset(result, 0, sizeof(result));

    while (value > 0) {
        result[ii++] = value % radix + '0';        // 将每位数字转换为字符
        value /= radix;
    }
    
    // 逆序排列
    for (int i = 0, len = strlen(result); i < len/2; i++) {
        char tmp = result[i];
        result[i] = result[len - 1 - i];
        result[len - 1 - i] = tmp;
    }

    for (char* ptr = result; *ptr != '\0'; ptr++) {
        cout << *ptr;
    }
}