/*

*/

#include <iostream>
#include <chrono>
using namespace std;

#define MAXSIZE 100     // 顺序表的最大长度
typedef int ElemType;     // 给数据元素的数据类型起个别名

struct SeqList {
    ElemType data[MAXSIZE];          // 静态数组存储顺序表的元素
    size_t length;                  // 有效元素的个数
};

// 清空顺序表
void ClearList(SeqList& LL) {
    // LL.length = 0;              // 表长置为 0 
    // memset(LL.data, 0, sizeof(ElemType) * MAXSIZE);      
    memset(&LL, 0, sizeof(SeqList));        // &LL取地址
}

bool InsertList1(SeqList& LL, size_t pos, const ElemType& ee);
bool InsertList2(SeqList& LL, size_t pos, const ElemType& ee);

size_t FindElem(const SeqList& LL, const ElemType& ee);     // 返回位置

bool DeleteElem(SeqList& LL, size_t pos);

int main()
{
    SeqList L1 = { {0},0 }, L2 = { {0},0 };


    //chrono::steady_clock::time_point start, end;    // start-计时开始，end-计时完成
    //chrono::nanoseconds dt;     // 时间差
    //start = chrono::steady_clock::now();        // 开始计时
    //for (int i = 0; i < 100; i++) {             // 执行一百万次
    //    // 填入要测时的代码
    //    InsertList1(L1, 1, 1);
    //}
    //end = chrono::steady_clock::now();          // 计时完成
    //dt = end - start;                                       // 计算时间差
    //cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间

    //start = chrono::steady_clock::now();        // 开始计时
    //for (int i = 0; i < 100; i++) {             // 执行一百万次
    //    // 填入要测时的代码
    //    InsertList2(L2, 1, 1);
    //}
    //end = chrono::steady_clock::now();          // 计时完成
    //dt = end - start;                                       // 计算时间差
    //cout << "耗时：" << (double)dt.count() / (1000 * 1000 * 1000) << "秒。\n";   // 显示消耗时间



}

// 传入顺序表的引用，pos 插入元素 ee 的位置，数据结构中从 1 开始；返回值 true-成功，false-失败
bool InsertList1(SeqList& LL, size_t pos, const ElemType& ee) {
    if (LL.length == MAXSIZE) { cout << "顺序表已满，不能插入。\n"; return false; }

    if (pos<1 || pos>LL.length + 1) {       // 可在末尾插入
        cout << "插入位置非法，应在 1-" << LL.length + 1 << "之间。\n"; return false;
    }

    if (pos < LL.length + 1)
        memcpy(LL.data + pos, LL.data + pos - 1, (LL.length - pos + 1) * sizeof(ElemType));
        // memcpy(&LL.data[pos], &LL.data[pos - 1], LL.length - pos + 1);

    memcpy(LL.data + pos - 1, &ee, (LL.length - pos + 1) * sizeof(ElemType));       // 采用memcpy是为了兼容ee为结构体的情况
    // LL.data[pos - 1] = ee;

    LL.length++;        // 表长加 1
    return true;
}

// 这种更快
bool InsertList2(SeqList& LL, size_t pos, const ElemType& ee) {
    if (LL.length == MAXSIZE) { cout << "顺序表已满，不能插入。\n"; return false; }

    if (pos<1 || pos>LL.length + 1) {       // 可在末尾插入
        cout << "插入位置非法，应在 1-" << LL.length + 1 << "之间。\n"; return false;
    }

    if (pos < LL.length + 1)
        // memcpy(LL.data + pos, LL.data + pos - 1, MAXSIZE - pos);
        memcpy(&LL.data[pos], &LL.data[pos - 1], (LL.length - pos + 1) * sizeof(ElemType));

    // memcpy(&LL.data[pos - 1], &ee, sizeof(ElemType));       // 采用memcpy是为了兼容ee为结构体的情况
    LL.data[pos - 1] = ee;     // 会快很多

    LL.length++;        // 表长加 1
    return true;
}

size_t FindElem(const SeqList& LL, const ElemType& ee) {
    for (size_t ii = 0; ii < LL.length; ii++) {
        // 如果元素ee为结构体，以下代码要修改（比较数据元素的关键字，来区分不同的元素）
        if (LL.data[ii] == ee) return ii + 1;
    }
    return 0;
}

bool DeleteElem(SeqList& LL, size_t pos) {
    // 检查输入合法性
    if (pos<1 || pos>LL.length) {
        cout << "删除位置非法，应在 1-" << LL.length << "之间。\n"; return false;
    }

    memcpy(&LL.data[pos - 1], &LL.data[pos], (LL.length - pos) * sizeof(ElemType));

    LL.length--;        // 表长加 1
    return true;
}