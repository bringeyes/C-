#pragma once
#include <iostream>
#include <string>
#include "subCal.h"
using namespace std;

// �˵�����
void menu();

// 1.�ӷ�
void Add(double a, double b);
// 2.����
void Sub(double a, double b);
// 3.�˷�
void Mul(double a, double b);
// 4.����
void Div(double a, double b);
// 5.ȡ��
void Mod(double a, double b);
// 6.����
void Sqrt(double a, double b);
// 7.����
void Pow(double a, double b);
// Q.�˳�
bool Quit();

// ������ʹ��
void calculator();