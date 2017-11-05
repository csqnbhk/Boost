/*************************************************************
         function:��Ϥһ�µ�����"���������ݽṹ"
		 author��Demon
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

	//1.boost::array(���ܶ�̬�ı��С����֪�����С��
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

	//2.boost::dynamic_bitset,���Զ�̬���ӡ�(C++��׼������������ݣ�vector<bool>������ǵ�ע�⣩��bitset��
	/*
	dynamic_bitset<> db1;
	dynamic_bitset<> db2(10);
	dynamic_bitset<> db3(string("110"));//ע�⣬Ҫ����string��������C�ַ���
	dynamic_bitset<> db4(0x10, BOOST_BINARY(10010));
	cout << "db1.size():" << db1.size()<<"  "<<db1<< endl;
	cout << "db2.size():" << db2.size()<<"  "<<db2<< endl;
	cout << "db3.size():" << db3.size()<<"  "<<db3<< endl;
	cout << "db4.size():" << db4.size()<<"  "<<db4<<endl;
	db4.resize(6);   //��С��С
	cout << "db4.size():" << db4.size() << "  " << db4 << endl;
	db4.clear();     //��գ���ʱ��СΪ0
	cout << "db4.size():" << db4.size() << "  " << db4 << endl;
	db4.push_back(1);//����Ԫ�أ���̬����
	db4.push_back(0);
	db4.push_back(1);
	cout << "db4.size():" << db4.size() << "  " << db4 << endl;
	//����Ԫ��test,���ĳ��λ�Ƿ�Ϊ1
	cout << db4.test(0) << endl;
	cout << db4.test(1) << endl;
	//�����Ƿ����1�����ڷ���true
	cout << db4.any() << endl;
	//���Բ�����1��none()����true
	cout << db4.none() << endl;
	//ͳ��1��Ԫ������
	cout << db4.count() << endl;
	//set�������԰�ȫ�������ص�λ��ֵ����Ϊ1����0
	db4.set();//ȫ��Ϊ1
	cout << "db4.size():" << db4.size() << "  " << db4 << endl;
	//reset�������԰�ȫ�������ص�λ��ֵ����Ϊ0
	db4.reset();
	cout << "db4.size():" << db4.size() << "  " << db4 << endl;
	//flip��תȫ������ָ���Ķ�����λ
	db4.flip();
	cout << "db4.size():" << db4.size() << "  " << db4 << endl;
	db4.flip(1);
	cout << "db4.size():" << db4.size() << "  " << db4 << endl;
	//find_first��first_next(���ص�һ��1��λ�ã�
	db4.push_back(0);
	db4.push_back(1);
	cout << "db4.size():" << db4.size() << "  " << db4 << endl;
	cout << db4.find_first() << endl;
	cout << db4.find_next(2) << endl;
	*/

	//3.unordered(ɢ��������,unordered_map/multimap,unordered_set/multiset
	
	/*
	unordered_map<int, std::string> u_m;
	u_m.emplace(9,"����");
	u_m.emplace(6,"�Ϻ�");
	u_m.emplace(13,"����");
	u_m.emplace(7,"����");
	u_m.insert(pair<int, std::string>(66, "�Ͼ�"));
	for (auto i=u_m.begin();i!=u_m.end();++i)
	{
		cout << i->first << ":" << i->second << endl;
	}
	*/
	
	//4.tuple(���ɵ�ÿ��Ԫ�����Ϳ��Բ�ͬ��
	//exceptin��������tuple1���������Ϣ�����Կ��ϴ�д���쳣����
	/*
	using int_str = boost::tuple<int, std::string>;
	int_str i_s={66, "���"};
	cout << i_s.get<0>() << endl;
	cout << i_s.get<1>() << endl;
	*/
	
	//any(ֻ������һ��Ԫ�أ��������������ͣ�
	/*
    any a(66);
	any b;
	cout << "sizeof(a):" << sizeof(a) << endl;
	cout << a.empty()<< endl;
	cout << b.empty() << endl;
	int temp = any_cast<int>(a);//��ÿ���
	temp = 12;
	{
		int&temp1 = any_cast<int&>(a);//�������
		temp1 = 13;
	}
	a = "�й�";
	*/


	//Ӧ���������� 
    /*
	vector<boost::any> v;
	any i(1);
	any s(string("�����"));//�ǵ������string������д��any s("�����");����C�ַ�����Ҫ������
	any d(66.64);//�����C�ַ���
	any c("��ң");
	v.push_back(i);
	v.push_back(s);
	v.push_back(d);
	v.push_back(c);
	cout << any_cast<int>(i) << endl;
	cout << any_cast<std::string>(s) << endl;
	cout << any_cast<double>(d) << endl;
	*/

    cout << "�п���д" << endl;
	return 0;
}