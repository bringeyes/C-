/*
二、根据数字判断月份
    在界面上输入数字的月份(1-12)，输出对应月份的英文单词的全称，
如果输入的数字不合法，给出提示。
其它要求:
1)用if.. else if..实现;
2)用switch 实现;
3)用字符串数组(C风格和C++风格)实现。
示例(if实现):
*/

#include <iostream>
using namespace std;

void judge_month1();    // 用 switch 语句实现
void judge_month2();    // 用 if ... else if ... 语句实现
void judge_month3();    // 用 字符串数组 实现

// 效率最高：
void judge_month3();    // 用 C++风格字符串数组实现
void judge_month4();    // 用 C风格字符串数组实现

int main()
{
    //judge_month1();     
    
    //judge_month2();
    
    judge_month3();
}

void judge_month1() {
    int month;

    while (true) {
        cout << "请输入数字月份（1~12）："; cin >> month;
        if (month < 1 || month>12) cout << "你输入的不是正确的月份（1~12）";
        else break;
    }

    switch (month) {
    case 1: cout << "January"; break;
    case 2: cout << "February"; break;
    case 3: cout << "March"; break;
    case 4: cout << "April"; break;
    case 5: cout << "May"; break;
    case 6: cout << "June"; break;
    case 7: cout << "July"; break;
    case 8: cout << "August"; break;
    case 9: cout << "September"; break;
    case 10: cout << "October"; break;
    case 11: cout << "November"; break;
    case 12: cout << "December"; break;
    default: cout << "输入的月份不正确（1~12）！";
    }
}

void judge_month2() {
    int month;
    cout << "请输入数字月份（1~12）："; cin >> month;

    if (month == 1) cout << "January";
    else if (month == 2) cout << "February";
    else if (month == 3) cout << "March";
    else if (month == 4) cout << "April";
    else if (month == 5) cout << "May";
    else if (month == 6) cout << "June";
    else if (month == 7) cout << "July";
    else if (month == 8) cout << "August";
    else if (month == 9) cout << "September";
    else if (month == 10) cout << "October";
    else if (month == 11) cout << "November";
    else if (month == 12) cout << "December";
    else cout << "输入的月份不正确（1~12）！";
}

void judge_month3() {
    int month;
    string month_word[12] = { "January" ,"February","March","April","May" ,"June",
                    "July","August","September","October","November" ,"December" };
    
    while (true) {
        cout << "请输入数字月份（1~12）："; cin >> month;
        if (month < 1 || month>12) cout << "你输入的不是正确的月份（1~12）";
        else break;
    }

    cout << month_word[month - 1];
}

void judge_month4() {
    int month;
    char month_word[12][10] = { "January" ,"February","March","April","May" ,"June",
                    "July","August","September","October","November" ,"December" };

    while (true) {
        cout << "请输入数字月份（1~12）："; cin >> month;
        if (month < 1 || month>12) cout << "你输入的不是正确的月份（1~12）";
        else break;
    }

    cout << month_word[month - 1];
}