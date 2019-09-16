#include <iostream>
using namespace std;

struct tree
{
    int zmienna;
    int nr;
    tree* parent;
    tree* child1;
    tree* child2;
    tree* next;
};

int ilosc_wierszy(int n)
{
    int tab[n/2], ilosc_wierszy1 = 3;
    tab[0] = 2;
    for(int i=1; i<n/2; i++)
    {
        tab[i] = (tab[i-1]*2) + 2;
    }

    for(int i=1; i<n/2; i++)
    {
        if( tab[i-1] <= n && tab[i] >= n ) break;
        else ilosc_wierszy1++;
    }

    return ilosc_wierszy1;
}

int main()
{
    int n = 18;
    int szukana = 0, licznik = 2;

    int wiersze = ilosc_wierszy(n);
    
    tree* a;
    tree* tmp;
    tree* cone;

    for(int i=0; i<n; i++)
    {
        a = new tree;
        a -> nr = i;

        if(i==0) cone = a;
        else 
        {
            tmp -> next = a;
        }
        tmp = a;
    } 

    a -> next = NULL;

    a = cone;
    tmp = cone;

    for(int i = 0; i < wiersze; i++)
    {
        if(i == 0)
        {
            a -> parent = NULL;
            a -> next -> parent = a;
            a -> next -> next -> parent = a;
            a -> child1 = a -> next;
            a -> child2 = a -> next -> next;
            a = a -> next;
            tmp = a -> next;
        }
        else
        {
            for(int j = 0; j < licznik; j++)
            {
                if((2*(a->nr))+1 < n)
                {
                    szukana = (2*(a->nr))+1;
                    while(tmp -> nr != szukana)
                    {
                        tmp = tmp -> next;
                    }
                    a -> child1 = tmp;
                    tmp -> parent = a;

                }
                else a -> child1 = NULL; 

                if((2*(a->nr))+2 < n)
                {
                    szukana = (2*(a->nr))+2;
                    while(tmp -> nr != szukana)
                    {
                        tmp = tmp -> next;
                    }
                    a -> child2 = tmp;
                    tmp -> parent = a;

                }
                else a -> child2 = NULL; 
                
                if(a -> next != NULL)   a = a->next;
                else break; 
            }
            licznik *= 2;  
           
        }
    }

    return 0;
}