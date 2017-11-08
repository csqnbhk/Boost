/********************************************************
         function:memory management
		 author:Demon
         Time:2017/11/8
********************************************************/
#define BOOST_SYSTEM_NO_DEPRECATED//singleton_pool依赖boost.system,避免链接错误
#include<iostream>
#include<boost/pool/pool.hpp>
#include<boost/pool/object_pool.hpp>
#include<boost/pool/singleton_pool.hpp>
#include<boost/pool/pool_alloc.hpp>
#include<vector>
using namespace boost;
using namespace std;
//#pragma pack(1)//如果指定这样子，内存对齐为一个字节
struct A
{
	A(int x,int y,int z):xPos(x),yPos(y),w(z){}
	void test() { cout << "xPos:" << xPos << " " << "yPos:" << yPos << " " << "w:" << w << endl; }
	int get_w_size() { return sizeof(w); }
 private:
	 int xPos;
	 int yPos;
	 char w; //故意搞个，复习一下内存对齐。#pragma back(xx)//xx为指定对齐的字节数
};
int main()
{
	//★1.pool
    /*
	pool<> p(sizeof(int));
	int *ptemp = static_cast<int*>(p.malloc());
	*ptemp = 66;
	int*ptemp1 = static_cast<int*>(p.malloc());
	*ptemp1 = 77;
	cout <<"sizeof(p)="<< sizeof(p) << endl;
	assert(p.is_from(ptemp));
	cout << ptemp1 << endl;
	p.free(ptemp1);  //其实free掉该内存，该指针还是指向该处的。还可以修改该内存地址值。
	                //不过不能在free了。（注意该free掉的内存可以被再次申请，如果确实有
	               //再次申请到该空间。那么原先的free掉的指针又可以再次free），感觉几率很小。
	              // 记得，不要真这样子做。会死的很难看的...
	cout << ptemp1 << endl;
	*ptemp = 99;
	*ptemp1 = 88;
	cout << *ptemp1 << endl;
    //验证我上面的发现
	int *pp = new int(sizeof(int));
	*pp = 100;
	cout << pp << endl;
	delete pp;
	cout << pp << endl;
	*pp = 200;
	cout << *pp << endl;
	*/
	//★2.object_pool(用于类实例的内存池）
	/*
	object_pool<A>  o_p;
	auto p = o_p.malloc();              //分配原始内存块，没有初始化分配的内存块
	cout << "sizeof(A):" << sizeof(A) << endl;
	auto p1 = o_p.construct(66, 77,'w');//初始化内存块，这个目前最大支持构造函数参数个数为3
	p->test();
	p1->test();
	cout << "sizeeof(w):" << p1->get_w_size() << endl;//出现内存对齐，为4，但是w还是一个字节的。
	*/
	//★3.singletion_pool(接口和pool一样，但是成员全部为静态成员），分配简单数据类型的内存指针，单例。
	/*
	 using s_p_int = singleton_pool<struct tag_int, sizeof(int) > ;//tag_int只是一个空类，标识
	{
		int *intp = static_cast<int*>(s_p_int::malloc());
		assert(s_p_int::is_from(intp));
		*intp = 66;
		cout << *intp << endl;
		s_p_int::release_memory();//s_p_int的内存只有在程序结束时才能释放，出作用域也没有释放
	}
	*/
	//★4.pool_alloc(可以作为标准容器模版参数的内存分配器）
	/*
	std::vector<int, pool_allocator<int>> v;//如果内存分配失败，抛出std::bad_alloc,头文件<boost/pool/pool_alloc.hpp>
	v.push_back(66);
	v.push_back(88);
	for (auto i : v) { 
		cout << i << " ";
	}
	cout << endl;
	*/

 	return 0;
}