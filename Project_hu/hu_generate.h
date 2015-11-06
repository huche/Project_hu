#pragma once
/*
6 ���ɺ�����
generate()	��һ�����Ľ�����������Ԫ��
generate_n()	��һ�����Ľ�������ǰn��Ԫ��
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdlib.h>
#include <time.h>
using namespace std;
//����쳲���������
class Fibonaci
{
	int a;
	int b;
public:
	Fibonaci(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	int operator () ()
	{
		int r = a + b;
		a = b;
		b = r;
		return r;
	}
};


void hu_fi()
{
	vector<int>v(20);
	generate(v.begin(), v.end(), Fibonaci(0, 1));
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	vector<int>vv(10);
	generate(vv.begin(), vv.end(), Fibonaci(0, 1));

	copy(vv.begin(), vv.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
}

/*
�����������
Ҫ����� 10��1-100֮������
		10��0-1֮��С��

������
��ñ���һ������������ӿ� ����ģ���ػ�����
������������ÿ����ʼ���Ӷ���ͬ���������ǲ���ʱ�亯�����������

*/

template<class T>
class HuR
{

};

template<>
class HuR<int>
{
public:
	HuR()
	{
		srand(time(NULL));
	}

	int operator ()()
	{
		int res = rand() % 100;
		return res;
	}
};

template<>
class HuR<float>
{
public:
	HuR()
	{
		srand(time(NULL));
	}

	float operator ()()
	{
		float res = rand() % 100 * 0.01f;
		return res;
	}
};

void hu_random(int n)
{
	cout << "����[0,100]֮���������" << n << "��" << endl;
	vector<int>vi(n);
	generate_n(vi.begin(), n, HuR<int>());
	copy(vi.begin(), vi.end(), ostream_iterator<int>(cout, "\t"));

	cout << "����[0,1]֮�����С��" << n << "��" << endl;
	vector<float>vf(n);
	generate_n(vf.begin(), n, HuR<float>());
	copy(vf.begin(), vf.end(), ostream_iterator<float>(cout, "\t"));

}