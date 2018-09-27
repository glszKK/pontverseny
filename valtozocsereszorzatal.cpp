#include "std_lib_facilities.h"

int main()
{


	int a = 9;
	int b = 6;
	cout<<"Before : "<< a << " "<< b << endl;
	a = a * b;
	b = a / b;
	a = a / b;

	cout <<"After : "<< a << " " << b << endl;
}
