#pragma once
//交换示例
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
using namespace std;

void hu_swap()
{
	int a = 10;
	int b = 43;
	cout << "原始数据：" << "a=" << a << "\tb=" << b << endl;
	swap(a, b);//交换两个数据
	cout << "交换之后数据：" << "a=" << a << "\tb=" << b << endl;


	int aa[3] = { 1,2,3 };
	int bb[3] = { 9,8,7 };
	cout << "原始数组：" << "aa[3]=" << endl;
	copy(aa, aa + 3, ostream_iterator<int>(cout,"\t"));
	cout << endl;
	cout << "原始数组 b[3]=" << endl;
	copy(bb, bb + 3, ostream_iterator<int>(cout, "\t"));
	cout << endl;

	//swap_ranges(aa, aa + 2, bb);//交换数组元素
	swap(aa,bb);//交换数组元素
	//iter_swap(&a,&b);

	cout << "交换后数组 aa[3]="<<endl;
	copy(aa, aa + 3, ostream_iterator<int>(cout, "\t"));
	cout << endl;
	cout << "交换后数组 bb[3]=" << endl;
	copy(bb, bb + 3, ostream_iterator<int>(cout, "\t"));
	cout << endl;


	vector<int>v1(aa, aa + 3);
	vector<int>v2(bb, bb + 3);
	cout << "原始向量 v1:" << endl;
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	cout << "原始向量v2：" << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	swap(v1, v2);//交换向量元素
	cout << "交换后向量 v1:" << endl;
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	cout << "交换后向量v2：" << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;



}