/*
字符串拼接 strcat()
char *strcat(char* dest,const char* src)
功能：将src 字符串拼接到 dest 所指的字符串尾部。
返回值：返回 dest 字符串起始地址。
dest 最后原有的结尾字符0会被覆盖掉，并在连接后的字符串的尾部再增加一个0。
如果参数 dest 所指的内存空间不够大，会导致数组的越界。

字符串拼接 strncat()
char *strncat (char* dest,const char* src, const size t n);
功能：将src 字符串的前n个字符拼接到 dest所指的字符串尾部。
返回值：返回 dest 字符串的起始地址。
如果n大于等于字符串 src的长度，那么将 src 全部追加到 dest的尾部，
如果n小于字符串 src 的长度，只追加src的前n个字符。
strncat 会将 dest 字符串最后的0覆盖掉，字符追加完成后，再追加0。
如果参数 dest 所指的内存空间不够大，会导致数组的越界。
*/

#include <iostream>
#include <chrono>
using namespace std;

char* mystrcat(char* dest, const char* src);
char* mystrncat(char* dest, const char* src, const size_t n);

int main()
{
    // char* p = (char*)"abc";
    // char p[15]; strcpy_s(p, "abc");
    char p[10] = "abc";
    cout << "p=" << p << '\n';
    cout << mystrcat(p, "123") << '\n';
    cout << mystrncat(p, "321", 2) << '\n';
}

char* mystrcat(char* dest, const char* src) {
    memcpy(dest + strlen(dest), src, strlen(src) + 1);      // char只占用1字节，+1保证'\0'也被复制
    return dest;
}

char* mystrncat(char* dest, const char* src, const size_t n) {
    size_t len = strlen(dest);
    memcpy(dest + len, src, n);
    *(dest + len + n) = 0;          // 单独添加休止符
    return dest;
}