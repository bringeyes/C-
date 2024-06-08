#include <iostream>

using namespace std;

int main()
{
    int age;
    cout << "输入PP年龄：" << endl;
    cin >> age;
    
    if (age < 30)       // {}可以省略，前提是得有代码执行
                              // 如果省略了，只会执行之后的一条语句
    {
        cout << "PP还很年轻！" << endl;
    }
    else if (age < 50) cout << "PP也还很年轻！！" << endl;     // 多条件语句最多127条分支
    else cout << "PP在我心里永远年轻！！！" << endl;

    if ((age < 60)  &&
        (age < 40)  &&
        (age < 30))             // 多个表达式这样写
    {
        cout << "PP还很年轻！" << endl;
    }
}
 