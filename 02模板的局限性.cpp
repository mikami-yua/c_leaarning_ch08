#include<iostream>
using namespace std;
#include<string>
//模板的局限性，有些特定是数据类型需要特殊的实现

class Person {
public:
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
private:
	
};


template<class T>
bool myCompare(T& a, T& b) {
	if (a == b) {
		return true;
	}
	else
	{
		printf("not equal\n");
		return false;
	}
}
//提供具体化的person，会优先调用
template<> bool myCompare(Person &a, Person& b) {
	if (a.name == b.name && a.age == b.age) {
		cout << "equal" << endl;
		return true;
	}
	else {
		return false;
	}
}

void test11() {
	int a = 10;
	int b = 20;
	bool ret = myCompare(a, b);
	cout <<ret << endl;
}

void test12() {
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	cout << myCompare(p1, p2) << endl;//1
}

int mfun2() {
	test11();
	test12();
	system("pause");
	return 0;
}