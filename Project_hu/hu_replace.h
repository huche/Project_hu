#pragma once
//�滻
/*

4 �滻������
replace()	��һЩ����ֵ�滻һЩֵ
replace_if()	�滻����������Ԫ��
repalce_copy()	��������ʱ����һ����ֵ�滻Ԫ��
repalce_copy_if()	��������ʱ���滻��������Ԫ��
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;

void hu_repalce()
{

	int a[6] = { 1,2,3,3,2,1 };
	copy(a, a + 6, ostream_iterator<int>(cout, "\t"));

	cout << endl;
	cout << "replace��8�滻2" << endl;
	vector<int>v(a, a + 6);
	/*

	//������ a[] ������Ԫ�ص���a[2] ��������333 �滻
	replace(a, a + 6, a[2], 333);//����ʹ�� ����3 :a[2]
	Ӧ���޸�Ϊ�� 
	int d=a[2];//d��a[2]ֵ��ȣ�������ͬһ�ڴ�ռ�
	replace(a, a + 6, d, 333);
	*/

	//replace(a, a + 6, 2, 8);//�ı�������
	//copy(a, a + 6, ostream_iterator<int>(cout, "\t"));
	replace(v.begin(), v.end(), 2, 8);
	copy(v.begin(),v.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;

	cout << "����Ԫ��С��3����10 �滻��" << endl;
	vector<int>v2(a, a + 6);
	replace_if(v2.begin(), v2.end(), bind2nd(less<int>(), 3), 10);
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;

	cout << "����2��8�滻�����Ҹ�ֵ�� ĳ����"<<endl;
	vector<int>v3(a, a + 6);
	vector<int>v4;
	replace_copy(v3.begin(), v3.end(), back_inserter(v4), 2, 8);
	copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	copy(v4.begin(), v4.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;

	cout << "����С��3 ��100 �滻�����Ҹ�ֵ ��ĳ����" << endl;
	vector<int>v5(a, a + 6);
	vector<int>v6;
	replace_copy_if(v5.begin(),v5.end(),back_inserter(v6),bind2nd(less<int>(),3),100);
	//���� 1 �����������ʼָ�� 2�������������ָ�� 3 �����������ʼָ�� 4һԪ�ж����� 5����Ԫ������ 
	copy(v5.begin(), v5.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	copy(v6.begin(), v6.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;


}