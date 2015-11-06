#pragma once
/*
8 去重函数：
unique()	删除相邻的重复元素
unique_copy()	复制序列时，删除相邻的重复元素
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
	vector<int>::iterator last = unique(v.begin(), v.end());//只删除相邻重复元素
	cout << "unique后原向量" << endl;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	cout << "有效数据：" << endl;
	copy(v.begin(), last, ostream_iterator<int>(cout, "\t"));
	cout << endl;


	//vector<int>vv;
	//unique_copy(v.begin(), v.end(), back_inserter(vv));
	//copy(vv.begin(), vv.end(), ostream_iterator<int>(cout, "\t"));

}

//文本存放单词，已排好序，统计单词个数
bool strCompare(string s1, string s2)
{
	bool f = false;
	int value = stricmp(s1.c_str(), s2.c_str());//忽略大小写
	if (value==0)
	{
		f = true;//相等
	}
	return f;
}
void hu_unique_copy()
{
	ifstream out("word_num.txt");
	vector<string>v;//读取文本文件，按字符串
	copy(istream_iterator<string>(out), istream_iterator<string>(), back_inserter(v));
	cout << endl;
	cout << "文本中有单词：" << endl;
	copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\t"));
	cout << endl;

	vector<string>vv;
	cout << "文本中除去重复单词后：" << endl;
	unique_copy(v.begin(), v.end(), back_inserter(vv), strCompare);
	copy(vv.begin(), vv.end(), ostream_iterator<string>(cout, "\t"));
	cout<<endl;
}