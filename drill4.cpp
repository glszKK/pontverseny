#include"std_lib_facilities.h"
using namespace std;

int main()
{
double a,largest,smallest;
largest=0;
smallest=5;
while (a!='|')
{
cin>>a;

if  (a>largest)
{
    largest=a;

}
else if (a==largest)
{
    cout<<"the largest so far";
}
else if (a<smallest)
{
    smallest=a;
}
else if (a==smallest)
{
    cout<<"the smallest so far";
}
else if (smallest=0)
{
    smallest=largest;
}
}
}
