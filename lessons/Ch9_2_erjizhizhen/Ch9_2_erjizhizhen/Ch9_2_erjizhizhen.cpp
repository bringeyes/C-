#include <iostream>
using namespace std;

void func(int** pp);

int main()
{
    /* int ii = 8;               cout << "ii=" << ii << "\tii的地址是：" << &ii << endl;
    int* pii = &ii;         cout << "pii=" << pii << "\tpii的地址是：" << &pii << "\t*pii="  << *pii << endl;
    int** ppii = &pii;    cout << "ppii=" << ppii << "\tppii的地址是：" << &ppii << "\t*ppii=" << *ppii << endl;
    cout << "**ppii=" << **ppii << endl;    */

    int* p = new int(3);
    cout << "p=" << p << "，*p=" << *p << "，&p=" << &p << endl;

    func(&p);           // 传入二级指针

    cout << "p=" << p << "，*p=" << *p << endl;
}

void func(int** pp)     // 指针的地址用二级指针存放
{
    cout << "pp=" << pp << "，*pp=" << *pp << endl;

    *pp = new int(4);       // pp解引用后就是p，用new让它指向新地址，并重新为变量*p赋值为4
    // 经过 new 后，p的地址&p变了，p指向的内存地址的值也变了

    cout << "pp=" << pp << "，*pp=" << *pp << endl;
}