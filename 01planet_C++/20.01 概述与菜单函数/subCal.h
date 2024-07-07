#pragma once
#include <cmath>
#include "abstrCal.h"

// �ӷ���
class AddCalculator :public AbstractCalculate
{
public:
	double getResult() { return num1 + num2; }
};
// ������
class SubCalculator :public AbstractCalculate
{
public:
	double getResult() { return num1 - num2; }
};
// �˷���
class MulCalculator :public AbstractCalculate
{
public:
	double getResult() { return num1 * num2; }
};
// ������
class DivCalculator :public AbstractCalculate
{
public:
	double getResult() { return num1 / num2; }
};
// ȡ����
class ModCalculator :public AbstractCalculate
{
public:
	double getResult() { return fmod(num1, num2); }
};
// ������
class SqrtCalculator :public AbstractCalculate
{
public:
	double getResult() { return pow(num1, 1 / num2); }
};
// ������
class PowCalculator :public AbstractCalculate
{
public:
	double getResult() { return pow(num1, num2); }
};