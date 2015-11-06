#pragma once
//替换
/*

4 替换函数：
replace()	用一些给定值替换一些值
replace_if()	替换满足条件的元素
repalce_copy()	复制序列时，用一给定值替换元素
repalce_copy_if()	复制序列时，替换满足条件元素
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
	cout << "replace用8替换2" << endl;
	vector<int>v(a, a + 6);
	/*

	//把数组 a[] 中所有元素等于a[2] 的数据用333 替换
	replace(a, a + 6, a[2], 333);//错误使用 参数3 :a[2]
	应该修改为： 
	int d=a[2];//d和a[2]值相等，但不再同一内存空间
	replace(a, a + 6, d, 333);
	*/

	//replace(a, a + 6, 2, 8);//改变了数组
	//copy(a, a + 6, ostream_iterator<int>(cout, "\t"));
	replace(v.begin(), v.end(), 2, 8);
	copy(v.begin(),v.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;

	cout << "数组元素小于3的用10 替换：" << endl;
	vector<int>v2(a, a + 6);
	replace_if(v2.begin(), v2.end(), bind2nd(less<int>(), 3), 10);
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;

	cout << "数组2用8替换，并且赋值给 某容器"<<endl;
	vector<int>v3(a, a + 6);
	vector<int>v4;
	replace_copy(v3.begin(), v3.end(), back_inserter(v4), 2, 8);
	copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	copy(v4.begin(), v4.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;

	cout << "数组小于3 用100 替换，并且赋值 给某容器" << endl;
	vector<int>v5(a, a + 6);
	vector<int>v6;
	replace_copy_if(v5.begin(),v5.end(),back_inserter(v6),bind2nd(less<int>(),3),100);
	//参数 1 输入迭代器开始指针 2输入迭代器结束指针 3 输出迭代器开始指针 4一元判定函数 5容器元素类型 
	copy(v5.begin(), v5.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	copy(v6.begin(), v6.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;


}