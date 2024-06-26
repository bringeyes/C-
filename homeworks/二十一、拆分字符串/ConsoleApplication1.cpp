/*
字符串 "aa,bb,cc,dd"，中间用逗号分隔，把它拆分到字符串维数组中，
拆分后有4个数据项，分别"aa"、"bb"、"cc"、"dd"
函数原型:
// str:目标串，需要拆分的字符串。
// splitstr:数据项的分隔字符串。
// values:一个字符串数组，用于存放拆分后的数据项。
// 返回拆分后数据项的个数。
size t splitstr(const char* str, const char* splitstr, char values[[51]);

// 注意：数据项=分隔符个数+1
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
using namespace std;

size_t splitstr(const char* str, const char* splitstr, char values[][51]);

int main()
{
    //chrono::steady_clock::time_point start, end;    // start-计时开始，end-计时完成
    //chrono::nanoseconds dt;     // 时间差
    //start = chrono::steady_clock::now();        // 开始计时
    //for (int i = 0; i < 1000000; i++) {             // 执行一百万次
    //    // 填入要测时的代码

    //}
    //end = chrono::steady_clock::now();          // 计时完成
    //dt = end - start;                                       // 计算时间差
    //cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    char values[20][51] = { 0 };
    size_t numSplit = splitstr("aa,bb,cc,dd", ",", values);

    for (int ii = 0; ii < numSplit; ii++) {
        cout << "values[" << ii << "]=" << values[ii] << endl;
    }
}

// char values[][51] 或 char (*values)[51]
size_t splitstr(const char* str, const char* splitstr, char values[][51]) {
    if (str == 0 || splitstr == 0) return 0;

    char* p = (char*)str;            // 找到分隔符位置
    char* cpy = (char*)str;         // 需要存放的数据项首地址

    size_t i = 0;                          // 拆分后有效数据项的个数
    size_t lensplit = strlen(splitstr);

    if (lensplit == 0) return 0;    // 如果分隔符内容为空，无意义

    while (p) {
        p = strstr(cpy, splitstr);                  // 找到下一个分隔符

        if (p != 0) {
            strncpy(values[i++], cpy, p - cpy);     // 把分隔符之前的内容放到数据项中
            cpy = p + lensplit;                             // 更新数据项首地址
        }
        else strcpy(values[i++], cpy);        // 没找到分隔符，说明是最后一个数据项
    }

    return i;
}