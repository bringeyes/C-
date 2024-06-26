/*
字符串复制或赋值 strcpy()
char *strcpy(char* dest, const char* src);
功 能:    将参数 src 字符串拷贝至参数 dest 所指的地址。
返回值:    返回参数 dest 的字符串起始地址。
复制完字符串后，会在 dest后追加 0。
如果参数 dest 所指的内存空间不够大，会导致数组的越界。

字符串复制或赋值 strncpy()
char* strncpy(char* dest, const char* src, const size_t n);
功能:把 src前n个字符的内容复制到dest中。
返回值: dest 字符串起始地址。
如果 src 字符串长度小于 n，则拷贝完字符串后，在 dest后追加 0，直到n个。
如果 src 的长度大于等于 n，就截取 src 的前n个字符，不会在 dest 后追加 0。
如果参数 dest 所指的内存空间不够大，会导致数组的越界。
*/

#define _CRT_SECURE_NO_WARNINGS // 使用C风格字符串操作的函数需要定义这个宏
#include <iostream>
#include <chrono>       // 时间操作库的头文件
using namespace std;

char* mystrcpy1(char* dest, const char* src);
char* mystrcpy2(char* dest, const char* src);
char* mystrcpy3(char* dest, const char* src);

char* mystrncpy(char* dest, const char* src, const size_t n);

int main()
{
    chrono::steady_clock::time_point start, end;    // start-计时开始，end-计时完成
    chrono::nanoseconds dt;     // 时间差

    char str[30] = "abcde", ptr[20];
    memset(ptr, 0, sizeof(ptr));

    start = chrono::steady_clock::now();        // 开始计时
    for (int i = 0; i < 1000000; i++) {
        mystrcpy1(ptr, str);
    }
    end = chrono::steady_clock::now();          // 计时完成
    dt = end - start;                                       // 计算时间差
    cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    start = chrono::steady_clock::now();        // 开始计时
    for (int i = 0; i < 1000000; i++) {
        mystrcpy2(ptr, str);
    }
    end = chrono::steady_clock::now();          // 计时完成
    dt = end - start;                                       // 计算时间差
    cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    start = chrono::steady_clock::now();        // 开始计时
    for (int i = 0; i < 1000000; i++) {
        mystrcpy3(ptr, str);
    }
    end = chrono::steady_clock::now();          // 计时完成
    dt = end - start;                                       // 计算时间差
    cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    cout << ptr;        // C风格字符串可以直接打印

    mystrncpy(ptr, str, 3);
    cout << ptr;
}

// 采用数组表示法
char* mystrcpy1(char* dest, const char* src) {
    int ii = 0, jj = 0;     // 目标字符串和源字符串的下标计数器
    while (src[jj]) {
        dest[ii++] = src[jj++];
    }
    dest[ii] = 0;
    return dest;
}

// 采用指针表示法，效率次高
char* mystrcpy2(char* dest, const char* src) {
    char* psrc = (char*)src;    // 指向源字符串，需要强制转换
    char* pdest = dest;         // 指向目标字符串，避免修改dest值
    while (*psrc) {
        *pdest++ = *psrc++;
    }
    *pdest = 0;
    return dest;
}

// 使用memcpy，效率最高
char* mystrcpy3(char* dest, const char* src) {
    memcpy(dest, src, strlen(src) + 1);     // 把结束标志也复制进去
    return dest;
}

char* mystrncpy(char* dest, const char* src, const size_t n) {      // 
    char* psrc = (char*)src;    // 指向源字符串，需要强制转换
    char* pdest = dest;         // 指向目标字符串，避免修改dest值
    int ii = 0;
    while (*psrc && ii++ < n) {
        *pdest++ = *psrc++;
    }
    *pdest = 0;

    return dest;
}