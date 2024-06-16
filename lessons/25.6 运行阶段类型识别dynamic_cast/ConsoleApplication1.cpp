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

void func(Hero* ptr) {};
void func(Hero& h) {};

int main()
{
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
		//if (hero_choice == 1) {
		//	Aixi* pax = (Aixi*)ptr;		// C风格强制转换，程序员必须保证目标类型正确
		//	pax->show();
		//}
		Aixi* pax = dynamic_cast<Aixi*>(ptr);
		if (pax != nullptr) pax->show();

		delete ptr;
	}
}

/*
运行阶段类型识别(RTTI RunTime Type Identification)为程序在运行阶段确定对象的类型，
	只适用于包含虚函数的类。

基类指针可以指向派生类对象，如何知道基类指针指向的是哪种派生类的对象呢?
	(想调用派生类中的非虚函数)。

dynamic cast 运算符用指向基类的指针来生成派生类的指针，它不能回答“指针指向的是什么类的对象”的问题，
	但能回答“是否可以安全的将对象的地址赋给特定类型的指针”的问题。
	语法:派生类指针 = dynamic_cast<派生类类型 *>(基类指针);

注意:
1) dynamic_cast 只适用于包含虚函数的类。(专为多态场景设计，使用时要查虚函数表)
2) dynamic_cast 可以将派生类指针转换为基类指针，这种画蛇添足的做法没有意义。
	因为派生类指针可以直接赋值给基类指针，不需要转换
3) dynamic_cast 可以用于引用，但是，没有与空指针对应的引用值，
	如果转换请求不正确，会出现 bad cast 异常。（实际开发中，根本没人用这个异常）
*/