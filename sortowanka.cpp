#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void selection_sort(int n, int* tab, int m)
{
    int min_wartosc = m, k = 0, schowek;
    bool f;

    for(int i=0; i<n; i++)
    {
        f = false;
        for(int j=k; j<n; j++)
        {
            if(tab[j] <= min_wartosc)
            {
                min_wartosc = tab[j];
                schowek = j;
                f = true;
                if(k!=0 && tab[j] - tab[k] == 1) break;
            }
        }
        if( f == false ) break;
        
        swap(tab[schowek], tab[k]);
        k++;
        min_wartosc = m;

    }

    for(int i=0; i<n; i++)
    {
        cout<<tab[i]<<" ";
    }
}

void insertion_sort(int n, int* tab)
{
    int k = 1, schowek; 
    
    for( int i=k; i<n ; i++ )
    {
        if(tab[k]<tab[k-1])
        {
            schowek = tab[k];
            for( int j = k-1; j >= 0; j-- )
            {
                if( schowek < tab[j] )
                {
                    swap(tab[j+1], tab[j]);
                }
            }
        }
        k++;
    }
    
    for(int i=0; i<n; i++)
    {
        cout<<tab[i]<<" ";
    }

}


int wartosc_max(int n, int* tab)
{
    int MAX = tab[0];
    for (int i=1; i<n; i++)
    {
        if(tab[i] > MAX)
        {
            MAX = tab[i];
        }
    }
    return MAX;
}

void countingsort(int n, int* tab, int m)
{
    int tab_pom[m], schowek, schowek1;
    for(int i=0; i<m; i++) tab_pom[i] = 0;
    
    for(int i=0; i<n; i++)
    {   
        schowek = tab[i];
        tab_pom[schowek]++;   
    }
    
 

    for(int i=1; i < n; i++)
    {
        tab_pom[i] = tab_pom[i] + tab_pom[i-1];
        if(tab_pom[i] == m) tab_pom[i]--;
    }

    int tab2[n];

    for(int i=0; i<n; i++)
    {   
        schowek1 = tab[i];
        schowek = tab_pom[schowek1]-1;
        tab2[schowek] = tab[i];
        tab_pom[schowek1]--;
    }
    

    
    for(int i=0; i<n; i++)
    {
        cout<<tab2[i]<<" ";
    }
}

void radixsort(int n, int* tab)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<n; j++)
        {

        }
    }
}

int main()
{
    int n, m,  max, wybierajka; cin>>n;
    int tab[n];

    srand(time(NULL));

    for(int i=0; i<n; i++)
    {    
        tab[i] = rand()%m;
        cout<<tab[i]<<" ";
    }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
    /*
    cout<<endl<<"1. counting sort"<<endl<<"2. selection sort"<<endl<<"3. insertion sort"<<endl;

    cin>>wybierajka;

   
    switch(wybierajka)
    {

    case(1):  cout<<endl<<"COUNTING SORT    "; countingsort(n, tab, m); break;

    case(2):   cout<<endl<<"SELECTION SORT   ";   selection_sort(n, tab, m); break;

    case(3):  cout<<endl<<"INSERTION SORT   ";   insertion_sort(n, tab); break;

    }
    cout<<endl; */

    return 0;
}

