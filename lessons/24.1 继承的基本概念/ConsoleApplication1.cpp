/*

*/

#include <iostream>
using namespace std;

class CAllComers		// 海选报名者类(基类)
{
public:
	string m_name;
	string m_tel;

	CAllComers() { m_name = "XXX"; m_tel = "不详"; }

	// 报名时需要唱一首歌
	void sing() { cout << "我是一只小小鸟。\n"; }
	void setname(const string name) { m_name = name; }
	void setTel(const string tel) { m_tel = tel; }
};

class CGirl :public CAllComers		// 超女类(派生类)
{
public:
	int m_bh;

	CGirl() { m_bh = 8; }

	void show() {
		cout << "编号：" << m_bh << "，姓名：" << m_name << "，联系方式：" << m_tel << endl;
	}
};

int main()
{
	CGirl g1;
	g1.show();
}

/*
使用继承的场景:
1) 如果新创建的类与现有的类相似，只是多出若干成员变量或成员函数时，可以使用继承。
2) 当需要创建多个类时，如果它们拥有很多相似的成员变量或成员函数，
	可以将这些类共同的成员提取出来，定义为基类，然后从基类继承。
*/