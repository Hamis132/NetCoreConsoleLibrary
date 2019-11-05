#include "historydata.h"


historydata::historydata()
{

}

int historydata::getsomeint(int _n)
{
    switch(_n)
    {
        case 1: return day1; break;
        case 2: return month1; break;
        case 3: return year1; break;
        case 4: return day2; break;
        case 5: return month2; break;
        case 6: return year2; break;
        case 7: return deltamileage; break;
        default: return 0; break;
    }
}

string historydata::getsomestring(int _n)
{
    switch(_n)
    {
        case 1: return registration;  break;
        case 2: return mark;  break;
        case 3: return PESEL; break;
        case 4: return _1stname; break;
        case 5: return _2ndname; break;
        default: return 0; break;
    }
}

void historydata::setsomeint(int _n, int _a)
{
     switch(_n)
    {
        case 1: day1 = _a; break;
        case 2: month1 = _a; break;
        case 3: year1 = _a; break;
        case 4: day2 = _a; break;
        case 5: month2 = _a; break;
        case 6: year2 = _a; break;
        case 7: deltamileage = _a; break;
        default: cout<<"0"; break;
    }
}

void historydata::setsomestring(int _n, string _s)
{
    switch(_n)
    {
        case 1: registration = _s; break;
        case 2: mark = _s; break;
        case 3: PESEL = _s; break;
        case 4: _1stname = _s; break;
        case 5: _2ndname = _s; break;
        default: cout<<'0'; break;
    }
}

historydata::~historydata()
{

}