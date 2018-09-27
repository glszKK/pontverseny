#include "std_lib_facilities.h"
int main()
{
    int a=6;
    int b=9;

    cout << "Eredeti ertekek: "
         << " a = " <<a
         << " b = " <<b
         <<endl;

    a=a^b;
    b=a^b;
    a=a^b;

    cout <<"Uj ertekek: "
         << " a = " <<a
         << " b = " <<b
         <<endl;
}
