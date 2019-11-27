namespace webowkaWejscie.Library
{
    using System;
    using System.Collections.Generic;
    using webowkaWejscie.Interfaces;
    using webowkaWejscie.Models;
    using webowkaWejscie.SortingAlgorithms;
    using System.Linq;
    public class Library : ILibrary
    {
        public List<Book> Books { get; private set; } 

        public Library()
        {
            Books = new List<Book>();
        }

        public void SortBooks()
        {
            BubbleSort.Sort(Books);
        }

        public void AddBook()
        {
            string s, b;
            
            Console.Write("Add the author name "); s = Console.ReadLine(); 
            Console.Write("\nAdd the title "); b = Console.ReadLine();

            Console.Clear();
            
            Books.Add(new Book(s,b));
        }


        public void FindBook()
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
            Book book;
            if(x == "1" || x == "2")
            {
                Console.WriteLine("input parameter ");
                a = Console.ReadLine();
                Console.Clear();

                if(x == "1")
                {
                    Func<Book, bool> func = (item) => {
                                        return item.Author.ToLower() == a.ToLower();
                                        };
                    book = Books.FirstOrDefault(func);
                    
                    if(book != null)
                    {
                        System.Console.WriteLine($"Author: {book.Author} Title: {book.Title}");
                    }

                }
                else
                {
                    book = Books.FirstOrDefault(x => x.Title
                                                    .Equals(a, StringComparison.CurrentCultureIgnoreCase)
                                                );
                    if(book != null)
                    {
                        System.Console.WriteLine($"Author: {book.Author} Title: {book.Title}");
                    }
                }

            }
            else
            {
                Console.WriteLine("input Author name "); a = Console.ReadLine();
                Console.WriteLine("input title "); b = Console.ReadLine();
                Console.Clear();

                book = Books.FirstOrDefault(x => x.Author.Equals(a) && x.Title.Equals(b));
            }

            if(f == false) Console.WriteLine("There is no such book");
            x = Console.ReadLine();

            Console.Clear();
        }
        public void showlistofbooks()
        {
            foreach(Book book in Books)
            {
                System.Console.WriteLine(
                    $"Author: {book.Author}\nTitle: {book.Title}");
            }
        }
    }
}