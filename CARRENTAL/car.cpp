#include "car.h"


car::car()
{

}

void car::setSomestring(int _n, string _s)
{
    switch(_n)
    {
        case 1: model = _s; break;
        case 2: mark = _s; break;
        case 3: VIN = _s; break;
        case 4: Registration = _s; break;
        default: cout<<'0'; break;
    }
}

string car::getsomestring(int _n)
{
     switch(_n)
    {
        case 1: return model; break;
        case 2: return mark; break;
        case 3: return VIN; break;
        case 4: return Registration; break;
        default: return 0; break;
    }
}

void car::setSomeint(int _n, int _a)
{
      switch(_n)
    {
        case 1: mileage = _a; break;
        case 2: acceleration = _a; break;
        case 3: id = _a; break;
        case 4: pseudobool = _a; break;
        default: cout<<'0'; break;
    }
}

int car::getsomeint(int _n)
{
    switch(_n)
    {
        case 1: return mileage; break;
        case 2: return acceleration; break;
        case 3: return id; break;
        case 4: return pseudobool; break;
        default: return 0; break;
    }
}

car::~car()
{

}