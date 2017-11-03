/*************************************************************
            funtion:��Ϥһ�µ�����֪ʶ��
			ע��ȫ����������"Boost�������ȫ����ָ��"
			    �����棨���ߣ��޽��棩
			author:Demon
			Time:2017/11/3
*************************************************************/
#include<iostream>
#include<exception>
#include<boost/exception/all.hpp>
#include<boost/throw_exception.hpp>
using namespace std;
using namespace boost;
//��̳�boost::exception
struct myexception :virtual std::exception, virtual boost::exception
{
};
//ʹ��boost::error_info
typedef  boost::error_info<struct tag_err_no, int> err_no;
typedef  boost::error_info<struct tag_err_str, std::string> err_str;

//����ʹ��enable_error_if(T&e)
struct myexception_a1
{

};

int main()
{


	//��exception�������
	/*
	   C++��׼������쳣���ƣ�std::exception��try/catch/throw
	   std::exception�������ࣺbad_alloc,bad_cast,out_of_range...

	  Boost����쳣������ƣ�boost::exception�����������쳣�ࣩ

					  { 1.exception(�����࣬���������࣬�κ��˶������Դ�������
	  boost::exception{
					  { 2.error_info

	*/

	//1.��Ӧ��
	/*
	try
	{
		try
		{
			throw myexception()<< err_no(66);
		}
		catch (myexception&e)
		{
			cout << *get_error_info<err_no>(e) << endl;
			cout << e.what() << endl;
			e << err_str("�ٴ��׳��쳣");
			throw e;
		}

	}

	catch (myexception&e)
	{
		cout << *get_error_info<err_str>(e) << endl;
	}
	*/

	//2.��Ϣ�����ࣨ�����Զ��壩
	
	//boost��Ԥ�������� typedef error_info<...> throw_function/throw_file/throw_line  ...
	
	/*try
	{
		throw myexception() << throw_function(BOOST_CURRENT_FUNCTION) << throw_file(__FILE__) << throw_line(__LINE__);
	}

	catch (boost::exception&e)
	{
		cout << *get_error_info<throw_function>(e)<<"  ";
		cout << *get_error_info<throw_file>(e) << "  ";
		cout << *get_error_info<throw_line>(e) << endl;
		
	}
	*/
	
	
	//�Զ�������
	/*
    #define myerror(type,name) typedef boost::error_info<struct tag_##name,type> err_double
	myerror(double,err_dou);
	try
	{
		throw myexception() <<err_str("�׳��Զ������")<< err_double(66.66);
	}
	catch (myexception&e)
	{  
		cout << *get_error_info<err_str>(e)<<":  ";
		cout << *get_error_info<err_double>(e) << endl;
	}
	*/

	//3.��װ��׼�쳣��ʹ��ģ�溯��enable_error_info(T&e),TΪ��׼�쳣����������Զ������ͣ�
	/*
	try
	{
		throw enable_error_info(myexception_a1()) << err_str("����ʹ��enable_error_info��װ��ע�쳣");
	}
	catch (boost::exception&e)//����һ��Ҫ����boost::exception�����쳣
	{
		cout << *get_error_info<err_str>(e) << endl;
	}
    */

	//4.ʹ�ú����׳��쳣(throw_exception,�д�ѧϰ��
	

	//diagnostic_information��BOOST_THROW_EXCEPTIONʹ��
	/*
	try
	{
		throw enable_error_info(myexception_a1()) << err_str("�׳��쳣") << err_no(666);
	}
	catch (boost::exception&e)
	{
		cout << diagnostic_information(e) << endl;
	}
	try
	{
		BOOST_THROW_EXCEPTION(std::logic_error("logic error"));//ע�⣬����������Ǳ�׼�쳣
	}
	catch (boost::exception&e)
	{
		cout << diagnostic_information(e) << endl;
	}
	*/
   
    cout << "�����д����������п���д.�չ��չ���" << endl;
	return 0;
}
