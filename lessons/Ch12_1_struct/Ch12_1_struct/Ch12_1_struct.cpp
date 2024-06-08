//#include <iostream>
//using namespace std;
//#pragma pack(1)     // 修改内存对齐规则
//                                // 用1，内存之间没有空隙，修改后结构体内存35字节
//struct st_girl      // 定义结构体的代码可以放在程序的任何地方，
//                        // 一般放在main上方或者头文件中，这样整个程序都能使用
//{
//    string name = "西施";     // 结构体中可以用string，但不提倡
//    
//    int age = 25;
//    double weight = 48.6;
//    char sex = 'X';
//    bool yz = true;
//
//}girl1{ "xishi",26,50,'X',false };     // 在结构体后跟变量名初始化
//// girl1 = { "xishi",26,50,'X',false };     // = 可写可不写
//
//int main()
//{
//    // 初始化：
//    //st_girl girl1 = { 0 };      // 创建结构
//    // st_girl girl1 = {};
//        // 第二种初始化方法：struct 结构体名 结构体变量名 = { 成员一的值,成员二的值… 成员n的值 };
//    cout << "姓名：" << girl1.name << "年龄：" << girl1.age << "体重：" << girl1.weight
//        << "性别：" << girl1.sex << "颜值：" << girl1.yz << endl;
//
//    st_girl girl2 = girl1;      // 用其他结构体来初始化
//
//    cout << "姓名：" << girl2.name << "年龄：" << girl2.age << "体重：" << girl2.weight
//        << "性别：" << girl2.sex << "颜值：" << girl2.yz << endl;
//     
//    memset(&girl1, 0, sizeof(girl1));   // 地址，赋值，长度
//}
//
//// 养成初始化的习惯，不能指望编译器检查错误
//
//
