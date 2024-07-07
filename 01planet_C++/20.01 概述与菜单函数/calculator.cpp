#include "calculator.h"

void menu() {
	cout << "************************\n"
		<< "******   1.加法   ******\n"
		<< "******   2.减法   ******\n"
		<< "******   3.乘法   ******\n"
		<< "******   4.除法   ******\n"
		<< "******   5.取余   ******\n"
		<< "******   6.开根   ******\n"
		<< "******   7.次幂   ******\n"
		<< "******   Q.退出   ******\n"
		<< "************************" << endl;
}

void Add(double a, double b) {
	cout << "请输入a和b的值："; cin >> a >> b;
	AbstractCalculate* p = new AddCalculator;
	p->num1 = a; p->num2 = b;
	cout << p->num1 << " + " << p->num2 << " = " << p->getResult() << endl;
	delete p;
	system("pause");
	system("cls");
}
void Sub(double a, double b) {
	cout << "请输入a和b的值："; cin >> a >> b;
	AbstractCalculate* p = new SubCalculator;
	p->num1 = a; p->num2 = b;
	cout << p->num1 << " - " << p->num2 << " = " << p->getResult() << endl;
	delete p;
	system("pause");
	system("cls");
}
void Mul(double a, double b) {
	cout << "请输入a和b的值："; cin >> a >> b;
	AbstractCalculate* p = new MulCalculator;
	p->num1 = a; p->num2 = b;
	cout << p->num1 << " * " << p->num2 << " = " << p->getResult() << endl;
	delete p;
	system("pause");
	system("cls");
}
void Div(double a, double b) {
	cout << "请输入a和b的值："; cin >> a >> b;
	AbstractCalculate* p = new DivCalculator;
	p->num1 = a; p->num2 = b;
	cout << p->num1 << " / " << p->num2 << " = " << p->getResult() << endl;
	delete p;
	system("pause");
	system("cls");
}
void Mod(double a, double b) {
	cout << "请输入a和b的值："; cin >> a >> b;
	AbstractCalculate* p = new ModCalculator;
	p->num1 = a; p->num2 = b;
	cout << p->num1 << " % " << p->num2 << " = " << p->getResult() << endl;
	delete p;
	system("pause");
	system("cls");
}
void Sqrt(double a, double b) {
	cout << "请输入a和b的值："; cin >> a >> b;
	AbstractCalculate* p = new SqrtCalculator;
	p->num1 = a; p->num2 = b;
	cout << p->num2 << "√" << p->num1 << " = " << p->getResult() << endl;
	delete p;
	system("pause");
	system("cls");
}
void Pow(double a, double b) {
	cout << "请输入a和b的值："; cin >> a >> b;
	AbstractCalculate* p = new PowCalculator;
	p->num1 = a; p->num2 = b;
	cout << p->num1 << "^" << p->num2 << " = " << p->getResult() << endl;
	delete p;
	system("pause");
	system("cls");
}

bool Quit() {
	char comfirm;
	cout << "确认退出？(Y/N)\t"; cin >> comfirm;
	if (comfirm == 'Y' || comfirm == 'y') exit(0);
	else system("cls");
}

void calculator() {
	string input;
	int select = 0;
	double a = 0, b = 0;
	bool is_input_valid = true;
	while (1) {
		menu();
		if (is_input_valid) { cout << "请选择序号进行计算："; cin >> input; }
		else { cout << "请输入正确的序号："; cin >> input; is_input_valid = true; }
		if (input == "Q" || input == "q") Quit();
		else {
			try {
				select = stoi(input);
			}
			catch (exception& e) {
				is_input_valid = false;
				system("cls");
				continue;
			}
		}

		switch (select)
		{
		case 1:
			Add(a, b);
			break;
		case 2:
			Sub(a, b);
			break;
		case 3:
			Mul(a, b);
			break;
		case 4:
			Div(a, b);
			break;
		case 5:
			Mod(a, b);
			break;
		case 6:
			Sqrt(a, b);
			break;
		case 7:
			Pow(a, b);
			break;
		default:
			is_input_valid = false;
			system("cls");
		}
	}
}