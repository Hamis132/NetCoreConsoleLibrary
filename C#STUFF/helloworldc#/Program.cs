using System;
using webowkaWejscie.Interfaces;
using webowkaWejscie.Library;
using webowkaWejscie.Models;

namespace webowkaWejscie
{
    class Program
    {
        static void Main(string[] args)
        {
            int books = 0;
            char x;
            ILibrary biblioteka = new Library.Library();

            Book head = null;
            Book previous = null;

            while(true)
            {
                Console.Write("\n\nWhat do you want to do? \n\n");
            
                    Console.Write("1. Add book \n");
                    Console.Write("2. find book \n");
                    Console.Write ("3. show list of books \n");
                    Console.Write("0. exit\n\n");

                x = Console.ReadKey().KeyChar;      
        
                Console.Clear();

                if(x == '1')
                { 
                    biblioteka.AddBook(); 
                }
                else if(x == '2')        
                {     
                    biblioteka.FindBook();              
                }  
                else if(x == '3') 
                {
                    biblioteka.showlistofbooks();
                }
                else if(x == '0') break;
            }        
        }
    }
}
