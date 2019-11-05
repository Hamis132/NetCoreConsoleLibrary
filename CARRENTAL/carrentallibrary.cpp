#include "carrentallibrary.h"

carrentallibrary::carrentallibrary()
{
    ifstream dane("liczby.txt");

    dane>>amountofclints>>amountofcars>>historydataamount;
}


void carrentallibrary::findcarthroughid(int _id)
{
    car* tmp = headc;

    while(tmp != NULL)
    {
        if(tmp -> getsomeint(3) == _id)
        {
            tmp -> setSomeint(4,0);
        }

        tmp = tmp -> next;
    }
}

void carrentallibrary::showhistory(string _a, bool _b)
{
    historydata* tmp = headH;

    if(_a == "0000")
    {
        while(tmp != NULL)
        {
            cout<<tmp -> getsomestring(1)<<" "<<tmp -> getsomestring(2)<<" "
                <<tmp -> getsomestring(3)<<"  "
                <<tmp -> getsomeint(1)<<'-'<<tmp -> getsomeint(2)
                <<'-'<<tmp -> getsomeint(3)<<" | "<<tmp -> getsomeint(4)
                <<'-'<<tmp -> getsomeint(5)<<'-'<<tmp -> getsomeint(6)<<"  "
                <<tmp -> getsomeint(7)
                <<"  "<<tmp -> getsomestring(4)<<" "<<tmp -> getsomestring(5)<<endl;

            tmp = tmp -> next;    
        }
    }
    else if(_a.size() < 9 && _b == true)
    {
        while(tmp != NULL)
        {
            if(_a == tmp -> getsomestring(1) && tmp -> getsomeint(7) == 0)
            {
                cout<<tmp -> getsomeint(4)
                <<'-'<<tmp -> getsomeint(5)<<'-'<<tmp -> getsomeint(6)<<endl;

                break;
            }

            tmp = tmp -> next;
        }
    }
    else if(_a.size() < 9 && _b == false)
    {
        while(tmp != NULL)
        {
            if(_a == tmp -> getsomestring(1) && tmp -> getsomeint(7) == 0)
            {
                 cout<<tmp -> getsomestring(1)<<" "<<tmp -> getsomestring(2)<<" "
                    <<tmp -> getsomestring(3)<<"  "
                    <<tmp -> getsomeint(1)<<'-'<<tmp -> getsomeint(2)
                    <<'-'<<tmp -> getsomeint(3)<<" | "<<tmp -> getsomeint(4)
                    <<'-'<<tmp -> getsomeint(5)<<'-'<<tmp -> getsomeint(6)<<"  "
                    <<tmp -> getsomeint(7)
                    <<"  "<<tmp -> getsomestring(4)<<" "<<tmp -> getsomestring(5)<<endl;

                break;
            }

            tmp = tmp -> next;
        }
    }
    else
    {
        while(tmp != NULL)
        {
            if(_a == tmp -> getsomestring(3))
            {
                cout<<tmp -> getsomestring(1)<<" "<<tmp -> getsomestring(2)<<" "
                    <<tmp -> getsomestring(3)<<"  "
                    <<tmp -> getsomeint(1)<<'-'<<tmp -> getsomeint(2)
                    <<'-'<<tmp -> getsomeint(3)<<" | "<<tmp -> getsomeint(4)
                    <<'-'<<tmp -> getsomeint(5)<<'-'<<tmp -> getsomeint(6)<<"  "
                    <<tmp -> getsomeint(7)
                    <<"  "<<tmp -> getsomestring(4)<<" "<<tmp -> getsomestring(5)<<endl;
            }

            tmp = tmp -> next;
        }
    }
    
}

car* carrentallibrary::findreturn(int _id)
{
    handoveredcars* tmp = headm;
    car* tmpc = headc;
    
    if(tmp == headm)
    {
        headm = tmp -> next;
        delete tmp;
    }
    else
    {
        while(tmp -> next -> id != _id) tmp = tmp -> next;

        tmp -> next = tmp -> next -> next;
        delete tmp;
    }

    while(tmpc -> getsomeint(3) != _id) tmpc = tmpc -> next;

    return tmpc;
}



