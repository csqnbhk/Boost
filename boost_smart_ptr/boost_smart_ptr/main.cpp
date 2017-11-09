/*************************************************************
          function:boost的智能指针
	  author：Demon
	  Time:2017/11/9
*************************************************************/
#include<iostream>
#include<boost/smart_ptr.hpp>
#include<boost/smart_ptr/intrusive_ref_counter.hpp>
using namespace std;
using namespace boost;
/*
struct A
{
	int Count = 0;
};
void intrusive_ptr_add_ref(A*p)
{
	++p->Count;
}
void intrusive_ptr_release(A*p)
{
	if (--p->Count==0)
	{
		delete p;
		cout << "释放intrusive_ptr智能指针" << endl;
	} 
}
struct B:public intrusive_ref_counter<B>
{
	~B() { cout << "B析构" << endl; }
};
using A_instrusive_ptr = intrusive_ptr<A>;
using B_intrusive_ptr = intrusive_ptr<B>;
*/
int main()
{

	//1.scoped_ptr（管理权不能转移）
	/*scoped_ptr<int> sp(new int(66));
	scoped_ptr<int> sp1(new int(88));
	sp.swap(sp1);
	scoped_ptr<string> sp_str(new string("Demon"));
	assert(sp);
	cout << *sp << endl;
	cout << *sp1 << endl;
	cout << *sp_str << ":" << sp_str->size() << endl;*/

	//2.scoped_array
	/*scoped_array<int> sa(new int[3]);
	sa[0] = 11;
	sa[1] = 22;
	sa[2] = 366;
	//sa[3] = 1234;越界，未定义。不过去看内存还是很有意思的
	*/

        //3.shared_array(可以使用shared_ptr<vector>，vector<shared_ptr>替代）
	/*shared_array<int> sa(new int[3]);
	cout << sa.use_count() << endl;
	shared_array<int> sa1(sa);
	cout << sa.use_count() << endl;
	sa[1] = 11;
	cout << sa1[1] << endl;
	assert(!sa.unique());*/

	//4.intrusive_ptr
	/*
	{
		A_instrusive_ptr p(new A());
		{
			assert(p);
			A_instrusive_ptr p1(p);
			cout << p1->Count << endl;
		}
		cout << p->Count << endl;
	}
	*/
	//继承intrusive_ref_counter<typename T>
	/*
	{
	        B_intrusive_ptr p(new B);
		{
			assert(p);
			B_intrusive_ptr p1(p);
			cout << p1->use_count() << endl;
		}
		cout << p->use_count() << endl;
	}
	*/

	//5.shared_ptr(标准库（shared_ptr,unique_ptr,weak_ptr)写过就不写了）

	//6.weak_ptr

	return 0;
}
