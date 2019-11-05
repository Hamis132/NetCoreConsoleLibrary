#ifndef HISTORYDATA_H
#define HISTORYDATA_H
#include <iostream>
#include <fstream>
using namespace std;

class historydata
{
    private:
        string registration;
        string mark;
        string PESEL;
        string _1stname;
        string _2ndname;
        int day1 , day2;
        int month1, month2;
        int year1, year2;
        int deltamileage; 
    public:
        historydata* next;
        historydata();
        int getsomeint(int n_);
        string getsomestring(int n_);
        void setsomeint(int n_, int a_);
        void setsomestring(int n_, string s_);
        ~historydata();
};



#endif