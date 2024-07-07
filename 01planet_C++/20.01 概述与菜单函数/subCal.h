#pragma once
#include <cmath>
#include "abstrCal.h"

// 加法类
class AddCalculator :public AbstractCalculate
{
public:
	double getResult() { return num1 + num2; }
};
// 减法类
class SubCalculator :public AbstractCalculate
{
public:
	double getResult() { return num1 - num2; }
};
// 乘法类
class MulCalculator :public AbstractCalculate
{
public:
	double getResult() { return num1 * num2; }
};
// 除法类
class DivCalculator :public AbstractCalculate
{
public:
	double getResult() { return num1 / num2; }
};
// 取余类
class ModCalculator :public AbstractCalculate
{
public:
	double getResult() { return fmod(num1, num2); }
};
// 开根类
class SqrtCalculator :public AbstractCalculate
{
public:
	double getResult() { return pow(num1, 1 / num2); }
};
// 次幂类
class PowCalculator :public AbstractCalculate
{
public:
	double getResult() { return pow(num1, num2); }
};