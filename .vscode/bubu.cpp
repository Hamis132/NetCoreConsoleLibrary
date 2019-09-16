#include <iostream> 
#include <cstdlib>
#include <ctime>

using namespace std;

struct lista2
{
    int n; 
    lista2* next1;
    lista2* next2;
};

int main()
{
    int k, liczba;
    
    cin>>k;
    
    int tab[k];

    srand(time(NULL));

    for(int i=0; i<k; i++) 
    {
        tab[i] = rand()%10+1;
        cout<<tab[i]<<" ";
    }
    
    cout<<endl;

    lista2* head1;
    lista2* head2;
    lista2* tmp;
    lista2* tmp1;
    lista2* tmp2;
    lista2* cubby1;
    lista2* cubby2;

    for(int i=0; i<k; i++)
    {
        tmp = new lista2;
        tmp -> n = tab[i];

        if(i == 0)
        {
            head1 = tmp;
            tmp -> next2 = NULL;
            head2 = tmp;
        }
        else
        {       
            head2 -> next1 = tmp;
            tmp -> next2 = head2;
            head2 = tmp;
        }     
    }
    tmp -> next1 = NULL;

    tmp = head1;
    tmp1 = tmp -> next1;
    tmp2 = tmp;
    
    while(true)
    {
        if(tmp -> n > tmp1 -> n)
        {   
            liczba = tmp1 -> n;
            while(liczba < tmp2 -> n && tmp2 -> next2 != NULL)
            {    
                tmp2 = tmp2 -> next2;
            }
            
            if(tmp2 -> next2 == NULL && tmp2 -> n > liczba)
            {
                cubby1 = tmp1 -> next1;
                tmp1 -> next2 = NULL;
                tmp1 -> next1 = tmp2;
                tmp -> next1 = cubby1;
                cubby1 -> next2 = tmp;
                tmp2 -> next2 = tmp1; 
                head1 = tmp1;

                tmp1 = cubby1;
                tmp2 = tmp;
            }
            else if(tmp1 -> next1 == NULL)
            {
                cubby1 = tmp2 -> next1;
                tmp2 -> next1 = tmp1;
                cubby1 -> next2 = tmp1;
                tmp1 -> next1 = cubby1;
                tmp1 -> next2 = tmp2;
                tmp -> next1 = NULL;
                head2 = tmp;
                break;
            }
            else
            {
                cubby1 = tmp1 -> next1;
                tmp -> next1 = cubby1;
                cubby1 -> next2 = tmp;
                cubby2 = tmp2 -> next1;
                tmp1 -> next1 = cubby2;
                tmp1 -> next2 = tmp2;
                cubby2 -> next2 = tmp1;
                tmp2 -> next1 = tmp1;

                tmp1 = cubby1;
                tmp2 = tmp;
            }
        }
        else
        {
            tmp = tmp->next1;
            tmp1 = tmp -> next1;
            tmp2 = tmp;
        }
    }

    tmp = head1;
    while(tmp != NULL)
    {
        cout<<tmp->n<<" ";
        tmp = tmp -> next1;
    }

    return 0;
}