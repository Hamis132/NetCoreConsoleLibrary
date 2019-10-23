#ifndef CLASSA_H
#define CLASSA_H
#include <iostream>
#include "classB.h"

class classA
{
    public:
        classA();
        classB* reTurn();
        ~classA();
};


#endif