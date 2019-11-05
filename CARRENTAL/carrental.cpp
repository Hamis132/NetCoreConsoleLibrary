#include <iostream>
#include <fstream>
#include "Customer.h"
#include "car.h"
#include "carrentallibrary.h"
#include "historydata.h"
using namespace std;

carrentallibrary* Wypozyczalnia = new carrentallibrary();

void showeveryhing()
{
    Customer* a;
    a = Wypozyczalnia -> headCu;

    while( a != NULL )
    {
        cout<< a -> getsomestring(1) <<"  "<< a -> getsomestring(2) <<"  "<< a -> getsomestring(3) <<"  "
            << a -> getsomeint(1) <<"  "<< a -> getsomeint(2) <<"  "<<endl;
        a = a -> next;
    }

}


void customerfunction1(string s)
{
    int tmpid;

    tmpid = Wypozyczalnia -> findcustomerid(s);
                        
    if(tmpid < 1) cout<<"YOU AREN RENTING ANY CAR"<<endl;
    else
        Wypozyczalnia -> showrenting(tmpid, "0"); cout<<"\n\n"; 
}

void customerfunction2(string s)
{
    Customer* tmp;
    int tmpid;

    tmpid = Wypozyczalnia -> findcustomerid(s);

    if(tmpid < 1) cout<<"YOU AREN RENTING ANY CAR"<<endl;
    else
    {
        tmp = Wypozyczalnia -> findcustomer(tmpid);

      
        if(tmp == Wypozyczalnia -> headCu && tmpid == Wypozyczalnia -> headCu -> getsomeint(2))
        {
            Wypozyczalnia -> savedatabeforedeleting(tmp, tmpid);
            Wypozyczalnia -> deletecustomer(tmp, true);   
        }    
        else
        {
            Wypozyczalnia -> savedatabeforedeleting(tmp->next, tmpid);
            Wypozyczalnia -> deletecustomer(tmp, false);
        }

        Wypozyczalnia -> amountofclints--;
    }

  
}

string customerfunction3()
{
    int x;
    bool f;

    cout<<"ENTER ID OF CAR WHICH YOU WANT TO RENT ";

    cin>>x;

    cout<<"\n\n";

    f = Wypozyczalnia -> iscaravailable(x);

    if(f == true)
    {
        char p;

        cout<<"\n\n"<<"YOU SURE ABOUT RENTING THIS CAR?"
            <<"ENTER x IF YOU SURE AND CONFIRM"<<"\n\n";
        
        cin>>p;

        switch(p)
        {
            case 'x': 
                    return Wypozyczalnia -> rentcar(x); 
                    Wypozyczalnia -> amountofclints ++;
                    Wypozyczalnia -> historydataamount ++;
                break;
            
            default:
                    return "x";
                 break;
        }
    }

}

void customerfunction4()
{
    cout<<"ADD FILTERS"<<"\n\n";

    cout<<"1. mark"<<"\n"
        <<"2. model"<<"\n"
        <<"3. mileage"<<"\n"
        <<"4. acceleration"<<"\n";
    
    int x; cin>>x;

    if(x == 1)
    {
        string s;
        cout<<"ADD MARK FILTER ";
        cin>>s;
        cout<<"\n\n";
        Wypozyczalnia -> showrenting(2,s);
        
    }
    else if(x == 2)
    {
        string s;
        cout<<"ADD MODEL FILTER ";
        cin>>s;
        cout<<"\n\n";
        Wypozyczalnia -> showrenting(1,s);
    }
    else if(x == 3)
    {
        int s;
        cout<<"ADD MILEAGE FILTER ";
        cin>>s;
        cout<<"\n\n";
        Wypozyczalnia -> showrenting(s, "1");
    }
    else if(x == 4)
    {
        int s;
        cout<<"ADD ACCELERATION FILTER ";
        cin>>s;
        cout<<"\n\n";
        Wypozyczalnia -> showrenting(s, "2");
    }
}

