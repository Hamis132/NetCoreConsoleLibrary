
#include "carrentallibrary.h"



void carrentallibrary::Clientssortalgorithm()
{
    int k = 0;

    cout<<"\n\n by which parameter would you like to sort \n"
        <<"1. age  \n"
        <<"2. first name \n"
        <<"3. sec name \n"
        <<"4. id \n";
    
        cin>>k;

    switch(k)
    {
        case 1: sortingfunctioncust2(1); break;
        case 2: sortingfunctioncust1(2); break;
        case 3: sortingfunctioncust1(3); break;
        case 4: sortingfunctioncust2(2); break;
        default: break;
    }
}

void carrentallibrary::sortingfunctioncust2(int _x)
{
    Customer* tmp = headCu;
    Customer* tmp1 = headCu -> next;
    Customer* tmp2 = tmp1 -> next;
    Customer* tmp3 = tmp2 -> next; 

    for(int i=0; i<amountofclints; i++)
    {
        for(int j=0; j<amountofclints-3; j++)
        {

    
            if(j == 0 && tmp->getsomeint(_x) > tmp1->getsomeint(_x))
            {
                headCu = tmp1;
                tmp1 -> next = tmp;
                tmp -> next = tmp2;
            }
            else if(tmp3 -> next == NULL && tmp2->getsomeint(_x) > tmp3->getsomeint(_x))
            {
                tmp1 -> next = tmp3;
                tmp3 ->next = tmp2;
                tmp2 -> next = NULL;

           
            }
            else if(tmp1->getsomeint(_x) > tmp2->getsomeint(_x))
            {
                tmp1 -> next = tmp3;
                tmp2 -> next = tmp1;
                tmp -> next = tmp2;

       
            }
            
            if(tmp3 -> next != NULL)
            {
                tmp = tmp -> next;
                tmp1 = tmp -> next;
                tmp2 = tmp1 -> next;
                tmp3 = tmp2 -> next;
            }
        }
        
        tmp = headCu;
        tmp1 = headCu -> next;
        tmp2 = tmp1 -> next;
        tmp3 = tmp2 -> next;
        
    }
}

void carrentallibrary::sortingfunctioncust1(int _x)
{

    Customer* tmp = headCu;
    Customer* tmp1 = headCu -> next;
    Customer* tmp2 = tmp1 -> next;
    Customer* tmp3 = tmp2 -> next; 

    for(int i=0; i<amountofclints; i++)
    {
        for(int j=0; j<amountofclints-3; j++)
        {

    
            if(j == 0 && tmp->getsomestring(_x)[0] > tmp1->getsomestring(_x)[0])
            {
                headCu = tmp1;
                tmp1 -> next = tmp;
                tmp -> next = tmp2;
            }
            else if(tmp3 -> next == NULL && tmp2->getsomestring(_x)[0] > tmp3->getsomestring(_x)[0])
            {
                tmp1 -> next = tmp3;
                tmp3 ->next = tmp2;
                tmp2 -> next = NULL;

           
            }
            else if(tmp1->getsomestring(_x)[0] > tmp2->getsomestring(_x)[0])
            {
                tmp1 -> next = tmp3;
                tmp2 -> next = tmp1;
                tmp -> next = tmp2;

       
            }
            
            if(tmp3 -> next != NULL)
            {
                tmp = tmp -> next;
                tmp1 = tmp -> next;
                tmp2 = tmp1 -> next;
                tmp3 = tmp2 -> next;
            }
        }
        
        tmp = headCu;
        tmp1 = headCu -> next;
        tmp2 = tmp1 -> next;
        tmp3 = tmp2 -> next;
        
    }
}


void carrentallibrary::Carssortalgorithm()
{
    int k = 0;

    cout<<"\n\n by which parameter would you like to sort \n"
        <<"1. mileage \n"
        <<"2. acceleration \n"
        <<"3. id \n"
        <<"4. model \n"
        <<"5. mark \n"
        <<"6. registration \n";
    
        cin>>k;

    switch(k)
    {
        case 1: sortingfunctioncar2(1); break;
        case 2: sortingfunctioncar2(2); break;
        case 3: sortingfunctioncar2(3); break;
        case 4: sortingfunctioncar1(1); break;
        case 5: sortingfunctioncar1(2); break;
        case 6: sortingfunctioncar1(4); break;
        default: break;
    }
}



