/*
一副牌有 54 张，除掉大小王，还有 52 张，用 1-52 之间的数字表示，把它随机发给 4个玩家。
函数原型:
arr:每个玩家的牌面，第一维的大小是 4。
void dealcards(int arr[][13]);
要求:为了达到更好的随机效果，不能把洗好的牌按顺序发给玩家，要随机发放。
*/

#include <iostream>
using namespace std;

// 生成 len 个不重复的随机整数，取值范围 min ~ max，填充 arr[]
void rrand(int arr[], const size_t len, int max, int min = 0);

void dealcards(int arr[][13]);
void dealcards1(int arr[][13]);

int main()
{
    srand(time(0));   // 随机数种子，time(0)当前时间，1970-1-1到现在的秒数，作为随机数种子
    int arr1[4][13] = { 0 }, arr2[4][13] = { 0 };
    dealcards(arr1);
    cout << endl;
    dealcards1(arr2);
}

void rrand(int arr[], const size_t len, int max, int min) {
    if (len > (max - min + 1) || len == 0) return;       // 合法性检查

    int tmp, count = 0, jj = 0;
    while (count < len) {                        // 达到 len 跳出循环
        tmp = rand() % (max - min + 1) + min;          // 范围内的随机数
        for (jj = 0; jj < count; jj++) {        // 如果完整遍历，jj = count
            if (tmp == arr[jj]) break;
        }
        if (jj == count) {          // 包含 jj = 0 的情况
            arr[jj] = tmp;
            count++;
        }
    }
}

void dealcards(int arr[][13]) {
    int list[52] = { 0 };
    rrand(list, 52, 52, 1);
    for (int ii = 0; ii < 4; ii++) {
        for (int jj = 0; jj < 13; jj++) {
            arr[ii][jj] = list[13 * ii + jj];
            cout << arr[ii][jj] << ' ';
        }
        cout << endl;
    }
}

// 随机发放，在随机排序的基础上，依次随机抽取
void dealcards1(int arr[][13]) {
    int list[52] = { 0 }, deal[52] = { 0 };
    rrand(list, 52, 52, 1); rrand(deal, 52, 51, 0);

    for (int jj = 0; jj < 13; jj++) {
        for (int ii = 0; ii < 4; ii++) {
            arr[ii][jj] = list[deal[13 * ii + jj]];
        }

        for (int ii = 0; ii < 4; ii++) {
            for (int jj = 0; jj < 13; jj++) {
                cout << arr[ii][jj] << ' ';
            }
            cout << endl;
        }
    }
}