void carrentallibrary::listofreturns()
{
    handoveredcars* tmp = headm;

    while(tmp != NULL)
    {
        cout<<tmp -> id<<" "<<tmp -> name<<" "
            <<tmp -> surname<<" "<<tmp -> pesel<<" "
            <<tmp -> registration<<"\n";
        
        tmp = tmp -> next;
    }
}

string carrentallibrary::rentcar(int _id)
{
    car* TMP_CAR = headc;
    Customer* TMP_CUST = headCu;
    Customer* tmp2cust;
    historydata* TMP_HIST = headH;
    historydata* tmp2hist;

    string slowo;
    int age;

    while(TMP_CAR != NULL)
    {
        if(TMP_CAR -> getsomeint(3) == _id)
        {
            TMP_CAR -> setSomeint(4 ,1);
            break;
        }
        TMP_CAR = TMP_CAR -> next;
    }  

    while(TMP_CUST -> next != NULL) TMP_CUST = TMP_CUST -> next;
    while(TMP_HIST -> next != NULL) TMP_HIST = TMP_HIST -> next;

    tmp2cust = new Customer();
    tmp2hist = new historydata();

    TMP_CUST -> next = tmp2cust;
    tmp2cust -> next = NULL;

    TMP_HIST -> next = tmp2hist;
    tmp2hist -> next = NULL;
    
    tmp2cust -> setSomeint(2, _id);
    tmp2hist -> setsomeint(1, day);
    tmp2hist -> setsomeint(2, month);
    tmp2hist -> setsomeint(3, year);
    tmp2hist -> setsomeint(7, 0);
    tmp2hist -> setsomestring(1, TMP_CAR -> getsomestring(4));
    tmp2hist -> setsomestring(2, TMP_CAR -> getsomestring(2));


    cout<<"ADD YOUR PERSONAL DATA"<<endl
        <<"first name ";
    
    cin>>slowo; tmp2cust -> setSomestring(2, slowo);
                tmp2hist -> setsomestring(4, slowo);

    cout<<"\n\n"<<"second name ";

    cin>>slowo; tmp2cust -> setSomestring(3, slowo);
                tmp2hist -> setsomestring(5, slowo);

    cout<<"\n\n"<<"pesel ";

    cin>>slowo; tmp2cust -> setSomestring(1, slowo);
                tmp2hist -> setsomestring(3, slowo);  

    cout<<"\n\n"<<"age ";

    cin>>age; tmp2cust -> setSomeint(1, age);
    
    cout<<"\n\n"<<"HOW LONG YOU WISH TO RENT A CAR (WRITE IN DAYS BELOW) *MAX THROUGH |INTERNET| IS 30 DAYS  ";
        
    cin>>age; 

    if(age + day > 31)
    {
        tmp2hist -> setsomeint(4, age+day - 31);
        tmp2hist -> setsomeint(5, month + 1);
    }
    else 
    {
        tmp2hist -> setsomeint(4, age + day);
        tmp2hist -> setsomeint(5, month);   
    }

    tmp2hist -> setsomeint(6, year);

    return tmp2cust -> getsomestring(1);
}
void carrentallibrary::showrenting(int _a, string _k)
{
    car* a = headc;

    cout<<"\n\n";

    if(_a == -1 && _k == "0")
    {
        while(a != NULL)
        {
            cout<<a->getsomeint(3)<<" "<<a->getsomestring(2)<<" "
                <<a->getsomestring(1)<<" "<<a->getsomestring(3)
                <<" "<<a->getsomestring(4)<<" "<<a->getsomeint(1)
                <<" "<<a->getsomeint(2)<<" ";
                
                if(a->getsomeint(4) == 1) cout<<"RENTED"<<endl;
                else cout<<"AVAILABLE"<<endl;
                
        
            a = a -> next;
        }
    }
    else if(_a == -2 && _k == "0")
    {
        while(a != NULL)
        {
            if(a -> getsomeint(4) == 0)
            {
                cout<<a->getsomeint(3)<<" "<<a->getsomestring(2)<<" "
                    <<a->getsomestring(1)<<" "<<a->getsomestring(3)
                    <<" "<<a->getsomestring(4)<<" "<<a->getsomeint(1)
                    <<" "<<a->getsomeint(2)<<endl;
            }
            a = a -> next;
        }
    }
    else if(_k == "0")
    {
        while(a != NULL)
        {
            if(_a == a -> getsomeint(3))
            {
                cout<<a->getsomeint(3)<<" "<<a->getsomestring(2)<<" "
                    <<a->getsomestring(1)<<" "<<a->getsomestring(3)
                    <<" "<<a->getsomestring(4)<<" "<<a->getsomeint(1)
                    <<" "<<a->getsomeint(2)<<endl;
            }
            a = a -> next;
        }
    }
    else if(_k != "0" && _a == 2)
    {
         while(a != NULL)
        {
            if(_k == a -> getsomestring(_a))
            {
                cout<<a->getsomeint(3)<<" "<<a->getsomestring(2)<<" "
                    <<a->getsomestring(1)<<" "<<a->getsomestring(3)
                    <<" "<<a->getsomestring(4)<<" "<<a->getsomeint(1)
                    <<" "<<a->getsomeint(2)<<endl;
            }
            a = a -> next;
        }
    }
    else if(_k != "0" && _a == 1)
    {
        while(a != NULL)
        {
            if(_k == a -> getsomestring(_a))
            {
                cout<<a->getsomeint(3)<<" "<<a->getsomestring(2)<<" "
                    <<a->getsomestring(1)<<" "<<a->getsomestring(3)
                    <<" "<<a->getsomestring(4)<<" "<<a->getsomeint(1)
                    <<" "<<a->getsomeint(2)<<endl;
            }
            a = a -> next;
        }
    }
    else if(_k == "1")
    {
        while(a != NULL)
        {
            if(_a <= a -> getsomeint(1))
            {
                cout<<a->getsomeint(3)<<" "<<a->getsomestring(2)<<" "
                    <<a->getsomestring(1)<<" "<<a->getsomestring(3)
                    <<" "<<a->getsomestring(4)<<" "<<a->getsomeint(1)
                    <<" "<<a->getsomeint(2)<<endl;
            }
            a = a -> next;
        }
    }
     else if(_k == "2")
    {
        while(a != NULL)
        {
            if(_a <= a -> getsomeint(2))
            {
                cout<<a->getsomeint(3)<<" "<<a->getsomestring(2)<<" "
                    <<a->getsomestring(1)<<" "<<a->getsomestring(3)
                    <<" "<<a->getsomestring(4)<<" "<<a->getsomeint(1)
                    <<" "<<a->getsomeint(2)<<endl;
            }
            a = a -> next;
        }
    }

    cout<<"\n\n";
}