void carrentallibrary::sortingfunctioncar1(int _x)
{
    car* tmp = headc;
    car* tmp1 = headc -> next;
    car* tmp2 = tmp1 -> next;
    car* tmp3 = tmp2 -> next; 


    for(int i=0; i<amountofcars; i++)
    {
        for(int j=0; j<amountofcars-3; j++)
        {

    
            if(j == 0 && tmp->getsomestring(_x)[0] > tmp1->getsomestring(_x)[0])
            {
                headc = tmp1;
                tmp1 -> next = tmp;
                tmp -> next = tmp2;
            }
            else if(tmp3 -> next == NULL && tmp2->getsomestring(_x)[0] > tmp3->getsomestring(_x)[0])
            {
                tmp1 -> next = tmp3;
                tmp3 ->next = tmp2;
                tmp2 -> next = NULL;

           
            }
            else if(tmp1->getsomestring(_x)[0] > tmp2->getsomestring(_x)[0])
            {
                tmp1 -> next = tmp3;
                tmp2 -> next = tmp1;
                tmp -> next = tmp2;

       
            }
            
            if(tmp3 -> next != NULL)
            {
                tmp = tmp -> next;
                tmp1 = tmp -> next;
                tmp2 = tmp1 -> next;
                tmp3 = tmp2 -> next;
            }
        }
        
        tmp = headc;
        tmp1 = headc -> next;
        tmp2 = tmp1 -> next;
        tmp3 = tmp2 -> next;
        
    }
}

void carrentallibrary::sortingfunctioncar2(int _x)
{
    car* tmp = headc;
    car* tmp1 = headc -> next;
    car* tmp2 = tmp1 -> next;
    car* tmp3 = tmp2 -> next; 

    for(int i=0; i<amountofcars; i++)
    {
        for(int j=0; j<amountofcars-3; j++)
        {

    
            if(j == 0 && tmp->getsomeint(_x) > tmp1->getsomeint(_x))
            {
                headc = tmp1;
                tmp1 -> next = tmp;
                tmp -> next = tmp2;
            }
            else if(tmp3 -> next == NULL && tmp2->getsomeint(_x) > tmp3->getsomeint(_x))
            {
                tmp1 -> next = tmp3;
                tmp3 ->next = tmp2;
                tmp2 -> next = NULL;

           
            }
            else if(tmp1->getsomeint(_x) > tmp2->getsomeint(_x))
            {
                tmp1 -> next = tmp3;
                tmp2 -> next = tmp1;
                tmp -> next = tmp2;

       
            }
            
            if(tmp3 -> next != NULL)
            {
                tmp = tmp -> next;
                tmp1 = tmp -> next;
                tmp2 = tmp1 -> next;
                tmp3 = tmp2 -> next;
            }
        }
        
        tmp = headc;
        tmp1 = headc -> next;
        tmp2 = tmp1 -> next;
        tmp3 = tmp2 -> next;
        
    }
}


void carrentallibrary::Historysortalgorithm()
{
    int k = 0;

    cout<<"\n\n by which parameter would you like to sort \n"
        <<"1. date of rent \n"
        <<"2. date of return \n"
        <<"3. firstname \n"
        <<"4. secname \n"
        <<"5. mark \n"
        <<"6. registration \n";
    
        cin>>k;

    switch(k)
    {
        case 1: sortingfunctionhist1(1); break;
        case 2: sortingfunctionhist1(2); break;
        case 3: sortingfunctionhist2(4); break;
        case 4: sortingfunctionhist2(5); break;
        case 5: sortingfunctionhist2(2); break;
        case 6: sortingfunctionhist2(1); break;
        default: break;
    }
}

