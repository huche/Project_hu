#pragma once

/*
�ȽϺ�����
equal() ���������еĶ���Ԫ�ض���ͬʱΪ��

mismatch() �ҳ�������������ĵ�һ��Ԫ��

*/

//ʾ������
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void hu_equal_mismatch()
{
	//�Ƚ���������Ԫ��
	int a[] = { 1,2,3,4 };
	int b[] = { 1,2,4,5 };
	int c[] = { 1,2,3,4 };

	const int N = sizeof(a) / sizeof(int);
	cout << "����a:";
	for (size_t i = 0; i < N; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
	cout << "����b:";
	for (size_t i = 0; i < N; i++)
	{
		cout << b[i] << "\t";
	}
	cout << endl;
	cout << "����c:";
	for (size_t i = 0; i < N; i++)
	{
		cout << c[i] << "\t";
	}
	cout << endl;
	bool markb,markc;
	markb = equal(a, a + N, b);
	markc = equal(a, a + N, c);

	if (markb)
	{
		cout << "����a b ���" << endl;
	}
	else
	{
		cout << "����a b����" << endl;
	}

	if (markc)
	{
		cout << "����a c ���" << endl;
	}
	else
	{
		cout << "����a c ����" << endl;
	}


	//mismatch()����
	pair<int*, int*>result = mismatch(a, a + N, b);
	cout << "��һ������ ��λ�ã�" << result.first - a << endl;
	cout << "����Ԫ��ֵΪ��" << *(result.first)<<"  "<< *(result.second) << endl;
}

//���� �� ����
//��ѯ��һ�� �ɼ�����ѧ������Ϣ

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

	bool operator == (student & s)
	{
		return this->grade == s.grade;
	}
};

void hu_student_mismatch()
{
	vector<student>v;
	 
	student s1(1001, "����", 80);
	student s2(1002, "����", 67);
	student s3(1003, "����", 90);
	student s4(1004, "����", 83);


	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);
	for (size_t i = 0; i < v.size(); i++)
	{//�����ʾ��Ϣ
		cout << v[i].No << "\t" << v[i].Name << "\t" << v[i].grade << endl;
	}

	vector<student>v2;

	student ss1(1001, "Tom", 80);
	student ss2(1002, "Smith", 57);
	student ss3(1003, "Job", 92);
	student ss4(1004, "Suny", 83);


	v2.push_back(ss1);
	v2.push_back(ss2);
	v2.push_back(ss3);
	v2.push_back(ss4);
	for (size_t i = 0; i < v.size(); i++)
	{//�����ʾ��Ϣ
		cout << v2[i].No << "\t" << v2[i].Name << "\t" << v2[i].grade << endl;
	}

	/*cout << "��ѯ��һ�Գɼ����ȵ�ѧ����Ϣ��" << endl;
	pair<student *, student *>result = mismatch(v.begin(), v.end(), v2.begin());//�����쳣��˼��ing...

	student& stu1 = *result.first;
	student& stu2 = *result.second;

	cout << "ѧ�ţ�" << stu1.No << "\t" << "������" << stu1.Name << "\t" <<"�ɼ���"<< stu1.grade << endl;
	cout << "ѧ�ţ�" << stu2.No << "\t" << "������" << stu2.Name << "\t" << "�ɼ���" << stu2.grade << endl;
*/


}