void workerfunction()
{
    int x; char c;
    car* tmp;

    cout<<"LIST OF RETURNS WAITING FOR CONFIRMATION"<<"\n";

    Wypozyczalnia -> listofreturns();

    cout<<"\n\n TYPE ID OF RETURN WHICH YOU WANT TO CONFIRM  "; cin>>x;

            tmp = Wypozyczalnia -> findreturn(x);

    cout<<"\n\n FIRSTLY ADD MILEAGE DIFFERENCE FROM CAR HERE "; cin>>x;

            Wypozyczalnia -> changeparameter(tmp, x);

    cout<<"\n\n Now press x to confirm and set car as available "; cin>>c;

            tmp -> setSomeint(4,0);
}

void workerfunctionsorting()
{
    int x;


    cout<<"WHICH DATA WOULD YOU LIKE TO SORT? \n\n"
        <<"1. Clients \n"
        <<"2. history \n"
        <<"3. cars \n";
    cin>>x;

    switch(x)
    {
        case 1: Wypozyczalnia -> Clientssortalgorithm(); break;
        case 2: Wypozyczalnia -> Historysortalgorithm(); break;
        case 3: Wypozyczalnia -> Carssortalgorithm(); break;
        default: break;
    }
}

void customertxthelp(bool k)
{
    if(k == true)
        cout<<"WHAT DO YOU WANT TO DO?:::::"<<"\n\n"
            <<"1. GET MY RENTING HISTORY"<<"\n"
            <<"2. SHOW DATA OF MY CURRENT RENTING"<<"\n"
            <<"3. HAND OVER CURRENTLY RENTED CAR"<<"\n"
            <<"4. RENT PARTICULAR CAR"<<"\n"
            <<"5. SHOW ME OFFER OF AVAILABLE CARS"<<"\n"
            <<"6. SHOW ME FULL CAR LIST"<<"\n"
            <<"7. FIND CAR BY ADDING A PARAMETER"<<"\n"
            <<"8. SHOW MY PERSONAL DATA"<<"\n"
            <<"0. exit"<<"\n";
    else
        cout<<"WHAT DO YOU WANT TO DO?:::::"<<"\n\n"
            <<"1. BLOCKED"<<"\n"
            <<"2. BLOCKED"<<"\n"
            <<"3. BLOCKED"<<"\n"
            <<"4. RENT PARTICULAR CAR"<<"\n"
            <<"5. SHOW ME OFFER OF AVAILABLE CARS"<<"\n"
            <<"6. SHOW ME FULL CAR LIST"<<"\n"
            <<"7. FIND CAR BY ADDING A PARAMETER"<<"\n"
            <<"8. BLOCKED"<<"\n"
            <<"0. exit"<<"\n";
}

