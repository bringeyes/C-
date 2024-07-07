#pragma once
#include <iostream>
#include <string>
#include "subCal.h"
using namespace std;

// 菜单界面
void menu();

// 1.加法
void Add(double a, double b);
// 2.减法
void Sub(double a, double b);
// 3.乘法
void Mul(double a, double b);
// 4.除法
void Div(double a, double b);
// 5.取余
void Mod(double a, double b);
// 6.开根
void Sqrt(double a, double b);
// 7.次幂
void Pow(double a, double b);
// Q.退出
bool Quit();

// 计算器使用
void calculator();