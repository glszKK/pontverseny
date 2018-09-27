#include "std_lib_facilities.h"
int main()
{
int a,b,c;
cout <<"Write two number:\n";
cin>> a;
cin>> b;
c=a;
a=(a+b)-a;
b=(b+c)-b; //2+1-2
cout <<a<<"\n";
cout<<b;
}