void carrentallibrary::sortingfunctionhist2(int _x)
{
    historydata* tmp = headH;
    historydata* tmp1 = headH -> next;
    historydata* tmp2 = tmp1 -> next;
    historydata* tmp3 = tmp2 -> next; 

    for(int i=0; i<historydataamount; i++)
    {
        for(int j=0; j<historydataamount-3; j++)
        {

    
            if(j == 0 && tmp->getsomestring(_x)[0] > tmp1->getsomestring(_x)[0])
            {
                headH = tmp1;
                tmp1 -> next = tmp;
                tmp -> next = tmp2;
            }
            else if(tmp3 -> next == NULL && tmp2->getsomestring(_x)[0] > tmp3->getsomestring(_x)[0])
            {
                tmp1 -> next = tmp3;
                tmp3 ->next = tmp2;
                tmp2 -> next = NULL;

           
            }
            else if(tmp1->getsomestring(_x)[0] > tmp2->getsomestring(_x)[0])
            {
                tmp1 -> next = tmp3;
                tmp2 -> next = tmp1;
                tmp -> next = tmp2;

       
            }
            
            if(tmp3 -> next != NULL)
            {
                tmp = tmp -> next;
                tmp1 = tmp -> next;
                tmp2 = tmp1 -> next;
                tmp3 = tmp2 -> next;
            }
        }
        
        tmp = headH;
        tmp1 = headH -> next;
        tmp2 = tmp1 -> next;
        tmp3 = tmp2 -> next;
        
    }
}

void carrentallibrary::sortingfunctionhist1(int _x)
{
    historydata* tmp = headH;
    historydata* tmp1 = headH -> next;
    historydata* tmp2 = tmp1 -> next;
    historydata* tmp3 = tmp2 -> next; 

    int day, month;

    if(_x == 1 )
    {
        day = 1;
        month = 2;
    }
    else
    {
        day = 4;
        month = 5;
    }

    for(int i=0; i<amountofcars; i++)
    {
        for(int j=0; j<amountofcars-3; j++)
        {

    
            if(j == 0 && tmp->getsomeint(month) > tmp1->getsomeint(month))
            {
                headH = tmp1;
                tmp1 -> next = tmp;
                tmp -> next = tmp2;
            }
            else if(tmp3 -> next == NULL && tmp2->getsomeint(month) > tmp3->getsomeint(month))
            {
                tmp1 -> next = tmp3;
                tmp3 ->next = tmp2;
                tmp2 -> next = NULL;
            }
            else if(tmp1->getsomeint(month) > tmp2->getsomeint(month))
            {
                tmp1 -> next = tmp3;
                tmp2 -> next = tmp1;
                tmp -> next = tmp2;
            }
            
            if(tmp3 -> next != NULL)
            {
                tmp = tmp -> next;
                tmp1 = tmp -> next;
                tmp2 = tmp1 -> next;
                tmp3 = tmp2 -> next;
            }
        }
        
        tmp = headH;
        tmp1 = headH -> next;
        tmp2 = tmp1 -> next;
        tmp3 = tmp2 -> next;
    }

    tmp = headH;
    tmp1 = headH -> next;
    tmp2 = tmp1 -> next;
    tmp3 = tmp2 -> next;

    for(int i=0; i<amountofcars; i++)
    {
        for(int j=0; j<amountofcars-3; j++)
        {

            if(j == 0 && tmp->getsomeint(month) == tmp1->getsomeint(month))
            {
                if(j == 0 && tmp->getsomeint(day) > tmp1->getsomeint(day))
                {
                    headH = tmp1;
                    tmp1 -> next = tmp;
                    tmp -> next = tmp2;
                }
            }
            else if(tmp3 -> next == NULL && tmp2->getsomeint(month) == tmp3->getsomeint(month))
            {
                if(tmp3 -> next == NULL && tmp2->getsomeint(day) > tmp3->getsomeint(day))
                {
                    tmp1 -> next = tmp3;
                    tmp3 ->next = tmp2;
                    tmp2 -> next = NULL;
                }
            }
            else if(tmp1->getsomeint(month) == tmp2->getsomeint(month))
            {
                if(tmp1->getsomeint(day) > tmp2->getsomeint(day))
                {
                    tmp1 -> next = tmp3;
                    tmp2 -> next = tmp1;
                    tmp -> next = tmp2;
                }
            }
            
            if(tmp3 -> next != NULL)
            {
                tmp = tmp -> next;
                tmp1 = tmp -> next;
                tmp2 = tmp1 -> next;
                tmp3 = tmp2 -> next;
            }
        }
        
        tmp = headH;
        tmp1 = headH -> next;
        tmp2 = tmp1 -> next;
        tmp3 = tmp2 -> next; 
    }
}