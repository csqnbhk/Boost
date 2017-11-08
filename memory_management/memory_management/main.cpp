/********************************************************
         function:memory management
		 author:Demon
         Time:2017/11/8
********************************************************/
#define BOOST_SYSTEM_NO_DEPRECATED//singleton_pool����boost.system,�������Ӵ���
#include<iostream>
#include<boost/pool/pool.hpp>
#include<boost/pool/object_pool.hpp>
#include<boost/pool/singleton_pool.hpp>
#include<boost/pool/pool_alloc.hpp>
#include<vector>
using namespace boost;
using namespace std;
//#pragma pack(1)//���ָ�������ӣ��ڴ����Ϊһ���ֽ�
struct A
{
	A(int x,int y,int z):xPos(x),yPos(y),w(z){}
	void test() { cout << "xPos:" << xPos << " " << "yPos:" << yPos << " " << "w:" << w << endl; }
	int get_w_size() { return sizeof(w); }
 private:
	 int xPos;
	 int yPos;
	 char w; //����������ϰһ���ڴ���롣#pragma back(xx)//xxΪָ��������ֽ���
};
int main()
{
	//��1.pool
    /*
	pool<> p(sizeof(int));
	int *ptemp = static_cast<int*>(p.malloc());
	*ptemp = 66;
	int*ptemp1 = static_cast<int*>(p.malloc());
	*ptemp1 = 77;
	cout <<"sizeof(p)="<< sizeof(p) << endl;
	assert(p.is_from(ptemp));
	cout << ptemp1 << endl;
	p.free(ptemp1);  //��ʵfree�����ڴ棬��ָ�뻹��ָ��ô��ġ��������޸ĸ��ڴ��ֵַ��
	                //����������free�ˡ���ע���free�����ڴ���Ա��ٴ����룬���ȷʵ��
	               //�ٴ����뵽�ÿռ䡣��ôԭ�ȵ�free����ָ���ֿ����ٴ�free�����о����ʺ�С��
	              // �ǵã���Ҫ�����������������ĺ��ѿ���...
	cout << ptemp1 << endl;
	*ptemp = 99;
	*ptemp1 = 88;
	cout << *ptemp1 << endl;
    //��֤������ķ���
	int *pp = new int(sizeof(int));
	*pp = 100;
	cout << pp << endl;
	delete pp;
	cout << pp << endl;
	*pp = 200;
	cout << *pp << endl;
	*/
	//��2.object_pool(������ʵ�����ڴ�أ�
	/*
	object_pool<A>  o_p;
	auto p = o_p.malloc();              //����ԭʼ�ڴ�飬û�г�ʼ��������ڴ��
	cout << "sizeof(A):" << sizeof(A) << endl;
	auto p1 = o_p.construct(66, 77,'w');//��ʼ���ڴ�飬���Ŀǰ���֧�ֹ��캯����������Ϊ3
	p->test();
	p1->test();
	cout << "sizeeof(w):" << p1->get_w_size() << endl;//�����ڴ���룬Ϊ4������w����һ���ֽڵġ�
	*/
	//��3.singletion_pool(�ӿں�poolһ�������ǳ�Աȫ��Ϊ��̬��Ա����������������͵��ڴ�ָ�룬������
	/*
	 using s_p_int = singleton_pool<struct tag_int, sizeof(int) > ;//tag_intֻ��һ�����࣬��ʶ
	{
		int *intp = static_cast<int*>(s_p_int::malloc());
		assert(s_p_int::is_from(intp));
		*intp = 66;
		cout << *intp << endl;
		s_p_int::release_memory();//s_p_int���ڴ�ֻ���ڳ������ʱ�����ͷţ���������Ҳû���ͷ�
	}
	*/
	//��4.pool_alloc(������Ϊ��׼����ģ��������ڴ��������
	/*
	std::vector<int, pool_allocator<int>> v;//����ڴ����ʧ�ܣ��׳�std::bad_alloc,ͷ�ļ�<boost/pool/pool_alloc.hpp>
	v.push_back(66);
	v.push_back(88);
	for (auto i : v) { 
		cout << i << " ";
	}
	cout << endl;
	*/

 	return 0;
}