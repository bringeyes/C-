/*

*/

#include <iostream>
#include <chrono>
using namespace std;

// 返回在字符串s中第一次出现c的位置，如果找不到，返回0。
const char* mystrchr(const char* s, int c);

// 返回在字符串s中最后一次出现c的位置，如果找不到，返回0。
const char* mystrrchr1(const char* s, int c);
const char* mystrrchr2(const char* s, int c);

int main()
{
    char str[] = "abcdecb";
    cout << mystrchr(str, 'c') << '\n';

    chrono::steady_clock::time_point start, end;    // start-计时开始，end-计时完成
    chrono::nanoseconds dt;     // 时间差
    start = chrono::steady_clock::now();        // 开始计时
    for (int i = 0; i < 1000000; i++) {             // 执行一百万次
        // 填入要测时的代码
        mystrrchr1(str, 'v');
    }
    end = chrono::steady_clock::now();          // 计时完成
    dt = end - start;                                       // 计算时间差
    cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间
    
    start = chrono::steady_clock::now();        // 开始计时
    for (int i = 0; i < 1000000; i++) {             // 执行一百万次
        // 填入要测时的代码
        mystrrchr2(str, 'v');
    }
    end = chrono::steady_clock::now();          // 计时完成
    dt = end - start;                                       // 计算时间差
    cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

}

const char* mystrchr(const char* s, int c) {
    char* ps = (char*)s;
    while (*ps) {
        if (*ps == c) return ps;
        ps++;
    }
    return 0;   // 0 表示空地址
}

// 当字符靠后时，此方法快，如果字符没有，方法2快
const char* mystrrchr1(const char* s, int c) {
    size_t len = strlen(s);     // 多调用了个strlen()时间复杂度翻倍
    char* ps = (char*)s + len -1;
    for (int ii = 0; ii < len; ii++) {
        if (*ps == c) return ps;
        ps--;
    }
    return 0;   // 0 表示空地址
}

// 还是这种方法好
const char* mystrrchr2(const char* s, int c) {
    char* ps = (char*)s;
    char* p1 = 0;
    while (*ps) {
        if (*ps == c) p1 = ps;      // 如果找到了，更新p1为当前位置
        ps++;
    }
    return p1;   // 0 表示空地址
}