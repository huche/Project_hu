#pragma once
/*
���� ��Ҫ������
STL ��Ҫ�ṩ��һ�²�ѯ������

count() ��������ͳ��ĳ��ֵ���ֵĴ���
count_if() ��������ͳ����ĳν�ʣ����ʽ��ƥ��Ĵ���
*/

#include <iostream>
#include<algorithm>
#include <vector>
#include <string>
using namespace std;
//count()���� ʾ������
void hu_count()
{
	int a[] = { 1,2,3,0,7,5,4,0,0,0,3,5,6,4,3,5,0,5,4 };
	const int N = sizeof(a) / sizeof(int);
	cout << "������0 �ĸ�����" << count(a, a + N, 0) << endl;
}

//��ѯ�ж���ѧ���ɼ� ���� 80 ��
class student
{
public:
	int No;
	string Name;
	int grade;

	student(int no, string name, int grade)
	{
		this->No = no;
		this->Name = name;
		this->grade = grade;
	}

	bool operator == (int grade)
	{
		return this->grade >= grade;
	}

	
};


void hu_count_student()
{
	student s1(1001, "����", 80);
	student s2(1002, "����", 67);
	student s3(1003, "����", 90);
	student s4(1004, "����", 83);

	vector<student>v;
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i].No<<"\t"<< v[i].Name <<"\t"<<v[i].grade<< endl;
	}

	int N = count(v.begin(), v.end(), 70);
	cout << "ѧ���ɼ�����70������Ϊ��" << N << endl;
}


//count_if() ��������

class stuCompare
{
	int grade;
public:
	stuCompare(int g)
	{
		this->grade = g;
	}

	bool operator () (student & s)
	{
		return s.grade < grade;//���� count_if()���������ط���С��ĳ��ֵ��ѧ������
	}
};

void hu_count_if_stu()
{
	student s1(1001, "����", 60);
	student s2(1002, "����", 67);
	student s3(1003, "����", 90);
	student s4(1004, "����", 83);

	vector<student>v;
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i].No << "\t" << v[i].Name << "\t" << v[i].grade << endl;
	}

	int N = count_if(v.begin(), v.end(), stuCompare(80));
	cout << "ѧ���ɼ�С��70������Ϊ��" << N << endl;
}