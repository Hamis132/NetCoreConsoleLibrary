#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void merge(int tab[], int n, int pocz, int c, int kon)
{
    int tmp[n];
    for(int i=pocz; i<=kon; i++)   tmp[i] = tab[i];
    
    int p1 = pocz, c1 = c;

    while(p1 <= c1 && c+1 <= kon)
    {
        if(tmp[p1] > tmp[c+1])   
           { tab[pocz++] = tmp[c+1]; c++; }
        
        else    
            tab[pocz++] = tmp[p1++];
    }

    while(p1 <= c1) 
        tab[pocz++] = tmp[p1++];    
}

void sort(int tab[], int n, int pocz, int kon)
{
    int center;

    if(pocz < kon)
    {
        center = (pocz+kon)/2;
        sort(tab, n, pocz, center);
        sort(tab, n, center+1, kon);
        merge(tab, n, pocz, center, kon);
    }
}

int main()
{
    int n; cin>>n;
    int tab[n];

    for(int i=0; i<n; i++)
    {
        cin>>tab[i];
    }
    
    int pocz = 0, kon = n-1;

    sort(tab, n, pocz, kon);

    for(int i=0; i<n; i++)
    {
        cout<<tab[i]<<" ";
    }

    return 0;
}