/*****************************************
      function:boost���assign
      author��Demon
	  TIME��2017/11/10
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

	////1.list_inserter,����std::back_inserter

	//1.ʹ��operator+=
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

	//2.ʹ��operator()
	/*vector<int> v;
	push_back(v)(1)(3)(5)(11);
	list<std::string> L;
	push_front(L)("C")("C++")("JAVA")("Python");
	set<double> s;
	insert(s)(1.55)(1.732)*/

	//3.ʹ��operator��
	/*
	vector<int> v;
	push_back(v),1, 3, 5, 7;//����vector<int> v1{ 1 ,2 ,4 ,5, 67, 34 };
	push_back(v)(2), 4, 6, 8;
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
	*/

	//4.generic_list�����Ʊ�׼��std::initializer_list

	////5.��ʼ��������assign���ṩ������������list_of(),map_list_of()/pair_list_of(),tuple_list_of

	//1.list_of()
	/*
	map<int, std::string> m = list_of(make_pair(1, "����")) (make_pair(2, "�Ϻ�"));
	vector<int> v = list_of(1)(3)(5);
	set<int> s = (list_of(10), 20, 30);
	//�Ա�
	map<int, std::string> std_m1{ {1,"����"},{2,"����"} };
	vector<int> std_v1{ 1,3,5 };
	set<int> std_s1{ 10,20,30 };
	*/

	//2.map_list_of()/pair_list_of()
	/*
	map<int, int> m = map_list_of(1, 11)(2, 22)(3, 33);//ģ��������ͣ�ģ�溯�����Ը��ݵ���ʵ���Զ��ƶϡ�����Ҳ����д����
	map<int, std::string> m1 = pair_list_of<int, std::string>(1, "�й�")(2, "Ӣ��")(3, "̩��");
	*/

	//3.tuple_list_of(�������ã�������������
	/*
	using tuple_int_double_string = std::tuple<int, double, std::string>;//�������б�׼tuple
	vector<tuple_int_double_string> v = { {1, 1.66, "�й�"},{3, 2.310, "Ӣ��"} };
	typedef std::tuple<int, std::string> tuple_int_string;
	tuple_int_string t_i_s = make_tuple(1, "����");
	*/

	return 0;
}