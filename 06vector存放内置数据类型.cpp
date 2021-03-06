#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include "cppjieba/Jieba.hpp"


void myPrintVectotr(int val) {
	cout << val << endl;
}


//vector容器
void test61() {
	//创建一个vector数组
	vector<int> v;
	//向容器中插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	//通过迭代器访问容器中的数据
	//vector<int>::iterator itBegin = v.begin();//初始迭代器指向容器中的第一个元素 
	//vector<int>::iterator itEnd = v.end();//结束迭代器指向容器器中最后一个元素的下一个元素

	////遍历1
	//while (itBegin!=itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//遍历2，迭代器和循环写在一起
	/*for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}*/

	//遍历3 利用stl的遍历算法
	for_each(v.begin(), v.end(), myPrintVectotr);//只写函数名即可，不用写括号

}

//vector存放自定义数据类型
class Person6 {
public:
	Person6(string name, int age) {
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
private:

};
void test62() {
	vector<Person6> v;
	Person6 p1("aaa", 10);
	Person6 p2("bbb", 20);
	Person6 p3("ccc", 30);
	Person6 p4("ddd", 40);
	Person6 p5("eee", 50);
	Person6 p6("fff", 60);

	//像容器添加数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);

	//遍历
	for (vector<Person6>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "name:" << (*it).name << "  age:" << (*it).age << endl;
	}
}

//存放自定义数据类型的指针
void test63() {
	vector<Person6*> v;
	Person6 p1("aaa", 10);
	Person6 p2("bbb", 20);
	Person6 p3("ccc", 30);
	Person6 p4("ddd", 40);
	Person6 p5("eee", 50);
	Person6 p6("fff", 60);

	//像容器添加数据
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	v.push_back(&p6);
	//遍历
	for (vector<Person6*>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "name:" << (*it)->name << "  age:" << (*it)->age << endl;
	}
}

//vector嵌套vector
void test65() {
	vector<vector<int>> v;

	//创建小容器
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	//向小容器添加数据
	for (int i = 0; i < 4; i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}

	//小容器放到大容器
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	//通过大容器遍历所有数据
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		//(*it)就是容器
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
			cout << *vit << " ";
		}
		cout << endl;
	}
}

/*
使用结巴需要
拷贝include dept dict到项目目录
在项目属性的include中设置设置include dept

如果使用分词，如何防止客户端不规矩的分词（好像原来的版本也没有办法防止client不规矩的取token）
*/

void test66() {
	char ch0[] = { "我喜欢吃苹果和apple banana" };
	const char* const DICT_PATH = "dict/jieba.dict.utf8";
	const char* const HMM_PATH = "dict/hmm_model.utf8";
	const char* const USER_DICT_PATH = "dict/user.dict.utf8";
	const char* const IDF_PATH = "dict/idf.utf8";
	const char* const STOP_WORD_PATH = "dict/stop_words.utf8";
	cout << "加载dict" << endl;
	cppjieba::Jieba jieba(DICT_PATH,
		HMM_PATH,
		USER_DICT_PATH,
		IDF_PATH,
		STOP_WORD_PATH);
	vector<string> words;
	vector<cppjieba::Word> jiebawords;
	string s = ch0;
	string result;
	cout << "切分" << endl;
	jieba.Cut(s, words, true);
	

	for (vector<string>::iterator vit = words.begin(); vit != words.end(); vit++) {
		cout << *vit << " ";
	}

	//ofstream file("result.txt");
	//file << limonp::Join(words.begin(), words.end(), "/") << endl;
	//file.close();
}

int main() {
	//test61();
	//test62();
	//test63();
	//test65();
	test66();

	cout << "你好" << endl;

	system("pause");
	return 0;
}