#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void show_3times(int n)
{
	cout << n * 3 << " ";
}

void hu_fun()
{
	const int VSIZE = 8;
	vector<int> num(VSIZE);
	vector<int>::iterator start, end, it;
	for (int i = 0; i < VSIZE; i++)
	{
		num[i] = i + 1;
	}

	start = num.begin();
	end = num.end();
	cout << "Num:" <<endl;
	for (it = start; it != end; it++)
	{
		cout << *it << " ";
	}

	cout << endl;
	for_each(start, end, show_3times);
	//for_each(参数1 ：数组或输入迭代器类,参数2 ：数组或输入迭代器类,参数3 ：函数名)
	//（向量）容器 vector num[start,end)之间的每个元素，作为函数show_3times(int n) 的参数传入并执行
	cout << endl;

	cout << "数组：";
	int arr[] = { 2,3,4,5,6,7,8 };
	for (int i = 0; i < 7; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;

	for_each(arr, arr + 7, show_3times);
}