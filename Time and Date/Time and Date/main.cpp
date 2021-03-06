/*********************************************************************************
function:该文件测试一下第二章知识点
注：全部内容均来自:"Boost程序库完全开发指南"该书第三版
author：Demon
Time:2017/11/1
**********************************************************************************/
//#define BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG//定义这个time_duration精确到纳秒
/*********************************************************************************/
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

//本地时间
#include<boost/date_time/local_time/local_time.hpp>
using namespace boost::local_time;

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

	//◆1.构建日期对象
	/*date d1;
	date d2(2017, 11, 1);
	date d3(2017, Nov, 1);
	date d_copy(d3);*/
	//使用函数from_string，（斜杠或者连字符）。from_undelimited_string，(纯字符串)
	/*date d_f_s = from_string("2017-11-1");
	date d_f_s1 = from_string("2017/11/1");
	date d_f_u_s = from_undelimited_string("20171101");*/
	//比较和赋值
	/*
	assert(d1 == date(not_a_date_time));//比较一个临时对象
	assert(d2 == d3);
	assert(!(d2 <d_copy));
	*/
	//◆2.访问日期
	/*
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
	*/
	//◆3。日期输出(to_simple_string,转化为YYY-mmm-DD格式.
	//to_iso_string转化为YYYYMMDD格式的数字字符串.
	//to_iso_extended_string,转化为YYYY-MM-DD格式的数字字符串）

	/*
	cout << to_simple_string(d1) << endl;
	cout << to_simple_string(d2) << endl;;
	cout << to_iso_string(d2) << endl;
	cout << to_iso_extended_string(d2) << endl;
	*/

	//◆4.date和tm互相转化。to_tm,date_from_tm
	/*
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


	//◆5.日期长度类（date_duration),typedef date_duration days
	//还有months,years,weeks这几个类
	/*
	date_duration d1(15);
	days d2(112);
	cout << "d1=" << d1<<endl;
	cout << "d2=" << d2<< endl;
	weeks w(2);
	cout << w.days() << endl;
	months m(2);
	cout << m.number_of_months() << endl;
	years y(2);
	cout << y.number_of_years() << endl;
	*/

	//◆6.日期运算（对date对象进行加操作没有什么意义）
	/*
	date d1(2017, 11, 2);
	date d2(2016, 10, 23);
	//date d3 = d1 + d2;//无意义做法，编译不能通过
	date d4 = (d1 + (d1 - d2));
	date d5(2017, 11, 1);
	cout<<d1 - d2<<endl;
	cout << to_simple_string(d4) << endl;
	*/

	//◆7.日期区间（date_time使用date_period类表示日期区间）,(时间区间：time_period)
	/*
	date_period d_p1(date(2017, 11, 2), days(10));
	date_period d_p2(date(2017, 11, 1), date(2017, 11, 11));//没怎么用这个构造函数
	cout << d_p1 << endl;
	cout << d_p1.length().days() << endl;
	*/


	//◆8.日期迭代器（day_iterator,week_iterator,month_iterator,year_iterator)，（也有时间迭代器）
	/*
	date d1(2017, 11, 10);
	day_iterator  it(d1);
	++it; //注意：只有重载了的运算符才可以用，比如it+=5;错误
	cout << *it << endl;
	*/

	//◆9.时间长度的精确度（date_time默认是微妙）
	/*
	time_duration td1(0, 0, 10, 666);
	cout << "td1=" << td1 << endl;
	cout << td1.num_fractional_digits() << endl;
	//定义宏BOOST_TIME_POSIX_TIME_STD_CONFIG(可以精确到纳秒）
	{
	time_duration td2(0, 0, 10, 66667777);
	cout << "td2=" << td2 << endl;
	cout << td2.num_fractional_digits() << endl;
	if (td2.resolution() == date_time::nano)
	{
	cout << "这是纳秒" << endl;
	}
	}
	*/

	//◆10.时间点对象（ptime类）,second_clock和microsec_clock为ptime类提供时钟类
	/*
	ptime pt1 = second_clock::local_time();
	ptime pt2 = microsec_clock::local_time();
	cout << "pt1=" << pt1 << endl;
	cout << "pt2=" << pt2 << endl;
	//世界时间（格林时间）
	pt1 = second_clock::universal_time();
	pt2 = microsec_clock::universal_time();
	cout << "pt1 universal_time=" << pt1 << endl;
	cout << "pt2 universal_time=" << pt2 << endl;
	*/

	//◆11.时间点对象的简单操作（可以分解非操作date,time_duration)
	/*
	ptime p1(date(2017, 11, 2), hours(15) + minutes(07));
	date d = p1.date();
	time_duration td = p1.time_of_day();
	cout << d << endl;
	cout << td << endl;
	*/

	//◆12.本地时间(不写了，熟悉一点再写）
	/*
	tz_database tz_db;//定义时区数据库对象
	tz_db.load_from_file(R"(E:\Boost\boost_1_65_1\libs\date_time\data\date_time_zonespec.csv)");
	//获取
	time_zone_ptr sfz = tz_db.time_zone_from_region("America/Los_Angeles");
	time_zone_ptr Hong_kong = tz_db.time_zone_from_region("Asia/Hong_Kong");
	cout << sfz->has_dst() << endl;
	cout << sfz->std_zone_name() << endl;
	cout << Hong_kong->has_dst() << endl;
	cout << Hong_kong->std_zone_name() << endl;
	*/

	cout << "没写完,改天有空再写！" << endl;

	//错误记录
	/*
	warning C4819: 该文件包含不能在当前代码页(936)中表示的字符。解决如下：
	1.打开引起警告C4819的文件，展开“文件”->“高级保存选项...”
	2.在“高级保存选项”对话框中，设置“编码”的值为“Unicode－代码页1200”
	3.确定后，保存文件，再编译就可以。
	*/
	return 0;
}