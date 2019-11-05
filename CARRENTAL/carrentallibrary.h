#ifndef CARRENTALLIBRARY_H
#define CARRENTALLIBRARY_H
#include "car.h"
#include "Customer.h"
#include "historydata.h"
#include <iostream>
#include <fstream>

struct handoveredcars
{
        int id = 0;
        string name;
        string surname;
        string pesel;
        string registration;
        handoveredcars* next;
};

class carrentallibrary
{ 
    public:
        car* headc;
        Customer* headCu;
        historydata* headH;

        int amountofclints;
        int amountofcars;
        int historydataamount;
        
        handoveredcars* headm = NULL;
        handoveredcars* previousmess;
        int messages = 0;
        
        int day = 10;
        int month = 8;
        int year = 2018;

        carrentallibrary();
        car* structcurrentcarlist(int amount_of_cars);
        void savedatabeforedeleting(Customer* tmp_, int tmpid_);
        car* findreturn(int id_);
        void changeparameter(car* tmp_, int mileage_);
        void deletecustomer(Customer* tmp_, bool f_);
        void Clientssortalgorithm();
        void Carssortalgorithm();
        void Historysortalgorithm();
        void sortingfunctioncust1(int x_);
        void sortingfunctioncust2(int x_);
        void sortingfunctioncar1(int x_);
        void sortingfunctioncar2(int x_);
        void sortingfunctionhist1(int x_);
        void sortingfunctionhist2(int x_);
        void findcarthroughid(int id_);
        string rentcar(int x_);
        Customer* structcurrentcustomerlist(int customers);  
        historydata* structcurrenthistorydatalist(int amount_of_data);    
        bool iscustomerexists(string a_);
        bool iscaravailable(int id_);
        int findcustomerid(string id_);
        Customer* findcustomer(int id_);
        void showhistory(string a_, bool _b);
        void listofreturns();
        void showrenting(int a_, string k_);
        void findcarby(int option_);
        void showclientsdata(string pesel_);
        virtual ~carrentallibrary();
};

#endif