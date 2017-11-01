#include<iostream>
#include<windows.h>
#include<boost/version.hpp>
#include<boost/timer.hpp>

using namespace std;
using namespace boost;
int main()
{
	timer t;
	cout << "BOOST_VERSION=" <<BOOST_VERSION<< endl;
	cout <<"BOOST_LIB_VERSION=" <<BOOST_LIB_VERSION<< endl;
	cout << t.elapsed_min() << endl;
	cout << t.elapsed() << endl;
	t.restart();
	Sleep(100);
	cout << t.elapsed() << endl;
	return 0;
}