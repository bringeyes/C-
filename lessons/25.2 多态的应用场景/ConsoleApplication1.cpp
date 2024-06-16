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
		delete ptr;
	}
}

/*
当函数需要传入派生类对象(或指针)，使用多态，把基类指针或引用传入就行；
	不使用多态，就需要传入派生类指针或地址，如果需要操作的派生类很多，会很冗余麻烦
	void func(Hero* ptr) {};
	void func(Hero& h) {};
*/