#include <iostream>
using namespace std;

struct st_girl
{
    //  string name = "西施";     // 结构体中可以用string，但不提倡
    char name[21];          // 记得初始化

    int age = 25;
    double weight = 48.6;
    char sex = 'X';
    bool yz = true;

}girl1{ "西施",26,50,'X',false };

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
    // 初始化：
    //st_girl girl1 = { 0 };      // 创建结构
    // st_girl girl1 = {};
        // 第二种初始化方法：struct 结构体名 结构体变量名 = { 成员一的值,成员二的值… 成员n的值 };
    cout << "姓名：" << girl1.name << "年龄：" << girl1.age << "体重：" << girl1.weight
        << "性别：" << girl1.sex << "颜值：" << girl1.yz << endl;

    // 结构体指针
    st_girl* pst = &girl1;
    cout << "姓名：" << (*pst).name << "年龄：" << (*pst).age << "体重：" << (*pst).weight
        << "性别：" << (*pst).sex << "颜值：" << (*pst).yz << endl;   // . 的优先级高于 * ，这里必须加 ()

    cout << "姓名：" << pst->name << "年龄：" << pst->age << "体重：" << pst->weight
        << "性别：" << pst->sex << "颜值：" << pst->yz << endl;
    // girl1.   (*pst).     pst->   效果等价
   

    // 用途：
    // 1. 函数参数；
    //      如果要把结构体传递给函数，实参取结构体变量的地址，函数的形参用结构体指针。
    //      如果不希望在函数中修改结构体变量的值，可以对形参加const 约束。
    func(pst);

    // 2. 动态分配内存
    st_girl* girl3 = new st_girl;   // 创建结构体指针，new一个结构体，让指针指向它
    // 正常用法是 st_girl* girl3 = new st_girl({ });     // 进行初始化
                 // 或 st_girl* girl3 = new st_girl({ "西施",26,50,'X',false });

    func(girl3);    // 这里没有初始化，姓名显示乱码
    memset(girl3, 0, sizeof(girl3));    // 这里的girl3是指针，大小只有8字节，所以只能清空8字节
    func(girl3);                                // 动态分配内存时没有结构体名
    memset(girl3, 0, sizeof(st_girl));  // 只能用结构体名
    func(girl3);

    delete girl3;       // 动态分配的内存要手动释放
     

}   
