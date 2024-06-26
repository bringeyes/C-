/*

*/

#include <iostream>
using namespace std;

class CGirl {
public:
    string name;        // 姓名
    int age;                // 年龄
    void setvalue(string name1, int age1);
    void show() {
        cout << "姓名：" << name << "，年龄：" << age << endl;
    }
};

void CGirl::setvalue(string name1, int age1) {
    name = name1; age = age1;
}

int main()
{
    CGirl girl1;
    girl1.setvalue("西施", 26);
    girl1.show();
}

// 类的成员可以是变量，也可以是函数。
// 类的成员变量也叫属性。
// 类的成员函数也叫方法 / 行为，类的成员函数可以定义在类的外面。
// 用类定义一个类的变量叫做创建(或实例化)一个对象。
// 类的成员变量和成员函数的作用域和生命周期与对象的作用域和生命周期相同。