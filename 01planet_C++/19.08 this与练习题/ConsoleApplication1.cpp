/*

*/

#include <iostream>
using namespace std;

class Animal
{
public:
	static int count;   // 被实例化次数
	int age;

	void eat() { cout << "吃。" << endl; }
	void run() { cout << "跑。" << endl; }
	void sleep() { cout << "睡。" << endl; }

	Animal() :age(0) { count++; }
	Animal(int age) :age(age) { count++; }
	bool operator>(Animal& a) {
		if (this->age > a.age) return true;
		return false;
	}
	bool operator==(Animal& a) {
		if (this->age == a.age) return true;
		return false;
	}
	bool operator<(Animal& a) {
		if (this->age < a.age) return true;
		return false;
	}
};

class Fraction
{
public:
	int numerator;		// 分子
	int denominator;		// 父母

	// 构造函数
	Fraction(int num, int den) {
		if (den == 0) throw "分母不能为0。";
		numerator = num;
		denominator = den;
		simplify();
	}

	// 简化分数
	void simplify() {
		int gcd = findGCD(numerator, denominator);	// 分子分母的最大公约数
		numerator /= gcd;
		denominator /= gcd;

		// 负号移到分子上
		if (numerator >= 0 && denominator < 0) {
			numerator *= -1;
			denominator *= -1;
		}
	}
	// 计算最大公约数
	int findGCD(int a, int b) const {
		if (b == 0) {
			return a;
		}
		return findGCD(b, a % b);
	}
	// 输出分数
	void print() const {
		cout << numerator << '/' << denominator << endl;
	}

	// 重载加法运算符
	Fraction operator+(Fraction& a) {
		int new_num = numerator * a.denominator + denominator * a.numerator;
		int new_den = denominator * a.denominator;
		return Fraction(new_num, new_den);
	}
	// 重载减法运算符
	Fraction operator-(Fraction& a) {
		int new_num = numerator * a.denominator - denominator * a.numerator;
		int new_den = denominator * a.denominator;
		return Fraction(new_num, new_den);
	}
	// 重载乘法运算符
	Fraction operator*(Fraction& a) {
		int new_num = numerator * a.numerator;
		int new_den = denominator * a.denominator;
		return Fraction(new_num, new_den);
	}
	// 重载除法运算符
	Fraction operator/(Fraction& a) {
		if (a.numerator == 0) throw "不能除以0";

		int new_num = numerator * a.denominator;
		int new_den = denominator * a.numerator;
		return Fraction(new_num, new_den);
	}
};

int Animal::count = 0;

int main()
{
	//Animal a1, a2(3);
	//a1.eat();
	//a2.run();
	//cout << a1.count << '\t' << a1.age << endl;
	//cout << a2.count << '\t' << a2.age << endl;
	//cout << (a1 > a2) << endl;

	Fraction x(1, 2), y(3, 4);
	Fraction z = x * y; z.print();
	z = x + y; z.print();
	z = x - y; z.print();
	z = x / y; z.print();
}