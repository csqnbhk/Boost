/*************************************************************************************
            function:该文件测试一下第二章知识点
	    注：全部内容均来自:"Boost程序库完全开发指南"该书第三版
            author：Demon
	    Time:2017/11/1                           
*************************************************************************************/
#include<iostream>
#include<Windows.h>
#include<boost/timer.hpp>
#include<boost/progress.hpp>
//处理日期
#include<boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;
//处理时间
#include<boost/date_time/posix_time/posix_time.hpp>
using namespace boost::posix_time;

using namespace std;
using namespace boost;

int main()
{
	//★★★★timer库（计时器timer,progress_timer和进度指示器progress_display)

	//■1.timer组件
	/*
	timer t;
	cout << "这是timer的使用" << endl;
	cout << "t.elased_max=" << t.elapsed_max() << endl;
	cout << "t.elased_min=" << t.elapsed_min() << endl;
	cout << "t.elased=" << t.elapsed() << endl;
	cout << "重新设定定时器" << endl;
	t.restart();
	Sleep(1000);
	cout << "此时t.elased=" << t.elapsed() << endl;
	*/

	//■2.progress_timer(继承timer）
	/*
	{
		progress_timer p_t;
		Sleep(200);
	}
	cout << "对象析构自动输出时间，如上(默认的指定流是std::cout)" << endl;
	*/

	//■3.progress_display
	/*
	//progress_display p_d(1000);
	progress_display p_d(1000, std::cout, "百分比", "简视图", "进度条");
	auto i = 100;
	while (i)
	{
		p_d+= 10;
		--i;
		Sleep(50);
	}
	*/


	//★★★★date_time库
	/*
	//◆1.构建日期对象
	date d1;
	date d2(2017, 11, 1);
	date d3(2017, Nov, 1);
	date d_copy(d3);
	//使用函数from_string，（斜杠或者连字符）。from_undelimited_string，(纯字符串)
	date d_f_s = from_string("2017-11-1");
	date d_f_s1 = from_string("2017/11/1");
	date d_f_u_s = from_undelimited_string("20171101");
	//比较和赋值
	assert(d1 == date(not_a_date_time));//比较一个临时对象
	assert(d2 == d3);
	assert(!(d2 <d_copy));
	//◆2.访问日期
	assert(d2.year() == 2017);
	assert(d2.month() == 11);
	date::ymd_type ymd = d2.year_month_day();
	assert(ymd.year == 2017);
	assert(ymd.month == 11);
	assert(ymd.day == 1);
	auto d_o_w = d2.day_of_week();
	auto d_o_y = d2.day_of_year();
	auto d_end_m = d2.end_of_month();//返回该月最后一天的date对象
	cout << "第几周:" << d_o_w << endl;
	cout << "第几天：" << d_o_y << endl;

	//◆3。日期输出(to_simple_string,转化为YYY-mmm-DD格式.
    //            to_iso_string转化为YYYYMMDD格式的数字字符串.
	//            to_iso_extended_string,转化为YYYY-MM-DD格式的数字字符串）
	cout << to_simple_string(d1) << endl;
	cout << to_simple_string(d2) << endl;;
	cout << to_iso_string(d2) << endl;
	cout << to_iso_extended_string(d2) << endl;

	//◆4.date和tm互相转化。to_tm,date_from_tm
	date d22(2017, 10, 29);
	cout << "date转tm" << endl;
	tm t_m = to_tm(d22);
	cout << t_m.tm_year<< endl;//还不是很清楚如何输出，下次改一下？？？？？？？
	cout << t_m.tm_mon << endl;
	cout << t_m.tm_mday << endl;
	cout << "t_m.tm.yday=" << t_m.tm_yday << endl;
	cout << "tm_hour,tm_min,tm_sec为0" << endl;
	cout << "t_m.tm_hour=" << t_m.tm_hour << endl;
	*/

	cout << "没有写完，改天再写。" << endl;
	return 0;
}