void carrentallibrary::changeparameter(car* _tmp, int _mileage)
{
    int currentmileage;

    currentmileage =_tmp -> getsomeint(1);

    _tmp -> setSomeint(1, currentmileage + _mileage);

    messages--;
}

void carrentallibrary::deletecustomer(Customer* _tmp, bool _f)
{
    Customer* pom;

    if(_f == true)
    {
        pom = headCu;
        headCu = _tmp -> next;
        delete pom;
    }
    else
    {
        pom = _tmp -> next;
        _tmp -> next = _tmp -> next -> next;
        delete pom;
    }
}

void carrentallibrary::savedatabeforedeleting(Customer* _tmp, int tmpid)
{
    handoveredcars* a;
    car* TMPC = headc;

    while(TMPC -> getsomeint(3) != tmpid) TMPC = TMPC -> next;

    if(messages == 0)
    {
        a = new handoveredcars;
        previousmess = a;
        headm = a;

        a -> id = _tmp -> getsomeint(2);
        a -> pesel = _tmp -> getsomestring(1);
        a -> name = _tmp -> getsomestring(2);
        a -> surname = _tmp -> getsomestring(3);
        a -> registration = TMPC -> getsomestring(4);
    }
    else
    {
        a = new handoveredcars;
        previousmess -> next = a;
        previousmess = a;

        a -> id = _tmp -> getsomeint(2);
        a -> pesel = _tmp -> getsomestring(1);
        a -> name = _tmp -> getsomestring(2);
        a -> surname = _tmp -> getsomestring(3);
        a -> registration = TMPC -> getsomestring(4);
    }
    
    a -> next = NULL;
    messages++;
}

