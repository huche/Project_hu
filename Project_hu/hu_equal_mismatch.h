#pragma once

/*
比较函数：
equal() 两个序列中的对立元素都相同时为真

mismatch() 找出两个序列相异的第一个元素

*/

//示例分析
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void hu_equal_mismatch()
{
	//比较两个数组元素
	int a[] = { 1,2,3,4 };
	int b[] = { 1,2,4,5 };
	int c[] = { 1,2,3,4 };

	const int N = sizeof(a) / sizeof(int);
	cout << "数组a:";
	for (size_t i = 0; i < N; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
	cout << "数组b:";
	for (size_t i = 0; i < N; i++)
	{
		cout << b[i] << "\t";
	}
	cout << endl;
	cout << "数组c:";
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
		cout << "数组a b 相等" << endl;
	}
	else
	{
		cout << "数组a b不等" << endl;
	}

	if (markc)
	{
		cout << "数组a c 相等" << endl;
	}
	else
	{
		cout << "数组a c 不等" << endl;
	}


	//mismatch()测试
	pair<int*, int*>result = mismatch(a, a + N, b);
	cout << "第一个不等 的位置：" << result.first - a << endl;
	cout << "相异元素值为：" << *(result.first)<<"  "<< *(result.second) << endl;
}

//容器 类 测试
//查询第一对 成绩不等学生的信息

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
	 
	student s1(1001, "张三", 80);
	student s2(1002, "李四", 67);
	student s3(1003, "王五", 90);
	student s4(1004, "赵六", 83);


	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);
	for (size_t i = 0; i < v.size(); i++)
	{//输出显示信息
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
	{//输出显示信息
		cout << v2[i].No << "\t" << v2[i].Name << "\t" << v2[i].grade << endl;
	}

	/*cout << "查询第一对成绩不等的学生信息：" << endl;
	pair<student *, student *>result = mismatch(v.begin(), v.end(), v2.begin());//出现异常，思考ing...

	student& stu1 = *result.first;
	student& stu2 = *result.second;

	cout << "学号：" << stu1.No << "\t" << "姓名：" << stu1.Name << "\t" <<"成绩："<< stu1.grade << endl;
	cout << "学号：" << stu2.No << "\t" << "姓名：" << stu2.Name << "\t" << "成绩：" << stu2.grade << endl;
*/


}