#pragma once
//�任���� 
/*
����ԭ�ͣ�
template<class InIt,class OutIt,class Unop>
OutIt transform(InIt first,InIt last,OutIt x,Unop uop)

template<class InIt,class OutIt,class Binop>
OutIt transform(InIt first,InIt last,Init2 first2,OutIt x,Binop uop);

InIt ���������
OutIt ���������
Unop һԪ����
Binop ��Ԫ����
transform

*/
//��ĳ����Ӧ����ָ����Χ��ÿ��Ԫ��

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
	cout << "ԭʼ���� v:" << endl;
	for (size_t i = 0; i < v1.size(); i++)
	{
		//���vector ��ʽ1
		cout << v1[i] << "\t";
	}
	cout << endl;
	//���vector ��ʽ2
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;

	cout << "v1 ����һԪ���������޸��Լ�" << endl;
	transform(v1.begin(), v1.end(), v1.begin(), fun1);
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	transform(v1.begin(), v1.end(), v2.begin(), fun1);//����һԪ��������v2 ��ֵ

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
	//a2 b2 ���� ��Ԫ����fun2�������ֵ�� ����c2
	transform(a2, a2 + 3, b2, c2, fun2);
	cout << "c2[3]=" << endl;
	copy(c2, c2 + 3, ostream_iterator<int>(cout, "\t"));
}

//�ַ����������
template<class T>
class hustr
{

};

//ģ���ػ�
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
			*it = *it + 1;//�����㷨����Ӧ�ַ��� ASSCII ��1
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
	transform(v.begin(), v.end(), back_inserter(sr), hustr<string>());//back_inserter(sr)��巽ʽ�������sr
	//����ת��
	copy(sr.begin(), sr.end(), ostream_iterator<string>(cout, "\n"));
}
