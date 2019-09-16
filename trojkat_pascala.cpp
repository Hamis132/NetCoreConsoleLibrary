#include <iostream>
using namespace std;

void struct_p(int tab[][30])
{
    int licznik = 0;
    for(int i=0 ; i<30; i++)
    {
        if(i == 0)
            for(int j=0; j<30; j++) tab[j][i] = 1;
        else
        {  
            for(int j=licznik; j<30; j++)
            {
                tab[j][i] = tab[j-1][i-1] + tab[j-1][i]; 
            } 
        }
        licznik++;
    }
}

int main()
{
    int tab[30][30];
    
    for(int i = 0; i < 30; i++)
    {
        for(int j=0; j<30; j++)
        {
            tab[i][j] = 0;
        }
    }
    
    struct_p(tab);

    

    for(int i = 0; i < 30; i++)
    {
        for(int j=0; j<30; j++)
        {
            if(tab[i][j] != 0 && tab[i][j] % 3 == 0) cout<<"X";
            else cout<<" ";
        }
        cout<<endl;
    }
}