void worker()
{
    string password;

    cout<<"TYPE PASSWORD "; cin>>password;

    if(password == "123")
    {
        while(true)
        {
            int x;
            string s;
            bool f = false;

            cout<<"AMOUNT OF CARS WAITING FOR RETURN CONFIRMATION "<<Wypozyczalnia->messages<<"\n\n\n";

            cout<<"1. SHOW ALL HISTORY \n"
                <<"2. SHOW HISTORY OF ONE PARTICULAR CLIENT \n"
                <<"3. SHOW HISTORY OF ONE PARTICULAR CAR \n"
                <<"4. ENTER THE RETURN CONFIRMATION PANEL \n"
                <<"5. SHOW AVAILABLE CARS \n"
                <<"6. SHOW FULL CAR LIST \n"
                <<"7. FIND CAR BY ADDING A PARAMETER \n"
                <<"8. SHOW LIST OF CLIENTS \n"
                <<"9. SHOW ONE PARTICULAR CLIENT \n"
                <<"10. SORT DATA BASE BY \n"
                <<"0. exit \n";

            cin >> x;

            switch(x)
            {
                case 1: Wypozyczalnia -> showhistory("0000", true); cout<<"\n\n";  break;
            
                case 2: cout<<"type pesel of client to see client history "; 
                        cin>>s;
                        Wypozyczalnia -> showhistory(s, true); cout<<"\n\n"; 
                    break;
            
                case 3: cout<<"type registration to see car history ";
                        cin>>s;
                        Wypozyczalnia -> showhistory(s, false); cout<<"\n\n";
                    break;

                case 4: workerfunction();
                    break;

                case 5: Wypozyczalnia -> showrenting(-2, "0"); break;
                case 6: Wypozyczalnia -> showrenting(-1, "0"); break;
                case 7: customerfunction4(); break;
                case 8: Wypozyczalnia -> showclientsdata(password); break;
            
                case 9: cout<<"type pesel of client to see client's data "; 
                        cin>>s;
                        Wypozyczalnia -> showclientsdata(s); cout<<"\n\n";  
                    break;
            
                case 10: workerfunctionsorting(); break;
                case 0: f = true; break;
            
                default: break;
            }

            if(f == true) break;
        }    
    
    }
    else cout<<"\n\n wrong password";
}

void customer()
{
    string s;
    bool f1, f2 = false, f3 = false;

    cout<<"PLEASE INPUT YOUR PESEL BELOW IF YOU HAVE EVER BEEN OUR CLIENT TO ACCESS::"<<endl
        <<"OR IF YOU ARE NEW CLIENT PRESS x TO ACCESS TO"<<endl
        <<"VERSION FOR NEW CLIENTS  "; 

    cin>>s;

    if(s == "x")
    {
        f1 = true;
        f3 = false;
    }
    else
    {
        f1 = Wypozyczalnia -> iscustomerexists(s);
        if(f1 == true) f3 = true;
    }

    if(f1 == true)
    {
        int x; 

        while(true)
        {
            customertxthelp(f3);
            
            cin>>x;

            switch (x)
            {
                case 1: 
                    Wypozyczalnia -> showhistory(s, true); cout<<"\n\n"; break;
                case 2:
                    customerfunction1(s); break;
                case 3:
                    customerfunction2(s); break;
                case 4:
                    s = customerfunction3(); f3 = true; break;
                case 5:
                    Wypozyczalnia -> showrenting(-2, "0"); break;
                case 6: 
                    Wypozyczalnia -> showrenting(-1, "0"); break;
                case 7:
                    customerfunction4(); break;
                case 0:
                    f2 = true; break;

                default:
                    break;
            }
            if(f2 == true) break;
        }
    }
    else cout<<"wrong pesel or there is no such"<<endl;
}



int main()
{
    
    Wypozyczalnia -> headc = Wypozyczalnia -> structcurrentcarlist(Wypozyczalnia -> amountofcars);
    Wypozyczalnia -> headCu = Wypozyczalnia -> structcurrentcustomerlist(Wypozyczalnia -> amountofclints);
    Wypozyczalnia -> headH = Wypozyczalnia -> structcurrenthistorydatalist(Wypozyczalnia -> historydataamount);

    while(true)
    {
        bool f = false;
        int x;
        
        cout<<"WELCOME TO OUR CARRENTAL DATA BASE"<<endl
        <<"YOU ARE:::::::::::::::::::::::::::::"<<endl
        <<"1. Worker"<<endl
        <<"2. Customer"<<endl
        <<"0. exit"<<endl;
        
        cin>>x;
        
        switch(x)
        {
            case 1: 
                worker(); break;
            case 2:
                customer(); break;
            case 0:
                f = true; break;
            default:
                cout<<"there is no such option"<<endl; break;
        }

        if(f == true) break;
    }
    cout<<Wypozyczalnia -> amountofclints<<Wypozyczalnia -> amountofcars<<Wypozyczalnia->historydataamount;

    Wypozyczalnia -> ~carrentallibrary();
    
    return 0;
}