#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <fstream>
using namespace std;

class car
{
    private:
        int mileage;
        int acceleration;
        string model;
        string mark;
        string VIN;
        string Registration;
        int pseudobool;
        int id;
    public:
   
        car();
        car* next;
        void setSomestring(int n_, string s_);
        string getsomestring(int n_);
        void setSomeint(int n_, int a_);
        int getsomeint(int n_);
        ~car();
        

};



#endif