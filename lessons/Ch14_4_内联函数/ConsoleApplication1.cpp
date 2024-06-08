#include <iostream>
using namespace std;

// 内联函数 inline ，编译的时候代码将嵌入到程序中，节省跳转开销，但消耗内存
// 内联函数的声明和定义一般写在一起
inline void show(const short bh, const string msg) {
    cout << "亲爱的" << bh << "号：" << msg << endl;
}

int main()
{
    show(3, "我是一只傻傻鸟。");
    show(5, "我是一只小小鸟。");
    show(8, "我有一只傻傻鸟。");
    
     
    cout << "";
}

// 内联函数不能递归，因为递归函数消耗的资源非常多，逻辑上也没法递归