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

	copy(a, a + 7, b);//���鸴������
	copy(a, a + 7, back_inserter(v));//����Ԫ�ظ��Ƶ� ����������

	cout << "ԭʼ����a��" << endl;
	copy(a, a + 7, ostream_iterator<int>(cout, "\t"));//��������Ԫ�ص���Ļ���
	cout << endl;
	cout << "����b��" << endl;
	copy(b, b + 7, ostream_iterator<int>(cout, "\t"));//��������Ԫ�ص���Ļ���
	cout << endl;

	cout << "����v��" << endl;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));//������������Ԫ��Ԫ�ص���Ļ���
	cout << endl;


	//�Ѽ�����������ݴ�ŵ� vector������
	vector<int>vi;
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(vi));
	copy(vi.begin(), vi.end(), ostream_iterator<int>(cout, "\t"));//������������Ԫ��Ԫ�ص���Ļ���

}