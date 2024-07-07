#pragma once

// 抽象计算基类
class AbstractCalculate
{
public:
	double num1, num2;
	virtual double getResult() = 0;
};