/*
—————多态的基本概念—————
C++面向对象 的三大特征为:封装、继承 和多态，这三种机制能够有效提高程序的可读性、可扩充性和可重用性。
	"多态”指的是同一名字的事物可以完成不同的功能。

多态可以分为编译时的多态和运行时的多态。前者主要是指 函数的重载(包括运算符的重载)、对重载函数的调用，
	在编译时就能根据实参确定应该调用哪个函数，因此叫编译时的多态;
而后者则和继承、房虚函数等概念有关

有虚函数，基类指针指向基类对象时就使用基类的成员(包括成员函数 和 成员变量)，指向派生类对象时就使用派生类的成员，
	换句话说，基类指针可以按照基类的方式来做事，也可以按照派生类的方式来做事，它有多种形态，或者说有多种表现方式，这种现象称为多态(Polymorphism[,pol'ma:fizm])。
C++提供多态的目的是:可以通过 基类指针 对所有派生类(包括直接派生和间接派生)的成员变量和成员函数进行“全方位”的访问，尤其是成员函数。如果没有多态，只能访问成员变量

—————构成多态的条件—————
1. 必须存在继承关系;
2. 继承关系中必须有同名的虚函数，并且它们是覆盖关系(函数原型相同)。
3. 存在基类的指针，通过该指针调用虚函数。

—————什么时候使用虚函数？—————
首先看 成员函数 所在的类是否会作为基类。然后看成员函数在类的继承后有无可能被更改功能如果希望更改其功能的，一般应人将它声明为虚函数。
	如果成员函数在类被继承后功能不需修改，或派生类用不到该函数则不要把它声明为虚函数。

用 C++开发的时候，用来做基类的类的析构函数一般都是虚函数。

—————虚析构—————
虚析构函数是为了避免内存泄露，而且是当 子类 中会有 指针 成员变量 时才会使用得到的。也就说虚析构函数使得在删除指向子类对象的基类指针时可以调用子类的析构函数达到释放子类中堆内存的目的，而防止内存泄露的。
当父类的析构函数不声明成虚析构函数的时候，当子类继承父类指针指向子类时，delete掉父类的指只调动父类的析构函数，而不调动子类的析构函数。
当父类的析构函数声明成虚析构函数的时候，当子类继承父类，父类的指针指向子类时，delete掉父类的指针，先调动子类的析构函数，再调动父类的析构函数。

—————虚函数表—————
虚表是一个指针数组，其元素是虚函数的指针，每个元素对应一个虚函数的函数指针。需要指出的是普通的函数即非虚函数，其调用并不需要经过虚表，所以虚表的元素并不包括普通函数的函数指针。
	虚表内的条目，即虚函数指针的赋值发生在编译器的编译阶段，也就是说在代码的编译阶段，虚表就可以构造出来了。
	虚表是属于类的，而不是属于某个具体的对象类只需要一个虚表即可。同一个类的所有对象都使用同一个虚表。
编译器如何处理虚函数。当编译器发现类中有虚函数的时候，编译器会创建一张虚函数表，把虚函数的函数入口地址放到虚函数表中
	并且在类中秘密增加一个指针，
	这个指针就是vpointer(缩写vptr)，指向虚函数表。
	在多态调用的时候，根据vptr指针，找到虚函数表来实现动态绑定。

—————C++如何实现动态绑定—————（面试题？！）
在编译阶段，编译器秘密增加了一个vptr指针，但是此时vptr指针并没有初始化指向虚函数表(vtable),
	什么时候vptr才会指向虚函数表?
	在对象构建的时候，也就是在对象初始化调用构造函数的时候。
	编译器首先默认会在我们所编写的每一个构造函数中，增加一些vptr指针初始化的代码。
		如果没有提供构造函数，编译器会提供默认的构造函数，那么就会在默认构造函数里做此项工作，初始化vptr指针，使之指向本对象的虚函数表。
起初，子类继承基类，子类继承了基类的vptr指针，这个vptr指针是指向基类虚函数表，
	当子类调用构造函数，使得子类的vptr指针指向了子类的虚函数表。

—————抽象基类和纯虚函数—————
在设计时，常常希望基类仅仅作为其派生类的一个接口。这就是说仅想对基类进行向上类型转换，使用它的接口，而不希望用户实际地创建一个基类的对象。
	要做到这点，可以在基类中加入至少一个纯虚函数，来使基类成为抽象类。纯虚函数使用关键字virtual，并且在其后面加上=0。如果某人试着生成一个抽象类的对象，编译器会制止他，这个工具允许生成特定的设计。
当继承一个抽象类时，必须实现所有的纯虚函数，否则继承出的类也将是一个抽象类。创建个纯虚函数允许在接口中放置成员函数，而不一定要提供一段可能对这个函数毫无意义的代码。同时，纯虚函数要求出的类对它提供一个定义。纯虚函数总是变成“哑”函数。
建立公共接口，也就是纯虚函数抽象类。它能对于每个不同的子类有不同的表示，它建立一个基本的格式。
*/

