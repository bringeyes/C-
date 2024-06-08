#include <iostream>

using namespace std;

int main()
{
    int age;
    cout << "请输入PP年龄：" << endl;
    cin >> age;

    switch (age)           // 只能是int或char
    {
    case 22:                // 表达式中不能使用变量
        cout << "就是现在！" << endl;
                                // case中不用加{}
        break;              // 不break会执行之后的全部代码
    case 23: 
        cout << "已经25年了吗？" << endl;
        break;
    default:
        cout << "原来PP这么大啦~" << endl;
    }
}
