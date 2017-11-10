/****************************************************
            function:boost库的random库
	    author:Demon
	    Time:2017/11/9
****************************************************/
#include<iostream>
#include<boost/random.hpp>
#include<ctime>
using namespace std;
using namespace boost;
int main()
{

	//1.rand48
	/*
	rand48 r48;
	cout << "min~max," << r48.min() << "~" << r48.max() << endl;
	r48.seed(time(0));//设置个随机种子先
	for (auto i = 0;i < 15;i++)
	{
		r48();
	}
	r48.discard(5);//这个成员函数可以去掉指定个数随机数
	vector<int> v(10);
	r48.generate(v.begin(), v.end());//这个成员函数可以填充一个容器
	cout << "获取的元素如下：" << endl;
	for (auto i : v)
	{
		cout << i <<endl;
	}
	cout << endl;
	*/
	//2.mt19937
	/*
	 mt19937 mt;
	 cout << "min~max," << mt.min() << "~" << mt.max() << endl;
	*/
	//3.lagged_fibonacci19937
	/*
	lagged_fibonacci19937 lf_19937;
	cout << "min~max," << lf_19937.min() << "~" << lf_19937.max() << endl;
	*/

	//4.随机数发生器的拷贝
	/*lagged_fibonacci19937 mt;
	mt.seed(time(0));
	cout << mt() << endl;
	lagged_fibonacci19937 lf_19937(mt);
	assert(mt() == lf_19937());*/

	//5.随机数分布器(需要配合随机数发生器才可以工作）
	/*mt19937 mt(time(0));
	random::uniform_int_distribution<int> ui(0, 66);
	for (auto i = 0;i < 20;++i)
	{
		cout << ui(mt) << "  ";
	}
	cout << endl;*/

	//6.变量发生器(组合随机数发生器和分布器）
	/*mt19937 mt(time(0));
	uniform_smallint<> us(1, 66);
	variate_generator<mt19937, uniform_smallint<>> gen(mt,us);
	for (auto i = 0;i < 10;++i)
	{
		cout << gen() << " ";
	}
	cout << endl;*/

	//7.产生随机数据块

	return 0;
}
