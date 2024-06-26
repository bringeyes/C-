#include <iostream>
using namespace std;

int main()
{
    enum colors { red = 0, yellow = 1, blue = 2, other = 3 };   // 创建枚举类型colors，包含4个整型常量
    // enum colors { red, yellow, blue, other };    // 会从0开始，默认0,1,2,3
    enum colors2 { red, yellow = 8, blue };      // 将为0,8,9
    enum colors3 { red = 10, yellow, blue };    // 将为10,11,12
    colors cc = red;        // 创建枚举变量，初始化，只能说枚举中的值
    // colors cc = 0；   会报错，只能用常量名
    colors cc = colors(1);      // 将整数强制转换为枚举量，语法：枚举类型(整数)

    switch (cc)     // cc是整型，可以用于创建switch语句
    {
        case red:         cout << "红色。\n"; break;
        case yellow:    cout << "黄色。\n"; break;
        case blue:       cout << "蓝色。\n"; break;
        default:           cout << "未知。\n"; 
    }
}
