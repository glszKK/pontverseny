#include "std_lib_facilities.h"
/* 9.4.1
struct Date {
    int y;
    int m;
    int d;
};
void init_day(Date& dd, int y, int m, int d)
{
    if (m < 1 || m > 12) error("invalid month");
    if (d < 1 || d > 31) error("impossible day");
    dd.y = y;
    dd.m = m;
    dd.d = d;
}
void add_day(Date& dd, int n)
{
    dd.d += n;
    if (dd.d > 31) dd.d %= 31;
}
ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}
int main()
{
    Date today;
    init_day(today, 1978, 6, 25);
    Date tomorrow = today;
    add_day(tomorrow, 1);
    cout << today << '\n'
         << tomorrow << '\n';
    //Date bad_day;
    //init_day(bad_day, 2004, 13, -5);
}
*/

/* 9.4.2
struct Date {
    int y, m, d;                    // year, month, day
    Date(int y, int m, int d);      // check for valid date and initialize
    void add_day(int n);            // increase the Date by n days
};
Date::Date(int yy, int mm, int dd)
    :y{yy}, m{mm}, d{dd}
{
    if (m < 1 || 12 < m) error("invalid month");
    if (d < 1 || 31 < d) error("impossible day");
}
void Date::add_day(int n)
{
    d += n;
    if (d > 31) d %= 31;
}
ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}
int main()
try {
    Date today(1978, 6, 25);
    Date tomorrow = today;
    tomorrow.add_day(1);
    cout << today << '\n'
         << tomorrow << '\n';
    //Date bad_day(2004, 13, -5);
}
catch(exception& e) {
    cerr << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "unknown error" << '\n';
    return 2;
}
*/

/* 9.4.3
class Date {
    int y, m, d;
public:
    Date(int y, int m, int d);      // check for valid date and initialize
    void add_day(int n);            // increase the Date by n days
    int month() const { return m; }
    int day() const { return d; }
    int year() const { return y; }
};
Date::Date(int yy, int mm, int dd)
    :y{yy}, m{mm}, d{dd}
{
    if (m < 1 || 12 < m) error("invalid month");
    if (d < 1 || 31 < d) error("impossible day");
}
void Date::add_day(int n)
{
    d += n;
    if (d > 31) d %= 31;
}
ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() << ')';
}
int main()
try {
    Date today(1978, 6, 25);
    Date tomorrow = today;
    tomorrow.add_day(1);
    cout << today << '\n'
         << tomorrow << '\n';
    //Date bad_day(2004, 13, -5);
}
catch(exception& e) {
    cerr << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "unknown error" << '\n';
    return 2;
}
*/

// 9.7.1

class Date {
public:
    enum Month {
        January = 1, February, March, April, May, June, July, August,
        September, October, November, December
    };
    Date () : y(1752), m(September), d(8) {}
    Date (int y, Month m, int d);
    void add_day (int n);
    int year() const {return y;}
    Month month() const {return m;}
    int day() const {return d;}
private:
    int y, d;
    Month m;
};

int days (Date::Month m, int y) {
    switch (m) {
case Date::February:
        if (y%4 == 0 && (y%100 != 0 || y%400 == 0))
            return 29;
        else
            return 28;
case Date::April: case Date::June: case Date::September:
case Date::November:
        return 30;
        break;
default:
        return 31;
        break;
    }
}

Date::Date (int y0, Date::Month m0, int d0) {
    if (y0 <= 1752 || y0 > 2080)
        error("The revised Julian and Gregorian calendars differ");
    if (d0 < 1 || d0 > days(m0,y0)) error("Invalid day");
    d = d0;
    m = m0;
    y = y0;
}

void Date::add_day (int n) {
    if (n < -500 || n > 500) error("Excessive lapse of time");
    if (n < 0)
        for (int i = 0; i < -n; ++i) {
            --d;
            if (d < 1) {
                m = Month(int(m)-1);
                if (m < January) {
                    --y;
                    if (y <= 1752) error("Decremented out of range");
                    m = December;
                }
                d = days(m,y);
            }
        }
    else
        for (int i = 0; i < n; ++i) {
            ++d;
            if (d > days(m,y)) {
                m = Month(int(m)+1);
                if (m > December) {
                    ++y;
                    if (y >= 2080) error("Incremented out of range");
                    m = January;
                }
                d = 1;
            }
        }
}

void ordinal (ostream & os, int n) {
    os << n;
    if (n%10 == 1)
        os << "st";
    else if (n%10 == 2)
        os << "nd";
    else if (n%10 == 3)
        os << "rd";
    else
        os << "th";
}

static ostream & operator<< (ostream & os, const Date::Month & mon) {
    switch (mon) {
case Date::January: os << "January"; break;
case Date::February: os << "February"; break;
case Date::March: os << "March"; break;
case Date::April: os << "April"; break;
case Date::May: os << "May"; break;
case Date::June: os << "June"; break;
case Date::July: os << "July"; break;
case Date::August: os << "August"; break;
case Date::September: os << "September"; break;
case Date::October: os << "October"; break;
case Date::November: os << "November"; break;
case Date::December: os << "December"; break;
     }
     return os;
}

ostream & operator<< (ostream & os, const Date & dd) {
    os << "This ";
    ordinal(os,dd.day());
    os << " day of " << dd.month() <<
        " in the year of Our Lord " << dd.year() << endl;
    return os;
}

int main() {
    Date today(2018,Date::December,12);
    Date tomorrow = today;
    tomorrow.add_day(1);
    cout << "Today = " << today;
    cout << "Tomorrow = " << tomorrow;
}
