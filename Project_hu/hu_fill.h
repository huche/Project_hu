#pragma once
/*
5 ��亯����
fill()	��һ����ֵ���������Ԫ��
fill_n()	��һ����ֵ�����ǰ n ��Ԫ��


*/


#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void hu_fill()
{

	int a[5];
	fill(a, a + 5, 1);//�������ȫ��Ϊ1
	copy(a, a + 5, ostream_iterator<int>(cout, "\t"));
	cout << endl;


	vector<int>v(5);//�����������ȫ��Ϊ1
	fill(v.begin(), v.end(), 10);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;

	vector<int>vv;
	fill_n(back_inserter(vv), 5, 20);//�����������ǰ5��Ԫ�� ȫ��Ϊ20
	//fill_n(vv.begin(), 5, 22);//�ȼ����
	copy(vv.begin(), vv.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
}
