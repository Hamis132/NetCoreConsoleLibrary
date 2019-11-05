#ifndef SORTING_H
#define SORTING_H
#include "car.h"
#include "Customer.h"
#include "historydata.h"
#include "carrentallibrary.h"
#include <iostream>
#include <fstream>


class sorting : public carrentallibrary
{
    public:
        sorting();
        void Clientssortalgorithm();
        void Carssortalgorithm();
        void Historysortalgorithm();
        void sortingfunctioncust1(int x_);
        void sortingfunctioncust2(int x_);
        ~sorting();
};


#endif