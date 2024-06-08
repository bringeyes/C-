// C标准的字符串操作函数需要加这一行
#define _CRT_SECURE_NO_WARNINGS     // 要么加这一行，要么用strcpy_s
#include <iostream>
using namespace std;

struct st_pet
{
    char name[21];          // 宠物名字

    char kind[21] = "dog";

}pet1{ "旺财" };

struct st_girl
{
    //  string name = "西施";     // 结构体中可以用string，但不提倡
    char name[21];          // 记得初始化

    int age = 25;
    double weight = 48.6;
    char sex = 'X';
    bool yz = true;
    struct st_pet pet;     // 要预先定义才能使用

}girl1{ "西施",26,50,'X',false,{"宝宝","狗狗"} };     // C++11标准语法

void func(const st_girl* pst)   // 如果不希望实参被修改，加const约束
{
    cout << "函数func：" << endl;
    // pst->name = "西瓜";    // C风格字符串，不能直接用字符串赋值

    //strcpy_s(pst->name, "西瓜");      // strcpy报错了，strcpy_s更安全
    //pst->age = 88; 

    cout << "姓名：" << pst->name << "年龄：" << pst->age << "体重：" << pst->weight
        << "性别：" << pst->sex << "颜值：" << pst->yz << endl;
}

int main()
{
    st_girl girls[3];
    memset(girls, 0, sizeof(girls));

    strcpy(girls[0].name, "西施"); girls[0].age = 18; girls[0].sex = 'X';

    girls[1] = { "西瓜",2,10,'Y',false };

    for (int ii = 0; ii < 3; ii++)
    {
        // 数组表示法（最常用）
        cout << "姓名：" << girls[ii].name << "年龄：" << girls[ii].age << "体重：" << girls[ii].weight
            << "性别：" << girls[ii].sex << "颜值：" << girls[ii].yz << endl;
        // 指针表示法
        cout << "姓名：" << (girls+ii)->name << "年龄：" << (girls + ii)->age << "体重：" << (girls + ii)->weight
            << "性别：" << (girls + ii)->sex << "颜值：" << (girls + ii)->yz << endl;
    }

    cout << "姓名：" << girl1.name << "的宠物是一只" << girl1.pet.kind << "，名字叫：" << girl1.pet.name << endl;
}


