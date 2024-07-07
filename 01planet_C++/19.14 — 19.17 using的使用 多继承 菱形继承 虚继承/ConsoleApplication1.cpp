/*
通过using来继承基类构造函数
C++11标准中，可通过using Base::Base把基类构造函数继承到派生类中，不再需要书写多个派生类构造函数来完成基类的初始化。
	更为巧妙的是，C++11标准规定，继承构造函数与类的一些默认函数(默认构造、析构、拷贝构造函数等)一样，是隐式声明，如果一个继承构造函数不被相关代码使用，编译器不会为其产生真正的函数代码。

基类构造函数的调用顺序和它们在派生类构造函数中出现的顺序无关，而是和声明派生类时基类出现的顺序相同。

在虚继承中，虚基类是由最终的派生类初始化的。所以在虚继承中必须调用间接基类的构造函数，这一点和普通继承不同，普通继承只能调用直接基类的构造函数。
*/

#include <iostream>
using namespace std;

/*
菱形继承
		Life				间接基类
	   /	\
	Animal	Person		直接基类
	   \    /
	   Student			派生类
*/
class Life
{
public:
	bool isAlive = true;

	Life() { cout << "调用Life()构造函数" << endl; };
	~Life() { cout << "调用~Life()构造函数" << endl; };
};
class Animal :virtual public Life
{
public:
	string nickName;		// 昵称

	Animal() { isAlive = false; cout << "调用Animal()构造函数" << endl; };
	~Animal() { cout << "调用~Animal()构造函数" << endl; };

	void info() { cout << "昵称：" << nickName << endl; }
};
class Person :virtual public Life
{
protected:
	string name;
	int age;
public:
	Person(string name, int age) :name(name), age(age) {
		cout << "调用Person(string name, int age)构造函数" << endl;
	}
	~Person() { cout << "调用~Person()析构函数" << endl; }

	void info() { cout << "name: " << name << ", age: " << age << endl; }
};
class Student :protected Person, public Animal	// 构造/析构的顺序是按照继承方式声明顺序的
{
private:
	double score;
public:
	using Person::Person;
	Student(string name, int age, double score) :Person(name, age), score(score) {
		cout << "调用Student(string name, int age, double score)构造函数" << endl;
	}
	~Student() { cout << "调用~Student()析构函数" << endl; }

	void info() {
		/*cout << "student name: " << name << ", student age: " << age
			<< ", score: " << score << ", nickName: " << nickName << endl;*/
		Person::info();
		Animal::info();
	}

	// 使用virtual 虚继承后，就可以直接使用 isAlive ，因为只有一份了
	void show_person_isAlive() { cout << "Person::isAlive = " << isAlive << endl; }
};

int main()
{
	//Student a1("PP", 22, 150);
	//a1.info();
	// a1.Person::info();		// 调用基类同名函数	// 如果继承方式不为public，那么将无法调用基类函数

	// 使用了using Person::Person; 就可以用基类的构造函数创建对象
	Student a2("QQ", 23);
	a2.nickName = "咪咪";
	a2.info();
	cout << "Animal::isAlive = " << a2.Animal::isAlive << endl;		// Animal::isAlive = 0, Person::isAlive = 1 但不可访问
	a2.show_person_isAlive();
}