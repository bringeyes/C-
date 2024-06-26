/*

*/

#include <iostream>
#include <chrono>
#include "linkList.h"
#include "sortAlgorithm.h"
using namespace std;

// 展示数组
void desplay(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

// 生成一个长度为len的取值范围min~max的元素可重复随机数组
int* generateRandomArray(int len, int min, int max);

// 桶排序，参数：arr-待排序数组的首地址，len-数组元素个数，bucketnum-桶的个数
void bucketSort(int arr[], int len, int bucketnum);

int main()
{
    int len = 200;
    int* cpy = generateRandomArray(len, 1, len);
    int* arr = new int[len];
    cout << "待排序数组：" << endl;
    desplay(cpy, len);

   // // 使用第二种方法，不使用动态分配创建链表头结点
   // LNode La; La.next = nullptr;
   // LNode Lb; Lb.next = nullptr;
   // LNode Lc; Lc.next = nullptr;
   // for (int ii = 0; ii < len; ii++) {
   //     PushOrder(&La, cpy[ii]);
   //     PushOrder(&Lb, cpy1[ii]);
   // }
   // MergeList(&La, &Lb, &Lc);
   // PrintList(&Lc);
   // DestroyList(Lc.next);       // 不能直接传入Lc的地址，因为它不是通过动态分配的方式创建的
   ///* cout << Lc.next << endl;*/    // 销毁后，Lc.next=nullptr

    // 使用桶排序
    bucketSort(cpy, len, 3);
    desplay(cpy, len);

    chrono::steady_clock::time_point start, end;    // start-计时开始，end-计时完成
    chrono::nanoseconds dt;     // 时间差

    // -----------------------------------------------------------
    // 希尔排序
    cout << "希尔排序：" << endl;

    start = chrono::steady_clock::now();        // 开始计时
    for (int i = 0; i < 100000; i++) {             // 执行十万次
        // 填入要测时的代码
        copy(cpy, cpy + len, arr);
        shellSort(arr, len);
    }
    end = chrono::steady_clock::now();          // 计时完成
    dt = end - start;                                       // 计算时间差
    cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    desplay(arr, len);
    cout << endl;

    // -----------------------------------------------------------
    // 桶排序
    cout << "桶排序：" << endl;

    start = chrono::steady_clock::now();        // 开始计时
    for (int i = 0; i < 100000; i++) {             // 执行十万次
        // 填入要测时的代码
        copy(cpy, cpy + len, arr);
        bucketSort(arr, len, 3);
    }
    end = chrono::steady_clock::now();          // 计时完成
    dt = end - start;                                       // 计算时间差
    cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    desplay(arr, len);
    cout << endl;

    // -----------------------------------------------------------
    delete[] cpy;
    delete[] arr;

    // 感悟：使用链表进行数据迁移很方便，只需要改变指针指向就行，相比之下数组就麻烦许多；
    //      但是使用链表的桶排序会慢很多(10倍不止) 因为动态分配、初始化头结点、有序插入元素、
    //      归并链表，都会大量耗时；其次，桶的性能高度依赖数据的分布，如果某些桶元素很多，会导致
    //      单个桶内排序时间增加。
}

int* generateRandomArray(int len, int min, int max) {
    int* arr = new int[len]; // 创建动态数组来存储随机数组

    // 使用当前时间作为随机数种子
    srand(time(nullptr));

    // 生成随机数组
    for (int i = 0; i < len; ++i) {
        arr[i] = min + rand() % (max - min + 1); // 生成 min 到 max 之间的随机数
    }

    return arr; // 返回随机数组的指针
}

void bucketSort(int arr[], int len, int bucketnum) {
    // 分配桶头结点的结构体数组
    LNode* buckets = new LNode[bucketnum];

    // 初始化桶，把头结点的next指针置空
    for (int ii = 0; ii < bucketnum; ii++)
        buckets[ii].next = nullptr;

    // 把数组arr的全部元素放入桶中
    for (int ii = 0; ii < len; ii++) 
        PushOrder(&buckets[arr[ii] % bucketnum], arr[ii]);      // 以取余的方式把arr中的元素划分到桶中
    
    //// 显示每个桶中的元素
    //cout << "每个桶中的元素如下：" << endl;
    //for (int ii = 0; ii < bucketnum; ii++) PrintList(&buckets[ii]);

    // 把全部桶中的元素归并到LL中
    LNode LL; LL.next = nullptr;
    LNode tmp; tmp.next = nullptr;

    for (int ii = 0; ii < bucketnum - 1; ii++) {
        MergeList(&buckets[ii], &buckets[ii + 1], &tmp);        // 按顺序归并到tmp中
        swap(tmp.next, buckets[ii + 1].next);         // 交换tmp与下一次要归并的桶的数据结点
    }

    LL.next = buckets[bucketnum - 1].next;        // 把最终归并结果交给LL

    // 把LL中的数据还回数组arr
    LNode* pp = LL.next;
    for (int ii = 0; ii < len; ii++) {
        arr[ii] = pp->data;
        pp = pp->next;
    }

    DestroyList(LL.next);         // 释放LL
    //PrintList(&LL);
    delete[] buckets;               // 释放桶的结构体数组（头结点们）
}