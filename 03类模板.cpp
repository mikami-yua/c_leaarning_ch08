#include<iostream>
using namespace std;
#include<string>

//类模板
template<class NameType,class AgeType=int>//类模板在模板参数列表中可以有默认参数
class Person {
public:
	Person(NameType name, AgeType age) {
		this->name = name;
		this->age = age;
	}

	void showPerson() {
		cout << "name: " << this->name << " ";
		cout << "age: " << this->age << endl;
	}

	void showPerson1() {
		cout << "show start" << endl;
	}

	NameType name;
	AgeType age;
};

class Person1 {
public:
	Person1(string name, int age) {
		this->name = name;
		this->age = age;
	}

	void showPerson() {
		cout << "name: " << this->name << " ";
		cout << "age: " << this->age << endl;
	}

	void showPerson1() {
		cout << "show start" << endl;
	}

	string name;
	int age;
};

void test31() {
	Person<string, int> p1("zhangsan", 98);
	p1.showPerson();
}

//类模板与函数模板的区别
//类模板不能自动类型推到(只能用显示指定类型)，类模板在模板参数列表中可以有默认参数
void test32() {
	Person<string> p2("lisi", 98);
	p2.showPerson();
	//类模板在模板参数列表中可以有默认参数  <class NameType,class AgeType>模板参数列表

}

//类模板中成员函数的创建时机---调用时创建(调用时知道类型)
void test33() {
	Person<string, int> p1("aaa", 10);
	Person1 p2("bbb", 12);
	//p1.showPerson1();
}

//类模板对象做函数参数【实际开发中1.方法最常用】
/*
1.指定传入的类型
2.参数模板化
3.整个类模板化
*/
//1.指定传入的类型-----把参数模板也写明白
void printPerson1(Person<string, int> &p) {
	p.showPerson();
}
//2.参数模板化
template<class NameType,class AgeType>
void printPerson2(Person<NameType, AgeType>& p) {
	p.showPerson();
	cout << "type of NameType:" << typeid(NameType).name() << endl;
}
//3.整个类模板化
template<class T>
void printPerson3(T &p) {
	p.showPerson();
	cout << "type of T:" << typeid(T).name() << endl;
}
void test34() {
	Person<string, int> p1("jjjjj", 10);
	printPerson1(p1);
	Person<string, int> p2("xxxxx", 10);
	printPerson2(p2);
	Person<string, int> p3("jx", 24);
	printPerson3(p3);
}

//类模板与继承
/*
子类在继承父类时，在子类声明时需要能确定父类的T类型，否则编译器无法给子类分配内存，想要灵魂指定父类中T的类型，子类也需要为类模板
*/
template<class T>
class Base {
	T m;
};
class Son :public Base<int> {//需要知道父类T的类型

};
void test35() {
	Son s1;
}

//想要灵魂指定父类中T的类型，子类也需要为类模板
template<class T1,class T2>
class Son2 :public Base<T1>{
public:
	Son2() {
		cout << "T1:" << typeid(T1).name() << endl;
		cout << "T2:" << typeid(T2).name() << endl;
	}
	T2 obj;
};
void test36() {
	Son2<int,char> s2;
}


int mfun3() {
	test31();
	test32();
	test33();
	test34();
	test35();
	test36();

	system("pause");
	return 0;
}//179