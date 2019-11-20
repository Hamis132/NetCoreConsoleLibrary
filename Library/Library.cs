namespace webowkaWejscie.Library
{
    using System;
    using webowkaWejscie.Interfaces;
    using webowkaWejscie.Models;

    public class Library : ILibrary
    {
        public void AddBook(Book book)
        {
            throw new NotImplementedException();
        }

        public void AddBook(string author)
        {
            throw new NotImplementedException();
        }

        public Book FindBook(int id)
        {
            throw new NotImplementedException();
        }

        public Book FindBook(string title)
        {
            throw new NotImplementedException();
        }

        public Book FindBook(string title, string author)
        {
            throw new NotImplementedException();
        }
    }
}