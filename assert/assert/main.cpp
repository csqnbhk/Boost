/*****************************************************
        function:主要学习assert(第六章）
		author:Demon
		time:2017/11/4
*****************************************************/
//#define BOOST_DISABLE_ASSERTS//禁用断言
//#define BOOST_ENABLE_ASSERT_HANDLER//会导致BOOST_ASSERT,BOOST_ASSERT_MSG行为变化
#include<iostream>
#include<cassert>
#include<boost/assert.hpp>
#include<boost/format.hpp>
#include<boost/static_assert.hpp>
#include<boost/core/lightweight_test.hpp>
#include<boost/core/lightweight_test_trait.hpp>
#include<boost/test/execution_monitor.hpp>
#include<boost/test/prg_exec_monitor.hpp>

using namespace std;
using namespace boost;
//自己实现boost的assertion_failed,和assertion_failed_msg
/*
void f(int x)
{
	BOOST_ASSERT(x!=0);
}
void f_msg(int x)
{
	BOOST_ASSERT_MSG(x != 0,"BOOST_ASSERT_MSG断言");
}
namespace boost
{
	void assertion_failed(char const*expr,char const*function,char const*file,long line)
	{
		cout << "Assertion failed" << endl;
		cout << "Expression:" << expr << endl;
		cout << "Function:" << function << endl;
		cout << "File:" << file << endl;
		cout << "Line:" << line << endl;

	}
	void assertion_failed_msg(char const*expr, char const*msg, char const*function, char const*file, long line)
	{
		boost::format fmt("Assertion failed!\nExpression:%s\n"
			              "Function:%s\nFile:%s\nLine:%ld\n"
			              "Msg:%s\n");
		fmt%expr%function%file%line%msg;
		cout << fmt;
	}
}
*/
/*
void test()
{

}
*/
//execution_monitor可以监控返回值为int或者可转化为int的函数
/*
int e_m()
{
	string str("我是string");
	throw "我是C字符串异常";//抛出异常必须是这三种：1.C字符串 2.std::string 3.std::exception才可以被execution_exception处理
	//throw str;
	//throw std::logic_error("我是std::exception异常");
	return 1;
}
*/

int main()
{

	//1.assert
	/*
	BOOST_ASSERT(8 == 8);
	BOOST_ASSERT_MSG(8 == 7, "8不等于7");
	*/

	//2.禁用boost断言（头文件前面定义BOOST_DISABLE_ASSERTS)
	/*
	BOOST_ASSERT(1 == 2);
	BOOST_ASSERT_MSG(1 == 2, "禁用断言，boost断言不可以用，标准assert不影响");
	assert(1 == 2);
	*/

	//3.BOOST_ENABLE_ASSERT_HANDLER的定义对BOOST_ASSERT影响
	//(自己实现boost的assertion_failed,和assertion_failed_msg函数，会自动调用）
	/*
	BOOST_ASSERT(1 == 2);
	f(0);
	f_msg(0);
	*/

	//4.static_assert(编译时断言，asser宏是运行时断言)
	//BOOST_STATIC_ASSERT和BOOST_STATIC_ASSERT_MSG,如果编译器不支持static_assert,
	//BOOST_STATIC_ASSERT_MSG等同于BOOST_STATIC_ASSERT
	/*
	BOOST_STATIC_ASSERT(1 == 2);
	BOOST_STATIC_ASSERT(1 == 1);
	BOOST_STATIC_ASSERT_MSG(1 == 2，"66");//不支持
	BOOST_STATIC_ASSERT_MSG(1 == 1，"77");
	*/

	//5.lightweight_test(5个，记得return boost::report_errors()，感觉挺好的）
	/*
	BOOST_TEST(1 == 2);
	BOOST_ERROR("断言失败！");
	BOOST_TEST_EQ(1, 2);//判断两个表达式相等
	BOOST_TEST_NE(1, 1);//判断两个表达式不相等
	BOOST_TEST_THROWS(1 == 2,std::exception);
	return boost::report_errors();//这样子就程序就不会中断,输出错误信息
	*/

	//6.测试元编程(BOOST_TEST_TRAIT_FALSE/TRUE宏的使用）
	/*
	BOOST_TEST_TRAIT_FALSE((is_integral<int>));
	BOOST_TEST_TRAIT_TRUE((is_function<int>));
	return boost::report_errors();
    */

	//7.预测断言(BOOST_CHECK,BOOST_REQUIRE,BOOST_ERROR,BOOST_FAIL)(还不怎么熟悉，到时候在看看？？？？？？）

    //8.测试日志

	//9.函数执行监视器（exception_monitor)
	/*
	boost::execution_monitor em;
	try
	{
		em.execute(e_m);
	}
	catch (execution_exception&e)
	{
		cout << e.what().begin() << endl;
	}
	*/
    
	try
	{
		throw "886";
	}
	catch (...)
	{
		cout << "改天有空再写异常，现在不想写了。收工收工∵" << endl;
	}
	
	return 0;
}