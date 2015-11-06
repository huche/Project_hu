#pragma once
/*
6 生成函数：
generate()	用一操作的结果，填充所有元素
generate_n()	用一操作的结果，填充前n个元素
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdlib.h>
#include <time.h>
using namespace std;
//生成斐波那契数列
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
生成随机数：
要求产生 10个1-100之间整数
		10个0-1之间小数

分析：
最好编制一个随机数产生接口 ——模板特化技术
产生随机数最好每次起始种子都不同，方案就是采用时间函数做随机种子

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
	cout << "产生[0,100]之间随机整数" << n << "个" << endl;
	vector<int>vi(n);
	generate_n(vi.begin(), n, HuR<int>());
	copy(vi.begin(), vi.end(), ostream_iterator<int>(cout, "\t"));

	cout << "产生[0,1]之间随机小数" << n << "个" << endl;
	vector<float>vf(n);
	generate_n(vf.begin(), n, HuR<float>());
	copy(vf.begin(), vf.end(), ostream_iterator<float>(cout, "\t"));

}