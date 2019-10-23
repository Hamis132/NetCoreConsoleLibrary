#include <iostream>
#include "classB.h"
#include "classA.h"
using namespace std;

int main()
{
    classB* b;
    classA* a = new classA; 
    b = a->reTurn();
    cout<<b -> a;
}