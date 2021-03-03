#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray {
public:
	/*
	@capacity:容量
	*/
	MyArray(int capacity) {
		cout << "constration used" << endl;
		this->m_Capacity = capacity;
		this->size = 0;
		this->pAddress = new T[this->m_Capacity];//开辟堆区
	}

	//拷贝构造------深拷贝
	MyArray(const MyArray& arr) {
		cout << "copying constration used" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->size = arr.size;
		//this->pAddress = arr.pAddress;潜拷贝导致堆区重复释放
		//深拷贝
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator=防止浅拷贝
	MyArray& operator=(const MyArray& arr) {
		cout << "= used" << endl;
		//判断堆区是否有数据
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->size = 0;
		}
		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->size = arr.size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	~MyArray() {
		
		if (this->pAddress != NULL) {
			cout << "unconstration used" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	T* pAddress;//指针指向堆区开辟的真实数组
	int m_Capacity;
	int size;
};