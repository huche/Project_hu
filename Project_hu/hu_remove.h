#pragma once
/*
7 ɾ��������
remove()	ɾ������ָ����Ԫ��
remove_if()	ɾ�����������ĵ�Ԫ��
remove_copy()	��������ʱ��ɾ��ָ����Ԫ��
remove_copy_if()	��������ʱ��ɾ������������Ԫ��
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
	last = remove(v.begin(), v.end(), 2);//ɾ������ 2��Ԫ��,ԭ�������ڴ�ռ䲢û�б仯,���ص��������ָ��

	cout << "���� v ɾ��Ԫ��2��" << endl;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	cout << "ɾ������Ч���ݣ�" << endl;
	copy(first, last, ostream_iterator<int>(cout, "\t"));
	cout << endl;

}

void hu_remove_copy()
{
	int a[6] = { 1,2,3,3,4,2 };
	vector<int>v(a, a + 6);
	copy(a, a + 6, ostream_iterator<int>(cout, "\t"));
	cout << endl;

	vector<int>::iterator last = remove_copy(v.begin(), v.end(), v.begin(), 2);//�޸���������ɾ��2Ԫ��֮��
	cout << "���� v ɾ��Ԫ��2��" << endl;
	copy(v.begin(), last, ostream_iterator<int>(cout, "\t"));
	cout << endl;
	
	vector<int>vv(a, a + 6);
	vector<int>vvv;
	remove_copy(vv.begin(), vv.end(), back_inserter(vvv), 2);//ɾ��������2Ԫ�غ󣬽�����Ƶ���һ����������
	cout << "ɾ��������2Ԫ�غ󣬽�����Ƶ���һ���������У�" << endl;
	copy(vvv.begin(),vvv.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
}


bool markCompare(int n)
{
	return n < 60;//ɾ��С��60
}
void hu_remove_if()
{
	int a[] = { 87,54,32,23,21,77,88,98 };
	int Len = sizeof(a) / sizeof(int);
	vector<int>v;
	copy(a, a + Len, ostream_iterator<int>(cout, "\t"));
	cout << endl;
	remove_copy_if(a,a+Len, back_inserter(v), markCompare);
	cout << "ɾ��С��60����ֵ";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;

}