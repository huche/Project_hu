#pragma once
/*
8 ȥ�غ�����
unique()	ɾ�����ڵ��ظ�Ԫ��
unique_copy()	��������ʱ��ɾ�����ڵ��ظ�Ԫ��
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
using namespace std;

void hu_unique()
{
	int a[] = { 1,2,2,2,3,4,3,4,2,5 };
	int Len = sizeof(a) / sizeof(int);
	copy(a, a + Len, ostream_iterator<int>(cout, "\t"));
	cout << endl;
	vector<int>v(a, a + Len);
	vector<int>::iterator last = unique(v.begin(), v.end());//ֻɾ�������ظ�Ԫ��
	cout << "unique��ԭ����" << endl;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	cout << "��Ч���ݣ�" << endl;
	copy(v.begin(), last, ostream_iterator<int>(cout, "\t"));
	cout << endl;


	//vector<int>vv;
	//unique_copy(v.begin(), v.end(), back_inserter(vv));
	//copy(vv.begin(), vv.end(), ostream_iterator<int>(cout, "\t"));

}

//�ı���ŵ��ʣ����ź���ͳ�Ƶ��ʸ���
bool strCompare(string s1, string s2)
{
	bool f = false;
	int value = stricmp(s1.c_str(), s2.c_str());//���Դ�Сд
	if (value==0)
	{
		f = true;//���
	}
	return f;
}
void hu_unique_copy()
{
	ifstream out("word_num.txt");
	vector<string>v;//��ȡ�ı��ļ������ַ���
	copy(istream_iterator<string>(out), istream_iterator<string>(), back_inserter(v));
	cout << endl;
	cout << "�ı����е��ʣ�" << endl;
	copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\t"));
	cout << endl;

	vector<string>vv;
	cout << "�ı��г�ȥ�ظ����ʺ�" << endl;
	unique_copy(v.begin(), v.end(), back_inserter(vv), strCompare);
	copy(vv.begin(), vv.end(), ostream_iterator<string>(cout, "\t"));
	cout<<endl;
}