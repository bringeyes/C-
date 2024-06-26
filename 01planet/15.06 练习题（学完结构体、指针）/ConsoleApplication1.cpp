/*

*/

#include <iostream>
using namespace std;

// 题目1——————————————————————————————————————————
//int maxScore = 0;	// 最高总成绩
//Student stu;			// 最高总成绩对应学生
//
//struct Student
//{
//	int bh;
//	char name[9];
//	int  age;
//	double chinese;
//	double math;
//	double english;
//	double totalScore;
//};
//// }students[100];
//
//void inputGrades(Student& stu, int num) {
//	cout << "学生" << num << "：\n";
//	cout << "姓名："; cin >> stu.name;
//	cout << "年龄："; cin >> stu.age;
//	cout << "语文成绩："; cin >> stu.chinese;
//	cout << "数学成绩："; cin >> stu.math;
//	cout << "英语成绩："; cin >> stu.english;
//	cout << endl;
//
//	stu.bh = num;
//	stu.totalScore = stu.chinese + stu.math + stu.english;
//}
//
//int main()
//{
//	int headcount;
//	cout << "输入学生总人数："; cin >> headcount;
//	Student* students = new Student[headcount];		// 创建学生结构体数组
//
//	for (int i = 0; i < headcount; i++) {
//		inputGrades(students[i], i + 1);
//		if (students[i].totalScore > maxScore) {
//			stu = students[i];
//			maxScore = students[i].totalScore;
//		}
//	}
//
//	cout << "总成绩最高者：" << stu.name
//		<< "\t年龄：" << stu.age
//		<< "\n语文成绩：" << stu.chinese
//		<< "\t数学成绩：" << stu.math
//		<< "\n英语成绩：" << stu.english
//		<< "\t总成绩：" << stu.totalScore << endl;
//}
// 题目1——————————————————————————————————————————

// 题目2——————————————————————————————————————————

enum Day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

int main()
{
	int day;
	cin >> day;
	switch (day)
	{
	case Sunday:
		cout << "周日\n"; break;
	case Monday:
		cout << "周一\n"; break;
	case Tuesday:
		cout << "周二\n"; break;
	case Wednesday:
		cout << "周三\n"; break;
	case Thursday:
		cout << "周四\n"; break;
	case Friday:
		cout << "周五\n"; break;
	case Saturday:
		cout << "周六\n"; break;
	}
}

// 题目2——————————————————————————————————————————