#include "calculator.h"

void menu() {
	cout << "************************\n"
		<< "******   1.�ӷ�   ******\n"
		<< "******   2.����   ******\n"
		<< "******   3.�˷�   ******\n"
		<< "******   4.����   ******\n"
		<< "******   5.ȡ��   ******\n"
		<< "******   6.����   ******\n"
		<< "******   7.����   ******\n"
		<< "******   Q.�˳�   ******\n"
		<< "************************" << endl;
}

void Add(double a, double b) {
	cout << "������a��b��ֵ��"; cin >> a >> b;
	AbstractCalculate* p = new AddCalculator;
	p->num1 = a; p->num2 = b;
	cout << p->num1 << " + " << p->num2 << " = " << p->getResult() << endl;
	delete p;
	system("pause");
	system("cls");
}
void Sub(double a, double b) {
	cout << "������a��b��ֵ��"; cin >> a >> b;
	AbstractCalculate* p = new SubCalculator;
	p->num1 = a; p->num2 = b;
	cout << p->num1 << " - " << p->num2 << " = " << p->getResult() << endl;
	delete p;
	system("pause");
	system("cls");
}
void Mul(double a, double b) {
	cout << "������a��b��ֵ��"; cin >> a >> b;
	AbstractCalculate* p = new MulCalculator;
	p->num1 = a; p->num2 = b;
	cout << p->num1 << " * " << p->num2 << " = " << p->getResult() << endl;
	delete p;
	system("pause");
	system("cls");
}
void Div(double a, double b) {
	cout << "������a��b��ֵ��"; cin >> a >> b;
	AbstractCalculate* p = new DivCalculator;
	p->num1 = a; p->num2 = b;
	cout << p->num1 << " / " << p->num2 << " = " << p->getResult() << endl;
	delete p;
	system("pause");
	system("cls");
}
void Mod(double a, double b) {
	cout << "������a��b��ֵ��"; cin >> a >> b;
	AbstractCalculate* p = new ModCalculator;
	p->num1 = a; p->num2 = b;
	cout << p->num1 << " % " << p->num2 << " = " << p->getResult() << endl;
	delete p;
	system("pause");
	system("cls");
}
void Sqrt(double a, double b) {
	cout << "������a��b��ֵ��"; cin >> a >> b;
	AbstractCalculate* p = new SqrtCalculator;
	p->num1 = a; p->num2 = b;
	cout << p->num2 << "��" << p->num1 << " = " << p->getResult() << endl;
	delete p;
	system("pause");
	system("cls");
}
void Pow(double a, double b) {
	cout << "������a��b��ֵ��"; cin >> a >> b;
	AbstractCalculate* p = new PowCalculator;
	p->num1 = a; p->num2 = b;
	cout << p->num1 << "^" << p->num2 << " = " << p->getResult() << endl;
	delete p;
	system("pause");
	system("cls");
}

bool Quit() {
	char comfirm;
	cout << "ȷ���˳���(Y/N)\t"; cin >> comfirm;
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
		if (is_input_valid) { cout << "��ѡ����Ž��м��㣺"; cin >> input; }
		else { cout << "��������ȷ����ţ�"; cin >> input; is_input_valid = true; }
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