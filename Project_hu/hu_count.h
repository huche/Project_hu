#pragma once
/*
计数 主要函数：
STL 主要提供了一下查询函数：

count() 在序列中统计某个值出现的次数
count_if() 在序列中统计与某谓词（表达式）匹配的次数
*/

#include <iostream>
#include<algorithm>
#include <vector>
#include <string>
using namespace std;
//count()函数 示例分析
void hu_count()
{
	int a[] = { 1,2,3,0,7,5,4,0,0,0,3,5,6,4,3,5,0,5,4 };
	const int N = sizeof(a) / sizeof(int);
	cout << "数组中0 的个数：" << count(a, a + N, 0) << endl;
}

//查询有多少学生成绩 大于 80 分
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
	student s1(1001, "张三", 80);
	student s2(1002, "李四", 67);
	student s3(1003, "王五", 90);
	student s4(1004, "赵六", 83);

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
	cout << "学生成绩大于70的人数为：" << N << endl;
}


//count_if() 函数测试

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
		return s.grade < grade;//测试 count_if()函数，返回分数小于某数值的学生个数
	}
};

void hu_count_if_stu()
{
	student s1(1001, "张三", 60);
	student s2(1002, "李四", 67);
	student s3(1003, "王五", 90);
	student s4(1004, "赵六", 83);

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
	cout << "学生成绩小于70的人数为：" << N << endl;
}