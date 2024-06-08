#include <iostream>
using namespace std;

void show(short bh, string msg) {
    cout << "short 亲爱的" << bh << "号：" << msg << endl;
}

//void show(double bh, string msg) {
//    cout << "double 亲爱的" << bh << "号：" << msg << endl;
//}

//void show(double& bh, string msg) {
//    cout << "double 亲爱的" << bh << "号：" << msg << endl;
//}
//
//void show(short bh, string msg, string gift = "我要送你一只小小鸟") {
//    cout << "double 亲爱的" << bh << "号：" << msg << gift << endl;
//}

//void show(const short bh, string msg) {
//    cout << "cosnt short 亲爱的" << bh << "号：" << msg << endl;
//}

//int show(short bh, string msg) {
//    cout << "short 亲爱的" << bh << "号：" << msg << endl;
//    return 0
//}     // 返回值类型不能作为函数重载的特征。

int main()
{
    long a = 10;
    string message = "我是一只小小鸟";

    //show(a, message);   // 编译器会尝试使用类型转换与函数匹配，可能造成精度损失
    
    // show(10, message);    // 传引用的不能调用，因为常量不能引用
    
    // show(10, message);   // 如果重载函数有默认参数，调用函数时，可能导致匹配失败。

    // show(10, message);      // const 不能作为函数重载的特征。

    cout << "";
}

//  注意：
//      使用重载函数时，如果数据类型不匹配，C++尝试使用类型转换与形参进行匹配，
//              如果转换后有多个函数能匹配上，编译将报错。
//      引用可以作为函数重载的条件，但是，调用重载函数的时候，如果实参是变量，
//              编译器将形参类型的本身和类型引用视为同一特征。
//      如果重载函数有默认参数，调用函数时，可能导致匹配失败。
//      const 不能作为函数重载的特征。
//      返回值不能作为函数重载的特征。

// C++的名称修饰：编译时，对每个函数名进行加密，替换成不同名的函数。
// 本质上还是不同名的函数，只是程序员看到的是同名