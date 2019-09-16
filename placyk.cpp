#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

void jebac_suchocka(int n, int* tab, int* tab_rz)
{
    int rzut;
    
    

    for(int i=1; i<n; i++)
    {    
        rzut = tab_rz[i];
        if(rzut%2 == 0)
        {
            if(tab[i-1]+rzut > 400)  tab[i] = tab[i-1];
            
            else    tab[i] = tab[i-1] + rzut; 
        }
        else
        {
            if(tab[i-1] - (rzut/2) < 0) tab[i-1] = 0;
            else tab[i] = tab[i-1] - (rzut/2);
        }

        cout<<tab[i]<<endl; 
    }
}

void WYPELNIJ_RZUTY(int n, int *tab)
{
    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        tab[i] = rand()%6+1;
    }
}

int main()
{
    int n = 401; 
    int tab[n];
    int tablica_rzutow[n];
    WYPELNIJ_RZUTY(n, tablica_rzutow);
    tab[0] = 0;
    
    cout<<tab[0]<<endl;
    
    jebac_suchocka(n, tab, tablica_rzutow);


    return 0;
}