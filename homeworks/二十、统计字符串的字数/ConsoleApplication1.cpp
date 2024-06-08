/*

*/

#include <iostream>
#include <chrono>
using namespace std;

// ASCII码取值范围 0~127
// 汉字用扩展ASCII码表示，取值范围 128~255，常用汉字以双字节为主，不常用有3或4字节（甲骨文、战国时期文字、不同版本繁体字）
// 用 (unsigned int) 显示汉字ASCII码
int sumwords(const char* str);

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

    cout << sumwords("我爱zd真的佩佩123abc");
}

int sumwords(const char* str) {
    char* p = (char*)str;
    int sum = 0;
    int sumHanzi = 0;

    while (*p) {
        if ((unsigned char)*p < 128) sum++;
        else sumHanzi++;
        p++;
    }

    return sum + sumHanzi / 2;
}