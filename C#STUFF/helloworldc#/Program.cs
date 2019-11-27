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
            string x;
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

                x = Console.ReadLine();      
        
                Console.Clear();

                if(x == "1")
                { 
                    previous = biblioteka.AddBook(books, previous); 
                    if(books == 0) head = previous; 
                    books++; 
                }
                else if(x == "2")        
                {    
                   if(head == null) Console.Write("There is no books here sorry\n"); 
                   else biblioteka.FindBook(head);              
                }  
                else if(x == "3") 
                {
                    biblioteka.showlistofbooks(head);
                }
                else if(x == "0") break;
               

            }        
        }
    }
}
