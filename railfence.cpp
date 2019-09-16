#include <iostream>
using namespace std;

void fence(int n, int p, string s)
{
    int j, od1, od2;
    bool f;
    
    for(int i=0; i<p; i++)
    {
        j = i;
        if(i == 0 || i == p-1)
        {
            while(j<=n)
            {
                cout<<s[j];
                j+=(p-1)*2;
            }
        }
        else if(p%2 == 1 && i == p/2)
        {
            while(j<=n)
            {
                cout<<s[j];
                j+=((p-1)*2)/2;
            }
        }
        else
        {
            od1 = ((p-1)*2)-2*i;
            od2 = 2*i;
            
            f = true;
            while(j<=n)
            {
                cout<<s[j];
                if(f == true)
                {
                    j+=od1;
                    f = false;
                }
                else
                {
                    j+=od2;
                    f = true;
                }
            }
        }
    }
}

int main()
{
    string s = "TABEFGBAAGKJILPZCDDWTSRCZKL";
    int l_liter = 27, przesuniecie;

    cin>>przesuniecie;
    
    fence(l_liter, przesuniecie, s);
}