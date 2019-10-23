#include "classA.h"
#include "classB.h"


classA::classA()
{

}

classB* classA::reTurn()
{
    classB* b;
    b = new classB;
    b ->a = 1;
    return b;
}


classA::~classA()
{

}