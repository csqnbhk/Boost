/*****************************************
      function:boost库的assign
      author：Demon
	  TIME：2017/11/10
*****************************************/
#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<boost/assign.hpp>
#include<type_traits>
using namespace std;
using namespace boost::assign;
int main()
{

	////1.list_inserter,类似std::back_inserter

	//1.使用operator+=
	/*vector<int> v;
	v += 1, 3, 5, 7, 9;
	map<int, std::string> s;
	s += make_pair(1, "C"), make_pair(2, "C++");
	for (auto i : v)
	{
		cout << i << "  ";
	}
	cout << endl;
	for (auto i:s)
	{
		cout << i.second.c_str << endl;
	}*/

	//2.使用operator()
	/*vector<int> v;
	push_back(v)(1)(3)(5)(11);
	list<std::string> L;
	push_front(L)("C")("C++")("JAVA")("Python");
	set<double> s;
	insert(s)(1.55)(1.732)*/

	//3.使用operator，
	/*
	vector<int> v;
	push_back(v),1, 3, 5, 7;//类似vector<int> v1{ 1 ,2 ,4 ,5, 67, 34 };
	push_back(v)(2), 4, 6, 8;
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
	*/

	//4.generic_list，类似标准库std::initializer_list

	////5.初始化容器，assign库提供三个工厂函数list_of(),map_list_of()/pair_list_of(),tuple_list_of

	//1.list_of()
	/*
	map<int, std::string> m = list_of(make_pair(1, "北京")) (make_pair(2, "上海"));
	vector<int> v = list_of(1)(3)(5);
	set<int> s = (list_of(10), 20, 30);
	//对比
	map<int, std::string> std_m1{ {1,"北京"},{2,"苏州"} };
	vector<int> std_v1{ 1,3,5 };
	set<int> std_s1{ 10,20,30 };
	*/

	//2.map_list_of()/pair_list_of()
	/*
	map<int, int> m = map_list_of(1, 11)(2, 22)(3, 33);//模版参数类型，模版函数可以根据调用实参自动推断。下面也可以写出了
	map<int, std::string> m1 = pair_list_of<int, std::string>(1, "中国")(2, "英国")(3, "泰国");
	*/

	//3.tuple_list_of(还不会用？？？？？？）
	/*
	using tuple_int_double_string = std::tuple<int, double, std::string>;//这里是有标准tuple
	vector<tuple_int_double_string> v = { {1, 1.66, "中国"},{3, 2.310, "英国"} };
	typedef std::tuple<int, std::string> tuple_int_string;
	tuple_int_string t_i_s = make_tuple(1, "胡歌");
	*/

	return 0;
}