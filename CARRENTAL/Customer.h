#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <fstream>
using namespace std;

class Customer
{

    private:
        string pesel;
        string _1stname;
        string _2ndname;
        int age;
        int id;
    public:
        Customer();
        Customer* next;
        void setSomestring(int n_, string s_);
        string getsomestring(int n_);
        void setSomeint(int n_, int a_);
        int getsomeint(int n_);
        ~Customer();

};


#endif