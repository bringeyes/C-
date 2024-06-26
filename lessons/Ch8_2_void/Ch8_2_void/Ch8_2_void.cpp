#include <iostream>

using namespace std;

void func(string varname, void* p);

int func1(void);

void cout_turn(string varname, void* p);

int main()
{
    int ax = 11;
    char b = 'a';
    string str = "ax";

    cout << "ax的地址是：" << &ax << endl;
    cout << "b的地址是：" << &b << endl;     // char型变量的地址会输出“烫烫烫烫...”
    cout_turn(str, &ax);
    cout_turn(str = "b", &b);       // 正常输出了

    func(str, &b);
}

void func(string varname, void* p)
{
    // cout << varname << "的值是：" << *p << endl;    // 直接解引用会显示不是完整类型的指针
    cout << varname << "的值是：" << *(char*)p << endl;
    return;
}

int func1(void)     // 参数填void，表示函数不需要参数（或让参数列表空着）
{
    // 函数体代码。
    return 0;
}

// 定义指针类型，是为了知道变量占用内存
// 只关心地址本身，不关心里面的内容，用void* 可以存放任意类型的地址。
void cout_turn(string varname, void* p)     
{
    cout << varname << "的地址是：" << p << endl;
}
