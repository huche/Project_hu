#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

template<class T,class OutVar>//模板 T输入参数类型，OutVar 返回返回类型
class PrintInfor :public unary_function<T, OutVar>
{
private:
	T msum;
	T mmax;
	T mmin;
	int count;
public:
	PrintInfor():count(0),msum(0)
	{}
	T GetSum()
	{
		return msum;
	}

	T GetMax()
	{
		return mmax;
	}

	T GetMin()
	{
		return mmin;
	}

	OutVar operator () (T x)
	{
		//cout << "enter here operator()";
		if (count == 0)
		{
			mmax = x;
			mmin = x;
		}
		else
		{
			if (mmax < x)
			{
				mmax = x;
			}
			if (mmin > x)
			{
				mmin = x;
			}
		}

		msum += x;
		count++;


	}
};


//求向量的最大值、最小值、和

void hu_max_min_sum()
{
	float a[] = { 1.2,2.3,4.5,54,43,43.23,7.21 };
	const int Len = sizeof(a) / sizeof(float);
	for (int i = 0; i < Len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	PrintInfor<float, void>& P = for_each(a, a + Len, PrintInfor<float, void>());
	//当 for_each()每一项元素执行结束之后，返回函数对象
	cout << "总和是：" << P.GetSum() << endl;
	cout << "最大值：" << P.GetMax() << endl;
	cout << "最小值：" << P.GetMin() << endl;


	
}