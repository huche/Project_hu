#pragma once

/*
已知学生基本属性：学号（整型，关键字），姓名，成绩。
现要求编写相关的功能类，能添加学生对象，并具有以下查询功能：
	1 按学号查询
	2 按一组学号查询 ：[1001,1003,1006]
	3 按学生姓名查询
	4 按成绩查询
	5 按成绩范围查询 (60,90)
编写简单的测试类加以测试：
分析：
1 设计思想：采取简单类、集合设计方法，在集合类中进行添加、查询功能
2 单学号查询 find() 关键字
3 组学号查询 find_first_of() 由于一次只能查询一个学号的学生信息，因此要用循环结构
4 姓名查询 find() 由于姓名不是关键字，因此要用循环结构
5 成绩查询 find() 由于成绩不是关键字，因此要用循环结构
6 成绩范围查询 find_first_of() 也要用循环结构
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
using namespace std;

const int NO_find = 1;//学号查询标记
const int Grade_find = 2;//分数查询标记  用于区分输入的数字是学号还是分数

class student
{
public:
	int no;
	string name;
	int grade;
	static int mark;//查询标记


	student(int sno, string sname, int sgrade)
	{
		no = sno;
		name = sname;
		grade = sgrade;
	}

	bool operator == (int n)
	{
		//用于学号或成绩查询
		if (mark==NO_find)
		{
			//学号查询
			return no == n;
		}
		else
		{//分数查询
			return grade == n;
		}
	}

	bool operator == (string s)
	{
		//用于姓名查询
		return name.compare(s) == 0;//如果姓名相同，返回true，否则false

	}
};
int student::mark = -1;//初始化mark

//重载cout<< 用于输出 student 对象类型数据
ostream & operator << (ostream & os, student & s)
{
	os << s.no << "\t" << s.name << "\t" << s.grade << endl;
	return os;
}


class stuFindIf
{
	//用于find_if函数的类
private:
	int low, high;
public:
	stuFindIf(int l, int h)
	{
		low = l;
		high = h;
	}

	bool operator () (student & s)
	{
		return s.grade >= low && s.grade <= high;
	}
};


class stuManage
{
	//学生管理类
	vector<student>vs;
public:
	bool add(student & s)
	{
		vs.push_back(s);//添加学生信息
		return true;
	}


	bool findByNo(int n)//按照学号查询
	{
		student::mark = NO_find;
		vector<student>::iterator it = find(vs.begin(), vs.end(), n);
		if (it!=vs.end())
		{
			cout << *it << endl;
		}
		else
		{
			cout << "学号：" << n << "没有记录..." << endl;
		}
		return true;
	}

	bool findByNo(int n[], int size)//按照学号数组查询
	{
		bool bfind = false;
		student::mark = NO_find;
		vector<student>::iterator it = find_first_of(vs.begin(), vs.end(), n, n + size);
		while (it!=vs.end())
		{
			bfind = true;
			cout << *it << endl;
			it++;
			it = find_first_of(it, vs.end(), n, n + size);//循环查询

		}
		if (!bfind)
		{
			//没有相关记录
			cout << "没有相关记录" << endl;
		}

		return true;

	}


	bool findByNmae(string s)
	{
		bool bfind = false;
		vector<student>::iterator it = find(vs.begin(), vs.end(), s);
		while (it != vs.end())
		{
			bfind = true;
			cout << *it << endl;
			it++;
			it = find(it, vs.end(), s);//循环查询,因为姓名不是关键字，会有重复记录

		}
		if (!bfind)
		{
			//没有相关记录
			cout << "没有相关记录" << endl;
		}

		return true;
	}


	bool findByGrade(int n)
	{
		student::mark = Grade_find;

		bool bfind = false;
		vector<student>::iterator it = find(vs.begin(), vs.end(), n);
		while (it != vs.end())
		{
			bfind = true;
			cout << *it << endl;
			it++;
			it = find(it, vs.end(), n);//循环查询

		}
		if (!bfind)
		{
			//没有相关记录
			cout << "没有相关成绩记录" <<n<< endl;
		}

		return true;
	}



	bool findByGradeRange(int min, int max)
	{
		//按照成绩范围查询
		bool bfind = false;
		stuFindIf sf(min, max);//确定查询范围
		vector<student>::iterator it = find_if(vs.begin(), vs.end(), sf);//在学生集合中遍历执行函数 sf(min,max) 查询符合条件的学生
		while (it != vs.end())
		{
			bfind = true;
			cout << *it << endl;
			it++;
			it = find_if(it, vs.end(), sf);//循环查询

		}
		if (!bfind)
		{
			//没有相关记录
			cout << "没有相关记录" << endl;
		}

		return true;
	}

};


//类测试函数
void hu_student_find()
{
	student s1(1001, "张明宇", 70);
	student s2(1002, "陈讲清", 32);
	student s3(1003, "韦海鹏", 90);
	student s4(1004, "戴望舒", 87);
	student s5(1005, "高丽萍", 54);
	student s6(1006, "卢永生", 78);

	stuManage sm;
	sm.add(s1);
	sm.add(s2);
	sm.add(s3);
	sm.add(s4);
	sm.add(s5);
	sm.add(s6);

	cout << "按学号查询(100X)：" << endl;
	int no;
	cin >> no;
	sm.findByNo(no);

	
	cout << "按成绩查询：" << endl;
	int grade;
	cin >> grade;
	sm.findByGrade(grade);

	cout << "按姓名查询：" << endl;
	string name;
	cin >> name;
	sm.findByNmae(name);

	//cout << "按照分数范围查询：" << endl;
	//int ml, mh;
	//cout << "输入查询分数范围 (min max):";
	//cin >> ml >> mh;
	//sm.findByGradeRange(ml, mh);
	//cout << "按照学号组查询：" << endl;
	////vector<int>vg;
	//int gg[10];//接受输入学号数组
	//for (int i = 0; i < 10; i++)
	//{
	//	int m;
	//	cin >> m;
	//	if (cin.fail())
	//	{
	//		break;
	//	}
	//	gg[i] = m;
	//}
	//sm.findByNo(gg, (sizeof(gg) / sizeof(int)));

	cout << "输入学号组：" << endl;
	vector<int>vgg;
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(vgg));//将输入流数据复制到向量容器

	int agg[10];
	copy(vgg.begin(), vgg.end(), agg);//将向量容器元素复制到 数组 agg

	/*for (int i = 0; i < vgg.size(); i++)
	{
	//输出数组，测试用
		cout << agg[i] << "\t";
	}*/

	sm.findByNo(agg, vgg.size());

}
