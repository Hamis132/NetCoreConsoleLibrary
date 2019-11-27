namespace webowkaWejscie.Library
{
    using System;
    using webowkaWejscie.Interfaces;
    using webowkaWejscie.Models;

    public class Library : ILibrary
    {
        public Book AddBook(int a, Book previous)
        {
            Book tmp;
            string s, b;
            
            Console.Write("Add the author name "); s = Console.ReadLine(); 
            Console.Write("\nAdd the title "); b = Console.ReadLine();

            Console.Clear();

            if(a == 0)
            {
                tmp = new Book(s,b);
                tmp.setnext(null);
                return tmp;
            }
            else
            {
                tmp = new Book(s,b);
                tmp.setnext(null);
                previous.setnext(tmp);
                return tmp;
            }

            throw new NotImplementedException("error");
        }
        public void FindBook(Book head)
        {
            string  a, b;
            string x;
            bool f = false;

            Console.WriteLine("do you want to looking for by author or by title?");
            Console.WriteLine("1.Author");
            Console.WriteLine("2.title");
            Console.WriteLine("3.By author and title");

            x = Console.ReadLine();

            Console.Clear();

            if(x == "1" || x == "2")
            {
                Console.WriteLine("input parameter "); a = Console.ReadLine();
                Console.Clear();

                if(x == "1")
                {
                    while(head != null)
                    {
                        if(head.Author == a)
                        {
                            Console.Write(head.Author, " ");
                            Console.WriteLine(head.Title);
                            f = true;
                        }

                        head = head.next;
                    }
                }
                else
                {
                     while(head != null)
                    {
                        if(head.Title == a)
                        {
                            Console.Write(head.Author, " ");
                            Console.WriteLine(head.Title);
                            f = true;
                        }
                        head = head.next;
                    }
                }

            }
            else
            {
                Console.WriteLine("input Author name "); a = Console.ReadLine();
                Console.WriteLine("input title "); b = Console.ReadLine();
                Console.Clear();

                while(head != null)
                {
                    if(head.Title == b && head.Author == a)
                    {
                        Console.Write(head.Author, " ");
                        Console.WriteLine(head.Title);
                        f = true;
                    }
                    head = head.next;
                }
            }

            if(f == false) Console.WriteLine("There is no such book");
            x = Console.ReadLine();

            Console.Clear();
        }
        public void showlistofbooks(Book head)
        {
            while(head != null)
            {
                Console.Write(head.Title);
                Console.Write("   ");
                Console.WriteLine(head.Author);

                head = head.next;
            }
        }
    }
}