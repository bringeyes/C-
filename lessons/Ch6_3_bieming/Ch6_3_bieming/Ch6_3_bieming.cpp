#include <iostream>

using namespace std;

int main()
{
    typedef unsigned int uint;
    typedef long long llong;
    typedef unsigned long long ullong;

    uint a = 122;
    llong b = 1354635;
    ullong c = 832472368;

    cout << "sizeof(a)=" << sizeof(a)
        << "\nsizeof(b)=" << sizeof(b)
        << "\nsizeof(c)=" << sizeof(c);

    // 在VS中，short是2字节，int是4字节，long也是4字节，long long 8字节
    typedef short                 int16_t;    // 16位的整数
    typedef int                     int32_t;    // 32位的整数
    typedef long long          int64_t;    // 64位的整数
    // 在Linux中，short 2字节，int 4字节，long 8字节，long long 8字节
    // 在程序源代码中，只使用别名int16_t、int32_t、int64_t，不使用原名
    // 这些别名一般放在头文件。
}
