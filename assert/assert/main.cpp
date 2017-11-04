/*****************************************************
        function:��Ҫѧϰassert(�����£�
		author:Demon
		time:2017/11/4
*****************************************************/
//#define BOOST_DISABLE_ASSERTS//���ö���
//#define BOOST_ENABLE_ASSERT_HANDLER//�ᵼ��BOOST_ASSERT,BOOST_ASSERT_MSG��Ϊ�仯
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
//�Լ�ʵ��boost��assertion_failed,��assertion_failed_msg
/*
void f(int x)
{
	BOOST_ASSERT(x!=0);
}
void f_msg(int x)
{
	BOOST_ASSERT_MSG(x != 0,"BOOST_ASSERT_MSG����");
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
//execution_monitor���Լ�ط���ֵΪint���߿�ת��Ϊint�ĺ���
/*
int e_m()
{
	string str("����string");
	throw "����C�ַ����쳣";//�׳��쳣�����������֣�1.C�ַ��� 2.std::string 3.std::exception�ſ��Ա�execution_exception����
	//throw str;
	//throw std::logic_error("����std::exception�쳣");
	return 1;
}
*/

int main()
{

	//1.assert
	/*
	BOOST_ASSERT(8 == 8);
	BOOST_ASSERT_MSG(8 == 7, "8������7");
	*/

	//2.����boost���ԣ�ͷ�ļ�ǰ�涨��BOOST_DISABLE_ASSERTS)
	/*
	BOOST_ASSERT(1 == 2);
	BOOST_ASSERT_MSG(1 == 2, "���ö��ԣ�boost���Բ������ã���׼assert��Ӱ��");
	assert(1 == 2);
	*/

	//3.BOOST_ENABLE_ASSERT_HANDLER�Ķ����BOOST_ASSERTӰ��
	//(�Լ�ʵ��boost��assertion_failed,��assertion_failed_msg���������Զ����ã�
	/*
	BOOST_ASSERT(1 == 2);
	f(0);
	f_msg(0);
	*/

	//4.static_assert(����ʱ���ԣ�asser��������ʱ����)
	//BOOST_STATIC_ASSERT��BOOST_STATIC_ASSERT_MSG,�����������֧��static_assert,
	//BOOST_STATIC_ASSERT_MSG��ͬ��BOOST_STATIC_ASSERT
	/*
	BOOST_STATIC_ASSERT(1 == 2);
	BOOST_STATIC_ASSERT(1 == 1);
	BOOST_STATIC_ASSERT_MSG(1 == 2��"66");//��֧��
	BOOST_STATIC_ASSERT_MSG(1 == 1��"77");
	*/

	//5.lightweight_test(5�����ǵ�return boost::report_errors()���о�ͦ�õģ�
	/*
	BOOST_TEST(1 == 2);
	BOOST_ERROR("����ʧ�ܣ�");
	BOOST_TEST_EQ(1, 2);//�ж��������ʽ���
	BOOST_TEST_NE(1, 1);//�ж��������ʽ�����
	BOOST_TEST_THROWS(1 == 2,std::exception);
	return boost::report_errors();//�����Ӿͳ���Ͳ����ж�,���������Ϣ
	*/

	//6.����Ԫ���(BOOST_TEST_TRAIT_FALSE/TRUE���ʹ�ã�
	/*
	BOOST_TEST_TRAIT_FALSE((is_integral<int>));
	BOOST_TEST_TRAIT_TRUE((is_function<int>));
	return boost::report_errors();
    */

	//7.Ԥ�����(BOOST_CHECK,BOOST_REQUIRE,BOOST_ERROR,BOOST_FAIL)(������ô��Ϥ����ʱ���ڿ�����������������

    //8.������־

	//9.����ִ�м�������exception_monitor)
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
		cout << "�����п���д�쳣�����ڲ���д�ˡ��չ��չ���" << endl;
	}
	
	return 0;
}