car* carrentallibrary::structcurrentcarlist(int _a)
{
    car* a;
    car* tmp;
    car* head;
    ifstream data("cars.txt");

        
    int ID, mileage, acceleration, pseudobool;
        
    string mark, model, vin, registration;

    for(int i=0; i<_a; i++)
    {
        
        data>>ID>>mark>>model>>vin>>registration
        >>mileage>>acceleration>>pseudobool;

        a = new car();
    
        a -> setSomestring(1, model);
        a -> setSomestring(2, mark);
        a -> setSomestring(3, vin);
        a -> setSomestring(4, registration);
        a -> setSomeint(4,pseudobool);
        a -> setSomeint(1, mileage);
        a -> setSomeint(2, acceleration);
        a -> setSomeint(3, ID);
    
        if(i == 0) head = a;
        else 
        {
            tmp -> next = a;
        }
        tmp = a;

    }
    a -> next = NULL;

    return head;    
}

Customer* carrentallibrary::structcurrentcustomerlist(int _a)
{
    Customer* a;
    Customer* tmp;
    Customer* head;
    ifstream data("customers.txt");

        
    int age, id;
        
    string pesel, firstname, secondname;

    for(int i=0; i<_a; i++)
    {
        
        data>>id>>firstname>>secondname>>pesel>>age;

        a = new Customer();
    
        a -> setSomestring(1, pesel);
        a -> setSomestring(2, firstname);
        a -> setSomestring(3, secondname);
        a -> setSomeint(1, age);
        a -> setSomeint(2, id);
    
        if(i == 0) head = a;
        else 
        {
            tmp -> next = a;
        }
        tmp = a;

    }
    a -> next = NULL;

    return head;
}
historydata* carrentallibrary::structcurrenthistorydatalist(int _a)
{
    historydata* a;
    historydata* tmp;
    historydata* head;
    ifstream data("historyofrents.txt");

        
    int day1, day2, month1, month2, year1, year2, deltaM;
        
    string registration, mark,pesel, firstname, secondname;

    for(int i=0; i<_a; i++)
    {
        
        data>>registration>>mark>>pesel>>day1>>
            month1>>year1>>day2>>month2>>year2
            >>deltaM>>firstname>>secondname;

        a = new historydata();

        a -> setsomestring(1, registration);
        a -> setsomestring(2, mark);
        a -> setsomestring(3, pesel);
        a -> setsomestring(4, firstname);
        a -> setsomestring(5, secondname);
        a -> setsomeint(1, day1);
        a -> setsomeint(2, month1);
        a -> setsomeint(3, year1);
        a -> setsomeint(4, day2);
        a -> setsomeint(5, month2);
        a -> setsomeint(6, year2);
        a -> setsomeint(7, deltaM);
    
        if(i == 0) head = a;
        else 
        {
            tmp -> next = a;
        }
        tmp = a;

    }
    a -> next = NULL;

    return head;
}

int carrentallibrary::findcustomerid(string _s)
{
    Customer* HEAD_C = headCu;

    bool f = false;

    string tmp;

    while(HEAD_C != NULL)
    {
        tmp = HEAD_C -> getsomestring(1);

        if(tmp == _s) 
        {
            f = true;
            break;
        }

        HEAD_C = HEAD_C -> next;
    }
    
    if(f == true)
        return HEAD_C -> getsomeint(2);
    else
        return 0;
}

bool carrentallibrary::iscustomerexists(string _s)
{
    Customer* HEAD_C = headCu;
    historydata* HEAD_H = headH;

    bool f = false;

    string tmp;

    while(HEAD_C != NULL)
    {
        tmp = HEAD_C -> getsomestring(1);

        if(tmp == _s) 
        {
            f = true;
            break;
        }

        HEAD_C = HEAD_C -> next;
    }
    
    if(f == true) return true;

    while(HEAD_H != NULL)
    {
        tmp = HEAD_H -> getsomestring(3);

        if(tmp == _s)
        {
            f = true;
            break;
        }

        HEAD_H = HEAD_H -> next;
    }

    if(f == true)
        return true;
    else 
        return false;

}

