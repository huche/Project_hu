#pragma once
//变换函数 
/*
函数原型：
template<class InIt,class OutIt,class Unop>
OutIt transform(InIt first,InIt last,OutIt x,Unop uop)

template<class InIt,class OutIt,class Binop>
OutIt transform(InIt first,InIt last,Init2 first2,OutIt x,Binop uop);

InIt 输入迭代器
OutIt 输出迭代器
Unop 一元函数
Binop 二元函数
transform

*/
//将某操作应用于指定范围的每个元素

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#include <fstream>
#include <functional>
#include <string>
using namespace std;

int fun1(int value)
{
	return value * 2;
}

int fun2(int v1, int v2)
{
	return v1 + v2;
}

void hu_transform()
{
	int a[3] = { 1,2,3 };
	vector<int>v1(a,a+3);
	vector<int>v2(3);
	cout << "原始向量 v:" << endl;
	for (size_t i = 0; i < v1.size(); i++)
	{
		//输出vector 方式1
		cout << v1[i] << "\t";
	}
	cout << endl;
	//输出vector 方式2
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;

	cout << "v1 调用一元函数，并修改自己" << endl;
	transform(v1.begin(), v1.end(), v1.begin(), fun1);
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	transform(v1.begin(), v1.end(), v2.begin(), fun1);//调用一元函数，给v2 赋值

	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;

	int a2[3] = { 4,5,3 };
	int b2[3] = { 9,4,6 };
	int c2[3];
	cout << "a2[3]="<<endl;
	copy(a2, a2 + 3, ostream_iterator<int>(cout, "\t"));
	cout << endl;
	cout << "b2[3]="<<endl;
	copy(b2, b2 + 3, ostream_iterator<int>(cout, "\t"));
	cout << endl;
	//a2 b2 调用 二元函数fun2，结果赋值给 数组c2
	transform(a2, a2 + 3, b2, c2, fun2);
	cout << "c2[3]=" << endl;
	copy(c2, c2 + 3, ostream_iterator<int>(cout, "\t"));
}

//字符串加密输出
template<class T>
class hustr
{

};

//模板特化
template<>
class hustr<string>
{
public:
	string operator()(const string& src)
	{
		string s = src;
		int len = s.length();
		for (string::iterator  it = s.begin(); it != s.end(); it++)
		{
			*it = *it + 1;//加密算法，对应字符串 ASSCII 加1
		}
		return s;
	}
};

void hu_strPass()
{
	string s;
	vector<string>v;
	vector<string>sr;
	ifstream in("datastr.txt");
	while (!in.eof())
	{
		getline(in, s, '\n');
		v.push_back(s);

	}

	in.close();
	transform(v.begin(), v.end(), back_inserter(sr), hustr<string>());//back_inserter(sr)后插方式填充容器sr
	//加密转换
	copy(sr.begin(), sr.end(), ostream_iterator<string>(cout, "\n"));
}
