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

	//尾插法
	void pushBack(const T &val) {
		//判读容量
		if (this->m_Capacity == this->size) {
			return;
		}
		this->pAddress[this->size] = val;//数组末尾加入数据
		this->size++;//更新大小
	}

	//尾删除
	void pop_back() {
		//不能访问即可
		if (this->size == 0) {
			return;
		}
		this->size--;
	}

	//通过下标访问数组元素 重载【】
	T& operator[](int index) {//返回T& 可以作为左值进行引用
		return this->pAddress[index];
	}

	int getCapacity() {
		return this->m_Capacity;
	}

	int get_size() {
		return this->size;
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