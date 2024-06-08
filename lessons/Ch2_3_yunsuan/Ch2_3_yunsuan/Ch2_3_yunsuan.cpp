#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int b = 7;
    bool result, result1, result2, result3;

    result = a == b;    // 先比较运算，再赋值
    result1 = a != b;
    result2 = a <= b;
    result3 = a > b;
    cout << "result=" << result 
        << "\nresult1=" << result1 
        << "\nresult2=" << result2
        << "\nresult3=" << result3
        << endl;
    cout << "\nresult=" << (a == b) << '\t' << a + b << endl;    // cout中关系表达式要加()，算数表达式不需要

    string str1 = "PP", str2 = "QQ";
    cout << "\nstr1=str2 ?\t" << (str1 != str2) << endl;

    bool a1 = true;
    bool b1 = false;
    bool c1 = a1 && b1;     // &&逻辑与，都为真才真
                                        // ||逻辑或，都为假才假
                                        // ! 逻辑非(反)
    bool c2;
    cout << "\nc1=" << c1 
        << "\nc2=" << (1 < 2 || b1) // cout中逻辑运算符要加()
        << endl;
}
