#include <iostream>
using namespace std;

void func(const string& msg = "我喜欢你！");     // 只能在函数的声明中写默认参数
    
int main()
{
    func();



    cout << "";
}

void func(const string& msg) {      // 定义中不要写默认参数
    cout << "亲爱的：" << msg << endl;
}

// 注意:
//      如果函数的声明和定义是分开书写的，在函数声明中书写默认参数，
//              函数的定义中不能书写默认参数。
//      函数必须从右向左设置默认参数。也就是说，如果要为某个参数设置默认值，
//              则必须为它右边所有的参数提供默认值。
//      调用函数的时候，如果指定了某个参数的值，那么该参数前面所有的参数都必须指定。



