#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>
using namespace std;

void hu_copy()
{

	int a[7] = { 1,2,3,4,5,6,7 };
	int b[7];
	vector<int>v;

	copy(a, a + 7, b);//数组复制数组
	copy(a, a + 7, back_inserter(v));//数组元素复制到 向量容器中

	cout << "原始数组a：" << endl;
	copy(a, a + 7, ostream_iterator<int>(cout, "\t"));//复制数组元素到屏幕输出
	cout << endl;
	cout << "数组b：" << endl;
	copy(b, b + 7, ostream_iterator<int>(cout, "\t"));//复制数组元素到屏幕输出
	cout << endl;

	cout << "向量v：" << endl;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));//复制向量容器元素元素到屏幕输出
	cout << endl;


	//把键盘输入的数据存放到 vector对象中
	vector<int>vi;
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(vi));
	copy(vi.begin(), vi.end(), ostream_iterator<int>(cout, "\t"));//复制向量容器元素元素到屏幕输出

}