#pragma once
//����ʾ��
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
	cout << "ԭʼ���ݣ�" << "a=" << a << "\tb=" << b << endl;
	swap(a, b);//������������
	cout << "����֮�����ݣ�" << "a=" << a << "\tb=" << b << endl;


	int aa[3] = { 1,2,3 };
	int bb[3] = { 9,8,7 };
	cout << "ԭʼ���飺" << "aa[3]=" << endl;
	copy(aa, aa + 3, ostream_iterator<int>(cout,"\t"));
	cout << endl;
	cout << "ԭʼ���� b[3]=" << endl;
	copy(bb, bb + 3, ostream_iterator<int>(cout, "\t"));
	cout << endl;

	//swap_ranges(aa, aa + 2, bb);//��������Ԫ��
	swap(aa,bb);//��������Ԫ��
	//iter_swap(&a,&b);

	cout << "���������� aa[3]="<<endl;
	copy(aa, aa + 3, ostream_iterator<int>(cout, "\t"));
	cout << endl;
	cout << "���������� bb[3]=" << endl;
	copy(bb, bb + 3, ostream_iterator<int>(cout, "\t"));
	cout << endl;


	vector<int>v1(aa, aa + 3);
	vector<int>v2(bb, bb + 3);
	cout << "ԭʼ���� v1:" << endl;
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	cout << "ԭʼ����v2��" << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	swap(v1, v2);//��������Ԫ��
	cout << "���������� v1:" << endl;
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	cout << "����������v2��" << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;



}