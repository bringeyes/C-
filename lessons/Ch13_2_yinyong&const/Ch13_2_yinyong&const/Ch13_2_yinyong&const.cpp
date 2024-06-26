#include <iostream>
using namespace std;

void func1(int no, string message) {
    cout << "亲爱的" << no << "号：" << message << endl;
}

void func2(int* no, string* message) {
    cout << "亲爱的" << *no << "号：" << *message << endl;
}

void func3(const int& no, const string& message) {
    cout << "亲爱的" << no << "号：" << message << endl;
}

int main()
{
    // 如果引用的数据对象类型不匹配，当引用为 const时，
    // C++将创建临时变量，让引用指向临时变量
     
    const int& ra = 8;    // 引用常量，C++会创建临时变量，让引用指向临时变量
        // int tmp = 8;
        // const int& ra = tmp;     // 相当于这两行代码

    // 加上const修饰形参，func3就可以直接传入常量了！！
    func3(8, "我是一只傻傻鸟。");   // C风格字符串，有const修饰，也会正确转换为string

}

// 将引用形参声明为 const 的理由有三个:
//      1. 使用 const 可以避免无意中修改数据的编程错误。
//      2. 使用 const 使函数能够处理 const 和非 const 实参，否则将只能接受非 const 实参。
//      3. 使用 const，函数能正确生成并使用临时变量。

// func2没有这种待遇，因为会变为 const int* p 常量指针，指向常量，可修改指向位置

// 左值是可以被引用的数据对象，可以通过地址访问它们，
//      例如：变量、数组元素、结构体成员、引用和解引用的指针。
// 
// 非左值包括字面常量(用双引号包含的字符串除外)和包含多项的表达式。
//                                  因为字符串常量有地址