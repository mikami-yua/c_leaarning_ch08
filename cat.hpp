#pragma once
#include<iostream>
using namespace std;

template<class NameType, class AgeType>
class Cat {
public:
	Cat(NameType name, AgeType age);

	void showCat();
	
	NameType name;
	AgeType age;
};

template<class NameType, class AgeType>
Cat<NameType, AgeType>::Cat(NameType name, AgeType age) {
	this->name = name;
	this->age = age;
}
template<class NameType, class AgeType>
void Cat<NameType, AgeType>::showCat() {
	cout << "name: " << this->name << " ";
	cout << "age: " << this->age << endl;
}