#include <iostream>
using namespace std;

// 生成 len 个不重复的随机整数，取值范围 min ~ max，填充 arr[]
void rrand(int arr[], const size_t len, int max, int min = 0);

int main()
{
	srand(time(0));   // 随机数种子，time(0)当前时间，1970-1-1到现在的秒数，作为随机数种子
	//for (int ii = 0; ii < 100; ii++)
	//    cout << rand()%21 << endl;      // 生成0~20之间的随机数

	int num[20] = { 0 };    // 初始化为全 0
	rrand(num, 20, 20, 1);
	for (int ii = 0; ii < 20; ii++)
		cout << num[ii] << endl;
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