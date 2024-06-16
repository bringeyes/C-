/*

*/

#include <iostream>
using namespace std;

class Hero
{
public:
	string m_name;

	virtual void skill1() { cout << "英雄1技能\n"; }
	virtual void skill2() { cout << "英雄2技能\n"; }
};

class Aixi :public Hero
{
	void skill1() { cout << "艾希1技能\n"; }
	void skill2() { cout << "艾希2技能\n"; }
public:
	void show() { cout << "艾希show()\n"; }
};

class Daomei :public Hero
{
	void skill1() { cout << "刀妹1技能\n"; }
	void skill2() { cout << "刀妹2技能\n"; }
};

int main()
{
	/*int ii = 3;
	int* pii = &ii;
	int& rii = ii;
	cout << "typeid(int)=" << typeid(int).name() << endl;
	cout << "typeid(ii)=" << typeid(ii).name() << endl;
	cout << "typeid(int *)=" << typeid(int*).name() << endl;
	cout << "typeid(pii)=" << typeid(pii).name() << endl;
	cout << "typeid(int &)=" << typeid(int&).name() << endl;
	cout << "typeid(rii)=" << typeid(rii).name() << endl;*/

	//Hero h;
	//Hero* ph = &h;
	//Hero& rh = h;
	//cout << "typeid(Hero)=" << typeid(Hero).name() << endl;
	//cout << "typeid(Hero)=" << typeid(h).name() << endl;
	//cout << "typeid(Hero *)=" << typeid(Hero*).name() << endl;
	//cout << "typeid(ph)=" << typeid(ph).name() << endl;
	//cout << "typeid(Hero &)=" << typeid(Hero&).name() << endl;
	//cout << "typeid(rh)=" << typeid(rh).name() << endl;

	//// type_info 重载了 == 和 != 运算符，用于对类型进行比较。
	//if (typeid(Hero) == typeid(h)) cout << "OK1\n";
	//if (typeid(Hero) == typeid(*ph)) cout << "OK2\n";
	//if (typeid(Hero) == typeid(rh)) cout << "OK3\n";
	//if (typeid(Hero*) == typeid(ph)) cout << "OK4\n";

	int hero_choice;
	cout << "选择你的英雄：1-艾希，2-刀妹："; cin >> hero_choice;

	Hero* ptr = nullptr;
	if (hero_choice == 1) {
		ptr = new Aixi;
	}
	else if (hero_choice == 2) {
		ptr = new Daomei;
	}
	else { cout << "输入了错误的选项。\n"; }

	if (ptr) {
		ptr->skill1();
		ptr->skill2();
		// 不能用(typeid(Aixi*) == typeid(ptr)) 判断类型，因为ptr是基类指针，肯定和派生类指针不一样
		// 需要用指针指向的对象判断
		if (typeid(Aixi) == typeid(*ptr)) {
			Aixi* pax = (Aixi*)ptr;		// C风格强制转换，程序员必须保证目标类型正确
			pax->show();
		}
		//Aixi* pax = dynamic_cast<Aixi*>(ptr);
		//if (pax != nullptr) pax->show();

		delete ptr;
	}
}

/*
typeid 运算符用于获取数据类型的信息。
	语法一: typeid(数据类型);
	语法二: typeid(变量名或表达式);
typeid 运算符返回 type_info 类(在头文件<typeinfo>中定义)的对象的引用。
type_info 类的实现随编译器而异，但至少有 name()成员函数，该函数返回一个字符串，
	通常是类名，这个值的作用只是调试
type info 重载了 == 和 != 运算符，用于对类型进行比较。

注意:
1) type info 的构造函数是 private 属性，也没有拷贝构造函数，所以不能直接实例化，只能由编译器在内部实例化。

2) 不建议用 name()成员函数返回的字符串作为判断数据类型的依据。(编译器可能会转换类型名）

3) typeid 运算符可以用于多态的场景，在运行阶段识别对象的数据类型。

4) 假设有表达式 typeid(*ptr)，当 ptr 是空指针时，如果 ptr 是多态的类型，将引发 bad _typeid异常。
*/