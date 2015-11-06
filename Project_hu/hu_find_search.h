#pragma once
/*
��ѯ������Ӧ����㷺�Ĳ�����STL�ṩ��һ�²�ѯ������
find()	�ڵ��������������ҳ� ĳ��ֵ ��һ�γ��ֵ�λ��
find_if()	�ڵ��������������ҳ����� ĳν�� �ĵ�һ��Ԫ��
find_first_of()	��˫�������������ҳ� һ��������ĳԪ�� ��һ�γ��ֵ�λ��
adjacent_find()	�ڵ��������������ҳ���һ�� ����ֵ���Ԫ�ص�λ��
find_end()	��˫�������������ҳ� һ������  ���һ�γ��ֵ�λ��
search()	��˫�������������ҳ� һ������  ��һ�γ��ֵ�λ��
search_n()	�ڵ��������������ҳ� һ��ֵ����n�γ��ֵ�λ��
*/
#include <iostream>
#include <algorithm>
using namespace std;
//ʾ������


bool bigger(int m)
{
	return m > 4;
}

void hu_test()
{
	int a[] = { 1,2,2,3,3,4,5,5,6,1,2,2,2,5,5,6,2,3 };
	int len = sizeof(a) / sizeof(int);
	cout << "ԭʼ���飺";
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << "\t";
	}

	cout << endl;
	
	int* p1 = find(a, a + len, 6);
	if (p1!=(a+len))
	{
		cout << "��find����һ�ε���6��λ�ã�" << p1 - a << "\tֵ��" << *p1 << endl;

	}

	int* p2 = find_if(a, a + len, bigger);
	if (p2!=a+len)
	{
		cout << "��find_of����һ�δ���4��λ�ã�" << p2 - a << "\tֵ��" << *p2 << endl;

	}

	int b[] = { 12,3,21,5 };
	int lenb = sizeof(b) / sizeof(int);
	int* p3 = find_first_of(a, a + len, b, b + lenb);
	if (p3!=a+len)
	{
		cout << "��find_first_of����һ�������� a�з���b����[12,3,21,5]��Ԫ�ص�λ�ã�" << p3 - a << "\tֵ��" << *p3 << endl;

	}

	int* p4 = adjacent_find(a, a + len);
	if (p4!=a+len)
	{
		cout << "��adjacent_find���״�����Ԫ��λ�ã�" << p4 - a << "\tֵ" << *p4 << endl;
	}

	int c[] = { 2,3 };
	int lenc = sizeof(c) / sizeof(int);
	int* p5 = find_end(a, a + len, c, c + lenc);
	if (p5 != a + len)
	{
		cout << "��find_end������ a�����һ��ƥ������c[2,3]��Ԫ�ص�λ�ã�" << p5 - a << "\tֵ��" << *p5 << endl;

	}

	int* p6 = search(a, a + len, c, c + lenc);
	if (p6!=a+len)
	{
		cout<<"��search������ a�е�һ��ƥ������c[2,3]��Ԫ�ص�λ�ã�" << p6 - a << "\tֵ��" << *p6 << endl;
	}

	int* p7 = search_n(a, a + len, 3, 2);
	if (p7 != a + len)
	{
		cout << "search_n����a�е�һ����������3��2��λ�ã�" << p7 - a << endl;
	}
}