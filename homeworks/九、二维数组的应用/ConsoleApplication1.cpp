/*
有两个任务:
1) 超女有3个小组，每组有4名选手，请提供一个界面，输入每个超女的体重，
    然后，计算出每组的超女的平均体重和全部超女的平均体重。
2) 从界面上输出三个超女的姓名，存放在C风格的字符串数组中，然后，分别向她们表白。“
*/

#include <iostream>
using namespace std;

void average_weight(double w[][4]);

int main()
{
    double weight[3][4];
    memset(weight, 0, sizeof(weight));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "输入第" << i + 1 << "组第" << j + 1 << "个超女的体重：";
            cin >> weight[i][j];
        }
    }
    
    average_weight(weight);
    
}

void average_weight(double w[][4]) {
    double total = 0;   // 全部总体重

    for (int i = 0; i < 3; i++) {
        double sum = 0;     // 小组总体重
        for (int j = 0; j < 4; j++) {
            sum += w[i][j];
        }
        cout << "第" << i + 1 << "组的总体重为：" << sum << endl;
        
        total += sum;
    }
    cout << "超女的总体重为：" << total << endl;
}