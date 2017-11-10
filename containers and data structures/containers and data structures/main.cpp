/*************************************************************
             function:熟悉一下第七章"容器和数据结构"
	     author：Demon
	     Time:2017/11/5
*************************************************************/
#include<iostream>
#include<vector>
#include<boost/array.hpp>
#include<boost/dynamic_bitset.hpp>
#include<boost/utility/binary.hpp>
#include<boost/unordered_map.hpp>
#include<boost/unordered_set.hpp>
#include<boost/tuple/tuple.hpp>
#include<boost/any.hpp>

using namespace boost;
using namespace std;

int main()
{

	//1.boost::array(不能动态改变大小，已知数组大小）
	/*
	boost::array<int,5> a;
	a.assign(66);
	a.back() = 88;
	a.front() = 77;
	int*p = a.c_array();
	*(p + 1) = 2;
	p[3] =4;
	cout << "size:" << a.size() << endl;
	for (auto i=a.begin();i<a.end();++i)
	{
		cout << *i << "   ";
	}
	cout << endl;
	for (auto i = a.rbegin();i < a.rend();++i)
	{
		cout << *i << "   ";
	}
	cout << endl;
	*/

	//2.boost::dynamic_bitset,可以动态增加。(C++标准处理二进制数据，vector<bool>（这个记得注意）和bitset）
	/*
	dynamic_bitset<> db1;
	dynamic_bitset<> db2(10);
	dynamic_bitset<> db3(string("110"));//注意，要求是string，不能是C字符串
	dynamic_bitset<> db4(0x10, BOOST_BINARY(10010));
	cout << "db1.size():" << db1.size()<<"  "<<db1<< endl;
	cout << "db2.size():" << db2.size()<<"  "<<db2<< endl;
	cout << "db3.size():" << db3.size()<<"  "<<db3<< endl;
	cout << "db4.size():" << db4.size()<<"  "<<db4<<endl;
	db4.resize(6);   //缩小大小
	cout << "db4.size():" << db4.size() << "  " << db4 << endl;
	db4.clear();     //清空，此时大小为0
	cout << "db4.size():" << db4.size() << "  " << db4 << endl;
	db4.push_back(1);//存入元素，动态增加
	db4.push_back(0);
	db4.push_back(1);
	cout << "db4.size():" << db4.size() << "  " << db4 << endl;
	//访问元素test,检查某个位是否为1
	cout << db4.test(0) << endl;
	cout << db4.test(1) << endl;
	//测试是否存在1，存在返回true
	cout << db4.any() << endl;
	//测试不存在1，none()返回true
	cout << db4.none() << endl;
	//统计1的元素数量
	cout << db4.count() << endl;
	//set函数可以把全部或者特点位置值设置为1或者0
	db4.set();//全部为1
	cout << "db4.size():" << db4.size() << "  " << db4 << endl;
	//reset函数可以把全部或者特点位置值设置为0
	db4.reset();
	cout << "db4.size():" << db4.size() << "  " << db4 << endl;
	//flip翻转全部或者指定的二进制位
	db4.flip();
	cout << "db4.size():" << db4.size() << "  " << db4 << endl;
	db4.flip(1);
	cout << "db4.size():" << db4.size() << "  " << db4 << endl;
	//find_first和first_next(返回第一个1的位置）
	db4.push_back(0);
	db4.push_back(1);
	cout << "db4.size():" << db4.size() << "  " << db4 << endl;
	cout << db4.find_first() << endl;
	cout << db4.find_next(2) << endl;
	*/

	//3.unordered(散列容器）,unordered_map/multimap,unordered_set/multiset
	
	/*
	unordered_map<int, std::string> u_m;
	u_m.emplace(9,"北京");
	u_m.emplace(6,"上海");
	u_m.emplace(13,"杭州");
	u_m.emplace(7,"苏州");
	u_m.insert(pair<int, std::string>(66, "南京"));
	for (auto i=u_m.begin();i!=u_m.end();++i)
	{
		cout << i->first << ":" << i->second << endl;
	}
	*/
	
	//4.tuple(容纳的每个元素类型可以不同）
	//exception，经常用tuple打包错误信息，可以看上次写的异常处理
	/*
	using int_str = boost::tuple<int, std::string>;
	int_str i_s={66, "令狐"};
	cout << i_s.get<0>() << endl;
	cout << i_s.get<1>() << endl;
	*/
	
	//any(只能容纳一个元素，可以是任意类型）
	/*
        any a(66);
	any b;
	cout << "sizeof(a):" << sizeof(a) << endl;
	cout << a.empty()<< endl;
	cout << b.empty() << endl;
	int temp = any_cast<int>(a);//获得拷贝
	temp = 12;
	{
		int&temp1 = any_cast<int&>(a);//获得引用
		temp1 = 13;
	}
	a = "中国";
	*/


	//应用在容器中 
        /*
	vector<boost::any> v;
	any i(1);
	any s(string("令狐冲"));//记得如果是string，不能写成any s("令狐冲");这是C字符串。要区别开来
	any d(66.64);
	any c("逍遥");//这个是C字符串
	v.push_back(i);
	v.push_back(s);
	v.push_back(d);
	v.push_back(c);
	cout << any_cast<int>(i) << endl;
	cout << any_cast<std::string>(s) << endl;
	cout << any_cast<double>(d) << endl;
	cout << any_cast<char const*>(v[3])<<endl;
	*/

       cout << "有空再写" << endl;
       return 0;
}
