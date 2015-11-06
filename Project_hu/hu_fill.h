#pragma once
/*
5 填充函数：
fill()	用一给定值，填充所有元素
fill_n()	用一给定值，填充前 n 个元素


*/


#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void hu_fill()
{

	int a[5];
	fill(a, a + 5, 1);//填充数组全部为1
	copy(a, a + 5, ostream_iterator<int>(cout, "\t"));
	cout << endl;


	vector<int>v(5);//填充容器向量全部为1
	fill(v.begin(), v.end(), 10);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;

	vector<int>vv;
	fill_n(back_inserter(vv), 5, 20);//填充向量容器前5个元素 全部为20
	//fill_n(vv.begin(), 5, 22);//等价填充
	copy(vv.begin(), vv.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
}
