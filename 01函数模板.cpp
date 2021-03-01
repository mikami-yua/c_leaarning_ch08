#include<iostream>
using namespace std;




//实现两个整型交换的函数
void swapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//实现两个浮点型交换的函数
void swapDouble(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}

//函数模板
template<typename T>//声明一个模板，告诉编译器后面代码紧跟的T不要报错，T是通用数据类型
void mySway(T &a,T &b) {
	T temp = a;
	a = b;
	b = temp;
}


//利用函数模板实现对不同数据类型数组的排序（规则从大到小，选择排序）
template<class T>
void mySort(T arr[],int len) {
	for (int i = 0; i < len; i++) {
		int max = i;//认定最大值的下标
		for (int j = i + 1; j < len; j++) {
			if (arr[max] < arr[j]) {//认定的最大值比遍历的要小，说明j才是最大值
				max = j;
			}
		}//没轮都找出一个最大值
		if (max != i) {
			//交换元素
			mySway(arr[max], arr[i]);
		}
	}
}

template<class T>
void printArray(T arr[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01() {
	char c_array[] = "jfhsiaks";
	mySort(c_array, size(c_array));
	printArray(c_array, size(c_array));
	int int_array[] = { 7,8,2,5,3,9,2,6,8,9,3 };
	mySort(int_array, size(int_array));
	printArray(int_array, size(int_array));
}



//自动类型转换：char的ASCII码和int的对应
int add01(int a, int b) {
	return a + b;
}

template<class T>
T add02(T a, T b) {
	return a + b;
}

void test02() {
	int a=10;
	char c = 'c';
	cout << add01(a, c) << endl;//109  转换成立ASCII码运算
	cout << add02<int>(a, c) << endl;//显示指定类型可以使用自动类型转换
}

//普通函数和函数模板的调用规则
void myPrint(int a, int b) {
	cout << "use common function" << endl;
}
template<class T>
void myPrint(T a, T b) {
	cout << "use template function" << endl;
}

template<class T>
void myPrint(T a, T b,T c) {
	cout << "use reload template function" << endl;
}

void test03() {
	int a = 10;
	int b = 20;
	int c = 100;
	myPrint(a,b);//use common function
	//通过空模板参数列表前置调用
	myPrint<>(a, b);//use template function
	myPrint(a, b, c);//use reload template function
	//函数模板产生更好的匹配优先使用函数模板
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);//use template function 这里的好对编译器意味着不用发生隐式类型转换

}

int mfun1() {

	int a = 10;
	int b = 20;
	swapInt(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	double c = 1.1;
	double d = 1.2;
	swapDouble(c, d);
	cout << "c=" << c << endl;
	cout << "d=" << d << endl;

	//函数模板两种方式
	//1.自动类型推导,必须能推导出一致的数据类型T，模板必须确定除T的数据类型才能使用（没有用到T，在没有确定T类型是可以使用显示数据类型，直接指定任意类型即可）
	mySway(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	//2.显示指定类型,可以发生自动类型转换
	mySway<double>(c, d);
	cout << "c=" << c << endl;
	cout << "d=" << d << endl;

	//测试
	test01();

	test02();

	test03();
	system("pause");
	return 0;
}