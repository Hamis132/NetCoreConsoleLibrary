#include <iostream>
using namespace std;

int quick(int n, int tab[], int pocz, int pivocik, int kon)
{
    int i = pocz, j = kon, schowek = j;

    pivocik = tab[pivocik];

    while(true)
    {
        while(tab[i]<pivocik) i++;
        while(tab[j]>pivocik) j--;
        if(i<j)
        {
            swap(tab[i],tab[j]);
            i++; j--;    
        }
        else
        {
            return j;
        }
    }
}

void sort(int n, int tab[], int pocz, int kon)
{
    int granica, pivot;
    
    if(pocz<kon)
    {
        pivot = (pocz+kon)/2;
        granica = quick(n, tab, pocz, pivot, kon);
        sort(n,tab,pocz,granica);
        sort(n,tab,granica+1,kon);
    }
}

int main()
{
    int n = 10; //cin >> n;

    int tab[n] = {5,3,1,8,9,9,3,1,7,6};

    int pocz = 0, kon = n - 1; 

    sort(n, tab, pocz, kon);

    for(int i=0; i<n; i++) cout<<tab[i]<<" ";
}