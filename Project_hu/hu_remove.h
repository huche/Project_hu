#pragma once
/*
7 删除函数：
remove()	删除所有指定的元素
remove_if()	删除满足条件的的元素
remove_copy()	复制序列时，删除指定的元素
remove_copy_if()	复制序列时，删除满足条件的元素
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

void hu_remove()
{
	int a[6] = { 1,2,3,3,4,2 };
	vector<int>v(a, a + 6);
	copy(a, a + 6, ostream_iterator<int>(cout, "\t"));
	cout << endl;

	vector<int>::iterator first = v.begin();
	vector<int>::iterator last;
	last = remove(v.begin(), v.end(), 2);//删除等于 2的元素,原来向量内存空间并没有变化,返回迭代器最后指针

	cout << "向量 v 删除元素2后" << endl;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	cout << "删除后有效数据：" << endl;
	copy(first, last, ostream_iterator<int>(cout, "\t"));
	cout << endl;

}

void hu_remove_copy()
{
	int a[6] = { 1,2,3,3,4,2 };
	vector<int>v(a, a + 6);
	copy(a, a + 6, ostream_iterator<int>(cout, "\t"));
	cout << endl;

	vector<int>::iterator last = remove_copy(v.begin(), v.end(), v.begin(), 2);//修改向量自身，删除2元素之后
	cout << "向量 v 删除元素2后" << endl;
	copy(v.begin(), last, ostream_iterator<int>(cout, "\t"));
	cout << endl;
	
	vector<int>vv(a, a + 6);
	vector<int>vvv;
	remove_copy(vv.begin(), vv.end(), back_inserter(vvv), 2);//删除向量中2元素后，结果复制到另一向量容器中
	cout << "删除向量中2元素后，结果复制到另一向量容器中：" << endl;
	copy(vvv.begin(),vvv.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
}


bool markCompare(int n)
{
	return n < 60;//删除小于60
}
void hu_remove_if()
{
	int a[] = { 87,54,32,23,21,77,88,98 };
	int Len = sizeof(a) / sizeof(int);
	vector<int>v;
	copy(a, a + Len, ostream_iterator<int>(cout, "\t"));
	cout << endl;
	remove_copy_if(a,a+Len, back_inserter(v), markCompare);
	cout << "删除小于60的数值";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;

}