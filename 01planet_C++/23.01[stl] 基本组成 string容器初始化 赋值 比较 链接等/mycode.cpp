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

	string s6(10, 'b');		// 10��'b'ƴ��
	cout << s6 << endl;

	string s7 = string("hello1");		// ����ʱ��string���ʼ��
	cout << s7 << endl;

	string s8(string("hello2"));
	cout << s8 << endl;
}

void test02() {
	string s1;
	cout << "�������ַ���"; cin >> s1;		// �����ո����
	cout << s1 << endl;

	// ���Խ��մ��ո���ַ���
	getline(cin, s1);	// vs��ʹ��getline()��������� #include <string>
	cout << s1 << endl;
}

void test03() {
	string s1 = "abcd", s2 = "efg";
	if (s1 < s2) cout << "s1 < s2" << endl;
	else cout << "s1 >= s2" << endl;

	string s3 = s1 + s2;
	// string s3 = "hello" + "world";	// ��������д���ַ���������const char* ������string
	cout << s3 << endl;
}

void test04() {
	string s1 = "abcdefg";
	// C++11 ������
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
	// ʹ�õ�������������ָ��
	string s1 = "hello world";
	for (auto i = s1.begin(); i != s1.end(); i++) {
		cout << *i << ' ';
	}
	cout << endl;
}

void test06() {
	/*
	string s(s1, pos)
		��s1���±�pos��ʼ��������β����pos>s1.size()ʱ,Ϊδ������Ϊ;
		��pos=s1.size(),����һ�����ַ�
	string s(s1, pos, len)
		��s1���±�pos��ʼ����������len���ַ�����pos>s1.size()ʱ,Ϊδ������Ϊ;
		��pos=s2.size()������һ�����ַ�
	*/

	string s1("hello"); cout << "s1.size() = " << s1.size() << endl;
	string s2(s1, 1); cout << "s2 = " << s2 << endl;
	// string s3(s1, 6); cout << "s3 = " << s3 << endl;		// �����ַ�������5������
	string s4(s1, s1.size()); cout << "s4 = " << s4 << endl;		// ���ַ�

	cout << "ʹ��string s(s1, pos, len)" << endl;
	string s5(s1, 1, 3); cout << "s5 = " << s5 << endl;
	string s6(s1, 1, 5); cout << "s6 = " << s6 << endl;
	string s7(s1, 5, 6); cout << "s7 = " << s7 << endl;		// ���len����ʣ���ַ���������ֻ���Ƶ��ַ�������
	// string s8(s1, 6, 2); cout << "s8 = " << s8 << endl;		// �����ַ�������5������
}

void test07() {
	/*
	s.substr(pos, n)
	����һ��string���󣬷��صĶ������s��pos�±꿪ʼ��n���ַ���
	pos��n��Ϊ��ѡ������posĬ��Ϊ�±�0;nĬ��Ϊs.size()-pos��
	*/

	string s1("Value");
	string s2 = s1.substr(); cout << "s2 = " << s2 << endl;					// Value
	string s3 = s1.substr(1, 3); cout << "s3 = " << s3 << endl;				// alu
	string s4 = s1.substr(1, 7); cout << "s4 = " << s4 << '-' << endl;		// alue
	string s5 = s1.substr(2); cout << "s5 = " << s5 << endl;					// lue
	// string s6 = s1.substr(6); cout << "s6 = " << s6 << endl;				// pos���������
	string s7 = s1.substr(s1.size()); cout << "s7 = " << s7 << '-' << endl;		// ��
}

void test08() {
	/*
	1. iterator insert( iterator pos, CharT ch )		�����ַ�
	2. void insert( iterator pos, size_type count, CharT ch )	�����ظ����ַ�
	3. void insert( iterator pos, inputlt first, inputlt last )
	4. �����ʼ���б�
	*/

	string s1("Value");
	string s2("123456");
	s1.insert(s1.begin(), 's'); cout << "s1 = " << s1 << endl;		// sValue
	s1.insert(s1.begin(), 2, 'x'); cout << "s1 = " << s1 << endl;	// xxsValue������2��'x'

	// �����ַ��� (����λ�ã��ַ�����ʼ��ַ��������ַ
	s1.insert(s1.begin(), s2.begin(), s2.begin() + 3); cout << "s1 = " << s1 << endl;		// 123xxsValue
	s1.insert(s1.end(), { '1','2' }); cout << "s1 = " << s1 << endl;		// 123xxsValue12
}

void test09() {
	/*
	basic_string& erase(size type pos=0, size _type n=npos)
		ɾ��s��pos�±꿪ʼ��n���ַ���������ɾ�����s����pos>s.size()ʱ������
	iterator erase(const iterator position)
		ɾ��s������positionλ�õ��ַ�����������һ���ַ��ĵ�������
	iterator erase(const iterator first, const iterator last)
		ɾ��s������[first,last)������ַ���������last�ַ��ĵ�������
	*/

	string s1("value"), s2("value"), s3("value"), s4("value"), s5("value");

	// ���
	s1.erase(); cout << "s1 = " << s1 << endl;

	// vue v-al-ue		ɾ�� ��ʼ �ַ���
	s2.erase(1, 2); cout << "s2 = " << s2 << endl;

	// vlue v-a-lue		ɾ������λ��
	s3.erase(s3.begin() + 1); cout << "s3 = " << s3 << endl;

	// va va-lue-		ɾ��λ�� 2 ��֮���ȫ��
	s4.erase(2); cout << "s4 = " << s4 << endl;

	// lue -va-lue		��ͷ��ʼ��ɾ2���ַ����൱�� s4.erase(0,2)
	s5.erase(s5.begin(), s5.begin() + 2); cout << "s5 = " << s5 << endl;
}

void test10() {
	/*
	append����string�����ĩβ���в����������һ��ʹ��+�����Ҳ������
	*/

	string s1("C++");
	s1.append("123");
	cout << "s1 = " << s1 << endl;
}

void test11() {
	string s1 = "I very love China!";
	const char* cp1 = "truly", * cp2 = "truly!!";
	string str1 = "really", str2 = "really!!";

	// ��λ�� 2 ��ʼ��ɾ 4 ���ַ���Ȼ���� cp1 ���λ�� 2
	s1.replace(2, 4, cp1); cout << "s1 = " << s1 << endl;

	//
}