#include<iostream>
using namespace std;
#include<string>

#include"MyArray.hpp"
#include"cat.hpp"

void printIntArray(MyArray<int> &arr1) {
	for (int i = 0; i < arr1.get_size(); i++) {
		cout << arr1[i] << endl;
	}
}

void printCatArray(MyArray<Cat<string, int>> &arr) {
	for (int i = 0; i < arr.get_size(); i++) {
		arr[i].showCat();
	}
}


void test51() {
	MyArray<int>arr1(5);
	MyArray<int>arr2(arr1);
	MyArray<int>arr3(100);
	arr3 = arr1;
}

void test52() {
	MyArray<int>arr1(5);
	for (int i = 0; i < 5; i++) {
		arr1.pushBack(i);
	}
	printIntArray(arr1);

	cout << arr1.getCapacity() << endl;
	cout << arr1.get_size() << endl;

	MyArray<int>arr2(arr1);
	//尾删除
	cout << arr2.get_size() << endl;
	arr2.pop_back();
	cout << arr2.getCapacity() << endl;
	cout << arr2.get_size() << endl;

}

//void test53() {
//	MyArray<Cat<string, int>> arr(10);
//	Cat<string, int> c1("nico1", 1);
//	Cat<string, int> c2("nico2", 2);
//	Cat<string, int> c3("nico3", 5);
//
//	//数据插入
//	arr.pushBack(c1);
//	arr.pushBack(c2);
//	arr.pushBack(c3);
//
//	printCatArray(arr);
//	cout << arr.getCapacity() << endl;
//	cout << arr.get_size() << endl;
//
//}

int mfun5() {
	test51();
	test52();
	//test53();

	system("pause");
	return 0;
}