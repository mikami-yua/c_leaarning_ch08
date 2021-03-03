#include<iostream>
using namespace std;
#include<string>
#include"MyArray.hpp"

void test51() {
	MyArray<int>arr1(5);
	MyArray<int>arr2(arr1);
	MyArray<int>arr3(100);
	arr3 = arr1;
}

int main() {
	test51();

	system("pause");
	return 0;
}