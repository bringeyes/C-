/*
有两个任务:
1) 用一个 while 循环，接受从键盘输入的整数，
    如果输入的整数不在1到100 之间(包括1和100)，认为无效，丢弃;
    如果输入的整数在1到100之间，则把每次输入的值累加起来;
    如果输入的整数为 0，跳出循环。
    最后，显示有效数据的个数和总和。
2) 输出1到100之间(包括1和100)的能整除5的数字。
*/

#include <iostream>
#include <vector>
using namespace std;

void selection_num();

int main()
{
    selection_num();
}

void selection_num() {

    int num, sum = 0;
    vector<int> arr;

    cout << "输入1~100间的数（包含1和100，输入完毕以输入0结束）：";
    while (1) {
        cin >> num;
        if (num >= 1 && num <= 100) {
            sum += num;
            if (num % 5 == 0) arr.push_back(num);
        }
        else if (num == 0) break;
        else {
            cout << "请输入正确的数！";
        }
    }

    cout << "有效数字个数：" << arr.size() 
        << "\t输入数字之和：" << sum << endl;
}
