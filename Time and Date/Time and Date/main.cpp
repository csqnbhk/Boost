/*************************************************************************************
            function:���ļ�����һ�µڶ���֪ʶ��
			ע��ȫ�����ݾ�����:"Boost�������ȫ����ָ��"���������
            author��Demon
			Time:2017/11/1                           
***************************************************************************************/
#include<iostream>
#include<Windows.h>
#include<boost/timer.hpp>
#include<boost/progress.hpp>
//��������
#include<boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;
//����ʱ��
#include<boost/date_time/posix_time/posix_time.hpp>
using namespace boost::posix_time;

using namespace std;
using namespace boost;

int main()
{
	//�����timer�⣨��ʱ��timer,progress_timer�ͽ���ָʾ��progress_display)

	//��1.timer���
	/*
	timer t;
	cout << "����timer��ʹ��" << endl;
	cout << "t.elased_max=" << t.elapsed_max() << endl;
	cout << "t.elased_min=" << t.elapsed_min() << endl;
	cout << "t.elased=" << t.elapsed() << endl;
	cout << "�����趨��ʱ��" << endl;
	t.restart();
	Sleep(1000);
	cout << "��ʱt.elased=" << t.elapsed() << endl;
	*/

	//��2.progress_timer(�̳�timer��
	/*
	{
		progress_timer p_t;
		Sleep(200);
	}
	cout << "���������Զ����ʱ�䣬����(Ĭ�ϵ�ָ������std::cout)" << endl;
	*/

	//��3.progress_display
	/*
	//progress_display p_d(1000);
	progress_display p_d(1000, std::cout, "�ٷֱ�", "����ͼ", "������");
	auto i = 100;
	while (i)
	{
		p_d+= 10;
		i--;
		Sleep(50);
	}
	*/


	//�����date_time��
	/*
	//��1.�������ڶ���
	date d1;
	date d2(2017, 11, 1);
	date d3(2017, Nov, 1);
	date d_copy(d3);
	//ʹ�ú���from_string����б�ܻ������ַ�����from_undelimited_string��(���ַ���)
	date d_f_s = from_string("2017-11-1");
	date d_f_s1 = from_string("2017/11/1");
	date d_f_u_s = from_undelimited_string("20171101");
	//�ȽϺ͸�ֵ
	assert(d1 == date(not_a_date_time));//�Ƚ�һ����ʱ����
	assert(d2 == d3);
	assert(!(d2 <d_copy));
	//��2.��������
	assert(d2.year() == 2017);
	assert(d2.month() == 11);
	date::ymd_type ymd = d2.year_month_day();
	assert(ymd.year == 2017);
	assert(ymd.month == 11);
	assert(ymd.day == 1);
	auto d_o_w = d2.day_of_week();
	auto d_o_y = d2.day_of_year();
	auto d_end_m = d2.end_of_month();//���ظ������һ���date����
	cout << "�ڼ���:" << d_o_w << endl;
	cout << "�ڼ��죺" << d_o_y << endl;

	//��3���������(to_simple_string,ת��ΪYYY-mmm-DD��ʽ.
    //            to_iso_stringת��ΪYYYYMMDD��ʽ�������ַ���.
	//            to_iso_extended_string,ת��ΪYYYY-MM-DD��ʽ�������ַ�����
	cout << to_simple_string(d1) << endl;
	cout << to_simple_string(d2) << endl;;
	cout << to_iso_string(d2) << endl;
	cout << to_iso_extended_string(d2) << endl;

	//��4.date��tm����ת����to_tm,date_from_tm
	date d22(2017, 10, 29);
	cout << "dateתtm" << endl;
	tm t_m = to_tm(d22);
	cout << t_m.tm_year<< endl;//�����Ǻ�������������´θ�һ�£�������������
	cout << t_m.tm_mon << endl;
	cout << t_m.tm_mday << endl;
	cout << "t_m.tm.yday=" << t_m.tm_yday << endl;
	cout << "tm_hour,tm_min,tm_secΪ0" << endl;
	cout << "t_m.tm_hour=" << t_m.tm_hour << endl;
	*/

	cout << "û��д�꣬������д��" << endl;
	return 0;
}