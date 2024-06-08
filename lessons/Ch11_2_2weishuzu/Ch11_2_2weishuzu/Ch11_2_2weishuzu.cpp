#include <iostream>
using namespace std;

// C风格字符串

int main()
{
    int bh[2][3] = { {1,2,3},{4,5,6} };           // 2行3列二维数组
    // int bh[2][3] = { 1,2,3,4,5,6 };
    // int bh[][3] = { 1,2,3,4,5,6 };           // 编译器根据元素个数和列数，推断出行数
    
    for (int ii = 0; ii < 2; ii++)
    {
        for (int jj = 0; jj < 3; jj++)
        {
            cout << "bh[" << ii << "][" << jj << "]=" << bh[ii][jj] << endl;
        }
    }

    for (int ii = 0; ii < 2; ii++)
    {
        for (int jj = 0; jj < 3; jj++)
        {
            // 地址分配连续
            cout << "&bh[" << ii << "][" << jj << "]=" << (long long) &bh[ii][jj] << endl;
        }
    }

    int* p = (int*)bh;          // 把二维数组当一维数组使用
    for (int ii = 0; ii < 6; ii++)
    {
        cout << "p[" << ii << "]=" << p[ii] << endl;
    }

    // 清空二维数组
    /*memset(bh, 0, sizeof(bh));
    for (int ii = 0; ii < 2; ii++)
    {
        for (int jj = 0; jj < 3; jj++)
        {
            cout << "bh[" << ii << "][" << jj << "]=" << bh[ii][jj] << endl;
        }
    }*/

    // 复制
    int bh1[6] = { 0 };
    memcpy(bh1, bh, sizeof(bh));        // 把二维数组中的值复制到一维数组
                                // 第3个参数用相同大小，只要不越界就行，如可以填入12(字节)，只会复制三个 int 值
    for (int ii = 0; ii < 6; ii++)
    {
        cout << "bh1[" << ii << "]=" << bh1[ii] << endl;
    }

    // 注意
    int a = 8;
    // int b[a];                         // 数组长度不能用变量，但linux可以（这个特点极其重要！）
    int c[sizeof(a) / 2] = { 0 };   // 但可以用 sizeof() 表达式

}