/*
char *strstr(const char* str,const char* substr);
返回子串 substr 在目标串 str 中第一次出现的位置，如果找不到，返回 0。

BF 算法，即暴力(Brute Force)算法。
KMP 算法是一种改进的字符串匹配算法，由D.E.Knuth，1.H.Morris和V.R.Pratt 提出(简称 KMP算法)。“
*/

#include <iostream>
#include <chrono>
using namespace std;

const char* mystrstr1(const char* str, const char* substr);
const char* mystrstr2(const char* str, const char* substr);

int main()
{
    char str1[] = "abccde", str2[] = "cd";

    const char* a = mystrstr1(str1, str2);


}

//const char* mystrstr1(const char* str, const char* substr) {
//    char* psub = (char*)substr;
//    char* p = (char*)str;
//    char* tmp1 = (char*)strchr(str, *psub);      // 找到在str中第一次出现substr[0]的位置
//
//    while (tmp1) {
//        char* tmp2 = tmp1;      // 用tmp2来代替tmp1操作
//        
//        while (*psub) {
//            if (*tmp2 == *psub) { tmp2++; psub++; continue; }       // 如果值相同，继续遍历
//            else {
//                psub = (char*)substr;
//                tmp1 = strchr(tmp1 + 1, *psub);
//                break;                                          // 值不同则跳出，寻找下一个和substr首字符相同的位置
//            }
//        }
//
//        if (*psub == 0) return tmp1;    // 如果完整遍历，返回tmp1
//    }
//    return 0;      // 找不到返回0
//}


// 这种效率更高
const char* mystrstr2(const char* str, const char* substr) {
    size_t ii = 0, jj = 0;          // 目标串和子串的数组下标，都从0开始
    size_t len = strlen(str), slen = strlen(substr);

    while (ii < len && jj < slen) {
        if (str[ii] == substr[jj]) {
            ii++; jj++;
        }
        else {
            ii -= jj-1;    // 目标串数组下标回退 jj-1，准备重来
            jj = 0;         // 子串数组下标回退到0，准备重来
        }
    }

    if (jj == slen) return str + (ii-jj);       // 如果循环终止时，jj==slen，表示查找成功

    return 0;       // 查找失败
}