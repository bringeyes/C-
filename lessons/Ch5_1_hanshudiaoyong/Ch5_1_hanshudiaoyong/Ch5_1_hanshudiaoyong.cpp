#include "tools.h"
#include "human.h"

using namespace std;

int f(int x);

int main()
{
    cout << "max(5, 8)=" << max(5, 8) << endl;
    cout << "min(5, 8)=" << min(5, 8) << endl;
    func(22, "PP");
    cout << "f(100)=" << f(100) << endl;
}

// 头文件（*.h）：需要包含的头文件，指定命名空间，声明全局变量，函数的声明，数据结构和类的声明等。
// 源文件（*.cpp）：函数的定义、类的定义。
// F5调试程序至断点，F10执行下一行，F11进入函数内部
// 调试过程可以拖动箭头跳过执行一些代码
// F11进入函数内部后可以修改局部变量的值（非常棒！）

int f(int x)
{
    if (x == 0) return 0;   // 递归终止条件

    return x + f(x - 1);    // 在函数体中调用自己
}
 