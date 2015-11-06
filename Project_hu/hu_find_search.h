#pragma once
/*
查询操作是应用最广泛的操作，STL提供了一下查询函数：
find()	在单迭代器序列中找出 某个值 第一次出现的位置
find_if()	在单迭代器序列中找出符合 某谓词 的第一个元素
find_first_of()	在双迭代器序列中找出 一子序列中某元素 第一次出现的位置
adjacent_find()	在单迭代器序列中找出第一次 相邻值相等元素的位置
find_end()	在双迭代器序列中找出 一子序列  最后一次出现的位置
search()	在双迭代器序列中找出 一子序列  第一次出现的位置
search_n()	在单迭代器序列中找出 一个值连续n次出现的位置
*/
#include <iostream>
#include <algorithm>
using namespace std;
//示例分析


bool bigger(int m)
{
	return m > 4;
}

void hu_test()
{
	int a[] = { 1,2,2,3,3,4,5,5,6,1,2,2,2,5,5,6,2,3 };
	int len = sizeof(a) / sizeof(int);
	cout << "原始数组：";
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << "\t";
	}

	cout << endl;
	
	int* p1 = find(a, a + len, 6);
	if (p1!=(a+len))
	{
		cout << "（find）第一次等于6的位置：" << p1 - a << "\t值：" << *p1 << endl;

	}

	int* p2 = find_if(a, a + len, bigger);
	if (p2!=a+len)
	{
		cout << "（find_of）第一次大于4的位置：" << p2 - a << "\t值：" << *p2 << endl;

	}

	int b[] = { 12,3,21,5 };
	int lenb = sizeof(b) / sizeof(int);
	int* p3 = find_first_of(a, a + len, b, b + lenb);
	if (p3!=a+len)
	{
		cout << "（find_first_of）第一次在数组 a中发现b数组[12,3,21,5]中元素的位置：" << p3 - a << "\t值：" << *p3 << endl;

	}

	int* p4 = adjacent_find(a, a + len);
	if (p4!=a+len)
	{
		cout << "（adjacent_find）首次相邻元素位置：" << p4 - a << "\t值" << *p4 << endl;
	}

	int c[] = { 2,3 };
	int lenc = sizeof(c) / sizeof(int);
	int* p5 = find_end(a, a + len, c, c + lenc);
	if (p5 != a + len)
	{
		cout << "（find_end）数组 a中最后一次匹配数组c[2,3]中元素的位置：" << p5 - a << "\t值：" << *p5 << endl;

	}

	int* p6 = search(a, a + len, c, c + lenc);
	if (p6!=a+len)
	{
		cout<<"（search）数组 a中第一次匹配数组c[2,3]中元素的位置：" << p6 - a << "\t值：" << *p6 << endl;
	}

	int* p7 = search_n(a, a + len, 3, 2);
	if (p7 != a + len)
	{
		cout << "search_n数组a中第一次连续出现3个2的位置：" << p7 - a << endl;
	}
}