bool carrentallibrary::iscaravailable(int _id)
{
    car* HEAD_c = headc;
    
    bool f1, f2 = false;
    
    string s;


    while(HEAD_c != NULL)
    {
        if(HEAD_c -> getsomeint(3) == _id)
        {
            cout<<"car id is correct ";
           
            s = HEAD_c -> getsomestring(4);

            f2 = true;
           
            if(HEAD_c -> getsomeint(4) == 0)
            {
                cout<<"and car is available"<<"\n\n";
                f1 = true;
                break;
            }
            else 
            {
                cout<<"but car is currently renting by someone else"<<endl
                    <<"car will be availble:: ";
                
                showhistory(s, true);

                cout<<"\n\n"; 
                f1 = false;
                break;
            }
        }
        HEAD_c = HEAD_c -> next;
    }

    if(f2 == false) cout<<"such id doesnt exists, check out car list"<<"\n\n";

    if(f1 == true) return true;
    else return false; 
}

Customer* carrentallibrary::findcustomer(int _id)
{
    Customer* HEAD_C1 = headCu;

    if(HEAD_C1 -> getsomeint(2) == _id) return HEAD_C1;

    bool f = false;

    int tmp;

    while(HEAD_C1 != NULL)
    {
        tmp = HEAD_C1 -> next -> getsomeint(2);

        if(tmp == _id) 
        {
            f = true;
            break;
        }

        HEAD_C1 = HEAD_C1 -> next;
    }
    
    return HEAD_C1;
}

void carrentallibrary::showclientsdata(string _s)
{
    Customer* tmp = headCu;
    bool f;

    if(_s == "123")
    {
        f = true;
        while(tmp != NULL)
        {
            cout<<tmp->getsomeint(2)<<" "<<tmp->getsomestring(2)<<" "
                <<tmp->getsomestring(3)<<" "<<tmp->getsomestring(1)<<" "
                <<tmp->getsomeint(1)<<"\n"; 

            tmp = tmp -> next; 
        }
        
    }
    else
    {
        f = false;
        while(tmp != NULL)
        {
            if(_s == tmp -> getsomestring(1))
            {
                cout<<tmp->getsomeint(2)<<" "<<tmp->getsomestring(2)<<" "
                    <<tmp->getsomestring(3)<<" "<<tmp->getsomestring(1)<<" "
                    <<tmp->getsomeint(1)<<"\n"; 

                f = true;    
                break;
            }
            tmp = tmp -> next;
        }
    }

    cout<<"\n\n";

    if(f == false) cout<<"THERE IS NO SUCH CLIENT"<<"\n\n";
}

carrentallibrary::~carrentallibrary()
{
    ofstream dane1("historyofrents.txt");
    char x = ' ';

    while(headH != NULL)
    {
        dane1<<headH -> getsomestring(1)<<x<<headH -> getsomestring(2)
             <<x<<headH -> getsomestring(3)<<x<<headH->getsomeint(1)
             <<x<<headH->getsomeint(2)<<x<<headH->getsomeint(3)
             <<x<<headH->getsomeint(4)<<x<<headH->getsomeint(5)
             <<x<<headH->getsomeint(6)<<x<<headH->getsomeint(7)
             <<x<<headH->getsomestring(4)<<x<<headH->getsomestring(5)<<"\n";

        headH = headH -> next;
    }

    ofstream dane2("cars.txt");
    
    while(headc != NULL)
    {
        dane2<<headc->getsomeint(3)<<x<<headc->getsomestring(2)
             <<x<<headc->getsomestring(1)<<x<<headc->getsomestring(3)
             <<x<<headc->getsomestring(4)<<x<<headc->getsomeint(1)
             <<x<<headc->getsomeint(2)<<x<<headc->getsomeint(4)<<"\n";

        headc = headc -> next;
    }

    ofstream dane3("customers.txt");

    while(headCu != NULL)
    {
        dane3<<headCu->getsomeint(2)<<x<<headCu->getsomestring(2)
             <<x<<headCu->getsomestring(3)<<x<<headCu->getsomestring(1)
             <<x<<headCu->getsomeint(1)<<"\n";

        headCu = headCu -> next;
    }    

    ofstream liczby("liczby.txt");

    liczby<<amountofclints<<x<<amountofcars<<x<<historydataamount;
}