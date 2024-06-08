#include <iostream>
using namespace std;

int main()
{
    int bh[5] = { 3, 4, 1, };     // 元素少于数组长度时，编译器会用0填充
    int bh2[] = { 3, 4, 1, 7,9 };     // 第二种初始化方法，自动按元素个数判断数组长度
    string name[3];

    for (int ii = 0; ii < 5; ii++)
    {
        cout << "bh[" << ii << "]=" << bh[ii] << endl;
    }
  
    memset(bh, 0, sizeof(bh));      // 使用 memset 初始化
    for (int ii = 0; ii < 5; ii++)
    {
        cout << "bh[" << ii << "]=" << bh[ii] << endl;
    }

    memcpy(bh2, bh, sizeof(bh));        // 保持复制和被复制的两个数组长度一致
    for (int ii = 0; ii < sizeof(bh2)/4; ii++)
    {
        cout << "bh2[" << ii << "]=" << bh2[ii] << endl;
    }
}
