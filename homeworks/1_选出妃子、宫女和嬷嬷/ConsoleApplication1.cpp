/*
一、选出妃子、宫女和嬷嬷
在界面上输入超女数据后，按下列要求选出妃子、宫女和嬷嬷。
妃子: 1)年龄18-25岁; 2)身高165-178cm;  3)身材火辣;                   4)颜值漂亮。
宫女: 1)年龄18-30岁; 2)身高160-165cm;  3)身材火辣或者普通;       4)颜值漂亮。
嬷嬷: 1)年龄35-40岁; 2)身高155-165cm;  3)身材普通或者飞机场;    4)颜值一般。
其它要求:
1) 用结构体表示超女数据
2) 先输入超女全部的数据项，然后才进行选秀;
3) 用逻辑表达式组合判断条件，不要用嵌套if语句。
*/

#include <iostream>
using namespace std;

struct st_girl
{
    int age;
    int height;
    string sc;          // 身材
    // char sc[31];
    bool yz;            // 颜值
};

void draft_girl() {
    st_girl girl;
    cout << "请输入超女年龄："; cin >> girl.age;
    cout << "请输入超女身高："; cin >> girl.height;
    cout << "请输入超女身材（火辣/普通/飞机场）："; cin >> girl.sc;
    cout << "请输入超女颜值（1表示漂亮，0表示一般）："; cin >> girl.yz;
    if (girl.age >= 18 && girl.age <= 25 && girl.height >= 165
        && girl.height <= 178 && girl.sc == "火辣" && girl.yz == 1) {
        cout << "妃子" << endl;
    }
    else if (girl.age >= 18 && girl.age <= 30 && girl.height >= 155
        && girl.height <= 165 && (girl.sc == "火辣" || girl.sc == "普通") && girl.yz == 1) {
        cout << "宫女" << endl;
    }
    else if (girl.age >= 35 && girl.age <= 40 && girl.height >= 160
        && girl.height <= 165 && (girl.sc == "飞机场" || girl.sc == "普通") && girl.yz == 0) {
        cout << "嬷嬷" << endl;
    }
}

int main()
{
    draft_girl();
    
}

