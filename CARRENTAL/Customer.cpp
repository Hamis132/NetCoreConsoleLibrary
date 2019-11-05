#include "Customer.h"


Customer::Customer()
{

}

void Customer::setSomestring(int _n, string _s)
{
    switch(_n)
    {
        case 1: pesel = _s; break;
        case 2: _1stname = _s; break;
        case 3: _2ndname = _s; break;
        default: cout<<'0'; break;
    }
}

string Customer::getsomestring(int _n)
{
     switch(_n)
    {
        case 1: return pesel;  break;
        case 2: return _1stname;  break;
        case 3: return _2ndname ; break;
        default: return 0; break;
    }
}

void Customer::setSomeint(int _n, int _a)
{
      switch(_n)
    {
        case 1: age = _a; break;
        case 2: id = _a; break;
        default: cout<<'0'; break;
    }
}

int Customer::getsomeint(int _n)
{
    switch(_n)
    {
        case 1: return age; break;
        case 2: return id; break;
        default: return 0; break;
    }
}

Customer::~Customer()
{

}