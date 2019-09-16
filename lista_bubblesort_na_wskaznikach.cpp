#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct node
{
    int n;
    node* next;
};

int main()
{
    int k; cin>>k;
    node* tmp;
    node* tmp1;
    node* tmp2;
    node* tmp3;
    node* a;
    node* head;

    srand(time(NULL));

    for(int i=0; i<k; i++)
    {
        a = new node;
        a->n = rand()%10+1;
        cout<<a->n<<" ";
        if( i!=0 ) tmp -> next = a; 
        else head = a;

        tmp = a;
    }
    a -> next = NULL;

    tmp = head;
    tmp1 = head -> next;
    tmp2 = tmp1 -> next;
    tmp3 = tmp2 -> next; 

    for(int i=0; i<k; i++)
    {
        for(int j=0; j<k-3; j++)
        {
    
            if(j == 0 && tmp->n > tmp1->n)
            {
                head = tmp1;
                tmp1 -> next = tmp;
                tmp -> next = tmp2;


            }
            else if(tmp3 -> next == NULL && tmp2->n > tmp3->n)
            {
                tmp1 -> next = tmp3;
                tmp3 ->next = tmp2;
                tmp2 -> next = NULL;

           
            }
            else if(tmp1->n > tmp2->n)
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
        
        tmp = head;
        tmp1 = head -> next;
        tmp2 = tmp1 -> next;
        tmp3 = tmp2 -> next;
        
    }

    cout<<endl;
    tmp = head;

    for(int i=0; i<k; i++)
    {
        cout<<tmp->n<<" ";

        tmp = tmp->next;
    }

    return 0;
}