#include<iostream>
using namespace std;
#include<string>

//解决方式1.直接包含cpp源文件
/*
包含.h时并不能生成函数，cpp中的代码编译器因为不知道类型从来没有见识过
直接包含cpp，编译器能把所有该看的东西都看了一遍
*/
//#include"cat.cpp"

//解决方式2.将声明和实现卸载同一个文件中，并更改后缀名为hpp（hpp只是约定的名）-----------------【开发中常用】
#include"cat.hpp"

//类模板成员函数的类外实现
template<class NameType, class AgeType>
class Person {
public:
	Person(NameType name, AgeType age);
	/*{
		this->name = name;
		this->age = age;
	}*/

	void showPerson();
	/*{
		cout << "name: " << this->name << " ";
		cout << "age: " << this->age << endl;
	}*/

	NameType name;
	AgeType age;
};
//构造函数是的类外实现 需要加上模板的参数列表
template<class NameType, class AgeType>
Person<NameType, AgeType>::Person(NameType name, AgeType age) {
	this->name = name;
	this->age = age;
}
template<class NameType, class AgeType>
void Person<NameType, AgeType>::showPerson() {
	cout << "name: " << this->name << " ";
	cout << "age: " << this->age << endl;
}

void test41() {
	Person<string, int> p("tom", 50);
	p.showPerson();
}

/*
类模板分文件编写
类模板成员函数创建实在调用时创建，导致份文件编写连接不到
解决方式1.直接包含cpp源文件
解决方式2.将声明和实现卸载同一个文件中，并更改后缀名为hpp（hpp只是约定的名）
*/
void test42() {
	Cat<string, int> c("nico", 5);
	c.showCat();
}

/*
类模板与友元
全局函数类内实现：直接在类内声明友元-----------------------------【建议这样写】
全局函数类外实现：需要提前让编译器知道全局函数的存在
*/
template<class NameType, class AgeType>
class Dog;

//全局函数类外实现 提前让编译器知道全局函数的存在
template<class NameType, class AgeType>
void printDog2(Dog<NameType, AgeType> d) {
	cout << "name: " << d.name << endl;
	cout << "age: " << d.age << endl;
}

template<class NameType, class AgeType>
class Dog {//通过全局函数打印dog的信息
	//全局函数类内实现
	friend void printDog(Dog<NameType, AgeType> d) {
		cout << "name: " << d.name << endl;
		cout << "age: " << d.age << endl;
	}
	//全局函数是类外实现的话需要让编译器提前知道这个函数的存在
	friend void printDog2<>(Dog<NameType, AgeType> d);
public:
	Dog(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}
private:
	NameType name;
	AgeType age;
};

//全局函数在类内的实现
void test43() {
	Dog<string, int> d("wang", 3);
	printDog(d);
}


void test44() {
	Dog<string, int> d("wang2", 3);
	printDog2(d);
}


int mfun4() {
	test41();
	test42();
	test43();
	test44();

	system("pause");
	return 0;
}//179