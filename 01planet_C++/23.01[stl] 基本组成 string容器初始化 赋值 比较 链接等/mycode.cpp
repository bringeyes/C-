#include "mycode.h"

void test01() {
	string s1 = "aaa";
	cout << s1 << endl;

	string s2(s1);
	cout << s2 << endl;

	string s3 = s1;
	cout << s3 << endl;

	string s4 = "hello";
	cout << s4 << endl;

	string s5("hello");
	cout << s5 << endl;

	string s6(10, 'b');		// 10个'b'拼接
	cout << s6 << endl;

	string s7 = string("hello1");		// 用临时的string类初始化
	cout << s7 << endl;

	string s8(string("hello2"));
	cout << s8 << endl;
}

void test02() {
	string s1;
	cout << "请输入字符："; cin >> s1;		// 遇到空格结束
	cout << s1 << endl;

	// 可以接收带空格的字符串
	getline(cin, s1);	// vs里使用getline()，必须加上 #include <string>
	cout << s1 << endl;
}

void test03() {
	string s1 = "abcd", s2 = "efg";
	if (s1 < s2) cout << "s1 < s2" << endl;
	else cout << "s1 >= s2" << endl;

	string s3 = s1 + s2;
	// string s3 = "hello" + "world";	// 不能这样写，字符串常量是const char* ，不是string
	cout << s3 << endl;
}

void test04() {
	string s1 = "abcdefg";
	// C++11 新特性
	for (auto c : s1) {
		cout << c << ' ';
	}
	cout << endl;

	cout << "s1[1] = " << s1[1] << endl;

	for (int i = 0; i < s1.size(); i++) {
		cout << s1[i] << ' ';
	}
	cout << endl;
}

void test05() {
	// 使用迭代器，本质是指针
	string s1 = "hello world";
	for (auto i = s1.begin(); i != s1.end(); i++) {
		cout << *i << ' ';
	}
	cout << endl;
}

void test06() {
	/*
	string s(s1, pos)
		将s1从下标pos开始拷贝到结尾。当pos>s1.size()时,为未定义行为;
		当pos=s1.size(),拷贝一个空字符
	string s(s1, pos, len)
		将s1从下标pos开始拷贝，拷贝len个字符。当pos>s1.size()时,为未定义行为;
		当pos=s2.size()，拷贝一个空字符
	*/

	string s1("hello"); cout << "s1.size() = " << s1.size() << endl;
	string s2(s1, 1); cout << "s2 = " << s2 << endl;
	// string s3(s1, 6); cout << "s3 = " << s3 << endl;		// 超过字符串长度5，报错
	string s4(s1, s1.size()); cout << "s4 = " << s4 << endl;		// 空字符

	cout << "使用string s(s1, pos, len)" << endl;
	string s5(s1, 1, 3); cout << "s5 = " << s5 << endl;
	string s6(s1, 1, 5); cout << "s6 = " << s6 << endl;
	string s7(s1, 5, 6); cout << "s7 = " << s7 << endl;		// 如果len超过剩余字符数量，则只复制到字符串结束
	// string s8(s1, 6, 2); cout << "s8 = " << s8 << endl;		// 超过字符串长度5，报错
}

void test07() {
	/*
	s.substr(pos, n)
	返回一个string对象，返回的对象包含s从pos下标开始的n个字符。
	pos和n均为可选参数。pos默认为下标0;n默认为s.size()-pos。
	*/

	string s1("Value");
	string s2 = s1.substr(); cout << "s2 = " << s2 << endl;					// Value
	string s3 = s1.substr(1, 3); cout << "s3 = " << s3 << endl;				// alu
	string s4 = s1.substr(1, 7); cout << "s4 = " << s4 << '-' << endl;		// alue
	string s5 = s1.substr(2); cout << "s5 = " << s5 << endl;					// lue
	// string s6 = s1.substr(6); cout << "s6 = " << s6 << endl;				// pos溢出，报错
	string s7 = s1.substr(s1.size()); cout << "s7 = " << s7 << '-' << endl;		// 空
}

void test08() {
	/*
	1. iterator insert( iterator pos, CharT ch )		插入字符
	2. void insert( iterator pos, size_type count, CharT ch )	插入重复的字符
	3. void insert( iterator pos, inputlt first, inputlt last )
	4. 插入初始化列表
	*/

	string s1("Value");
	string s2("123456");
	s1.insert(s1.begin(), 's'); cout << "s1 = " << s1 << endl;		// sValue
	s1.insert(s1.begin(), 2, 'x'); cout << "s1 = " << s1 << endl;	// xxsValue，插入2个'x'

	// 插入字符段 (插入位置，字符段起始地址，结束地址
	s1.insert(s1.begin(), s2.begin(), s2.begin() + 3); cout << "s1 = " << s1 << endl;		// 123xxsValue
	s1.insert(s1.end(), { '1','2' }); cout << "s1 = " << s1 << endl;		// 123xxsValue12
}

void test09() {
	/*
	basic_string& erase(size type pos=0, size _type n=npos)
		删除s从pos下标开始的n个字符，并返回删除后的s。当pos>s.size()时，报错
	iterator erase(const iterator position)
		删除s迭代器position位置的字符，并返回下一个字符的迭代器。
	iterator erase(const iterator first, const iterator last)
		删除s迭代器[first,last)区间的字符，并返回last字符的迭代器。
	*/

	string s1("value"), s2("value"), s3("value"), s4("value"), s5("value");

	// 清空
	s1.erase(); cout << "s1 = " << s1 << endl;

	// vue v-al-ue		删除 起始 字符数
	s2.erase(1, 2); cout << "s2 = " << s2 << endl;

	// vlue v-a-lue		删除单个位置
	s3.erase(s3.begin() + 1); cout << "s3 = " << s3 << endl;

	// va va-lue-		删除位置 2 及之后的全部
	s4.erase(2); cout << "s4 = " << s4 << endl;

	// lue -va-lue		从头开始，删2个字符，相当于 s4.erase(0,2)
	s5.erase(s5.begin(), s5.begin() + 2); cout << "s5 = " << s5 << endl;
}

void test10() {
	/*
	append是在string对象的末尾进行插入操作。这一点使用+运算符也能做到
	*/

	string s1("C++");
	s1.append("123");
	cout << "s1 = " << s1 << endl;
}

void test11() {
	string s1 = "I very love China!";
	const char* cp1 = "truly", * cp2 = "truly!!";
	string str1 = "really", str2 = "really!!";

	// 从位置 2 开始，删 4 个字符，然后用 cp1 填充位置 2
	s1.replace(2, 4, cp1); cout << "s1 = " << s1 << endl;

	//
}