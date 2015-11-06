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
	//for_each(����1 ������������������,����2 ������������������,����3 ��������)
	//������������ vector num[start,end)֮���ÿ��Ԫ�أ���Ϊ����show_3times(int n) �Ĳ������벢ִ��
	cout << endl;

	cout << "���飺";
	int arr[] = { 2,3,4,5,6,7,8 };
	for (int i = 0; i < 7; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;

	for_each(arr, arr + 7, show_3times);
}