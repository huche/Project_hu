#pragma once

/*
��֪ѧ���������ԣ�ѧ�ţ����ͣ��ؼ��֣����������ɼ���
��Ҫ���д��صĹ����࣬�����ѧ�����󣬲��������²�ѯ���ܣ�
	1 ��ѧ�Ų�ѯ
	2 ��һ��ѧ�Ų�ѯ ��[1001,1003,1006]
	3 ��ѧ��������ѯ
	4 ���ɼ���ѯ
	5 ���ɼ���Χ��ѯ (60,90)
��д�򵥵Ĳ�������Բ��ԣ�
������
1 ���˼�룺��ȡ���ࡢ������Ʒ������ڼ������н�����ӡ���ѯ����
2 ��ѧ�Ų�ѯ find() �ؼ���
3 ��ѧ�Ų�ѯ find_first_of() ����һ��ֻ�ܲ�ѯһ��ѧ�ŵ�ѧ����Ϣ�����Ҫ��ѭ���ṹ
4 ������ѯ find() �����������ǹؼ��֣����Ҫ��ѭ���ṹ
5 �ɼ���ѯ find() ���ڳɼ����ǹؼ��֣����Ҫ��ѭ���ṹ
6 �ɼ���Χ��ѯ find_first_of() ҲҪ��ѭ���ṹ
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
using namespace std;

const int NO_find = 1;//ѧ�Ų�ѯ���
const int Grade_find = 2;//������ѯ���  �������������������ѧ�Ż��Ƿ���

class student
{
public:
	int no;
	string name;
	int grade;
	static int mark;//��ѯ���


	student(int sno, string sname, int sgrade)
	{
		no = sno;
		name = sname;
		grade = sgrade;
	}

	bool operator == (int n)
	{
		//����ѧ�Ż�ɼ���ѯ
		if (mark==NO_find)
		{
			//ѧ�Ų�ѯ
			return no == n;
		}
		else
		{//������ѯ
			return grade == n;
		}
	}

	bool operator == (string s)
	{
		//����������ѯ
		return name.compare(s) == 0;//���������ͬ������true������false

	}
};
int student::mark = -1;//��ʼ��mark

//����cout<< ������� student ������������
ostream & operator << (ostream & os, student & s)
{
	os << s.no << "\t" << s.name << "\t" << s.grade << endl;
	return os;
}


class stuFindIf
{
	//����find_if��������
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
	//ѧ��������
	vector<student>vs;
public:
	bool add(student & s)
	{
		vs.push_back(s);//���ѧ����Ϣ
		return true;
	}


	bool findByNo(int n)//����ѧ�Ų�ѯ
	{
		student::mark = NO_find;
		vector<student>::iterator it = find(vs.begin(), vs.end(), n);
		if (it!=vs.end())
		{
			cout << *it << endl;
		}
		else
		{
			cout << "ѧ�ţ�" << n << "û�м�¼..." << endl;
		}
		return true;
	}

	bool findByNo(int n[], int size)//����ѧ�������ѯ
	{
		bool bfind = false;
		student::mark = NO_find;
		vector<student>::iterator it = find_first_of(vs.begin(), vs.end(), n, n + size);
		while (it!=vs.end())
		{
			bfind = true;
			cout << *it << endl;
			it++;
			it = find_first_of(it, vs.end(), n, n + size);//ѭ����ѯ

		}
		if (!bfind)
		{
			//û����ؼ�¼
			cout << "û����ؼ�¼" << endl;
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
			it = find(it, vs.end(), s);//ѭ����ѯ,��Ϊ�������ǹؼ��֣������ظ���¼

		}
		if (!bfind)
		{
			//û����ؼ�¼
			cout << "û����ؼ�¼" << endl;
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
			it = find(it, vs.end(), n);//ѭ����ѯ

		}
		if (!bfind)
		{
			//û����ؼ�¼
			cout << "û����سɼ���¼" <<n<< endl;
		}

		return true;
	}



	bool findByGradeRange(int min, int max)
	{
		//���ճɼ���Χ��ѯ
		bool bfind = false;
		stuFindIf sf(min, max);//ȷ����ѯ��Χ
		vector<student>::iterator it = find_if(vs.begin(), vs.end(), sf);//��ѧ�������б���ִ�к��� sf(min,max) ��ѯ����������ѧ��
		while (it != vs.end())
		{
			bfind = true;
			cout << *it << endl;
			it++;
			it = find_if(it, vs.end(), sf);//ѭ����ѯ

		}
		if (!bfind)
		{
			//û����ؼ�¼
			cout << "û����ؼ�¼" << endl;
		}

		return true;
	}

};


//����Ժ���
void hu_student_find()
{
	student s1(1001, "������", 70);
	student s2(1002, "�½���", 32);
	student s3(1003, "Τ����", 90);
	student s4(1004, "������", 87);
	student s5(1005, "����Ƽ", 54);
	student s6(1006, "¬����", 78);

	stuManage sm;
	sm.add(s1);
	sm.add(s2);
	sm.add(s3);
	sm.add(s4);
	sm.add(s5);
	sm.add(s6);

	cout << "��ѧ�Ų�ѯ(100X)��" << endl;
	int no;
	cin >> no;
	sm.findByNo(no);

	
	cout << "���ɼ���ѯ��" << endl;
	int grade;
	cin >> grade;
	sm.findByGrade(grade);

	cout << "��������ѯ��" << endl;
	string name;
	cin >> name;
	sm.findByNmae(name);

	//cout << "���շ�����Χ��ѯ��" << endl;
	//int ml, mh;
	//cout << "�����ѯ������Χ (min max):";
	//cin >> ml >> mh;
	//sm.findByGradeRange(ml, mh);
	//cout << "����ѧ�����ѯ��" << endl;
	////vector<int>vg;
	//int gg[10];//��������ѧ������
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

	cout << "����ѧ���飺" << endl;
	vector<int>vgg;
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(vgg));//�����������ݸ��Ƶ���������

	int agg[10];
	copy(vgg.begin(), vgg.end(), agg);//����������Ԫ�ظ��Ƶ� ���� agg

	/*for (int i = 0; i < vgg.size(); i++)
	{
	//������飬������
		cout << agg[i] << "\t";
	}*/

	sm.findByNo(agg, vgg.size());

}
