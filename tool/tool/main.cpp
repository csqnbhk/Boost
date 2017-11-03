/*************************************************************
            funtion:熟悉一下第四章知识点
			注：全部内容来自"Boost程序库完全开发指南"
			    第三版（作者，罗剑锋）
			author:Demon
			Time:2017/11/3
*************************************************************/
#include<iostream>
#include<exception>
#include<boost/exception/all.hpp>
#include<boost/throw_exception.hpp>
using namespace std;
using namespace boost;
//虚继承boost::exception
struct myexception :virtual std::exception, virtual boost::exception
{
};
//使用boost::error_info
typedef  boost::error_info<struct tag_err_no, int> err_no;
typedef  boost::error_info<struct tag_err_str, std::string> err_str;

//测试使用enable_error_if(T&e)
struct myexception_a1
{

};

int main()
{


	//★exception处理机制
	/*
	   C++标准定义的异常机制：std::exception，try/catch/throw
	   std::exception派生子类：bad_alloc,bad_cast,out_of_range...

	  Boost库的异常处理机制：boost::exception（包含两个异常类）

					  { 1.exception(抽象类，除了它子类，任何人都不可以创建对象）
	  boost::exception{
					  { 2.error_info

	*/

	//1.简单应用
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
			e << err_str("再次抛出异常");
			throw e;
		}

	}

	catch (myexception&e)
	{
		cout << *get_error_info<err_str>(e) << endl;
	}
	*/

	//2.信息错误类（可以自定义）
	
	//boost库预定义类型 typedef error_info<...> throw_function/throw_file/throw_line  ...
	
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
	
	
	//自定义类型
	/*
    #define myerror(type,name) typedef boost::error_info<struct tag_##name,type> err_double
	myerror(double,err_dou);
	try
	{
		throw myexception() <<err_str("抛出自定义错误")<< err_double(66.66);
	}
	catch (myexception&e)
	{  
		cout << *get_error_info<err_str>(e)<<":  ";
		cout << *get_error_info<err_double>(e) << endl;
	}
	*/

	//3.包装标准异常（使用模版函数enable_error_info(T&e),T为标准异常类或者其它自定义类型）
	/*
	try
	{
		throw enable_error_info(myexception_a1()) << err_str("测试使用enable_error_info包装标注异常");
	}
	catch (boost::exception&e)//这里一定要是有boost::exception捕获异常
	{
		cout << *get_error_info<err_str>(e) << endl;
	}
    */

	//4.使用函数抛出异常(throw_exception,有待学习）
	

	//diagnostic_information和BOOST_THROW_EXCEPTION使用
	/*
	try
	{
		throw enable_error_info(myexception_a1()) << err_str("抛出异常") << err_no(666);
	}
	catch (boost::exception&e)
	{
		cout << diagnostic_information(e) << endl;
	}
	try
	{
		BOOST_THROW_EXCEPTION(std::logic_error("logic error"));//注意，在这里必须是标准异常
	}
	catch (boost::exception&e)
	{
		cout << diagnostic_information(e) << endl;
	}
	*/
   
    cout << "今天就写到这里，改天有空再写.收工收工∵" << endl;
	return 0;
}