#include <iostream>
using namespace std;

class Person
{
protected:
	string name;
	int age;
public:
	Person(string name, int age) :name(name), age(age) {}
	virtual ~Person() { cout << "调用了~Person()析构函数" << endl; }
	void virtual info() { cout << "Call Person info, Name=" << name << ", Age=" << age << endl; }
};
class Student :public Person
{
protected:
	double score;
public:
	Student(string name, int age, double score) :Person(name, age), score(score) {}
	~Student() { cout << "调用了~Student()析构函数" << endl; }
	void virtual info() { cout << "Call Student info, Name=" << name << ", Age=" << age << ", Score=" << score << endl; }
};

//———————抽象基类和纯虚函数———————
class AbstractDrinking
{
public:
	// 烧水
	virtual void Boil() = 0;
	// 泡
	virtual void Brow() = 0;
	// 倒入杯子
	virtual void PourInCup() = 0;
	// 辅料
	virtual void PutSomething() = 0;

	// 规定流程
	void MakeDrink() {
		Boil();
		Brow();
		PourInCup();
		PutSomething();
	}
};
class Coffee :public AbstractDrinking
{
public:
	// 烧水
	virtual void Boil() { cout << "煮白开水" << endl; };
	// 泡
	virtual void Brow() { cout << "泡咖啡" << endl; };
	// 倒入杯子
	virtual void PourInCup() { cout << "咖啡倒入杯子" << endl; };
	// 辅料
	virtual void PutSomething() { cout << "加牛奶" << endl; };
};
class Tea :public AbstractDrinking
{
public:
	// 烧水
	virtual void Boil() { cout << "煮山泉" << endl; };
	// 泡
	virtual void Brow() { cout << "泡茶" << endl; };
	// 倒入杯子
	virtual void PourInCup() { cout << "茶倒入杯子" << endl; };
	// 辅料
	virtual void PutSomething() { cout << "加盐" << endl; };
};

// 业务函数
void DoBusiness(AbstractDrinking* drink) {
	drink->MakeDrink();
	delete drink;
}

//————————————————————————————

int main()
{
	//Person* person = new Person("QQ", 17);
	//person->info();

	//Student* student = new Student("X", 15, 150);
	//student->info();

	//person = new Student("Y", 16, 151);
	//person->info();		// 如果没有虚函数，person只能调用基类方法；同名函数在基类和派生类中都声明为虚函数，就可以实现多态
	//person->Person::info();

	////———————引用实现多态———————
	//cout << "\n———————引用实现多态———————\n" << endl;

	//Person p1("小明", 11);
	//Student s1("小张", 12, 90);
	//Person& rPerson = p1;		// 和常量类似，引用的同时需要初始化
	//Person& rStudent = s1;
	//rPerson.info();
	//rStudent.info();				// 用基类引用调用派生类方法，引用实现多态

	//———————虚析构———————
	cout << "\n———————虚析构———————\n" << endl;

	Person* a1 = new Student("张三", 20, 90);
	a1->info();
	delete a1;		// 未声明虚析构时，delete a1 只会使用基类的析构函数，会导致派生类的部分成员对象没被释放

	//———————抽象基类和纯虚函数———————
	cout << "\n———————抽象基类和纯虚函数———————\n" << endl;

	DoBusiness(new Coffee);
	cout << endl;
	DoBusiness(new Tea);
}