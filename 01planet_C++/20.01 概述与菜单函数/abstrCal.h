#pragma once

// ����������
class AbstractCalculate
{
public:
	double num1, num2;
	virtual double getResult() = 0;
};